// uiView.h : interface of the CUiView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_UIVIEW_H__7BAB0426_57DB_4152_B6A1_DE137DF40C3D__INCLUDED_)
#define AFX_UIVIEW_H__7BAB0426_57DB_4152_B6A1_DE137DF40C3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUiView : public CView
{
protected: // create from serialization only
	CUiView();
	DECLARE_DYNCREATE(CUiView)

// Attributes
public:
	CUiDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUiView)
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
	virtual ~CUiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUiView)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in uiView.cpp
inline CUiDoc* CUiView::GetDocument()
   { return (CUiDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UIVIEW_H__7BAB0426_57DB_4152_B6A1_DE137DF40C3D__INCLUDED_)
