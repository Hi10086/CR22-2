// ModaLessPlaneDLL.h : main header file for the MODALESSPLANEDLL DLL
//

#if !defined(AFX_MODALESSPLANEDLL_H__B6487C8A_0E92_4262_A450_67CA1C7F883D__INCLUDED_)
#define AFX_MODALESSPLANEDLL_H__B6487C8A_0E92_4262_A450_67CA1C7F883D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CModaLessPlaneDLLApp
// See ModaLessPlaneDLL.cpp for the implementation of this class
//

class CModaLessPlaneDLLApp : public CWinApp
{
public:
	CModaLessPlaneDLLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModaLessPlaneDLLApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CModaLessPlaneDLLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODALESSPLANEDLL_H__B6487C8A_0E92_4262_A450_67CA1C7F883D__INCLUDED_)
