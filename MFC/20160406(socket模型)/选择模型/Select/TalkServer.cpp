// TalkServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SocketInit.h"
#include <process.h>
#include <LIST>
#include <STRING.H>
using namespace std;

CSocketInit g_Init;
SOCKET g_Clients[FD_SETSIZE];
int g_nCount = 0;


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
    //轮询
    timeval tv = {2, 0};
    fd_set freadfds;
    FD_ZERO(&freadfds);
    for (int i = 0; i < g_nCount; i++)
       FD_SET(g_Clients[i], &freadfds);
    
//     freadfds.fd_count = g_nCount;
// 
//     for (int i = 0; i < freadfds.fd_count; i++)
//       freadfds.fd_array[i] = g_Clients[i];
   

    nResult = select(0, &freadfds, NULL, NULL, &tv);
    //超时
    if (nResult == 0)
    {
      continue;
    }

    if (nResult == SOCKET_ERROR)
      break;

    //检测哪个socket有信息
    for (int j = 0; j < freadfds.fd_count; j++)
    {
        if (freadfds.fd_array[j] == g_Clients[0])
        {
          sockaddr_in addr;
          int nLen = sizeof(addr);
          SOCKET sClient = accept(freadfds.fd_array[j], (sockaddr*)&addr, &nLen);
          sprintf(szBuff, "%d %s:%d connect...\r\n", 
            sClient, 
            inet_ntoa(addr.sin_addr), 
            htons(addr.sin_port));
            printf(szBuff);
          
            //检查超过64

            //保存socket
            g_Clients[g_nCount++] = sClient;
        }
        else
        {
          nResult = recv(freadfds.fd_array[j], szBuff, sizeof(szBuff), 0);
          if (nResult <= 0)
          {
            //断线
            for (int i = 0; i < g_nCount; i++)
            {
              if (g_Clients[i] == freadfds.fd_array[j])
              {
                closesocket(g_Clients[i]);
                g_Clients[i] = g_Clients[g_nCount - 1];
                g_nCount--;
                printf("%d close...\r\n", i);
                break;
              }
            }
          }
          else
          {
            puts(szBuff);
          }
        }
    }
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

  g_Clients[g_nCount++] = Socket;

  //开启线程
  HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, WorkThread, NULL, 0, NULL);

  WaitForSingleObject(hThread, -1);
  CloseHandle(hThread);

  closesocket(Socket);
  puts("Server stop...");
	return 0;
}

