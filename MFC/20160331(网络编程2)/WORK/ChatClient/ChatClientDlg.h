// ChatClientDlg.h : header file
//

#if !defined(AFX_CHATCLIENTDLG_H__A06F3210_B1B1_49B8_9301_0921D274AADD__INCLUDED_)
#define AFX_CHATCLIENTDLG_H__A06F3210_B1B1_49B8_9301_0921D274AADD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>
/////////////////////////////////////////////////////////////////////////////
// CChatClientDlg dialog

class CChatClientDlg : public CDialog
{
// Construction
public:
	int m_sock;
	void FmtMessage(const CString& msg);
	CChatClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChatClientDlg)
	enum { IDD = IDD_CHATCLIENT_DIALOG };
	CListBox	m_ListMember;
	CListBox	m_ListBox;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChatClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonConnect();
	afx_msg void OnButtonSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATCLIENTDLG_H__A06F3210_B1B1_49B8_9301_0921D274AADD__INCLUDED_)
