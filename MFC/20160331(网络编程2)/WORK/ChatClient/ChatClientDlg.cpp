// ChatClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChatClient.h"
#include "ChatClientDlg.h"

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
// CChatClientDlg dialog

CChatClientDlg::CChatClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChatClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChatClientDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChatClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatClientDlg)
	DDX_Control(pDX, IDC_LIST_MEMBER, m_ListMember);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChatClientDlg, CDialog)
	//{{AFX_MSG_MAP(CChatClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, OnButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatClientDlg message handlers

BOOL CChatClientDlg::OnInitDialog()
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

void CChatClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChatClientDlg::OnPaint() 
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
HCURSOR CChatClientDlg::OnQueryDragIcon()
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

void HandleMsg(CChatClientDlg *pDlg, TagMsg *pMsg)
{
	CString FmtMsg;

	switch (pMsg->m_nOper)
	{
	case MSG_CHAT:
		pDlg->m_ListBox.AddString(pMsg->data);
		break;
	case MSG_ONLINE:
		FmtMsg.Format("%d", pMsg->m_nDest);
		if (pDlg->m_ListMember.FindString(NULL, FmtMsg))
		{
			pDlg->m_ListMember.AddString(FmtMsg);
		}		
		break;
	}
}

UINT recvThread(LPVOID pParam)
{
	CChatClientDlg *pDlg = (CChatClientDlg *)pParam;
	int nResult;
	TagMsg *pMsg = NULL;

	char szBuff[MAXBYTE];
	CString str;
	do 
	{
		nResult = recv(pDlg->m_sock, szBuff, sizeof(szBuff), 0);
		if (SOCKET_ERROR == nResult || nResult == 0)
		{	
			pDlg->m_ListBox.AddString("服务器失去连接...");
		}
		
		pMsg = (TagMsg *)&szBuff;
		HandleMsg(pDlg, pMsg);

	} while (TRUE);

	closesocket(pDlg->m_sock);
	return 0;
}

void CChatClientDlg::OnButtonConnect() 
{	
	/*
	1、创建套接字（socket）。	
	2、向服务器发出连接请求（connect）。
	3、和服务器端进行通信（send/recv）。
	4、关闭套接字。
	*/
	
	int nResult;
	m_sock = socket(AF_INET, /*协议族*/
		SOCK_STREAM,  /*流套接字*/
		IPPROTO_TCP /*协议*/);
	if (INVALID_SOCKET == m_sock)
	{
		ShowErrorMsg();
		return;
	}
	
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(12345);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	nResult = connect(m_sock, (sockaddr*)&addr, sizeof(addr));
	if (INVALID_SOCKET == m_sock || m_sock == 0)
	{
		ShowErrorMsg();
		return;
	}

	AfxBeginThread(recvThread, this);
}

void CChatClientDlg::FmtMessage(const CString& msg)
{
	
}

void CChatClientDlg::OnButtonSend() 
{
	// TODO: Add your control notification handler code here
	CString str;
	GetDlgItemText(IDC_EDIT2, str);
	
	int nSize = str.GetLength() + sizeof(TagMsg);
	TagMsg *pMsg = (TagMsg *)new char[nSize];
	memset(pMsg, 0, nSize);
	pMsg->m_nSize = nSize;
	//pMsg->m_nFrom = m_sock;
	memcpy(pMsg->data, str.GetBuffer(0), str.GetLength());
	GetDlgItemText(IDC_EDIT_DEST, str); 
	if (!str.IsEmpty())
	{
		pMsg->m_nDest = atoi(str.GetBuffer(0));
	}

	if (SOCKET_ERROR == send(m_sock, (char *)pMsg, nSize, 0))
	{
		ShowErrorMsg();
	}
	else
	{
		SetDlgItemText(IDC_EDIT2, "");
	}
}

