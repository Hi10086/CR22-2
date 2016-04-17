// ListViewTaskMangerDoc.h : interface of the CListViewTaskMangerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LISTVIEWTASKMANGERDOC_H__D87AA5A3_96E4_494F_87DC_9654A50DCC80__INCLUDED_)
#define AFX_LISTVIEWTASKMANGERDOC_H__D87AA5A3_96E4_494F_87DC_9654A50DCC80__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "TaskMap.h"
#include "TaskInfo.h"

class CListViewTaskMangerDoc : public CDocument
{
protected: // create from serialization only
	CListViewTaskMangerDoc();
	DECLARE_DYNCREATE(CListViewTaskMangerDoc)
// Attributes
public:
	CTaskMap<DWORD, CTaskInfo*> m_TaskMap;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListViewTaskMangerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListViewTaskMangerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CListViewTaskMangerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTVIEWTASKMANGERDOC_H__D87AA5A3_96E4_494F_87DC_9654A50DCC80__INCLUDED_)
