
// FileServerDlg.h : 头文件
//

#pragma once
#include "MyNet.h"

// CFileServerDlg 对话框
class CFileServerDlg : public CDialogEx
{
// 构造
public:
	CFileServerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_FILESERVER_DIALOG };

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
    afx_msg void OnBnClickedButtonStart();
    void AcceptConnect(SOCKET socket, fd_set* pFdClients);
    void RecvData(SOCKET socket, fd_set *pFdClients);
    void ParmeCommand(TCHAR *msg, SOCKET curSocket);
    fd_set m_FdClients;
    int m_Socket;
};

