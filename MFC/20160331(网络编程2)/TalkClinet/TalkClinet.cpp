// TalkClinet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../TalkServer/SocketInit.h"
#include <process.h>
#include <STRING.H>

CSocketInit g_Init;

int Test()
{
  for (int i = 0; i < 2000; i++)
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

    //char szBuff[MAXBYTE] = "hello";
    //nResult = send(Socket, szBuff, sizeof(szBuff), 0);
  }
  return 0;
}


unsigned int __stdcall WorkThread(void *lpParam)
{
  SOCKET Socket = (SOCKET)lpParam;
  char szBuff[MAXBYTE];
  char szFmt[MAXBYTE];
  int nResult;
  
  while(true)
  {
    nResult = recv(Socket, szBuff, sizeof(szBuff), 0);
    if (SOCKET_ERROR == nResult || nResult == 0)
    {
      break;
    }

    sprintf(szFmt, "server:%s\r\n", szBuff);
    printf(szFmt);
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
    char szBuff[MAXBYTE];
    scanf("%s", szBuff);
    if (strcmp(szBuff, "e") == 0)
      break;

    for (int i = 0; i < 10; i++)
    {
      nResult = send(Socket, szBuff, strlen(szBuff), 0);
    }
  }

  closesocket(Socket);
	return 0;
}

