// ConfigFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ConfigFile.h"
#include "ConfigFileDlg.h"

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
// CConfigFileDlg dialog

CConfigFileDlg::CConfigFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConfigFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConfigFileDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CConfigFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConfigFileDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CConfigFileDlg, CDialog)
	//{{AFX_MSG_MAP(CConfigFileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConfigFileDlg message handlers

BOOL CConfigFileDlg::OnInitDialog()
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

void CConfigFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CConfigFileDlg::OnPaint() 
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
HCURSOR CConfigFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CConfigFileDlg::OnButton1() 
{
  BOOL bResult;
  char szBuf[MAX_PATH];

  //获取应用程序路径
  ::GetCurrentDirectory(sizeof(szBuf), szBuf); 
  strcat(szBuf, "\\config.ini");

  //创建SECTION
  //bResult = ::WritePrivateProfileSection("pen", "", szBuf);

  //写KEY
  bResult = ::WritePrivateProfileString("pen", "color", "0", szBuf);
  bResult = ::WritePrivateProfileString("pen", "width", "1", szBuf);
  bResult = ::WritePrivateProfileString("pen", "style", "0", szBuf);
  bResult = ::WritePrivateProfileString("pen", "width", "2", szBuf);

  tagPen pen = {0x12345678};
  bResult = ::WritePrivateProfileStruct("pen1", "penvalue", &pen, 
                                       sizeof(pen), szBuf);

  ::WriteProfileString("pen", "color", "1");
}

void CConfigFileDlg::OnButton2() 
{
  UINT nColor;
  char szBuf[MAX_PATH];
  
  //获取应用程序路径
  ::GetCurrentDirectory(sizeof(szBuf), szBuf); 
  strcat(szBuf, "\\config.ini");

  nColor = ::GetPrivateProfileInt("pen", "color", -1, szBuf);
  UINT nWidth = ::GetPrivateProfileInt("pen", "width", 1, szBuf);

  char szStyle[20];
  ::GetPrivateProfileString("pen", "style", "1", szStyle, sizeof(szStyle), szBuf);
  UINT nStyle = atoi(szStyle);


  tagPen pen;
  ::GetPrivateProfileStruct("pen1", "penvalue", &pen, 
                                       sizeof(pen), szBuf);
}

void CConfigFileDlg::OnButton3() 
{
  //创建 key
  HKEY hKey;
  long Result;
  DWORD dwDisposition; 
  Result = ::RegCreateKeyEx(HKEY_CURRENT_CONFIG,
                   "Software\\CR22",
                   NULL, 
                   "", 
                   0, 
                   KEY_ALL_ACCESS, 
                   NULL, 
                   &hKey, 
                   &dwDisposition);
  if (ERROR_SUCCESS != Result)
  {
    return;
  }
  ::RegCloseKey(hKey);
   
   //创建值   
  Result = ::RegOpenKey(HKEY_CURRENT_CONFIG, "Software\\CR22", &hKey);
  if (ERROR_SUCCESS != Result)
  {
    return;
  }

  DWORD dwColor = 1;
  Result = ::RegSetValueEx(hKey, "pen color", 0, REG_DWORD, (BYTE*)&dwColor, sizeof(dwColor)); 
  Result = ::RegSetValueEx(hKey, NULL, 0, REG_SZ, (BYTE*)"hello", sizeof("hello")); 
  if (ERROR_SUCCESS != Result)
  {
      return;
  }
  //::RegCloseKey(hKey);

  //删除注册表
  //RegDeleteKey(HKEY_CURRENT_CONFIG, "Software\\CR22");
  //RegDeleteValue;


  //遍历注册表
  DWORD dwValues;
  CHAR  szValueName[MAXBYTE];
  UCHAR  szData[MAXBYTE];
  DWORD dwValueSize = sizeof(szValueName);
  DWORD dwType;
  DWORD dwDataSize = sizeof(szData);
  CString str;
  RegQueryInfoKey(hKey, NULL, NULL, NULL, NULL, NULL, NULL, 
                  &dwValues, NULL, NULL, NULL, NULL);
  for (DWORD i = 0; i < dwValues; i++)
  {
    szValueName[0] = '\0';
    DWORD dwValueSize = sizeof(szValueName);
    DWORD dwDataSize = sizeof(szData);
    ::RegEnumValue(hKey, i, szValueName, &dwValueSize, NULL, 
                   &dwType, szData, &dwDataSize);
    switch(dwType)
    {
    case REG_SZ:
      str.Format("%s %s", szValueName, szData);
      break;
    case REG_DWORD:
      str.Format("%s %d", szValueName, *(DWORD*)szData);
      break;
    }
    AfxMessageBox(str);
  }
  
 ::RegCloseKey(hKey);
}
