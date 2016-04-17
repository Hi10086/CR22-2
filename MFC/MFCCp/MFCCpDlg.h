// MFCCpDlg.h : header file
//

#if !defined(AFX_MFCCPDLG_H__EEA029E5_9ACB_4B39_8DEE_F46E24D842FC__INCLUDED_)
#define AFX_MFCCPDLG_H__EEA029E5_9ACB_4B39_8DEE_F46E24D842FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCCpDlg dialog

class CMFCCpDlg : public CDialog
{
// Construction
public:
	CMFCCpDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFCCpDlg)
	enum { IDD = IDD_MFCCP_DIALOG };
	CString	m_szPath;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCCpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCCpDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonChoice();
	afx_msg void OnButtonCopy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCCPDLG_H__EEA029E5_9ACB_4B39_8DEE_F46E24D842FC__INCLUDED_)
