// StaticDll.h : main header file for the STATICDLL DLL
//

#if !defined(AFX_STATICDLL_H__62774067_2BB8_4775_BE12_21C8433D31D7__INCLUDED_)
#define AFX_STATICDLL_H__62774067_2BB8_4775_BE12_21C8433D31D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStaticDllApp
// See StaticDll.cpp for the implementation of this class
//

class CStaticDllApp : public CWinApp
{
public:
	CStaticDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticDllApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CStaticDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICDLL_H__62774067_2BB8_4775_BE12_21C8433D31D7__INCLUDED_)
