
// ChatServerDlg.h : ͷ�ļ�
//

#pragma once
#include "UDPSocket.h"
#include "afxwin.h"
#define MSG_TALK  WM_USER + 1
#define MSG_START WM_USER + 2
#define MSG_STOP  WM_USER + 3


// CChatServerDlg �Ի���
class CChatServerDlg : public CDialogEx
{
// ����
public:
	CChatServerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SERVER_DLG };

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
    afx_msg void OnBnClickedBtnStart();
    LRESULT OnTalk(WPARAM wParam, LPARAM lParam);
    LRESULT OnServerStart(WPARAM wParam, LPARAM lParam);
    LRESULT OnServerStop(WPARAM wParam, LPARAM lParam);
    BOOL ServerStart();
    int m_socket;
    CListBox m_ListBox;
};
