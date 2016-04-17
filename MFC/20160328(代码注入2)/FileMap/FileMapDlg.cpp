// FileMapDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileMap.h"
#include "FileMapDlg.h"

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
// CFileMapDlg dialog

CFileMapDlg::CFileMapDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileMapDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileMapDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileMapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileMapDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFileMapDlg, CDialog)
	//{{AFX_MSG_MAP(CFileMapDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileMapDlg message handlers

BOOL CFileMapDlg::OnInitDialog()
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

void CFileMapDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileMapDlg::OnPaint() 
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
HCURSOR CFileMapDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFileMapDlg::OnButton1() 
{
  //创建文件映射对象
  HANDLE hMap = ::CreateFileMapping(INVALID_HANDLE_VALUE, /*内存映射*/
                      NULL, 
                      PAGE_READWRITE, 
                      0, 
                      0x1000, //大小
                      "FileMap");
  //check

  //映射
  LPVOID  lpBuff = ::MapViewOfFile(hMap, 
                                    FILE_MAP_ALL_ACCESS,
                                    0, 
                                    0, /*偏移*/
                                    0/*全部映射*/);
  if (lpBuff != NULL)
    strcpy((char*)lpBuff, "hello");

  //取消映射
  ::UnmapViewOfFile(lpBuff);

  //::CloseHandle(hMap);
}

void CFileMapDlg::OnButton2() 
{
  //创建文件映射对象
  HANDLE hMap = ::OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, "FileMap");
  //check
  
  //映射
  LPVOID  lpBuff = ::MapViewOfFile(hMap, 
                                    FILE_MAP_ALL_ACCESS,
                                    0, 
                                    0, /*偏移*/
                                    0/*全部映射*/);
  if (lpBuff != NULL)
    AfxMessageBox((char*)lpBuff);
  
  //取消映射
  ::UnmapViewOfFile(lpBuff);
  
  ::CloseHandle(hMap);
}

void CFileMapDlg::OnButton3() 
{
  HANDLE hFile = ::CreateFile("ReadMe.txt", 
                             GENERIC_READ |GENERIC_WRITE, 
                             0, 
                             NULL, 
                             OPEN_EXISTING, 
                             FILE_ATTRIBUTE_NORMAL, 
                             NULL);
  //check

  //创建文件映射对象
  HANDLE hMap = ::CreateFileMapping(hFile, /*内存映射*/
                                    NULL, 
                                    PAGE_READWRITE, 
                                    0, 
                                    0x1000, //大小
                                    NULL);
  //check
  
  //映射
  CHAR*  lpBuff = (CHAR*)::MapViewOfFile(hMap, 
                                    FILE_MAP_ALL_ACCESS,
                                    0, 
                                    0, /*偏移*/
                                    0/*全部映射*/);
  if (lpBuff != NULL)
  {
    lpBuff[0] = 'a';
    AfxMessageBox((char*)lpBuff);
  }
  
  //取消映射
  ::UnmapViewOfFile(lpBuff);
  
  ::CloseHandle(hMap);
  ::CloseHandle(hFile);
}
