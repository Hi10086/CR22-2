// MFCCp.h : main header file for the MFCCP application
//

#if !defined(AFX_MFCCP_H__69DA745A_21E5_4619_AE13_D6310613D5DD__INCLUDED_)
#define AFX_MFCCP_H__69DA745A_21E5_4619_AE13_D6310613D5DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCCpApp:
// See MFCCp.cpp for the implementation of this class
//

class CMFCCpApp : public CWinApp
{
public:
	CMFCCpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCCpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMFCCpApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCCP_H__69DA745A_21E5_4619_AE13_D6310613D5DD__INCLUDED_)
