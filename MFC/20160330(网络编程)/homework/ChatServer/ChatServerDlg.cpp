// ChatServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChatServer.h"
#include "ChatServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatServerDlg dialog

CChatServerDlg::CChatServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChatServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChatServerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatServerDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChatServerDlg, CDialog)
	//{{AFX_MSG_MAP(CChatServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_BEGIN, OnButtonBegin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatServerDlg message handlers

BOOL CChatServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
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
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CChatServerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CChatServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void ShowErrorMsg()
{
	LPVOID lpMsgBuf;
	::FormatMessage( 
		FORMAT_MESSAGE_ALLOCATE_BUFFER | 
		FORMAT_MESSAGE_FROM_SYSTEM | 
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		::WSAGetLastError(),
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
		(LPTSTR) &lpMsgBuf,
		0,
		NULL 
		);
	// Process any inserts in lpMsgBuf.
	// ...
	// Display the string.
	::MessageBox( NULL, (LPCTSTR)lpMsgBuf, "Error", MB_OK | MB_ICONINFORMATION );
	// Free the buffer.
	::LocalFree( lpMsgBuf );
}

UINT CChatServerDlg::recvThread(LPVOID pParam)
{
	tagClient client;
	int sock = (int)pParam;
	char szBuff[MAXBYTE] = {0};

	do 
	{
		if (SOCKET_ERROR == recv(sock, szBuff, sizeof(szBuff), 0))
		{
			ShowErrorMsg();
			AfxMessageBox("recv");
			return 1;
		}else
		{
			CString str;
			str.Format("%d 说: %s", client.m_sSock, szBuff);
			POSITION pos = m_ListClient.GetHeadPosition();
			while (pos != NULL)
			{
				client = m_ListClient.GetNext(pos);
				send(client.m_sSock, str.GetBuffer(0), strlen(str)+1, 0);
			}
// 			for (int i = 0; i < m_ListClient.GetCount(); i++)
// 			{
// 				POSITION pos = m_ListClient.GetHeadPosition();
// 				client = m_ListClient.GetAt(pos);
// 				send(client.m_sSock, str.GetBuffer(0), strlen(str)+1, 0);
// 				pos++;
// 			}

		}
	} while (TRUE);
}

UINT CreateRec(LPVOID pParam)
{
	CChatServerDlg *pDlg = (CChatServerDlg *)pParam;
	CList<tagClient, tagClient>& ListClient = pDlg->m_ListClient;
	tagClient client;

	POSITION pos = ListClient.GetHeadPosition();
	while (TRUE)
	{
		client = ListClient.GetAt(pos);
		if (client.m_state == ASK_REC)
		{
			// 创建接收线程
			AfxBeginThread(pDlg->recvThread, (LPVOID)client.m_sSock);
			client.m_state = RECING;
			ListClient.RemoveAt(pos);
			ListClient.AddHead(client);
		}
		++pos;
	}

	return 0;
}

UINT AcceptClient(LPVOID pParam)
{
	CChatServerDlg *pDlg = (CChatServerDlg *)pParam;
	static CList<tagClient, tagClient>& ListClient = pDlg->m_ListClient;

	tagClient newClient;
	tagClient client;
	sockaddr caddr;
	int nLen = sizeof(caddr);

	do 
	{
		int sClient = accept(pDlg->m_SSocket, &caddr, &nLen);
		if (INVALID_SOCKET == sClient)
		{
			ShowErrorMsg();
		}

		BOOL isNew = TRUE;

		newClient.m_sAddr = caddr;
		newClient.m_sSock = sClient;
		newClient.m_state = ASK_REC;
		

// 		if (!ListClient.Find(newClient))
// 		{
// 			ListClient.AddTail(newClient);
// 		}

		// !ListClient.Find(newClient)编译不过, 只能手工遍历了
		POSITION pos = ListClient.GetHeadPosition();
		while (pos != NULL)
		{
			client = ListClient.GetNext(pos);
			if (client == newClient)
			{
				isNew = FALSE;
			}
		}

		if (isNew)
		{
			ListClient.AddTail(newClient);
			AfxBeginThread(pDlg->recvThread, (LPVOID)sClient);
		}
	} while (TRUE);

	return 0;
}

void CChatServerDlg::OnButtonBegin() 
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup( wVersionRequested, &wsaData );
	if ( err != 0 ) {          
		return;
	}

	/*
	1、创建套接字（socket）。	
	2、将套接字绑定到一个本地地址和端口上（bind）。
	3、将套接字设为监听模式，准备接收客户请求（listen）。
	4、等待客户请求到来；当请求到来后，接受连接请求，返回一个新的对应于此次连接的套接字（accept）。
	5、用返回的套接字和客户端进行通信（send/recv）。
	6、返回，等待另一客户请求。
	7、关闭套接字。
	*/

	m_SSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_SSocket == -1)
	{
		ShowErrorMsg();
		return;
	}

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");


	if (bind(m_SSocket, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		ShowErrorMsg();
		return;
	}

	if (SOCKET_ERROR == listen(m_SSocket, SOMAXCONN))
	{
		ShowErrorMsg();
		return;
	}
	
	// ACCEPT线程, 往客户端链表增加新的客户端信息
	AfxBeginThread(AcceptClient, this);

	// 遍历客户端链表，处理客户端状态（创建各客户端线程）
	//AfxBeginThread(CreateRec, this);

	AfxMessageBox("服务成果启动");
}

CList<tagClient, tagClient> CChatServerDlg::m_ListClient;