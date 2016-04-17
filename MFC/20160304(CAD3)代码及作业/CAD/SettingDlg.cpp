// SettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CAD.h"
#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg dialog


CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingDlg)
	//}}AFX_DATA_INIT
}


void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingDlg)
	DDX_Control(pDX, IDC_BTN_COLOR, m_ctlPenColor);
	//}}AFX_DATA_MAP
  
  DDX_Radio(pDX, IDC_RADIO1, m_pen.m_nPenStyle);
  DDX_Text(pDX, IDC_EDIT_WIDTH, m_pen.m_nWidth);
	DDX_Text(pDX, IDC_EDIT_PEN_COLOR, m_pen.m_crColor);
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialog)
	//{{AFX_MSG_MAP(CSettingDlg)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, OnDeltaposSpin1)
	ON_BN_CLICKED(IDC_BTN_COLOR, OnBtnColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg message handlers

BOOL CSettingDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  m_ctlPenColor.m_crBackground = m_pen.m_crColor;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSettingDlg::OnOK() 
{
  UpdateData(TRUE);
	CDialog::OnOK();
}

void CSettingDlg::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
  if (pNMUpDown->iDelta == 1)
  {
    if (m_pen.m_nWidth != 1)
      m_pen.m_nWidth--;
  }
  else 
  {
    m_pen.m_nWidth++;
  }
  UpdateData(FALSE);

	*pResult = 0;
}

void CSettingDlg::OnBtnColor() 
{
  CColorDialog dlg;
  if (dlg.DoModal() == IDOK)
  {
    m_pen.m_crColor = dlg.GetColor();
    m_ctlPenColor.m_crBackground = m_pen.m_crColor;
  }
  UpdateData(FALSE);
}
