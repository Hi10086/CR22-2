// Call.h : main header file for the CALL application
//

#if !defined(AFX_CALL_H__C368B212_F515_457D_9E85_2C5A79187C48__INCLUDED_)
#define AFX_CALL_H__C368B212_F515_457D_9E85_2C5A79187C48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCallApp:
// See Call.cpp for the implementation of this class
//

class CCallApp : public CWinApp
{
public:
	CCallApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCallApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCallApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALL_H__C368B212_F515_457D_9E85_2C5A79187C48__INCLUDED_)
