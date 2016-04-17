// SankCAD.h : main header file for the SANKCAD application
//

#if !defined(AFX_SANKCAD_H__0E47C3E7_BFB3_4E6A_B269_6E2CF01BF5DD__INCLUDED_)
#define AFX_SANKCAD_H__0E47C3E7_BFB3_4E6A_B269_6E2CF01BF5DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSankCADApp:
// See SankCAD.cpp for the implementation of this class
//

class CSankCADApp : public CWinApp
{
public:
	CSankCADApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSankCADApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSankCADApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SANKCAD_H__0E47C3E7_BFB3_4E6A_B269_6E2CF01BF5DD__INCLUDED_)
