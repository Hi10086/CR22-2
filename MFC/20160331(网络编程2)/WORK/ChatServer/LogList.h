#if !defined(AFX_LOGLIST_H__6F284EA1_F9BD_4D49_BAD0_0D7F5CF26ABE__INCLUDED_)
#define AFX_LOGLIST_H__6F284EA1_F9BD_4D49_BAD0_0D7F5CF26ABE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogList window

class CLogList : public CListBox
{
// Construction
public:
	CLogList();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogList)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLogList();

	// Generated message map functions
protected:
	//{{AFX_MSG(CLogList)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGLIST_H__6F284EA1_F9BD_4D49_BAD0_0D7F5CF26ABE__INCLUDED_)
