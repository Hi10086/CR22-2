// SankCADView.h : interface of the CSankCADView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SANKCADVIEW_H__A0915CDE_F116_47F5_AA19_7E1E13891CBF__INCLUDED_)
#define AFX_SANKCADVIEW_H__A0915CDE_F116_47F5_AA19_7E1E13891CBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <afxtempl.h>
#include "IShape.h"
#include "IShapeFactory.h"
#include "LineFactory.h"
#include "PolyFactory.h"
#include "AddCommand.h"
#include "CommandMrg.h"
#include "MoveCommand.h"
#include "DelCommand.h"
#include "MyList.h"

class CSankCADView : public CView
{
protected: // create from serialization only
	CSankCADView();
	DECLARE_DYNCREATE(CSankCADView)

// Attributes
public:
	CSankCADDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSankCADView)
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
	virtual ~CSankCADView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	BOOL m_isSelect;
	BOOL m_isMoving;
	BOOL m_isCopy;
	IShape *m_CurShape;
	TagShape m_OldDate;
	IShape *m_SelectShape;
	IShapeFactory *m_Factory;
	//CMyList<IShape *, IShape *>& m_ShapeList;

	ICommand *m_pCommand;
	CCommandMrg m_CommandMrg;

// Generated message map functions
protected:
	//{{AFX_MSG(CSankCADView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnToolLine();
	afx_msg void OnToolPolygon();
	afx_msg void OnEditSelect();
	afx_msg void OnRightMove();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnEditUndo();
	afx_msg void OnEditRedo();
	afx_msg void OnRightCopy();
	afx_msg void OnRightPates();
	afx_msg void OnRightDel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SankCADView.cpp
inline CSankCADDoc* CSankCADView::GetDocument()
   { return (CSankCADDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SANKCADVIEW_H__A0915CDE_F116_47F5_AA19_7E1E13891CBF__INCLUDED_)
