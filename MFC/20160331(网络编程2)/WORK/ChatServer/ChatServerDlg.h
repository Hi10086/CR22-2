// ChatServerDlg.h : header file
//

#if !defined(AFX_CHATSERVERDLG_H__363F0F0F_B4EC_4C2B_AFFA_607EF5F44511__INCLUDED_)
#define AFX_CHATSERVERDLG_H__363F0F0F_B4EC_4C2B_AFFA_607EF5F44511__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <LIST>

/////////////////////////////////////////////////////////////////////////////
// CChatServerDlg dialog
#define ASK_REC 1
#define RECING	2
#define ASK_END 3

struct tagClient
{
	tagClient()
	{
		m_sSock = 0;
		m_state = 0;
	}
	bool operator==(const tagClient& client) const
	{
		return m_sSock == client.m_sSock;
	}

	bool operator!=(const tagClient& client) const
	{
		return m_sSock != client.m_sSock;
	}

	bool operator<(const tagClient& client) const
	{
		return m_sSock < client.m_sSock;
	}

	char m_szUserName[MAXBYTE];
	int m_sSock;
	int m_state;
};

class CChatServerDlg : public CDialog
{
public:
	static UINT recvThread(LPVOID pParam);
	int m_SSocket;
	BOOL m_bIsStop;
// Construction
public:
	CChatServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChatServerDlg)
	enum { IDD = IDD_CHATSERVER_DIALOG };
	CListBox	m_ListBox;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChatServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonBegin();
	afx_msg void OnButtonStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATSERVERDLG_H__363F0F0F_B4EC_4C2B_AFFA_607EF5F44511__INCLUDED_)
