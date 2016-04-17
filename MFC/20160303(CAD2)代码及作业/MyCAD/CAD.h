// CAD.h : main header file for the CAD application
//

#if !defined(AFX_CAD_H__32539225_F1C8_43DB_85C0_22F7787558A2__INCLUDED_)
#define AFX_CAD_H__32539225_F1C8_43DB_85C0_22F7787558A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCADApp:
// See CAD.cpp for the implementation of this class
//

class CCADApp : public CWinApp
{
public:
	CCADApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCADApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCADApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAD_H__32539225_F1C8_43DB_85C0_22F7787558A2__INCLUDED_)
