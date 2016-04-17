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
enum OPER {SHAPE_MOVE, SHAPE_EDIT, SHAPE_CREAT, UNKNOWN};

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
	afx_msg void OnSetting();
	afx_msg void OnSelect();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnEdit();
	afx_msg void OnMenuDelite();
	afx_msg void OnMenuMove();
	afx_msg void OnMenuCopy();
	afx_msg void OnMenuPaste();
	afx_msg void OnMenuUndo();
	afx_msg void OnEditUndo();
	afx_msg void OnEditRedo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CMyPen m_pen;
	IShape* m_pCurShape;
	IShape* m_pSelectShape;
	IMyClassFactory *m_pClassFactory;
	BOOL    m_isDown;
	BOOL    m_isMoving;
	BOOL	m_isEdit;
	CList<IShape*, IShape*> m_Shapes;
	CList<OPER, OPER> m_OperLink;
	CList<IShape*, IShape*> m_Undo;
	CList<IShape*, IShape*> m_Redo;
    //CList<IShape*, IShape*> m_Shapes;
	BOOL m_isSelect;
};

#ifndef _DEBUG  // debug version in CADView.cpp
inline CCADDoc* CCADView::GetDocument()
   { return (CCADDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CADVIEW_H__B51D4106_05DD_443B_ADEB_7181DCE05372__INCLUDED_)
