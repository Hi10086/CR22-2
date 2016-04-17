// DoubleOpen.h : main header file for the DOUBLEOPEN application
//

#if !defined(AFX_DOUBLEOPEN_H__6D08A299_C101_4FF5_B274_9AE6C190BB31__INCLUDED_)
#define AFX_DOUBLEOPEN_H__6D08A299_C101_4FF5_B274_9AE6C190BB31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDoubleOpenApp:
// See DoubleOpen.cpp for the implementation of this class
//

class CDoubleOpenApp : public CWinApp
{
public:
	CDoubleOpenApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDoubleOpenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDoubleOpenApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOUBLEOPEN_H__6D08A299_C101_4FF5_B274_9AE6C190BB31__INCLUDED_)
