// SankTools.h : main header file for the SANKTOOLS application
//

#if !defined(AFX_SANKTOOLS_H__4DC8D69E_C93D_4F9E_A34F_008DD53766F2__INCLUDED_)
#define AFX_SANKTOOLS_H__4DC8D69E_C93D_4F9E_A34F_008DD53766F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSankToolsApp:
// See SankTools.cpp for the implementation of this class
//

class CSankToolsApp : public CWinApp
{
public:
	CSankToolsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSankToolsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSankToolsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SANKTOOLS_H__4DC8D69E_C93D_4F9E_A34F_008DD53766F2__INCLUDED_)
