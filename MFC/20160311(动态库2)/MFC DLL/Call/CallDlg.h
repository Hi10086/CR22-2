// CallDlg.h : header file
//

#if !defined(AFX_CALLDLG_H__299E0464_92DF_4E1D_B414_A507D6DBE65B__INCLUDED_)
#define AFX_CALLDLG_H__299E0464_92DF_4E1D_B414_A507D6DBE65B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../ExtendDll/MyButton.h"
#pragma comment(lib, "../ExtendDll/debug/ExtendDll.lib")
/////////////////////////////////////////////////////////////////////////////
// CCallDlg dialog

class CCallDlg : public CDialog
{
// Construction
public:
	CCallDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCallDlg)
	enum { IDD = IDD_CALL_DIALOG };
	CMyButton	m_MyButton;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCallDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCallDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnStatic();
	afx_msg void OnBtnShared();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALLDLG_H__299E0464_92DF_4E1D_B414_A507D6DBE65B__INCLUDED_)
