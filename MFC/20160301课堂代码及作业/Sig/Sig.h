// Sig.h : main header file for the SIG application
//

#if !defined(AFX_SIG_H__868C67A5_9726_4769_AA14_474E1FD1EBFD__INCLUDED_)
#define AFX_SIG_H__868C67A5_9726_4769_AA14_474E1FD1EBFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSigApp:
// See Sig.cpp for the implementation of this class
//

class CSigApp : public CWinApp
{
public:
	CSigApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSigApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSigApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIG_H__868C67A5_9726_4769_AA14_474E1FD1EBFD__INCLUDED_)
