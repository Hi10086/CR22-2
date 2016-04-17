// TestDlg.h : header file
//

#if !defined(AFX_TESTDLG_H__F23B78B2_4D27_4205_A0E3_F16D2CF7BAD8__INCLUDED_)
#define AFX_TESTDLG_H__F23B78B2_4D27_4205_A0E3_F16D2CF7BAD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestDlg dialog

class CTestDlg : public CDialog
{
// Construction
public:
	CTestDlg(CWnd* pParent = NULL);	// standard constructor
  afx_msg LRESULT MyMessage(WPARAM, LPARAM);
// Dialog Data
	//{{AFX_DATA(CTestDlg)
	enum { IDD = IDD_TEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
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
	afx_msg void OnBtnStart();
	afx_msg void OnBtnStop();
	afx_msg void OnBtnSus();
	afx_msg void OnBtnRes();
	afx_msg void OnBtnSus2();
	afx_msg void OnBtnRes2();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
    int   m_nNum;
    HANDLE m_hThread;
    BOOL  m_isStop;
    HANDLE m_hEvent;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLG_H__F23B78B2_4D27_4205_A0E3_F16D2CF7BAD8__INCLUDED_)
