// ModalPlaneDLL.h : main header file for the MODALPLANEDLL DLL
//

#if !defined(AFX_MODALPLANEDLL_H__1F95945E_595E_4915_8E2D_B8057027D80F__INCLUDED_)
#define AFX_MODALPLANEDLL_H__1F95945E_595E_4915_8E2D_B8057027D80F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "GodThread.h"

/////////////////////////////////////////////////////////////////////////////
// CModalPlaneDLLApp
// See ModalPlaneDLL.cpp for the implementation of this class
//

class CModalPlaneDLLApp : public CWinApp
{
public:
	static CGodThread* m_pGodThread;
	static WNDPROC m_gOldProc;
	static LRESULT CALLBACK WindowProc( HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	CModalPlaneDLLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModalPlaneDLLApp)
	public:
	virtual int ExitInstance();
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CModalPlaneDLLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODALPLANEDLL_H__1F95945E_595E_4915_8E2D_B8057027D80F__INCLUDED_)
