// PlaneHackDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PlaneHack.h"
#include "PlaneHackDlg.h"

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
// CPlaneHackDlg dialog

CPlaneHackDlg::CPlaneHackDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPlaneHackDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPlaneHackDlg)
	m_nPlaneX = 0;
	m_nPlaneY = 0;
	m_wBullet = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hwnd = NULL;
	m_hGame = NULL;
	m_dwPID = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPlaneHackDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlaneHackDlg)
	DDX_Text(pDX, IDC_EDIT_PL_X, m_nPlaneX);
	DDX_Text(pDX, IDC_EDIT_PL_Y, m_nPlaneY);
	DDX_Text(pDX, IDC_EDIT_BULLET_NUM, m_wBullet);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPlaneHackDlg, CDialog)
	//{{AFX_MSG_MAP(CPlaneHackDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_BEGIN, OnButtonBegin)
	ON_BN_CLICKED(IDC_BUTTON_AUTO, OnButtonAuto)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlaneHackDlg message handlers

BOOL CPlaneHackDlg::OnInitDialog()
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

void CPlaneHackDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPlaneHackDlg::OnPaint() 
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
HCURSOR CPlaneHackDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPlaneHackDlg::OnButtonBegin() 
{
	// TODO: Add your control notification handler code here
	m_hwnd = ::FindWindow(NULL, "摿孭");
	if (m_hwnd == NULL)
	{
		AfxMessageBox("请先运行游戏");
		return;
	}
	::GetWindowThreadProcessId(m_hwnd, &m_dwPID);
	m_hGame = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, m_dwPID);
	if (m_hGame == INVALID_HANDLE_VALUE)
	{
		AfxMessageBox("打开进程失败");
		return;
	}
	//VirtualProtectEx
}

UINT AFX_CDECL GameProc(LPVOID lpParam)
{
	CPlaneHackDlg *pDlg = (CPlaneHackDlg *)lpParam;
	HANDLE hGame = pDlg->m_hGame;
	SIZE_T NumBerOfBytesRead = 0;
	UINT wNum = 0;

	tagPlane plan = {0};
	while (TRUE)
	{
		// 读取飞机坐标
		if ( !ReadProcessMemory(hGame, (LPCVOID)PLAN_POINT, &plan, sizeof(plan), &NumBerOfBytesRead) \
			|| NumBerOfBytesRead != sizeof(plan))
		{
			AfxMessageBox("读取飞机坐标失败!");
			return 1;
		}

		// 读取子弹数目
		if (ReadProcessMemory(hGame, (LPCVOID)BULL_COUNT, &wNum, sizeof(wNum), &NumBerOfBytesRead) \
			&& NumBerOfBytesRead == sizeof(wNum))
		{
			pDlg->GetBulletNum(wNum);
		}
		pDlg->SetPlanePos(plan);
	
	}
	return 0;
}

void CPlaneHackDlg::OnButtonAuto() 
{
	// TODO: Add your control notification handler code here
	SetTimer(1, 20, NULL);
	AfxBeginThread(GameProc, this);
}



void CPlaneHackDlg::SetPlanePos(tagPlane pos)
{
	m_nPlaneX = pos.x;
	m_nPlaneY = pos.y;
}

tagPlane CPlaneHackDlg::GetPlanePos()
{
	tagPlane pos = {m_nPlaneX, m_nPlaneY};
	return pos;
}

void CPlaneHackDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	UpdateData(FALSE);
	CDialog::OnTimer(nIDEvent);
}

void CPlaneHackDlg::GetBulletNum(UINT wNum)
{
	m_wBullet = wNum;
}
