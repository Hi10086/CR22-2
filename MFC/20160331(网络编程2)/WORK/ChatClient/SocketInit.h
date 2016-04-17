// SocketInit.h: interface for the CSocketInit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOCKETINIT_H__CFE61E5E_4D60_49EB_A97C_F2CC719229BA__INCLUDED_)
#define AFX_SOCKETINIT_H__CFE61E5E_4D60_49EB_A97C_F2CC719229BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <Winsock2.h>
#pragma comment(lib, "Ws2_32.lib")

class CSocketInit  
{
public:
	CSocketInit();
	virtual ~CSocketInit();
};

#define MSG_CHAT	1
#define MSG_ONLINE	2
#define MSG_OFFLINE	3

#pragma pack(push)
#pragma pack(1)

// struct TagCommand
// {
// 	
// };

struct TagMsg
{
	int m_nSize;
	int m_nFrom;
	int m_nDest;
	int m_nOper;

	char data[1];
};

#pragma pack(pop)

#endif // !defined(AFX_SOCKETINIT_H__CFE61E5E_4D60_49EB_A97C_F2CC719229BA__INCLUDED_)





















