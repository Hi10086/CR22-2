// WM_COPYDATA.h : main header file for the WM_COPYDATA application
//

#if !defined(AFX_WM_COPYDATA_H__30BB44AA_E342_4A6B_9C8E_2DC2CCE108EE__INCLUDED_)
#define AFX_WM_COPYDATA_H__30BB44AA_E342_4A6B_9C8E_2DC2CCE108EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWM_COPYDATAApp:
// See WM_COPYDATA.cpp for the implementation of this class
//

class CWM_COPYDATAApp : public CWinApp
{
public:
	CWM_COPYDATAApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWM_COPYDATAApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWM_COPYDATAApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WM_COPYDATA_H__30BB44AA_E342_4A6B_9C8E_2DC2CCE108EE__INCLUDED_)
