// CtlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Ctl.h"
#include "CtlDlg.h"

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
// CCtlDlg dialog

CCtlDlg::CCtlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCtlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCtlDlg)
	m_nSex = 0;
	m_nCourse = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCtlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCtlDlg)
	DDX_Control(pDX, IDC_TREE1, m_TreeCtrl);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	DDX_Radio(pDX, IDC_RADIO1, m_nSex);
	DDX_Radio(pDX, IDC_RADIO3, m_nCourse);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCtlDlg, CDialog)
	//{{AFX_MSG_MAP(CCtlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	ON_NOTIFY(TVN_ITEMEXPANDING, IDC_TREE1, OnItemexpandingTree1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCtlDlg message handlers

BOOL CCtlDlg::OnInitDialog()
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
	InitCtrl();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCtlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCtlDlg::OnPaint() 
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
HCURSOR CCtlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCtlDlg::OnButton1() 
{
  CString strTemp;
  for (int i = 0; i < 3; i++)
  {
    CButton *pButton = (CButton*)GetDlgItem(IDC_CHECK1 + i);
    if (pButton->GetCheck())
    {
      pButton->GetWindowText(strTemp);
      AfxMessageBox(strTemp);
    }
  }

   UpdateData(TRUE);
   GetDlgItem(IDC_RADIO1 + m_nSex)->GetWindowText(strTemp);
   AfxMessageBox(strTemp);

   GetDlgItem(IDC_RADIO3 + m_nCourse)->GetWindowText(strTemp);
   AfxMessageBox(strTemp);

   int nIndex = m_Combo.GetCurSel();
   m_Combo.GetLBText(nIndex, strTemp);
   AfxMessageBox(strTemp);

   nIndex = m_ListBox.GetCurSel();
   if (nIndex != LB_ERR)
   {
    m_ListBox.GetText(nIndex, strTemp);
    AfxMessageBox(strTemp);
   }
}

void CCtlDlg::InitCtrl()
{
  m_ImageList.Create(32, 32, ILC_COLOR32 | ILC_MASK, 0, 10);
  m_ImageList.Add(::LoadIcon(AfxGetInstanceHandle(), (char*)IDI_ICON1));
  m_ImageList.Add(::LoadIcon(AfxGetInstanceHandle(), (char*)IDI_ICON2));

  m_Combo.AddString("上海");
  m_Combo.SetCurSel(2);

  m_ListBox.AddString("湖北");
  m_ListBox.AddString("湖南");
  m_ListBox.AddString("广西");
  m_ListBox.AddString("广东");

  HTREEITEM hRoot = m_TreeCtrl.InsertItem("Ctl Classes", 0, 0);
  m_TreeCtrl.InsertItem("CAboutDlg", 1, 1, hRoot);
  m_TreeCtrl.InsertItem("CCtlApp", 1, 1, hRoot);
  m_TreeCtrl.InsertItem("CCtlDlg", 1, 1, hRoot);
  m_TreeCtrl.Expand(hRoot, TVE_EXPAND);
  m_TreeCtrl.SetImageList(&m_ImageList, TVSIL_NORMAL);
}

void CCtlDlg::OnSelchangeList1() 
{
  CString strTemp;
  int nIndex = m_ListBox.GetCurSel();
  if (nIndex != LB_ERR)
  {
    m_ListBox.GetText(nIndex, strTemp);
    AfxMessageBox(strTemp);
   }
}

void CCtlDlg::OnItemexpandingTree1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	

	*pResult = 0;
}
