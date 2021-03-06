#if !defined(AFX_MYTREE_H__95472E87_F9D2_45B5_9060_CFFA415E7405__INCLUDED_)
#define AFX_MYTREE_H__95472E87_F9D2_45B5_9060_CFFA415E7405__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyTree.h : header file
//
#include <afxcview.h>
#include <afxtempl.h>
#include "MFCRegDoc.h"
/////////////////////////////////////////////////////////////////////////////
// CMyTree view

class CMyTree : public CTreeView
{
protected:
	CMyTree();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMyTree)
	void QueryKey(HTREEITEM hRoot, HKEY hRootKey, const CString path);
	void LayerQuery(HTREEITEM hRoot, HKEY hRootKey, CString szPath);
	void LayerSearch(HTREEITEM hItem);
	void QueryRegKey(HTREEITEM hRootItem, HKEY hRootKey, CString szPath);
	void DeleteChildItem(HTREEITEM hRootItem);
	void InitReg();
	CString GetRegPath(HTREEITEM hItem);
	HKEY GetPath(HTREEITEM hItem, CString& szPath);
// Attributes
public:
	CMFCRegDoc* GetDocument();
// Operations
public:
	CList<HTREEITEM, HTREEITEM> m_ListItem;
	CTreeCtrl& m_tree;
	HKEY m_hKey;
	HKEY m_hChildKey;
	CString m_szPath;
	HTREEITEM m_hItem;
	DWORD m_dwValues;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyTree)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMyTree();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyTree)
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTREE_H__95472E87_F9D2_45B5_9060_CFFA415E7405__INCLUDED_)
