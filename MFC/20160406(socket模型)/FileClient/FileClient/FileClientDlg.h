
// FileClientDlg.h : ͷ�ļ�
//

#pragma once
#include "BigInt.h"
#include "../../FileServer/FileServer/MyNet.h"

// CFileClientDlg �Ի���
class CFileClientDlg : public CDialogEx
{
// ����
public:
	CFileClientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_FILECLIENT_DIALOG };

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
    afx_msg void OnBnClickedBtnSelect();
    CString m_pathName;
    CString m_strFilename;
    SOCKET m_socket;
    afx_msg void OnBnClickedBtnSend();
    void ParmeCommand(char *msg, SOCKET curSocket);
    void SendFile();
};
