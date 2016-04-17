// MyCAD.h : main header file for the MYCAD application
//

#if !defined(AFX_MYCAD_H__DE38B2DC_D4D6_4B09_B277_FCB1749D3B61__INCLUDED_)
#define AFX_MYCAD_H__DE38B2DC_D4D6_4B09_B277_FCB1749D3B61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyCADApp:
// See MyCAD.cpp for the implementation of this class
//

class CMyCADApp : public CWinApp
{
public:
	CMyCADApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCADApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyCADApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCAD_H__DE38B2DC_D4D6_4B09_B277_FCB1749D3B61__INCLUDED_)
