// MFCThreadDlg.h : header file
//

#if !defined(AFX_MFCTHREADDLG_H__98D8F4E0_6563_40AA_B2AC_DC0695E7BB30__INCLUDED_)
#define AFX_MFCTHREADDLG_H__98D8F4E0_6563_40AA_B2AC_DC0695E7BB30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCThreadDlg dialog

class CMFCThreadDlg : public CDialog
{
// Construction
public:
	CMFCThreadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMFCThreadDlg)
	enum { IDD = IDD_MFCTHREAD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCThreadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMFCThreadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCTHREADDLG_H__98D8F4E0_6563_40AA_B2AC_DC0695E7BB30__INCLUDED_)
