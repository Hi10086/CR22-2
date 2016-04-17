
// ChatServerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ChatServer.h"
#include "ChatServerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CUDPSocket g_Sock;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CChatServerDlg 对话框



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


// CChatServerDlg 消息处理程序

BOOL CChatServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CChatServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CChatServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAboutDlg::OnBnClickedOk()
{
    // TODO: 在此添加控件通知处理程序代码
    CDialogEx::OnOK();
}


void CChatServerDlg::OnBnClickedBtnStart()
{
    if (!ServerStart())
    {
        m_ListBox.AddString(TEXT("套接字创建失败"));
        return ;
    }
        
    CString str;
    str.Format(TEXT("套接字创建成功, 正在监听%d端口"), m_socket);
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
    addr.sin_addr.S_un.S_addr = 0; //任意地址可通讯
    addr.sin_port = htons(1122); //0系统分配一个未占用的端口

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


