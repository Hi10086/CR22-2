// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "TestDlg.h"
#include <process.h>
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
// CTestDlg dialog

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
{
  m_nNum = 0;
  m_hThread = NULL;
  m_isStop = FALSE;
	//{{AFX_DATA_INIT(CTestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_START, OnBtnStart)
	ON_BN_CLICKED(IDC_BTN_STOP, OnBtnStop)
	ON_BN_CLICKED(IDC_BTN_SUS, OnBtnSus)
	ON_BN_CLICKED(IDC_BTN_RES, OnBtnRes)
	ON_BN_CLICKED(IDC_BTN_SUS2, OnBtnSus2)
	ON_BN_CLICKED(IDC_BTN_RES2, OnBtnRes2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
    ON_MESSAGE(WM_USER + 1, MyMessage)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

BOOL CTestDlg::OnInitDialog()
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

void CTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestDlg::OnPaint() 
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
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

unsigned int  __stdcall ThreadProc(void *lpParam)
{
  CTestDlg *lpDlg = (CTestDlg*)lpParam;
  
  while(!lpDlg->m_isStop)
  {
    lpDlg->m_nNum++;
    //lpDlg->SetDlgItemInt(IDC_EDIT1, lpDlg->m_nNum);

    lpDlg->PostMessage(WM_USER + 1, NULL, NULL);
    Sleep(1);
    //::SendMessage(); //不要在线程send

    WaitForSingleObject(lpDlg->m_hEvent, -1);
  }

  return 1;
}

void CTestDlg::OnBtnStart() 
{
  m_nNum = 0;
  m_isStop = FALSE;
  m_hEvent = ::CreateEvent(NULL, TRUE, TRUE, NULL);
  m_hThread = (HANDLE)_beginthreadex(NULL, 0, ThreadProc, this, 0, NULL);
}

void CTestDlg::OnBtnStop() 
{
  m_isStop = TRUE;
  
  //等待线程结束
  ::WaitForSingleObject(m_hThread, -1);

  //获取回调函数的返回值
  DWORD dwExitCode;
  ::GetExitCodeThread(m_hThread, &dwExitCode);

  //::TerminateThread(m_hThread, 0);  //线程结束代码位置未知,不推荐使用
  ::CloseHandle(m_hThread);
}

afx_msg LRESULT CTestDlg::MyMessage(WPARAM, LPARAM)
{
  SetDlgItemInt(IDC_EDIT1, m_nNum);
  return true;
}

void CTestDlg::OnBtnSus() 
{
  //挂起线程
  ::SuspendThread(m_hThread);  //引用计数
}

void CTestDlg::OnBtnRes() 
{
  ::ResumeThread(m_hThread);
}

void CTestDlg::OnBtnSus2() 
{
  ::ResetEvent(m_hEvent);
}

void CTestDlg::OnBtnRes2() 
{
  ::SetEvent(m_hEvent);
}

void CTestDlg::OnButton1() 
{
  HWND hCalc = ::FindWindow(NULL, "计算器");
  if (hCalc != NULL)
  {
    DWORD dwThreadID = ::GetWindowThreadProcessId(hCalc, NULL);
    HANDLE hThread = ::OpenThread(THREAD_ALL_ACCESS, FALSE, dwThreadID);
    //::TerminateThread(hThread, 0);
    ::ResumeThread(hThread);
    //::SuspendThread(hThread);
  }
  
}
