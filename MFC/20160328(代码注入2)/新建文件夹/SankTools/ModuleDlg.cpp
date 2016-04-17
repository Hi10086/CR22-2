// ModuleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SankTools.h"
#include "ModuleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CModuleDlg dialog


CModuleDlg::CModuleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CModuleDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CModuleDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CModuleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CModuleDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CModuleDlg, CDialog)
	//{{AFX_MSG_MAP(CModuleDlg)
	ON_COMMAND(ID_MENU_MODULE_FLUSH, OnMenuModuleFlush)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CModuleDlg message handlers

BOOL CModuleDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString str;
	str.Format("[%s] pid: %d", m_strName, m_dwPID);
	SetWindowText(str);
	InitCtrl();
	EnumModule();
	return TRUE; 
}

void CModuleDlg::InitCtrl()
{
	
	m_ListCtrl.SetExtendedStyle
		(m_ListCtrl.GetExtendedStyle()|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	
	m_ListCtrl.InsertColumn(0, "模块名");
	m_ListCtrl.InsertColumn(1, "基地址");
	m_ListCtrl.InsertColumn(2, "大小");
	m_ListCtrl.InsertColumn(3, "路径");
	
	//自动对齐
	int nCount = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	for (int i = 0; i < nCount; i++)
		m_ListCtrl.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
}

void CModuleDlg::EnumModule()
{
    if (m_dwPID == -1)
    {
        AfxMessageBox("获取模块句柄失败");
    }
    
    
    //创建模块快照
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
            //获取进程路径
            int nIndex = 0;
			
            //  显示       
            
            int nSubItem = 1;
            // 模块名
            m_ListCtrl.InsertItem(nCount, me.szModule);     
            //  模块基地址
            strFmt.Format("0x%p", me.modBaseAddr);
            m_ListCtrl.SetItemText(nCount, nSubItem++, strFmt);
            //  模块大小
            strFmt.Format("%d", me.modBaseSize);
            m_ListCtrl.SetItemText(nCount, nSubItem++, strFmt);
			
            // 文件路径
            m_ListCtrl.SetItemText(nCount, nSubItem++, me.szExePath);
            
            nCount++;
        } 
        while (Module32Next(hSnapshot, &me));
        
        ::CloseHandle(hSnapshot);
    }
    
    //自动对齐
    nCount = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
    for (int i = 0; i < nCount; i++)
        m_ListCtrl.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
    
    m_ListCtrl.SetRedraw(TRUE);
}

void CModuleDlg::SetPID(DWORD pid)
{
    m_dwPID = pid;
}

void CModuleDlg::OnMenuModuleFlush() 
{
	// TODO: Add your command handler code here
	EnumModule();
}

void CModuleDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	RECT rc;
	GetClientRect(&rc);
	m_ListCtrl.MoveWindow(&rc);
}

void CModuleDlg::SetProcessName(CString name)
{
	m_strName = name;
}
