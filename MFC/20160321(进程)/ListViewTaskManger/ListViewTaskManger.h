// ListViewTaskManger.h : main header file for the LISTVIEWTASKMANGER application
//

#if !defined(AFX_LISTVIEWTASKMANGER_H__DCF3962F_FDB6_41AA_B059_EEE367377F7C__INCLUDED_)
#define AFX_LISTVIEWTASKMANGER_H__DCF3962F_FDB6_41AA_B059_EEE367377F7C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CListViewTaskMangerApp:
// See ListViewTaskManger.cpp for the implementation of this class
//

class CListViewTaskMangerApp : public CWinApp
{
public:
	CListViewTaskMangerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListViewTaskMangerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CListViewTaskMangerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTVIEWTASKMANGER_H__DCF3962F_FDB6_41AA_B059_EEE367377F7C__INCLUDED_)
