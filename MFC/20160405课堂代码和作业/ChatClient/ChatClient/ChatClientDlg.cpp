
// ChatClientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChatClientDlg �Ի���
extern CUDPSocket g_Sock;

CChatClientDlg::CChatClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChatClientDlg::IDD, pParent)
    , m_socket(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatClientDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST_SHOW, m_ListBox);
}

BEGIN_MESSAGE_MAP(CChatClientDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BTN_CONNECT, &CChatClientDlg::OnBnClickedBtnConnect)
    ON_MESSAGE(MSG_TALK, OnTalk)
    ON_MESSAGE(MSG_START, OnServerStart)
    ON_MESSAGE(MSG_STOP, OnServerStop)
END_MESSAGE_MAP()


// CChatClientDlg ��Ϣ�������

BOOL CChatClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CChatClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CChatClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

UINT WorkThread(LPVOID lpParam)
{
    CChatClientDlg* lpDlg =  (CChatClientDlg*)lpParam;
    SOCKET socket = lpDlg->m_socket;
    char szBuff[MAXBYTE];
    char *pBuf = NULL;
    sockaddr_in addr;
    int nLen = sizeof(addr);


    lpDlg->PostMessage(MSG_START, (WPARAM)new CString(szBuff), NULL);


    while(true)
    {
        int nResult = g_Sock.RecvData(socket, pBuf, 0, 
            (sockaddr*)&addr, &nLen);
        if (nResult <= 0)
            break;

        lpDlg->PostMessage(MSG_TALK, (WPARAM)new CString(pBuf), NULL);
        delete[] pBuf;
    }


    closesocket(socket);
    lpDlg->PostMessage(MSG_STOP, (WPARAM)new CString(szBuff), NULL);
    return 0;
}

BOOL CChatClientDlg::ServerStart()
{
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.S_un.S_addr = 0; //�����ַ��ͨѶ
    addr.sin_port = htons(1122); //0ϵͳ����һ��δռ�õĶ˿�

    m_socket = g_Sock.UdpSocket(*(sockaddr*)&addr);
    if (m_socket == INVALID_SOCKET)
        return FALSE;

    AfxBeginThread(WorkThread, (LPVOID)this);
    return TRUE;
}

LRESULT CChatClientDlg::OnTalk(WPARAM wParam, LPARAM lParam)
{
    CString *lpData = (CString*)wParam;
    m_ListBox.AddString(*lpData);
    delete lpData;
    return TRUE;
}

LRESULT CChatClientDlg::OnServerStart(WPARAM wParam, LPARAM lParam)
{
    m_ListBox.AddString(TEXT("Server start..."));
    return TRUE;
}

LRESULT CChatClientDlg::OnServerStop(WPARAM wParam, LPARAM lParam)
{
    m_ListBox.AddString(TEXT("Server stop..."));
    return TRUE;
}

void CChatClientDlg::OnBnClickedBtnConnect()
{
    if (!ServerStart())
    {
        m_ListBox.AddString(TEXT("�׽��ִ���ʧ��"));
        return ;
    }

    CString str;
    str.Format(TEXT("�׽��ִ����ɹ�, ���ڼ���%d�˿�"), m_socket);
    m_ListBox.AddString(str);
}
