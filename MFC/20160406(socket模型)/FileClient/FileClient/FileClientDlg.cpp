
// FileClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FileClient.h"
#include "FileClientDlg.h"
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


// CFileClientDlg 对话框



CFileClientDlg::CFileClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFileClientDlg::IDD, pParent)
    , m_strFilename(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFileClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BTN_SELECT, &CFileClientDlg::OnBnClickedBtnSelect)
    ON_BN_CLICKED(IDC_BTN_Send, &CFileClientDlg::OnBnClickedBtnSend)
END_MESSAGE_MAP()


// CFileClientDlg 消息处理程序

BOOL CFileClientDlg::OnInitDialog()
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

void CFileClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileClientDlg::OnPaint()
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
HCURSOR CFileClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFileClientDlg::OnBnClickedBtnSelect()
{
    CFileDialog dlg(TRUE, NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT);
    if (dlg.DoModal() == IDOK)
    {
        SetDlgItemText(IDC_EDIT1, dlg.GetPathName());
        m_strFilename = dlg.GetFileName();
    }
}

UINT WorkThread(LPVOID lpwarem)
{
    int nResult;
    DWORD nByteReaded = 0;
    tagFpSock *pFp = (tagFpSock *)lpwarem;
    int sendSize;
    int nLen = sizeof(sendSize);
    ::getsockopt(pFp->socket, SO_SNDBUF, NULL, (char*)&sendSize, &nLen);
    char *pBuf = new char[sendSize];

    for (int i = 0; i < pFp->nCopys; i++)
    {
        ::ReadFile(pFp->hFile, pBuf, sendSize, &nByteReaded, NULL);
        nResult = ::send(pFp->socket, pBuf, nByteReaded, 0);
        if (nResult == SOCKET_ERROR)
        {
            AfxMessageBox(TEXT("错误"));
            break;
        }
    }

    delete[] pBuf;
    delete pFp;
}

void CFileClientDlg::OnBnClickedBtnSend()
{
    int nResult;
    m_socket = ClientStart(SOCK_STREAM);
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5566);
    addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    if (m_socket != SOCKET_ERROR)
    {
        nResult = ::connect(m_socket, (sockaddr*)&addr, sizeof(addr));
        if (nResult == -1)
        {
            return ;
        }

        SendFile();
    }
}

void CFileClientDlg::SendFile()
{
    int nResult;
    int nCopys = 0;
    tagPacket **ppPacket = NULL;
    DWORD dwLowSize;
    DWORD dwHighSize;

    HANDLE hFile = ::CreateFile(m_pathName,
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (hFile != INVALID_HANDLE_VALUE)
    {   
        dwLowSize = ::GetFileSize(hFile, &dwHighSize);

        nCopys = dwLowSize / 0x2000;
        //CBigInt big;
        
        char buf[MAXBYTE];
        CString str;
        str.Format(TEXT("cmd:file\nfilename:%s\filecopys:%d"), m_strFilename, nCopys);
        MySend(m_socket, (char*)str.GetBuffer(0));

        nResult = MyRecv(ppPacket, m_socket);
        if (nResult > 0)
        {
            ParmeCommand((*ppPacket)->m_data, m_socket);
        }
    }
 
}

void CFileClientDlg::ParmeCommand(char *msg, SOCKET curSocket)
{

}