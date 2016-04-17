// CTL2.h : main header file for the CTL2 application
//

#if !defined(AFX_CTL2_H__95077E0B_7F30_4B74_A796_19F465295CB2__INCLUDED_)
#define AFX_CTL2_H__95077E0B_7F30_4B74_A796_19F465295CB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCTL2App:
// See CTL2.cpp for the implementation of this class
//

class CCTL2App : public CWinApp
{
public:
	CCTL2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTL2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCTL2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTL2_H__95077E0B_7F30_4B74_A796_19F465295CB2__INCLUDED_)
