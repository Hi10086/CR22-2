// ConfigFile.h : main header file for the CONFIGFILE application
//

#if !defined(AFX_CONFIGFILE_H__A893EF08_D83D_42AD_9212_43FE4A6C58F3__INCLUDED_)
#define AFX_CONFIGFILE_H__A893EF08_D83D_42AD_9212_43FE4A6C58F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CConfigFileApp:
// See ConfigFile.cpp for the implementation of this class
//

class CConfigFileApp : public CWinApp
{
public:
	CConfigFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConfigFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CConfigFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONFIGFILE_H__A893EF08_D83D_42AD_9212_43FE4A6C58F3__INCLUDED_)
