
// ChatServerDlg.h : 头文件
//

#pragma once
#include "UDPSocket.h"
#include "afxwin.h"
#define MSG_TALK  WM_USER + 1
#define MSG_START WM_USER + 2
#define MSG_STOP  WM_USER + 3


// CChatServerDlg 对话框
class CChatServerDlg : public CDialogEx
{
// 构造
public:
	CChatServerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SERVER_DLG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedBtnStart();
    LRESULT OnTalk(WPARAM wParam, LPARAM lParam);
    LRESULT OnServerStart(WPARAM wParam, LPARAM lParam);
    LRESULT OnServerStop(WPARAM wParam, LPARAM lParam);
    BOOL ServerStart();
    int m_socket;
    CListBox m_ListBox;
};
