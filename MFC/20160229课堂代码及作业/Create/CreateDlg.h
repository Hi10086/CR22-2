// CreateDlg.h : header file
//

#if !defined(AFX_CREATEDLG_H__6FD2A0B4_E28C_4649_9896_5CA4D934E4EA__INCLUDED_)
#define AFX_CREATEDLG_H__6FD2A0B4_E28C_4649_9896_5CA4D934E4EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCreateDlg dialog

class CCreateDlg : public CDialog
{
// Construction
public:
	CCreateDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCreateDlg)
	enum { IDD = IDD_CREATE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCreateDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
  afx_msg void OnCmdMsg(UINT nID);
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEDLG_H__6FD2A0B4_E28C_4649_9896_5CA4D934E4EA__INCLUDED_)
