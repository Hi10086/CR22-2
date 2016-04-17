// UDPServerDlg.h : header file
//

#if !defined(AFX_UDPSERVERDLG_H__A061FB9B_414D_4BED_B0F9_3AAB9959DA53__INCLUDED_)
#define AFX_UDPSERVERDLG_H__A061FB9B_414D_4BED_B0F9_3AAB9959DA53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUDPServerDlg dialog
#define MSG_TALK  WM_USER + 1
#define MSG_START WM_USER + 2
#define MSG_STOP  WM_USER + 3

class CUDPServerDlg : public CDialog
{
// Construction
public:
	BOOL OnStart();
	CUDPServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUDPServerDlg)
	enum { IDD = IDD_UDPSERVER_DIALOG };
	CListBox	m_ListBox;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUDPServerDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
public:
	LRESULT OnServerStop(WPARAM wParam, LPARAM lParam);
	LRESULT OnServerStart(WPARAM wParam, LPARAM lParam);
	LRESULT OnTalk(WPARAM wParam, LPARAM lParam);
  SOCKET m_socket;

	// Generated message map functions
	//{{AFX_MSG(CUDPServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UDPSERVERDLG_H__A061FB9B_414D_4BED_B0F9_3AAB9959DA53__INCLUDED_)
