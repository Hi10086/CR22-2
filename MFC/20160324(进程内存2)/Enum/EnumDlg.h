// EnumDlg.h : header file
//

#if !defined(AFX_ENUMDLG_H__F71D6DF9_BD23_4376_8EA1_1FF96F1EF853__INCLUDED_)
#define AFX_ENUMDLG_H__F71D6DF9_BD23_4376_8EA1_1FF96F1EF853__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEnumDlg dialog
#include "MyStatic.h"
#include "MemoryDlg.h"

class CEnumDlg : public CDialog
{
// Construction
public:
	void EnumProcess();
	void InitCtrl();
	CEnumDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEnumDlg)
	enum { IDD = IDD_ENUM_DIALOG };
	CMyStatic	m_MyStatic;
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnumDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
    BOOL m_IsStop;
protected:
	HICON m_hIcon;
  CImageList m_ImageList;
	// Generated message map functions
	//{{AFX_MSG(CEnumDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnumProcess();
	afx_msg void OnWindow();
	afx_msg void OnMyStatic();
	afx_msg void OnMemory();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENUMDLG_H__F71D6DF9_BD23_4376_8EA1_1FF96F1EF853__INCLUDED_)
