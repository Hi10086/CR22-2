// FileMap.h : main header file for the FILEMAP application
//

#if !defined(AFX_FILEMAP_H__3CCE9AA7_C4A8_447F_9708_4FC5FE0A0EDD__INCLUDED_)
#define AFX_FILEMAP_H__3CCE9AA7_C4A8_447F_9708_4FC5FE0A0EDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileMapApp:
// See FileMap.cpp for the implementation of this class
//

class CFileMapApp : public CWinApp
{
public:
	CFileMapApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileMapApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileMapApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEMAP_H__3CCE9AA7_C4A8_447F_9708_4FC5FE0A0EDD__INCLUDED_)
