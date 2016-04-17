// Sheet.h : main header file for the SHEET application
//

#if !defined(AFX_SHEET_H__A3928407_EA4E_413B_99D6_20D42DEC9114__INCLUDED_)
#define AFX_SHEET_H__A3928407_EA4E_413B_99D6_20D42DEC9114__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSheetApp:
// See Sheet.cpp for the implementation of this class
//

class CSheetApp : public CWinApp
{
public:
	CSheetApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSheetApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSheetApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHEET_H__A3928407_EA4E_413B_99D6_20D42DEC9114__INCLUDED_)
