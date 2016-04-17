
// ChatClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChatClientDlg 对话框
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


// CChatClientDlg 消息处理程序

BOOL CChatClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CChatClientDlg::OnPaint()
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
    addr.sin_addr.S_un.S_addr = 0; //任意地址可通讯
    addr.sin_port = htons(1122); //0系统分配一个未占用的端口

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
        m_ListBox.AddString(TEXT("套接字创建失败"));
        return ;
    }

    CString str;
    str.Format(TEXT("套接字创建成功, 正在监听%d端口"), m_socket);
    m_ListBox.AddString(str);
}
