// SocketInit.h: interface for the CSocketInit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOCKETINIT_H__C22FE742_FE79_4A70_ACC4_84FB39FB9118__INCLUDED_)
#define AFX_SOCKETINIT_H__C22FE742_FE79_4A70_ACC4_84FB39FB9118__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <WINDOWS.H>
#include <WINSOCK2.H>
#pragma comment(lib, "Ws2_32.lib")

class CSocketInit
{
public:
  CSocketInit()
  {
    WORD wVersionRequested;
    WSADATA wsaData;
    int err;
    
    wVersionRequested = MAKEWORD(2, 2);
    err = WSAStartup( wVersionRequested, &wsaData);
    if ( err != 0 ) {          
      return;
    }
  }
  virtual ~CSocketInit()
  {
    WSACleanup();
  }
};

inline void ShowErrorMsg()
{
  LPVOID lpMsgBuf;
  ::FormatMessage( 
    FORMAT_MESSAGE_ALLOCATE_BUFFER | 
    FORMAT_MESSAGE_FROM_SYSTEM | 
    FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL,
    ::WSAGetLastError(),
    MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
    (LPTSTR) &lpMsgBuf,
    0,
    NULL 
    );
  // Process any inserts in lpMsgBuf.
  // ...
  // Display the string.
  printf((char*)lpMsgBuf);
  
  ::LocalFree( lpMsgBuf );
}

#pragma pack(1)
struct tagPacket
{
  unsigned short m_nLength;
  char m_Data[1];
};


#pragma pack(8)

//协议
/*
1.登陆
2.群聊
3.私聊

"login"
"public"
"private"
*/

inline int MySend(SOCKET Socket, const char *pszCmd)
{
  int nResult;
  int nLength = strlen(pszCmd) + sizeof(char) + (int)(((tagPacket*)NULL)->m_Data);
  tagPacket *pPakcet = (tagPacket*)new char[nLength];
  
  pPakcet->m_nLength = nLength;
  strcpy(pPakcet->m_Data, pszCmd);
  
  //发送数据
  nResult = send(Socket, (char*)pPakcet, pPakcet->m_nLength, 0);
  delete pPakcet;
  return nResult;
}

int MyRecv(SOCKET Socket, tagPacket **ppPakcet)
{
  int nResult;
  unsigned short nLength;
  int nTotal = sizeof(nLength);
  int nRecvBytes = 0;
  
  while(nRecvBytes < nTotal)
  {
    //接受长度
    nResult = recv(Socket, (char*)&nLength + nRecvBytes, nTotal - nRecvBytes, 0);
    if (SOCKET_ERROR == nResult || nResult == 0)
    {
      return nResult;
    }
    nRecvBytes += nResult;
  }
  
  //接受数据
  tagPacket *pPacket = (tagPacket*)new char[nLength];
  pPacket->m_nLength = nLength;
  
  nTotal = nLength - sizeof(pPacket->m_nLength);
  nRecvBytes = 0;
  while(nRecvBytes < nTotal)
  {
    nResult = recv(Socket, pPacket->m_Data + nRecvBytes, nTotal - nRecvBytes, 0);
    if (SOCKET_ERROR == nResult || nResult == 0)
    {
      delete[] pPacket;
      return nResult;
    }
    nRecvBytes += nResult;
  }

  *ppPakcet = pPacket;
  return nResult;
}

inline void MyStrtok(char* ary[], char *pszData)
{
  //分割字符串
  int nIndex = 0;
  char *pToken = strtok(pszData, "\n");
  while(pToken)
  {
    ary[nIndex++] = pToken;
    pToken = strtok(NULL, "\n");
  }
}

inline const char* GetParam(char *pszData, const char *pszKey)
{
  const char *pToken = strtok(pszData, ":");
  if (pToken == NULL)
    return NULL;
  
  if (strcmp(pToken, pszKey) != 0)
    return NULL;
  
  pToken = strtok(NULL, "\n");
  if (pToken == NULL)
    return NULL;
  
  return pToken;
}

#endif // !defined(AFX_SOCKETINIT_H__C22FE742_FE79_4A70_ACC4_84FB39FB9118__INCLUDED_)
