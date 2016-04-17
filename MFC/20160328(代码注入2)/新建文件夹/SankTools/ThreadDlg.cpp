// ThreadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "sanktools.h"
#include "ThreadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThreadDlg dialog


CThreadDlg::CThreadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThreadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThreadDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CThreadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThreadDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CThreadDlg, CDialog)
	//{{AFX_MSG_MAP(CThreadDlg)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreadDlg message handlers

BOOL CThreadDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitCtrl();
	EnumThread();
	return TRUE; 
}

void CThreadDlg::InitCtrl()
{
	
	m_ListCtrl.SetExtendedStyle
		(m_ListCtrl.GetExtendedStyle()|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	
	m_ListCtrl.InsertColumn(0, "线程ID");
	
	//自动对齐
	int nCount = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	for (int i = 0; i < nCount; i++)
		m_ListCtrl.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
}

void CThreadDlg::EnumThread()
{
    if (m_dwPID == -1)
    {
        AfxMessageBox("获取模块句柄失败");
    }
    
    
    //创建模块快照
    THREADENTRY32 te;
    te.dwSize = sizeof(te);
    int nCount = 0;
    CString strFmt;
    
    HANDLE hSnapshot = ::CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, m_dwPID);
    if (INVALID_HANDLE_VALUE != hSnapshot)
    {
        if (!::Thread32First(hSnapshot, &te))
            return;        
        do 
        {
			if (te.th32OwnerProcessID == m_dwPID)
			{
				strFmt.Format("%d", te.th32ThreadID);
				m_ListCtrl.InsertItem(nCount, strFmt);
				
// 				::OpenProcess(PROCESS_VM_READ, FALSE, te.th32OwnerProcessID);
// 				HANDLE hThread = ::OpenThread(THREAD_QUERY_INFORMATION, FALSE, te.th32ThreadID);
// 								::GetModuleInformation(hThread, )
			}
    
        } 
        while (Thread32Next(hSnapshot, &te));
        
        ::CloseHandle(hSnapshot);
    }
    
    //自动对齐
    nCount = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
    for (int i = 0; i < nCount; i++)
        m_ListCtrl.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
    
    m_ListCtrl.SetRedraw(TRUE);
}

void CThreadDlg::SetPID(DWORD pid)
{
    m_dwPID = pid;
}

void CThreadDlg::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CMenu menu;
	if (!menu.LoadMenu(IDR_MENU_PROCESS))
	{
		AfxMessageBox("LoadMenu");
	}
		
	CMenu *pSubMenu = menu.GetSubMenu(2);
	if (pSubMenu == NULL)
	{
		AfxMessageBox("GetSubMenu");
	}
	
	CPoint pt;
	GetCursorPos(&pt);
	pSubMenu->TrackPopupMenu(TPM_LEFTALIGN, pt.x, pt.y, this);
	*pResult = 0;
}
