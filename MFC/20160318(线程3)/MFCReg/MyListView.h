#if !defined(AFX_MYLISTVIEW_H__1F3E2AC6_7DAD_42B6_B741_66D370DE5290__INCLUDED_)
#define AFX_MYLISTVIEW_H__1F3E2AC6_7DAD_42B6_B741_66D370DE5290__INCLUDED_
#include <afxcview.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyListView.h : header file
//
#include "MFCRegDoc.h"
/////////////////////////////////////////////////////////////////////////////
// CMyListView view

class CMyListView : public CListView
{
protected:
	CMyListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMyListView)

// Attributes
public:
	CListCtrl& m_tree;
// Operations
public:
	CMFCRegDoc* GetDocument();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyListView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyListView)
	afx_msg void OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLISTVIEW_H__1F3E2AC6_7DAD_42B6_B741_66D370DE5290__INCLUDED_)
