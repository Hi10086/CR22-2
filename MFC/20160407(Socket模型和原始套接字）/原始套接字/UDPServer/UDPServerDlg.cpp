// UDPServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UDPServer.h"
#include "UDPServerDlg.h"

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
// CUDPServerDlg dialog

CUDPServerDlg::CUDPServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUDPServerDlg::IDD, pParent)
{
  m_socket = INVALID_SOCKET;
	//{{AFX_DATA_INIT(CUDPServerDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUDPServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUDPServerDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUDPServerDlg, CDialog)
	//{{AFX_MSG_MAP(CUDPServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
  ON_MESSAGE(MSG_TALK, OnTalk)
  ON_MESSAGE(MSG_START, OnServerStart)
  ON_MESSAGE(MSG_STOP, OnServerStop)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUDPServerDlg message handlers

BOOL CUDPServerDlg::OnInitDialog()
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
	
  if (!OnStart())
    EndDialog(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CUDPServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CUDPServerDlg::OnPaint() 
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
HCURSOR CUDPServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

struct ip_hdr
{
  unsigned char h_len:4;         //length of header
  unsigned char version:4;      //Version of IP
  unsigned char tos;               //Type of service
  unsigned short total_len;     //total length of the packet
  
  unsigned short ident;          //unique identifier
  unsigned short frag_and_flags; //flags
  
  unsigned char ttl;          //ttl
  unsigned char proto;        //protocol(TCP ,UDP etc)
  unsigned short checksum;    //IP checksum
  
  unsigned int sourceIP;
  unsigned int destIP;
};


typedef struct _UDP_HEADER 
{
  USHORT nSourPort ;   // 源端口号16bit
  USHORT nDestPort ;   // 目的端口号16bit
  USHORT nLength ;   // 数据包长度16bit
  USHORT nCheckSum ;   // 校验和16bit
}UDP_HEADER, *PUDP_HEADER ;


UINT WorkThread(LPVOID lpParam)
{
  CUDPServerDlg* lpDlg =  (CUDPServerDlg*)lpParam;
  SOCKET socket = lpDlg->m_socket;
  char szBuff[0x3000];
  sockaddr_in addr;
  int nLen = sizeof(addr);


  lpDlg->PostMessage(MSG_START, (WPARAM)new CString(szBuff), NULL);

  
  while(true)
  {
    int nResult = recvfrom(socket, szBuff, sizeof(szBuff), 0, 
                           (sockaddr*)&addr, &nLen);
    if (nResult <= 0)
      break;

    ip_hdr *pIP = (ip_hdr*)szBuff;
    UDP_HEADER *pUDP = (UDP_HEADER*)(pIP + 1);
    lpDlg->PostMessage(MSG_TALK, (WPARAM)new CString(szBuff), NULL);
  }


  closesocket(socket);
  lpDlg->PostMessage(MSG_STOP, (WPARAM)new CString(szBuff), NULL);
  return 0;
}

BOOL CUDPServerDlg::OnStart()
{
  int nResult;

  m_socket = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
  if (m_socket == INVALID_SOCKET)
    return FALSE;

  //获取socket缓冲区大小
  int nRecvSize = 0;
  int nSendSize = 0;
  int nLen = sizeof(int);

  nResult = getsockopt(m_socket, SOL_SOCKET, SO_RCVBUF, (char*)&nRecvSize, &nLen);
  nResult = getsockopt(m_socket, SOL_SOCKET, SO_SNDBUF, (char*)&nSendSize, &nLen);

  //修改
  nRecvSize = 0x2000;
  nSendSize = 0x2000;
  nResult = setsockopt(m_socket, SOL_SOCKET, SO_RCVBUF, (char*)&nRecvSize, nLen);
  nResult = setsockopt(m_socket, SOL_SOCKET, SO_SNDBUF, (char*)&nSendSize, nLen);


  //绑定端口
  sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_addr.S_un.S_addr = 0; //任意地址可通讯
  addr.sin_port = htons(5566); //0系统分配一个未占用的端口
  nResult = bind(m_socket, (sockaddr*)&addr, sizeof(addr)); 
  if (nResult == SOCKET_ERROR)
    return FALSE;

//   sockaddr_in addr2;
//   int nLen = sizeof(addr2);
//   getsockname(m_socket, (sockaddr*)&addr2, &nLen);

  //阻塞，同步(非阻塞，异步)
  AfxBeginThread(WorkThread, (LPVOID)this);

  //recvfrom(m_socket, 
  return TRUE;
}

BOOL CUDPServerDlg::DestroyWindow() 
{
  if (m_socket != INVALID_SOCKET)
    closesocket(m_socket);

	return CDialog::DestroyWindow();
}

LRESULT CUDPServerDlg::OnTalk(WPARAM wParam, LPARAM lParam)
{
  CString *lpData = (CString*)wParam;
  m_ListBox.AddString(*lpData);
  delete lpData;
  return TRUE;
}

LRESULT CUDPServerDlg::OnServerStart(WPARAM wParam, LPARAM lParam)
{
  m_ListBox.AddString("Server start...");
  return TRUE;
}

LRESULT CUDPServerDlg::OnServerStop(WPARAM wParam, LPARAM lParam)
{
  m_ListBox.AddString("Server stop...");
  return TRUE;
}
