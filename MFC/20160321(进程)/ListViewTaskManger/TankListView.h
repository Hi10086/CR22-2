#if !defined(AFX_TANKLISTVIEW_H__9251EE06_923F_4C45_9969_656B02CFAB53__INCLUDED_)
#define AFX_TANKLISTVIEW_H__9251EE06_923F_4C45_9969_656B02CFAB53__INCLUDED_

#include <afxcview.h>
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TankListView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTankListView view

class CTaskListView : public CListView
{
protected:
	CTaskListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTaskListView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTankListView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTaskListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CTankListView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TANKLISTVIEW_H__9251EE06_923F_4C45_9969_656B02CFAB53__INCLUDED_)
