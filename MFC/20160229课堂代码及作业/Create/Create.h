// Create.h : main header file for the CREATE application
//

#if !defined(AFX_CREATE_H__35E65FCD_47F8_44A2_98C3_0251AD00B727__INCLUDED_)
#define AFX_CREATE_H__35E65FCD_47F8_44A2_98C3_0251AD00B727__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateApp:
// See Create.cpp for the implementation of this class
//

class CCreateApp : public CWinApp
{
public:
	CCreateApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATE_H__35E65FCD_47F8_44A2_98C3_0251AD00B727__INCLUDED_)
