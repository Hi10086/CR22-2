// GodPlaneDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ModalPlaneDLL.h"
#include "GodPlaneDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGodPlaneDlg dialog


CGodPlaneDlg::CGodPlaneDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGodPlaneDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGodPlaneDlg)
	m_nPlaneX = 0;
	m_nPlaneY = 0;
	//}}AFX_DATA_INIT
}


void CGodPlaneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGodPlaneDlg)
	DDX_Text(pDX, IDC_EDIT_PLANE_X, m_nPlaneX);
	DDX_Text(pDX, IDC_EDIT_PLANE_Y, m_nPlaneY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGodPlaneDlg, CDialog)
	//{{AFX_MSG_MAP(CGodPlaneDlg)
	ON_BN_CLICKED(IDC_BUTTON_SCAN, OnButtonScan)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGodPlaneDlg message handlers

#define PLAN_POINT 0x00406D6C
#define BULL_COUNT 0x00406DA8
#define BULL_ARRAY 0x00406E10

struct tagPlan
{
	int x;
	int y;
};

UINT GodScanThread(LPVOID pParam)
{	
	CGodPlaneDlg* pDlg = (CGodPlaneDlg*)pParam;
	tagPlan *pPlanePos = (tagPlan *)PLAN_POINT;

	while (pDlg->m_bScanStop == FALSE)
	{
		pDlg->m_nPlaneX = pPlanePos->x;
		pDlg->m_nPlaneY = pPlanePos->y;
	}

	return 0;
}

void CGodPlaneDlg::OnButtonScan() 
{
	// TODO: Add your control notification handler code here
	m_bScanStop = FALSE;
	SetTimer(1, 100, NULL);
	m_pScanThread = ::AfxBeginThread(GodScanThread, this);
}

void CGodPlaneDlg::OnButtonStop() 
{
	m_bScanStop = TRUE;
	// TODO: Add your control notification handler code here
	if (m_pScanThread != NULL)
	{
		::PostThreadMessage(m_pScanThread->m_nThreadID, WM_QUIT, 0, 0);
		m_pScanThread = NULL;
	}
	KillTimer(1);
}

BOOL CGodPlaneDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_bScanStop = FALSE;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CGodPlaneDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	UpdateData(FALSE);
	CDialog::OnTimer(nIDEvent);
}


BOOL CGodPlaneDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	if (m_pScanThread != NULL)
	{
		::PostThreadMessage(m_pScanThread->m_nThreadID, WM_QUIT, 0, 0);
		m_pScanThread = NULL;
	}
	return CDialog::DestroyWindow();
}
