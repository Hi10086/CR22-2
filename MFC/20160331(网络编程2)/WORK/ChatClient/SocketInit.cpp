// SocketInit.cpp: implementation of the CSocketInit class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SocketInit.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSocketInit::CSocketInit()
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {          
		return;
	}
}

CSocketInit::~CSocketInit()
{

}
