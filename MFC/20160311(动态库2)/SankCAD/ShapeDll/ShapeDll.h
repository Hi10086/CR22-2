// ShapeDll.h : main header file for the SHAPEDLL DLL
//

#if !defined(AFX_SHAPEDLL_H__A756BBE3_3F98_4723_A341_1304ED56C9CA__INCLUDED_)
#define AFX_SHAPEDLL_H__A756BBE3_3F98_4723_A341_1304ED56C9CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShapeDllApp
// See ShapeDll.cpp for the implementation of this class
//

class CShapeDllApp : public CWinApp
{
public:
	CShapeDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShapeDllApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CShapeDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHAPEDLL_H__A756BBE3_3F98_4723_A341_1304ED56C9CA__INCLUDED_)
