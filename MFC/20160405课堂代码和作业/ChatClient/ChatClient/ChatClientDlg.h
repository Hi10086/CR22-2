
// ChatClientDlg.h : ͷ�ļ�
//

#pragma once
#include "UDPSocket.h"
#include "afxwin.h"

#define MSG_TALK  WM_USER + 1
#define MSG_START WM_USER + 2
#define MSG_STOP  WM_USER + 3
// CChatClientDlg �Ի���
class CChatClientDlg : public CDialogEx
{
// ����
public:
	CChatClientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CHATCLIENT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    LRESULT OnTalk(WPARAM wParam, LPARAM lParam);
    LRESULT OnServerStart(WPARAM wParam, LPARAM lParam);
    LRESULT OnServerStop(WPARAM wParam, LPARAM lParam);
    BOOL ServerStart();
    int m_socket;
    CListBox m_ListBox;
    afx_msg void OnBnClickedBtnConnect();
};
