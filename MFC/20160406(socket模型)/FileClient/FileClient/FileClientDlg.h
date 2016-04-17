
// FileClientDlg.h : 头文件
//

#pragma once
#include "BigInt.h"
#include "../../FileServer/FileServer/MyNet.h"

// CFileClientDlg 对话框
class CFileClientDlg : public CDialogEx
{
// 构造
public:
	CFileClientDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_FILECLIENT_DIALOG };

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
    afx_msg void OnBnClickedBtnSelect();
    CString m_pathName;
    CString m_strFilename;
    SOCKET m_socket;
    afx_msg void OnBnClickedBtnSend();
    void ParmeCommand(char *msg, SOCKET curSocket);
    void SendFile();
};
