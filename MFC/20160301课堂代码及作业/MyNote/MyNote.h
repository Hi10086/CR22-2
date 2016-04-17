// MyNote.h : main header file for the MYNOTE application
//

#if !defined(AFX_MYNOTE_H__364CF7D6_E0D3_48C7_8DDC_9E3392B3B4C0__INCLUDED_)
#define AFX_MYNOTE_H__364CF7D6_E0D3_48C7_8DDC_9E3392B3B4C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyNoteApp:
// See MyNote.cpp for the implementation of this class
//

class CMyNoteApp : public CWinApp
{
public:
	CMyNoteApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyNoteApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyNoteApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYNOTE_H__364CF7D6_E0D3_48C7_8DDC_9E3392B3B4C0__INCLUDED_)
