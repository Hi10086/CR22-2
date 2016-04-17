// CTL2Dlg.h : header file
//

#if !defined(AFX_CTL2DLG_H__9C29E2BD_5FE4_4215_B3A0_A43FE29C96F3__INCLUDED_)
#define AFX_CTL2DLG_H__9C29E2BD_5FE4_4215_B3A0_A43FE29C96F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCTL2Dlg dialog
#include "MyButton.h"

class CCTL2Dlg : public CDialog
{
// Construction
public:
	CCTL2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCTL2Dlg)
	enum { IDD = IDD_CTL2_DIALOG };
	CMyButton	m_MyButton;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCTL2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCTL2Dlg)
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

#endif // !defined(AFX_CTL2DLG_H__9C29E2BD_5FE4_4215_B3A0_A43FE29C96F3__INCLUDED_)
