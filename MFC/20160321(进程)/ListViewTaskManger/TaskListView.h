#if !defined(AFX_TASKLISTVIEW_H__0DE94011_4545_430F_A31B_AB81C857CB73__INCLUDED_)
#define AFX_TASKLISTVIEW_H__0DE94011_4545_430F_A31B_AB81C857CB73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TaskListView.h : header file
//

#include <afxcview.h>
#include <Tlhelp32.h.>
#include "TaskInfo.h"
#include "TaskMap.h"
#include "ListViewTaskMangerDoc.h"
#include <utility>
/////////////////////////////////////////////////////////////////////////////
// CTaskListView view

class CTaskListView : public CListView
{
protected:
	CTaskListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTaskListView)
// Attributes
public:
	CTaskMap<DWORD, CTaskInfo*>* m_pTaskMap;
	CListCtrl& m_tree;
	int m_CurrentItem;
// Operations
public:
	void ShowTask();
	CListViewTaskMangerDoc* GetDocument();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTaskListView)
	public:
	virtual void OnInitialUpdate();
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
	//{{AFX_MSG(CTaskListView)
	afx_msg void OnItemclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuitemClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKLISTVIEW_H__0DE94011_4545_430F_A31B_AB81C857CB73__INCLUDED_)
