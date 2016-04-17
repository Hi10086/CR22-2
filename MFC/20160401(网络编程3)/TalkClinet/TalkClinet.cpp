// TalkClinet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../TalkServer/SocketInit.h"
#include <process.h>
#include <STRING.H>

CSocketInit g_Init;


int ParseCommand(SOCKET Socket, tagPacket *pPakcet)
{
  int nResult = 0;
  char* Param[10];
  MyStrtok(Param, pPakcet->m_Data);
  
  //获取命令
  const char *pszCmd = GetParam(Param[0], "cmd");
  if (pszCmd == NULL)
    return -1;
  
  if (strcmp(pszCmd, "login_ok") == 0)
  {
    printf("login ok\r\n");
  }
  if (strcmp(pszCmd, "public") == 0)
  {
    const char*pszMsg = GetParam(Param[1], "msg");
    const char *pszUser = GetParam(Param[2], "user");
    printf("%s说:%s\r\n", pszUser, pszMsg);
  }
  else if (strcmp(pszCmd, "public") == 0)
  {
  }
  else if (strcmp(pszCmd, "private") == 0)
  {
  }

  return 1;
}

unsigned int __stdcall WorkThread(void *lpParam)
{
  SOCKET Socket = (SOCKET)lpParam;
  
  while(true)
  {
    tagPacket *pPacket = NULL;
    if (MyRecv(Socket, &pPacket) <= 0)
      break;

    //解析命令
    if (ParseCommand(Socket, pPacket) <= 0)
      break;
    
    delete[] pPacket;
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
  
  //登陆
  char szUser[MAXBYTE];
  char szPassword[MAXBYTE];
  char szBuff[MAXBYTE];
  printf("user:");
  scanf("%s", szUser);
  printf("passwork:");
  scanf("%s", szPassword);
  sprintf(szBuff, "cmd:login\n"
                  "user:%s\n"
                  "password:%s", 
          "admin", "admin");
  MySend(Socket, szBuff);
  
  //开启线程
  _beginthreadex(NULL, 0, WorkThread, (LPVOID)Socket, 0, NULL);


  while(true)
  {
    char szMsg[MAXBYTE];
    scanf("%s", szMsg);
    if (strcmp(szMsg, "e") == 0)
      break;

    sprintf(szBuff, "cmd:public\n"
            "msg:%s\n"
            "user:%s",
            szMsg, 
            szUser);

    MySend(Socket, szBuff);
  }

  closesocket(Socket);
	return 0;
}

