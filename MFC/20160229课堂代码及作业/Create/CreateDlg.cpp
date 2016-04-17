// CreateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Create.h"
#include "CreateDlg.h"

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
// CCreateDlg dialog

CCreateDlg::CCreateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCreateDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCreateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCreateDlg, CDialog)
	//{{AFX_MSG_MAP(CCreateDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
  ON_COMMAND_RANGE(0x1000, 0x1009, OnCmdMsg)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CCreateDlg message handlers

BOOL CCreateDlg::OnInitDialog()
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

void CCreateDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCreateDlg::OnPaint() 
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
HCURSOR CCreateDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCreateDlg::OnButton1() 
{
  int nWidth = 50;
  int nHeight = 50;
  int nID = 0x1000;
  CString str;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
      str.Format("%d", nID - 0x1000);
      ::CreateWindow("BUTTON",
                      str, 
                      WS_CHILD | WS_VISIBLE, 
                      j * nWidth,
                      i * nHeight, 
                      nWidth,
                      nHeight, 
                      GetSafeHwnd(),
                      ((HMENU)nID++), NULL, NULL);
    }


}
#include "MyButton.h"

void CCreateDlg::OnButton2() 
{
  int nID = 0x1000;
  CString str;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    {
      str.Format("%d", nID - 0x1000);
      CButton *pButton = new CButton();
      RECT rc;
      rc.left = j * 157;
      rc.right = rc.left + 157;
      rc.top = i * 59;
      rc.bottom = rc.top + 59;
      pButton->Create(str, BS_PUSHBUTTON, rc, this, nID++);
      pButton->ShowWindow(SW_NORMAL);
    }

}

LRESULT CCreateDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
//   if (message == WM_COMMAND)
//   {
//     WORD wID = LOWORD(wParam); 
//     if (wID >= 0x1000 && wID < 0x1009)
//     {
//       CString str;
//       GetDlgItemText(wID, str);
//       AfxMessageBox(str);
//     }
//   }

	return CDialog::WindowProc(message, wParam, lParam);
}

void CCreateDlg::OnCmdMsg(UINT nID)
{
  int n = 0;
}

void CCreateDlg::OnButton3() 
{
  CMyButton *pButton = new CMyButton();
  RECT rc;
  rc.left = 0;
  rc.right = rc.left + 157;
  rc.top = 0;
  rc.bottom = rc.top + 59;
  pButton->Create("", BS_PUSHBUTTON | BS_OWNERDRAW, rc, this, 0);
  pButton->ShowWindow(SW_NORMAL);
}
