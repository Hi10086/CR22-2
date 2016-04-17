// WM_COPYDATADlg.h : header file
//

#if !defined(AFX_WM_COPYDATADLG_H__401650C2_505B_499A_B27C_67D60F51306E__INCLUDED_)
#define AFX_WM_COPYDATADLG_H__401650C2_505B_499A_B27C_67D60F51306E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CWM_COPYDATADlg dialog

class CWM_COPYDATADlg : public CDialog
{
// Construction
public:
	CWM_COPYDATADlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CWM_COPYDATADlg)
	enum { IDD = IDD_WM_COPYDATA_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWM_COPYDATADlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWM_COPYDATADlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WM_COPYDATADLG_H__401650C2_505B_499A_B27C_67D60F51306E__INCLUDED_)
