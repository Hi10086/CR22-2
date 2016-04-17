// Process.h : main header file for the PROCESS application
//

#if !defined(AFX_PROCESS_H__3CDE817F_C702_478C_9139_7CF32A58BD31__INCLUDED_)
#define AFX_PROCESS_H__3CDE817F_C702_478C_9139_7CF32A58BD31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CProcessApp:
// See Process.cpp for the implementation of this class
//

class CProcessApp : public CWinApp
{
public:
	CProcessApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcessApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CProcessApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCESS_H__3CDE817F_C702_478C_9139_7CF32A58BD31__INCLUDED_)
