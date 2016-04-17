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

using namespace std;
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
std::list<tagClient> m_ListClient;
CListBox *g_pLogBox;

CChatServerDlg::CChatServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChatServerDlg::IDD, pParent)
{
	m_bIsStop = TRUE;
	//{{AFX_DATA_INIT(CChatServerDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatServerDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChatServerDlg, CDialog)
	//{{AFX_MSG_MAP(CChatServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_BEGIN, OnButtonBegin)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
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
	g_pLogBox = &m_ListBox;
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

void SendAllClients(TagMsg *pMsg)
{
	tagClient client;

	for (list<tagClient>::iterator it = m_ListClient.begin(); it != m_ListClient.end(); ++it)
	{
		client = *it;
		send(client.m_sSock, (char *)pMsg, pMsg->m_nSize, 0);
	}
}

bool SendSingle(int nDest, int nSrc, const char *szMsg)
{
	CString strDest, strSrc, strSYS;
	strDest.Format("%d 对 您悄悄说: %s", nSrc, szMsg);
	strSrc.Format("您 对 %d悄悄说: %s", nDest, szMsg);
	strSYS.Format("%d 对 %d悄悄说: %s", nSrc, nDest, szMsg);
	int nSize = 0;
	TagMsg *pMsg = NULL;

	for (list<tagClient>::iterator it = m_ListClient.begin(); it != m_ListClient.end(); ++it)
	{
		if (nDest == (*it).m_sSock)
		{
			nSize = sizeof(TagMsg) + strDest.GetLength();
			pMsg = (TagMsg *)new char[nSize];
			memset(pMsg, 0, nSize);
			pMsg->m_nSize = nSize;
			pMsg->m_nFrom = nSrc;
			pMsg->m_nDest = nDest;
			pMsg->m_nOper = MSG_CHAT;
			memcpy(pMsg->data, strDest.GetBuffer(0), strDest.GetLength());
			send(nDest, (char *)pMsg, nSize, 0);

			g_pLogBox->AddString(strSYS);			
			delete[] (void *)pMsg;
		}
		else if (nSrc == (*it).m_sSock)
		{
			nSize = sizeof(TagMsg) + strSrc.GetLength();
			pMsg = (TagMsg *)new char[nSize];
			memset(pMsg, 0, nSize);
			pMsg->m_nSize = nSize;
			pMsg->m_nFrom = nSrc;
			pMsg->m_nDest = nDest;
			pMsg->m_nOper = MSG_CHAT;
			memcpy(pMsg->data, strSrc.GetBuffer(0), strSrc.GetLength());
			send(nSrc, (char *)pMsg, nSize, 0);
			
			g_pLogBox->AddString(strSYS);			
			delete[] (void *)pMsg;
		}
				
	}
	return false;
}

UINT CChatServerDlg::recvThread(LPVOID pParam)
{
	tagClient client;
	int sClient = (int)pParam;
	char szBuff[MAXBYTE] = {0};
	int nResult;

	sockaddr_in addr;
	int nLen = sizeof(addr);
	getpeername(sClient, (sockaddr*)&addr, &nLen);
	CString str;

	do 
	{
		nResult = recv(sClient, szBuff, sizeof(szBuff), 0);
		if (SOCKET_ERROR == nResult || nResult == 0)
		{
			/*
				0客户端正常关闭
				0x2746 客户端强制关闭
			*/
			str.Format("%d %s:%d disconnect...", sClient, inet_ntoa(addr.sin_addr), htons(addr.sin_port));
			g_pLogBox->AddString(str);
			break;
		}
		else
		{
			TagMsg *pMsg = (TagMsg *)&szBuff;
			pMsg->m_nFrom = sClient;

			if (pMsg->m_nDest != 0)
			{
				SendSingle(pMsg->m_nDest, sClient, pMsg->data);
			}
			else
			{
				str.Format("%d 说: %s", sClient, pMsg->data);				
				int nSize = sizeof(TagMsg) + str.GetLength();
				TagMsg *pmsg = (TagMsg *)new char[nSize];
				pmsg->m_nSize = nSize;
				pmsg->m_nFrom = sClient;
				pmsg->m_nOper = MSG_CHAT;
				memcpy(pmsg->data, str.GetBuffer(0), str.GetLength()+1);

				SendAllClients(pmsg);
				g_pLogBox->AddString(str);
				delete[] (void *)pmsg;
			}

		}
	} while (TRUE);

	str = "WorkThread end...";
	g_pLogBox->AddString(str);
	closesocket(sClient);

	// 删除客户端信息
	for (list<tagClient>::iterator it = m_ListClient.begin(); it != m_ListClient.end(); ++it)
	{
		if ((*it).m_sSock == sClient)
		{
			m_ListClient.erase(it);
			break;
		}
	}
	return 0;
}

// UINT CreateRec(LPVOID pParam)
// {
// 	CChatServerDlg *pDlg = (CChatServerDlg *)pParam;
// 	list<tagClient>& ListClient = pDlg->m_ListClient;
// 	tagClient client;
// 
// 	while (TRUE)
// 	{
// 		for (list<tagClient>::iterator it = ListClient.begin(); it != ListClient.end(); ++it)
// 		{
// 			client = *it;
// 			if (client.m_state == ASK_REC)
// 			{
// 				// 创建接收线程
// 				AfxBeginThread(pDlg->recvThread, (LPVOID)client.m_sSock);
// 				client.m_state = RECING;
// 				ListClient.erase(it);
// 				ListClient.push_back(client);
// 			}
// 		}
// 	}
// 
// 	return 0;
// }

UINT AcceptClient(LPVOID pParam)
{
	CChatServerDlg *pDlg = (CChatServerDlg *)pParam;

	CString str;
	tagClient newClient;
	tagClient client;
	sockaddr caddr;
	TagMsg msg;
	msg.m_nSize = sizeof(msg);
	int nLen = sizeof(caddr);

	do 
	{
		int sClient = accept(pDlg->m_SSocket, &caddr, &nLen);
		str.Format("%d connecting...", sClient);
		
		g_pLogBox->AddString(str);
		
		newClient.m_sSock = sClient;
		newClient.m_state = ASK_REC;
		
		m_ListClient.push_back(newClient);

		msg.m_nDest = sClient;
		msg.m_nOper = MSG_ONLINE;		
		SendAllClients(&msg);

		AfxBeginThread(pDlg->recvThread, (LPVOID)sClient);
	} while (TRUE);

	closesocket(pDlg->m_SSocket);
	g_pLogBox->ResetContent();
	g_pLogBox->AddString("server stop...");

	return 0;
}

void CChatServerDlg::OnButtonBegin() 
{
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
	
	m_bIsStop = FALSE;
	// ACCEPT线程, 往客户端链表增加新的客户端信息
	AfxBeginThread(AcceptClient, this);

	// 遍历客户端链表，处理客户端状态（创建各客户端线程）
	//AfxBeginThread(CreateRec, this);	
	m_ListBox.AddString("servers Runing....");
}

void CloseAllSocket()
{	
	for (list<tagClient>::iterator it = m_ListClient.begin(); it != m_ListClient.end(); ++it)
	{
		closesocket((*it).m_sSock);
		m_ListClient.erase(it);
	}	
}

void CChatServerDlg::OnButtonStop() 
{
	// TODO: Add your control notification handler code here
	CloseAllSocket();
}

