// MyProcessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SankTools.h"
#include "MyProcessDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyProcessDlg dialog


CMyProcessDlg::CMyProcessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyProcessDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyProcessDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMyProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyProcessDlg)
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyProcessDlg, CDialog)
	//{{AFX_MSG_MAP(CMyProcessDlg)
	ON_WM_PAINT()
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_COMMAND(ID_MENU_PRO_FLUSH, OnMenuProFlush)
	ON_COMMAND(ID_MENU_PRO_MODULE, OnMenuProModule)
	ON_COMMAND(ID_MENU_PRO_INJECT, OnMenuProInject)
	ON_COMMAND(ID_MENU_PRO_THREAD, OnMenuProThread)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyProcessDlg message handlers

BOOL CMyProcessDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	InitCtrl();
	EnumProcess();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMyProcessDlg::InitCtrl()
{
	m_ImageList.Create(16, 16, ILC_COLOR32|ILC_MASK, 0, 100);
	m_ImageList.Add(::LoadIcon(NULL, IDI_WINLOGO));
	m_ListCtrl.SetExtendedStyle
		(m_ListCtrl.GetExtendedStyle()|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT);
	
	m_ListCtrl.SetImageList(&m_ImageList, LVSIL_SMALL);
	
	//m_ListCtrl.SetTextColor(RGB(255, 255, 255));
	//m_ListCtrl.SetBkColor(0);
	//m_ListCtrl.SetTextBkColor(0);
	
	m_ListCtrl.InsertColumn(0, "进程名称");
	m_ListCtrl.InsertColumn(1, "进程ID");
	m_ListCtrl.InsertColumn(2, "线程数量");
	m_ListCtrl.InsertColumn(3, "进程路径");
	
	//自动对齐
	int nCount = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	for (int i = 0; i < nCount; i++)
		m_ListCtrl.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
}

void CMyProcessDlg::EnumProcess()
{
	m_ListCtrl.DeleteAllItems();
	
	m_ListCtrl.SetRedraw(FALSE);
	
	//创建进程快照
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(pe);
	int nCount = 0;
	CString strFmt;
	
	HANDLE hSnapshot = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE != hSnapshot)
	{
		if (!Process32First(hSnapshot, &pe))
			return;
		
		do 
		{
			//获取进程路径
			char szPath[MAX_PATH] = {0};
			HMODULE hModule = NULL;
			HICON hIcon = NULL;
			int nIndex = 0;
			HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, pe.th32ProcessID);
			if (::GetModuleFileNameEx(hProcess, hModule, szPath, sizeof(szPath)) == 0)
			{
				szPath[0] = '\0';
			}
			else
			{
				//提取图标
				::ExtractIconEx(szPath, 0, NULL, &hIcon, 1);
				if (hIcon != NULL)
					nIndex = m_ImageList.Add(hIcon);
			}
			
			//显示
			
			
			int nSubItem = 1;
			m_ListCtrl.InsertItem(nCount, pe.szExeFile, nIndex);
			strFmt.Format("%d", pe.th32ProcessID);
			m_ListCtrl.SetItemText(nCount, nSubItem++, strFmt);
			strFmt.Format("%d", pe.cntThreads);
			m_ListCtrl.SetItemText(nCount, nSubItem++, strFmt);
			m_ListCtrl.SetItemText(nCount, nSubItem++, szPath);
			nCount++;
		} 
		while (Process32Next(hSnapshot, &pe));
		
		::CloseHandle(hSnapshot);
	}
	
	//自动对齐
	nCount = m_ListCtrl.GetHeaderCtrl()->GetItemCount();
	for (int i = 0; i < nCount; i++)
		m_ListCtrl.SetColumnWidth(i, LVSCW_AUTOSIZE_USEHEADER);
	
	m_ListCtrl.SetRedraw(TRUE);
}

void CMyProcessDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	RECT rc;
	GetClientRect(&rc);
	m_ListCtrl.MoveWindow(&rc);
}

void CMyProcessDlg::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CMenu menu;
	if (!menu.LoadMenu(IDR_MENU_PROCESS))
	{
		AfxMessageBox("LoadMenu");
	}

	//CHECK
	
	CMenu *pSubMenu = menu.GetSubMenu(0);
	if (pSubMenu == NULL)
	{
		AfxMessageBox("GetSubMenu");
	}
	
	CPoint pt;
	GetCursorPos(&pt);
	pSubMenu->TrackPopupMenu(TPM_LEFTALIGN, pt.x, pt.y, this);
	*pResult = 0;
}

void CMyProcessDlg::OnMenuProFlush() 
{
	// TODO: Add your command handler code here
	EnumProcess();
}

void CMyProcessDlg::OnMenuProModule() 
{
	int nIndex = m_ListCtrl.GetSelectionMark();
	if (nIndex != -1)
	{
		CModuleDlg dlg;
		CString strPID = m_ListCtrl.GetItemText(nIndex, 1);
		dlg.SetPID(atoi(strPID));
		
		strPID = m_ListCtrl.GetItemText(nIndex, 0);
		dlg.SetProcessName(strPID);
		dlg.DoModal();
	}
}

void CMyProcessDlg::OnMenuProInject() 
{ 
	// TODO: Add your command handler code here
	int nIndex = m_ListCtrl.GetSelectionMark();
	if (nIndex != -1)
	{
		CInjectDlg dlg;
		CString strPID = m_ListCtrl.GetItemText(nIndex, 1);
		dlg.SetPID(atoi(strPID));
		
		//strPID = m_ListCtrl.GetItemText(nIndex, 0);
		//dlg.SetProcessName(strPID);
		dlg.DoModal();
	}	
}

void CMyProcessDlg::OnMenuProThread() 
{
	// TODO: Add your command handler code here
	int nIndex = m_ListCtrl.GetSelectionMark();
	if (nIndex != -1)
	{
		CThreadDlg dlg;
		CString strPID = m_ListCtrl.GetItemText(nIndex, 1);
		dlg.SetPID(atoi(strPID));
		
		//strPID = m_ListCtrl.GetItemText(nIndex, 0);
		//dlg.SetProcessName(strPID);
		dlg.DoModal();
	}
}
