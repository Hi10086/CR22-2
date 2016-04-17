// PlaneHack.h : main header file for the PLANEHACK application
//

#if !defined(AFX_PLANEHACK_H__BA16A590_04D7_4F08_8712_0748BC6676F5__INCLUDED_)
#define AFX_PLANEHACK_H__BA16A590_04D7_4F08_8712_0748BC6676F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPlaneHackApp:
// See PlaneHack.cpp for the implementation of this class
//

class CPlaneHackApp : public CWinApp
{
public:
	CPlaneHackApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlaneHackApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPlaneHackApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLANEHACK_H__BA16A590_04D7_4F08_8712_0748BC6676F5__INCLUDED_)
