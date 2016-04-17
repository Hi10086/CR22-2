// Enum.h : main header file for the ENUM application
//

#if !defined(AFX_ENUM_H__5FBF17D1_0B5F_47EC_8AAD_0548DCBE58D7__INCLUDED_)
#define AFX_ENUM_H__5FBF17D1_0B5F_47EC_8AAD_0548DCBE58D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEnumApp:
// See Enum.cpp for the implementation of this class
//

class CEnumApp : public CWinApp
{
public:
	CEnumApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnumApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEnumApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENUM_H__5FBF17D1_0B5F_47EC_8AAD_0548DCBE58D7__INCLUDED_)
