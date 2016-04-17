// Ctl.h : main header file for the CTL application
//

#if !defined(AFX_CTL_H__01DDCD82_5130_4752_970F_74E21285D75E__INCLUDED_)
#define AFX_CTL_H__01DDCD82_5130_4752_970F_74E21285D75E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCtlApp:
// See Ctl.cpp for the implementation of this class
//

class CCtlApp : public CWinApp
{
public:
	CCtlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCtlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTL_H__01DDCD82_5130_4752_970F_74E21285D75E__INCLUDED_)
