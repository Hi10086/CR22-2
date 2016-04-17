// TalkServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SocketInit.h"
#include <process.h>
#include <LIST>
#include <STRING.H>
using namespace std;

CSocketInit g_Init;
SOCKET g_Clients[WSA_MAXIMUM_WAIT_EVENTS];
WSAEVENT g_Events[WSA_MAXIMUM_WAIT_EVENTS];

int g_nCount = 0;

void InsertClient(SOCKET Socket)
{
  g_Clients[g_nCount]  = Socket;
  g_Events[g_nCount] = WSACreateEvent();
  WSAEventSelect(g_Clients[g_nCount],
                 g_Events[g_nCount],
                 FD_ACCEPT | FD_CLOSE | FD_READ);
  g_nCount++;
}

void RemoveClinet(DWORD dwIndex)
{
  WSACloseEvent(g_Events[dwIndex]);
  closesocket(g_Clients[dwIndex]);

  g_Clients[dwIndex] = g_Clients[g_nCount];
  g_Events[dwIndex] = g_Events[g_nCount];
  g_nCount--;
}

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
    DWORD dwIndex = WSAWaitForMultipleEvents(g_nCount, g_Events, FALSE, WSA_INFINITE, FALSE);
    if (WSA_WAIT_FAILED == dwIndex)
      break;
    dwIndex = dwIndex - WSA_WAIT_EVENT_0;

    //获取事件
    WSANETWORKEVENTS  Events;
    if (WSAEnumNetworkEvents(g_Clients[dwIndex], g_Events[dwIndex], &Events)
       == SOCKET_ERROR)
    {
      break;
    }

    switch(Events.lNetworkEvents)
    {
    case FD_ACCEPT:
      {
        sockaddr_in addr;
        int nLen = sizeof(addr);
        SOCKET sClient = accept(g_Clients[dwIndex], (sockaddr*)&addr, &nLen);
        sprintf(szBuff, "%d %s:%d connect...\r\n", 
                sClient, 
                inet_ntoa(addr.sin_addr), 
                htons(addr.sin_port));
        printf(szBuff);
        InsertClient(sClient);
      }
      break;
    case FD_READ:
      {
        nResult = recv(g_Clients[dwIndex], szBuff, sizeof(szBuff), 0);
        puts(szBuff);
      }
      break;
    case FD_CLOSE:
      {
        RemoveClinet(dwIndex);
      }
      break;
    }
  }
  
  printf("WorkThread end...\r\n");
  return 0;
}

/*
 WSACreateEvent
 WSACloseEvent
 WSAWaitForMultipleEvents
 WSAEventSelect
*/
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

  //socket选择事件对象
  InsertClient(Socket);
  
  //开启线程
  HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, WorkThread, NULL, 0, NULL);

  system("pause");
  WSAResetEvent(g_Events[0]);
  WaitForSingleObject(hThread, -1);
  CloseHandle(hThread);
  puts("Server stop...");
	return 0;
}

