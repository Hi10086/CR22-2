#if !defined(AFX_GODTHREAD_H__F5C2A9FE_5477_48D3_9EF1_E38452DF3171__INCLUDED_)
#define AFX_GODTHREAD_H__F5C2A9FE_5477_48D3_9EF1_E38452DF3171__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GodThread.h : header file
//
#include "GodPlaneDlg.h"


/////////////////////////////////////////////////////////////////////////////
// CGodThread thread

class CGodThread : public CWinThread
{
	DECLARE_DYNCREATE(CGodThread)
protected:
	CGodThread();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
	CGodPlaneDlg* m_pGodDlg;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGodThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CGodThread();

	// Generated message map functions
	//{{AFX_MSG(CGodThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GODTHREAD_H__F5C2A9FE_5477_48D3_9EF1_E38452DF3171__INCLUDED_)
