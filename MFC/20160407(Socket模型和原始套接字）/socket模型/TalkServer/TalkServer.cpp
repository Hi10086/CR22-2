// TalkServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SocketInit.h"
#include <process.h>
#include <LIST>
#include <STRING.H>
using namespace std;

CSocketInit g_Init;

unsigned int __stdcall WorkThread(void *lpParam)
{
  SOCKET sClient = (SOCKET)lpParam;
  sockaddr_in addr;
  int nLen = sizeof(addr);
  getpeername(sClient, (sockaddr*)&addr, &nLen);
  char szBuff[MAXBYTE];
  int nResult;


  while(true)
  {
    for (int i = 0; i < 00);

    nResult = recv(sClient, szBuff, sizeof(szBuff), 0);
    if (SOCKET_ERROR == nResult || nResult == 0)
    {
      if (WSAGetLastError() == WSAEWOULDBLOCK)
      {
        continue;
      }
      break;
    }
    puts(szBuff);
  }
  
  printf("WorkThread end...\r\n");
  closesocket(sClient);

  return 0;
}

int main(int argc, char* argv[])
{
  int nResult;
  SOCKET Socket = socket(AF_INET, /*协议族*/
                     SOCK_STREAM,  /*流套接字*/
                     IPPROTO_TCP /*协议*/);
  if (INVALID_SOCKET == Socket)
  {
    ShowErrorMsg();
    return 0;
  }

  //设置socket为非阻塞模式
  u_long nFlag = 1;
  ioctlsocket(Socket, FIONBIO, &nFlag);

  sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(12345);
  addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
  nResult = bind(Socket, (sockaddr*)&addr, sizeof(addr));
  if (nResult == SOCKET_ERROR)
  {
    ShowErrorMsg();
    return 0;
  }

  nResult = listen(Socket, SOMAXCONN);
  if (nResult == SOCKET_ERROR)
  {
    ShowErrorMsg();
    return 0;
  }

  puts("Server start...");

  //等待连接
  while(true)
  {
    sockaddr_in caddr;
    int nLen = sizeof(addr);
    SOCKET sClient = accept(Socket, (sockaddr*)&caddr, &nLen);
    if (sClient == INVALID_SOCKET)
    {
      if (WSAGetLastError() == WSAEWOULDBLOCK)
      {
        continue;
      }
    }
    char szBuff[MAXBYTE];
    sprintf(szBuff, "%d %s:%d connect...\r\n", 
            sClient, 
            inet_ntoa(caddr.sin_addr), 
            htons(caddr.sin_port));
    printf(szBuff);

    //开启线程
    _beginthreadex(NULL, 0, WorkThread, (LPVOID)sClient, 0, NULL);
  }

  closesocket(Socket);
  puts("Server stop...");
	return 0;
}

