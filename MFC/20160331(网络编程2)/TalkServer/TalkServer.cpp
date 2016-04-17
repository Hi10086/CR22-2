// TalkServer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SocketInit.h"
#include <process.h>
#include <LIST>
#include <STRING.H>
using namespace std;

CSocketInit g_Init;

CRITICAL_SECTION g_cs;
list<SOCKET> g_ClientList;

void SendAllClient(const char *pszMsg)
{
  EnterCriticalSection(&g_cs);
  for (list<SOCKET>::iterator it = g_ClientList.begin();
      it != g_ClientList.end(); 
      it++)
  {
    send(*it, pszMsg, strlen(pszMsg) + 1, 0);
  }
  LeaveCriticalSection(&g_cs);
}


unsigned int __stdcall WorkThread(void *lpParam)
{
  SOCKET sClient = (SOCKET)lpParam;
  char szBuff[MAXBYTE];
  char szFmt[MAXBYTE];
  int nResult;
  sockaddr_in addr;
  int nLen = sizeof(addr);
  getpeername(sClient, (sockaddr*)&addr, &nLen);

  
  while(true)
  {
    nResult = recv(sClient, szBuff, sizeof(szBuff), 0);
    if (SOCKET_ERROR == nResult || nResult == 0)
    {
      /*
       0客户端正常关闭
       0x2746 客户端强制关闭
      */
      sprintf(szFmt, "%d %s:%d disconnect...\r\n", 
              sClient, 
              inet_ntoa(addr.sin_addr), 
              htons(addr.sin_port));
      printf(szFmt);
      break;
    }

    szBuff[nResult] = '\0';
    sprintf(szFmt, "%d %s:%d bytes:%d %s\r\n", 
              sClient, 
              inet_ntoa(addr.sin_addr), 
              htons(addr.sin_port), 
              nResult,
              szBuff);
    printf(szFmt);
    
    //发送信息给所有客户端
    SendAllClient(szBuff);
  }

  printf("WorkThread end...\r\n");
  closesocket(sClient);

  //删除客户端
  EnterCriticalSection(&g_cs);
  for (list<SOCKET>::iterator it = g_ClientList.begin();
  it != g_ClientList.end(); 
  it++)
  {
    if (*it == sClient)
    {
      g_ClientList.erase(it);
      break;
    }
  }
  LeaveCriticalSection(&g_cs);

  return 0;
}

int main(int argc, char* argv[])
{
  InitializeCriticalSection(&g_cs);

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

  //等待连接
  while(true)
  {
    sockaddr_in caddr;
    int nLen = sizeof(addr);
    SOCKET sClient = accept(Socket, (sockaddr*)&caddr, &nLen);
    
    char szBuff[MAXBYTE];
    sprintf(szBuff, "%d %s:%d connect...\r\n", 
            sClient, 
            inet_ntoa(caddr.sin_addr), 
            htons(caddr.sin_port));
    printf(szBuff);

    //保存客户端
    EnterCriticalSection(&g_cs);
    g_ClientList.push_back(sClient);
    LeaveCriticalSection(&g_cs);

    //开启线程
    _beginthreadex(NULL, 0, WorkThread, (LPVOID)sClient, 0, NULL);
  }

  closesocket(Socket);
  puts("Server stop...");

  DeleteCriticalSection(&g_cs);
	return 0;
}

