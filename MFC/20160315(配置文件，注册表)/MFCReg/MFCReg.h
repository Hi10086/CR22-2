// MFCReg.h : main header file for the MFCREG application
//

#if !defined(AFX_MFCREG_H__DDB7B71B_EA08_422A_90AC_B32F2814065E__INCLUDED_)
#define AFX_MFCREG_H__DDB7B71B_EA08_422A_90AC_B32F2814065E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCRegApp:
// See MFCReg.cpp for the implementation of this class
//

class CMFCRegApp : public CWinApp
{
public:
	CMFCRegApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCRegApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMFCRegApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCREG_H__DDB7B71B_EA08_422A_90AC_B32F2814065E__INCLUDED_)
