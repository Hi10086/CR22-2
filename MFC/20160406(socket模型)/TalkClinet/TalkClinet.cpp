// TalkClinet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../TalkServer/SocketInit.h"
#include <process.h>
#include <STRING.H>

CSocketInit g_Init;


unsigned int __stdcall WorkThread(void *lpParam)
{
  SOCKET Socket = (SOCKET)lpParam;
  char szBuff[MAXBYTE];
  int nResult;

  while(true)
  {
    //接受长度
    nResult = recv(Socket, szBuff, sizeof(szBuff), 0);
    if (SOCKET_ERROR == nResult || nResult == 0)
    {
      return nResult;
    }
    puts(szBuff);
  }

  printf("WorkThread end...\r\n");
  closesocket(Socket);
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
  

  sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(12345);
  addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
  nResult = connect(Socket, (sockaddr*)&addr, sizeof(addr));
  if (INVALID_SOCKET == nResult)
  {
    ShowErrorMsg();
    return 0;
  }
  
  //开启线程
  _beginthreadex(NULL, 0, WorkThread, (LPVOID)Socket, 0, NULL);

  while(true)
  {
    char szMsg[MAXBYTE];
    scanf("%s", szMsg);
    nResult = send(Socket, szMsg, sizeof(szMsg), 0);
  }

  closesocket(Socket);
	return 0;
}

