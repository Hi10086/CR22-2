// ui.h : main header file for the UI application
//

#if !defined(AFX_UI_H__C0961A4B_B541_4495_B288_F965519CBEA0__INCLUDED_)
#define AFX_UI_H__C0961A4B_B541_4495_B288_F965519CBEA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CUiApp:
// See ui.cpp for the implementation of this class
//

class CUiApp : public CWinApp
{
public:
	CUiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CUiApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UI_H__C0961A4B_B541_4495_B288_F965519CBEA0__INCLUDED_)
