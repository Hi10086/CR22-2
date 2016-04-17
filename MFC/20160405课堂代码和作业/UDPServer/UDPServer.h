// UDPServer.h : main header file for the UDPSERVER application
//

#if !defined(AFX_UDPSERVER_H__12EA6018_BFA8_47C4_8AA2_9672BF7BA7B3__INCLUDED_)
#define AFX_UDPSERVER_H__12EA6018_BFA8_47C4_8AA2_9672BF7BA7B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUDPServerApp:
// See UDPServer.cpp for the implementation of this class
//

class CUDPServerApp : public CWinApp
{
public:
	CUDPServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUDPServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUDPServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UDPSERVER_H__12EA6018_BFA8_47C4_8AA2_9672BF7BA7B3__INCLUDED_)
