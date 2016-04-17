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
#endif // !defined(AFX_SOCKETINIT_H__C22FE742_FE79_4A70_ACC4_84FB39FB9118__INCLUDED_)
