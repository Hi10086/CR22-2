// MyCADView.h : interface of the CMyCADView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCADVIEW_H__DFDCB3E0_84DF_4555_978C_A2531014E6B5__INCLUDED_)
#define AFX_MYCADVIEW_H__DFDCB3E0_84DF_4555_978C_A2531014E6B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>
#include "Shape.h"
#include "Line.h"

enum TYPE {SHAPE_LINE, SHAPE_RECT, SHAPE_UNKNOWN};

class CMyCADView : public CView
{
protected: // create from serialization only
	CMyCADView();
	DECLARE_DYNCREATE(CMyCADView)

// Attributes
public:
	CMyCADDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCADView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyCADView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL m_isdown;
	CShape *m_pShape;
	CList<CShape*, CShape*> m_list;

// Generated message map functions
protected:
	//{{AFX_MSG(CMyCADView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnCancelMode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyCADView.cpp
inline CMyCADDoc* CMyCADView::GetDocument()
   { return (CMyCADDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCADVIEW_H__DFDCB3E0_84DF_4555_978C_A2531014E6B5__INCLUDED_)
