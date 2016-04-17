// TestDlg.h : header file
//

#if !defined(AFX_TESTDLG_H__E6458B49_FEC8_4F8B_9F04_3E029829C364__INCLUDED_)
#define AFX_TESTDLG_H__E6458B49_FEC8_4F8B_9F04_3E029829C364__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog
#include "MyEdit.h"

class CTestDlg : public CDialog
{
// Construction
public:
	CTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestDlg)
	enum { IDD = IDD_TEST_DIALOG };
	CMyEdit	m_MyEdit1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnButton1();
	afx_msg void OnBtnPath();
	afx_msg void OnBtnRead();
	afx_msg void OnBtnWrite();
	afx_msg void OnBtnSava();
	afx_msg void OnButton5();
	afx_msg void OnOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLG_H__E6458B49_FEC8_4F8B_9F04_3E029829C364__INCLUDED_)
