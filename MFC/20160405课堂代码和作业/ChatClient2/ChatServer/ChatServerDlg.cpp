
// ChatServerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ChatServer.h"
#include "ChatServerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CUDPSocket g_Sock;
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
    ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CChatServerDlg �Ի���



CChatServerDlg::CChatServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChatServerDlg::IDD, pParent)
    , m_socket(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatServerDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST1, m_ListBox);
}

BEGIN_MESSAGE_MAP(CChatServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BTN_START, &CChatServerDlg::OnBnClickedBtnStart)
    ON_MESSAGE(MSG_TALK, OnTalk)
    ON_MESSAGE(MSG_START, OnServerStart)
    ON_MESSAGE(MSG_STOP, OnServerStop)
    ON_BN_CLICKED(IDC_BUTTON1, &CChatServerDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CChatServerDlg ��Ϣ�������

BOOL CChatServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CChatServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CChatServerDlg::OnPaint()
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
HCURSOR CChatServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAboutDlg::OnBnClickedOk()
{
    // TODO: �ڴ���ӿؼ�֪ͨ����������
    CDialogEx::OnOK();
}


void CChatServerDlg::OnBnClickedBtnStart()
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

UINT WorkThread(LPVOID lpParam)
{
    CChatServerDlg* lpDlg =  (CChatServerDlg*)lpParam;
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

BOOL CChatServerDlg::ServerStart()
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

LRESULT CChatServerDlg::OnTalk(WPARAM wParam, LPARAM lParam)
{
    CString *lpData = (CString*)wParam;
    m_ListBox.AddString(*lpData);
    delete lpData;
    return TRUE;
}

LRESULT CChatServerDlg::OnServerStart(WPARAM wParam, LPARAM lParam)
{
    m_ListBox.AddString(TEXT("Server start..."));
    return TRUE;
}

LRESULT CChatServerDlg::OnServerStop(WPARAM wParam, LPARAM lParam)
{
    m_ListBox.AddString(TEXT("Server stop..."));
    return TRUE;
}

void CChatServerDlg::OnBnClickedButton1()
{
    CString str;
    GetDlgItemText(IDC_EDIT_TEXT, str);

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(5566); 

    if (!str.IsEmpty())
    {
        g_Sock.SendData("HahaHahaHahaHahaHahaHaha", m_socket, (sockaddr*)&addr);
    }
}


