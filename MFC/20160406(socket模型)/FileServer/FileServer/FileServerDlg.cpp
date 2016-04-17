
// FileServerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FileServer.h"
#include "FileServerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



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
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFileServerDlg 对话框



CFileServerDlg::CFileServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFileServerDlg::IDD, pParent)
    , m_Socket(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFileServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BUTTON_START, &CFileServerDlg::OnBnClickedButtonStart)
END_MESSAGE_MAP()


// CFileServerDlg 消息处理程序

BOOL CFileServerDlg::OnInitDialog()
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

void CFileServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileServerDlg::OnPaint()
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
HCURSOR CFileServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

unsigned int __stdcall WorkThread(void *lpParam)
{
    CFileServerDlg *pDlg = (CFileServerDlg *)lpParam;
    
    int nResult = 0;
    fd_set freadds;
    timeval tv;
    tv.tv_sec = 10;

    while (nResult != SOCKET_ERROR)
    {   
        // 同步socket数组
        freadds.fd_count = pDlg->m_FdClients.fd_count;
        for (size_t i = 0; i < freadds.fd_count; i++)
            freadds.fd_array[i] = pDlg->m_FdClients.fd_array[i];

        nResult = ::select(0, &freadds, NULL, NULL, &tv);
        if (nResult == 0)
        {
            // 继续轮询
            continue;
        }
        for (size_t j = 0; j < freadds.fd_count; j++)
        {
            if (freadds.fd_array[j] == pDlg->m_FdClients.fd_array[0])
            {
                // 处理服务器接收
                pDlg->AcceptConnect(freadds.fd_array[j], &(pDlg->m_FdClients));
            }
            else
            {
                // 处理recv
            }
        }
    }

    return 0;
}

void CFileServerDlg::OnBnClickedButtonStart()
{
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5566);
    addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    m_Socket = ServerStart((sockaddr *)&addr, SOCK_STREAM, true);

    if (m_Socket != INVALID_SOCKET)
    {
        AfxMessageBox(TEXT("ServerStart..."));
        FD_SET(m_Socket, &m_FdClients);
        _beginthreadex(NULL, 0, WorkThread, this, 0, NULL);
    }

}

unsigned int __stdcall WorkThread2(void *lpParam)
{
    fd_set *pFdClients = (fd_set *)lpParam;

    int nResult = 0;
    fd_set freadds;
    timeval tv;
    tv.tv_sec = 10;

    while (nResult != SOCKET_ERROR)
    {   
        // 同步socket数组
        freadds.fd_count = pFdClients->fd_count;
        for (size_t i = 0; i < freadds.fd_count; i++)
            freadds.fd_array[i] = pFdClients->fd_array[i];

        nResult = ::select(0, &freadds, NULL, NULL, &tv);
        if (nResult == 0)
        {
            // 继续轮询
            continue;
        }
        for (size_t j = 0; j < freadds.fd_count; j++)
        {
                // 处理recv
        }
    }

    delete pFdClients;
    return 0;
}

void CFileServerDlg::AcceptConnect(SOCKET socket, fd_set *pFdClients)
{
    sockaddr_in addr;
    int nLen = sizeof(addr);
    SOCKET sClient = ::accept(socket, (sockaddr*)&addr, &nLen);
    if (pFdClients->fd_count < FD_SETSIZE)
    {
        FD_SET(sClient, pFdClients);
        return ;
    }
    else
    {
        fd_set *pClient = new fd_set;
        _beginthreadex(NULL, 0, WorkThread2, pClient, 0, NULL);
    }
}


void CFileServerDlg::RecvData(SOCKET socket, fd_set *pFdClients)
{
    int nResult;
    tagPacket **pBuff = NULL;
    nResult = MyRecv(pBuff, socket);
    if (nResult <= 0)
    {
        //断线
        closesocket(socket);
        FD_CLR(socket, pFdClients);
    }
    else
    {
        //处理信息
    }
}



void CFileServerDlg::ParmeCommand(TCHAR *msg, SOCKET curSocket)
{
    CStrtok strtok;
    strtok.Begin();
    strtok.StrTok(msg, TEXT("\n"));
    strtok.MakePair(TEXT(":"));

    if (!strtok.GetValue(TEXT("cmd")).Compare(TEXT("file")))
        return ;

    CString filename = strtok.GetValue(TEXT("filename"));
    // 得到包份数
    int nCopys = StrToInt(strtok.GetValue(TEXT("filecopys"))); 
    HANDLE hFile = ::CreateFile(filename, GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) 
    { 
        MySend(curSocket, "cmd:false\n");
        return ;
    }


    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(1122);
    addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    SOCKET socket = ServerStart((sockaddr *)&addr, SOCK_STREAM, false);

    tagFpSock *pFp = new tagFpSock;
    pFp->hFile = hFile;
    pFp->socket = socket;
    pFp->nCopys = nCopys;

    
    HANDLE hThread = (HANDLE)::_beginthreadex(NULL, 0, FileThread, pFp, CREATE_SUSPENDED, NULL);
    MySend(curSocket, "cmd:ok\n");
    ResumeThread(hThread);
}

