#if !defined(AFX_MYTREE_H__208DDCD4_D7BA_4895_B15F_03FC17DD4442__INCLUDED_)
#define AFX_MYTREE_H__208DDCD4_D7BA_4895_B15F_03FC17DD4442__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyTree.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyTree view
#include <afxcview.h>

class CMyTree : public CTreeView
{
protected:
	CMyTree();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMyTree)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyTree)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyTree();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyTree)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTREE_H__208DDCD4_D7BA_4895_B15F_03FC17DD4442__INCLUDED_)
