// CADView.h : interface of the CCADView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CADVIEW_H__B51D4106_05DD_443B_ADEB_7181DCE05372__INCLUDED_)
#define AFX_CADVIEW_H__B51D4106_05DD_443B_ADEB_7181DCE05372__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>
#include "IShape.h"

enum TYPE {SHAPE_LINE, SHAPE_RECT, SHAPE_UNKNOWN};

// 
// struct tagShape
// {
//   TYPE   m_Type;
//   CPoint m_ptBegin;
//   CPoint m_ptEnd;
// };

class CCADView : public CView
{
protected: // create from serialization only
	CCADView();
	DECLARE_DYNCREATE(CCADView)

// Attributes
public:
	CCADDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCADView)
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
	virtual ~CCADView();
  void CCADView::OnDrawOld(CDC* pDC);
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCADView)
	afx_msg void OnLine();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnCancelMode();
	afx_msg void OnRect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
  TYPE    m_Type;
  IShape* m_pCurShape;
  BOOL    m_isDown;
  CList<IShape*, IShape*> m_Shapes;
};

#ifndef _DEBUG  // debug version in CADView.cpp
inline CCADDoc* CCADView::GetDocument()
   { return (CCADDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CADVIEW_H__B51D4106_05DD_443B_ADEB_7181DCE05372__INCLUDED_)
