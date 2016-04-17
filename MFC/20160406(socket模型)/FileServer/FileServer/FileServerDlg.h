
// FileServerDlg.h : ͷ�ļ�
//

#pragma once
#include "MyNet.h"

// CFileServerDlg �Ի���
class CFileServerDlg : public CDialogEx
{
// ����
public:
	CFileServerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_FILESERVER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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

