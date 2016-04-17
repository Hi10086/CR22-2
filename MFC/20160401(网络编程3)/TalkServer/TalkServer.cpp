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
    MySend(*it, pszMsg);
  }
  LeaveCriticalSection(&g_cs);
}

int ParseCommand(SOCKET Socket, tagPacket *pPakcet)
{
  char szBuff[MAXBYTE];
  strcpy(szBuff, pPakcet->m_Data);


  int nResult = 0;
  char* Param[10];
  MyStrtok(Param, pPakcet->m_Data);



  //获取命令
  const char *pszCmd = GetParam(Param[0], "cmd");
  if (pszCmd == NULL)
      return -1;

  if (strcmp(pszCmd, "login") == 0)
  {
    //登陆
    const char*pszUser = GetParam(Param[1], "user");
    const char *pszPassword = GetParam(Param[2], "password");

    //验证
    nResult = MySend(Socket, "cmd:login_ok");
  }
  else if (strcmp(pszCmd, "public") == 0)
  {
    SendAllClient(szBuff);
    nResult = 1;
  }
  else if (strcmp(pszCmd, "private") == 0)
  {
  }

  return nResult;
}

unsigned int __stdcall WorkThread(void *lpParam)
{
  SOCKET sClient = (SOCKET)lpParam;
  sockaddr_in addr;
  int nLen = sizeof(addr);
  getpeername(sClient, (sockaddr*)&addr, &nLen);

  
  while(true)
  {
    tagPacket *pPacket = NULL;
    if (MyRecv(sClient, &pPacket) <= 0)
      break;

    //解析命令
    if (ParseCommand(sClient, pPacket) <= 0)
      break;

    delete[] pPacket;
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

