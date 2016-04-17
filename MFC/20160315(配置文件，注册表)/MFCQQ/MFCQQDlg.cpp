// MFCQQDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCQQ.h"
#include "MFCQQDlg.h"

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
// CMFCQQDlg dialog

CMFCQQDlg::CMFCQQDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMFCQQDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMFCQQDlg)
	m_szPassword = _T("");
	m_szAccount = _T("");
	m_bAutoLogin = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCQQDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMFCQQDlg)
	DDX_Text(pDX, IDC_EDIT_PASSWARD, m_szPassword);
	DDX_Text(pDX, IDC_EDIT_ACCOUNT, m_szAccount);
	DDX_Check(pDX, IDC_CHECK_AUTO, m_bAutoLogin);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMFCQQDlg, CDialog)
	//{{AFX_MSG_MAP(CMFCQQDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, OnButtonLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCQQDlg message handlers

BOOL CMFCQQDlg::OnInitDialog()
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
	ReadConfig();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCQQDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCQQDlg::OnPaint() 
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
HCURSOR CMFCQQDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMFCQQDlg::OnButtonLogin() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_szAccount == "" || m_szPassword == "")
	{
		AfxMessageBox("’À∫≈ªÚ√‹¬Î≤ªƒ‹Œ™ø’");
		return;
	}
	CString str;
	str.Format("’À∫≈:%s √‹¬Î%s", m_szAccount, m_szPassword);
	AfxMessageBox(str);
	
	if (m_bAutoLogin)
	{
		WriteConfig();
	}
}

void CMFCQQDlg::WriteConfig()
{
	char szBuf[MAX_PATH];
	BOOL bResult;
	CString szAuto;
	szAuto.Format("%d", m_bAutoLogin);
	if (GetCurrentDirectory(MAX_PATH, szBuf) != NULL)
	{
		strcat(szBuf, "\\Debug\\config.ini");
		bResult = ::WritePrivateProfileString("LoginInfo", "AutoLogin", szAuto, szBuf);		
		bResult = ::WritePrivateProfileString("LoginInfo", "Account", m_szAccount, szBuf);
		bResult = ::WritePrivateProfileString("LoginInfo", "Password", m_szPassword, szBuf);

	}
}

void CMFCQQDlg::ReadConfig()
{
	char szBuf[MAX_PATH];
	BOOL bResult;
	char szAccount[MAXBYTE];
	char szPass[MAXBYTE];
	BOOL szAuto;
	if (GetCurrentDirectory(MAX_PATH, szBuf) != NULL)
	{
		strcat(szBuf, "\\Debug\\config.ini");
		szAuto = ::GetPrivateProfileInt("LoginInfo", "AutoLogin", FALSE, szBuf);
		if (szAuto)
		{
			m_bAutoLogin = szAuto;
			::GetPrivateProfileString("LoginInfo", "Account", "", szAccount, MAXBYTE, szBuf);
			::GetPrivateProfileString("LoginInfo", "Password", "", szPass, MAXBYTE, szBuf);
			m_szAccount.Format("%s", szAccount);
			m_szPassword.Format("%s", szPass);
			UpdateData(FALSE);
		}
	}
}
