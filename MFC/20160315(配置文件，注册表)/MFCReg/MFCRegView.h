// MFCRegView.h : interface of the CMFCRegView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCREGVIEW_H__2D68A045_C581_43E8_BA0A_3F02EC9044C9__INCLUDED_)
#define AFX_MFCREGVIEW_H__2D68A045_C581_43E8_BA0A_3F02EC9044C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCRegView : public CView
{
protected: // create from serialization only
	CMFCRegView();
	DECLARE_DYNCREATE(CMFCRegView)

// Attributes
public:
	CMFCRegDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCRegView)
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
	virtual ~CMFCRegView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCRegView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MFCRegView.cpp
inline CMFCRegDoc* CMFCRegView::GetDocument()
   { return (CMFCRegDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCREGVIEW_H__2D68A045_C581_43E8_BA0A_3F02EC9044C9__INCLUDED_)
