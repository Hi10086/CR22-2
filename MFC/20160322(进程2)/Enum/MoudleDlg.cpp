// MoudleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Enum.h"
#include "MoudleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMoudleDlg dialog


CMoudleDlg::CMoudleDlg(CWnd* pParent /*=NULL*/)
: CDialog(CMoudleDlg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CMoudleDlg)
    // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
    
    m_dwPID = -1;
}


void CMoudleDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CMoudleDlg)
	DDX_Control(pDX, IDC_LIST2, m_ListCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMoudleDlg, CDialog)
//{{AFX_MSG_MAP(CMoudleDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMoudleDlg message handlers

void CMoudleDlg::OnOK() 
{
    // TODO: Add extra validation here
    
    CDialog::OnOK();
}

void CMoudleDlg::GetPID(DWORD pid)
{
    m_dwPID = pid;
}


void CMoudleDlg::EnumModule()
{
    if (m_dwPID == -1)
    {
        AfxMessageBox("��ȡģ����ʧ��");
    }
    
    
    //����ģ�����
    MODULEENTRY32 me;
    me.dwSize = sizeof(me);
    int nCount = 0;
    CString strFmt;
    
    HANDLE hSnapshot = ::CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, m_dwPID);
    if (INVALID_HANDLE_VALUE != hSnapshot)
    {
        if (!Module32First(hSnapshot, &me))
            return;
        
        do 
        {
            //��ȡ����·��
            int nIndex = 0;
      
            //  ��ʾ       
            
            int nSubItem = 1;
            // ģ����
            m_ListCtrl.InsertItem(nCount, me.szModule);     
            //  ģ��ID
            strFmt.Format("%d", me.th32ModuleID);
            m_ListCtrl.SetItemText(nCount, nSubItem++, strFmt);
            //  ����ID
            strFmt.Format("%d", me.th32ProcessID);
            m_ListCtrl.SetItemText(nCount, nSubItem++, strFmt);
            //  ģ�����ַ
            strFmt.Format("%p", me.modBaseAddr);
            m_ListCtrl.SetItemText(nCount, nSubItem++, strFmt);
            //  ģ���С
            strFmt.Format("%p", me.modBaseSize);
            m_ListCtrl.SetItemText(nCount, nSubItem++, strFmt);
           
            // �ļ�·��
            m_ListCtrl.SetItemText(nCount, nSubItem++, me.szModule);
            
            nCount++;
        } 
        while (Module32Next(hSnapshot, &me));
        
        ::CloseHandle(hSnapshot);
    }
    
    //�Զ�����
    nCount = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
    for (int i = 0; i < nCount; i++)
        m_ListCtrl.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
    
    m_ListCtrl.SetRedraw(TRUE);
}

void CMoudleDlg::InitCtrl()
{

  m_ListCtrl.SetExtendedStyle
    (m_ListCtrl.GetExtendedStyle()|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);

  m_ListCtrl.InsertColumn(0, "ģ����");
  m_ListCtrl.InsertColumn(1, "ģ��ID");
  m_ListCtrl.InsertColumn(2, "����ID");
  m_ListCtrl.InsertColumn(3, "ģ�����ַ");
  m_ListCtrl.InsertColumn(4, "ģ���С");
  m_ListCtrl.InsertColumn(5, "ģ��·��");

  //�Զ�����
  int nCount = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
  for (int i = 0; i < nCount; i++)
    m_ListCtrl.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
}

BOOL CMoudleDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
    InitCtrl();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
