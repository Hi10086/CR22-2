// SharedDll.h : main header file for the SHAREDDLL DLL
//

#if !defined(AFX_SHAREDDLL_H__5883E890_69BB_4352_ADD3_4D44D3FF4764__INCLUDED_)
#define AFX_SHAREDDLL_H__5883E890_69BB_4352_ADD3_4D44D3FF4764__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSharedDllApp
// See SharedDll.cpp for the implementation of this class
//

class CSharedDllApp : public CWinApp
{
public:
	CSharedDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSharedDllApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CSharedDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHAREDDLL_H__5883E890_69BB_4352_ADD3_4D44D3FF4764__INCLUDED_)
