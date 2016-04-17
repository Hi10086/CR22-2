// Test2.h : main header file for the TEST2 application
//

#if !defined(AFX_TEST2_H__EA382CF7_59A4_43A6_A907_6BE6E2931440__INCLUDED_)
#define AFX_TEST2_H__EA382CF7_59A4_43A6_A907_6BE6E2931440__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest2App:
// See Test2.cpp for the implementation of this class
//

class CTest2App : public CWinApp
{
public:
	CTest2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest2App)
	public:
	virtual BOOL InitInstance();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTest2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
  HACCEL m_hAccel;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST2_H__EA382CF7_59A4_43A6_A907_6BE6E2931440__INCLUDED_)
