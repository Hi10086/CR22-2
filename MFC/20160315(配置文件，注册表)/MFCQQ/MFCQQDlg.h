// MFCQQDlg.h : header file
//

#if !defined(AFX_MFCQQDLG_H__F7FB37F9_2F7C_4580_9F6D_3AFCE8A1F95E__INCLUDED_)
#define AFX_MFCQQDLG_H__F7FB37F9_2F7C_4580_9F6D_3AFCE8A1F95E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCQQDlg dialog

class CMFCQQDlg : public CDialog
{
// Construction
public:
	CMFCQQDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFCQQDlg)
	enum { IDD = IDD_MFCQQ_DIALOG };
	CString	m_szPassword;
	CString	m_szAccount;
	BOOL	m_bAutoLogin;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCQQDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCQQDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonLogin();
	afx_msg void ReadConfig();
	afx_msg void WriteConfig();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCQQDLG_H__F7FB37F9_2F7C_4580_9F6D_3AFCE8A1F95E__INCLUDED_)
