// Test2Dlg.h : header file
//

#if !defined(AFX_TEST2DLG_H__0A8490FB_FDDD_4191_9336_74E990B326CB__INCLUDED_)
#define AFX_TEST2DLG_H__0A8490FB_FDDD_4191_9336_74E990B326CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTest2Dlg dialog

class CTest2Dlg : public CDialog
{
// Construction
public:
	CTest2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTest2Dlg)
	enum { IDD = IDD_TEST2_DIALOG };
	CEdit	m_Edit1;
	CString	m_strText;
	int		m_nEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest2Dlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTest2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTest();
	afx_msg void OnButton1();
	afx_msg void OnBtnSetText();
	afx_msg void OnButton3();
	afx_msg void OnBtnPast();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST2DLG_H__0A8490FB_FDDD_4191_9336_74E990B326CB__INCLUDED_)
