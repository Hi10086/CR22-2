// TaskListView.cpp : implementation file
//

#include "stdafx.h"
#include "ListViewTaskManger.h"
#include "TaskListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using std::make_pair;
/////////////////////////////////////////////////////////////////////////////
// CTaskListView

IMPLEMENT_DYNCREATE(CTaskListView, CListView)

CTaskListView::CTaskListView()
	:m_tree(GetListCtrl())
{
	m_CurrentItem = -1;
	m_pTaskMap = NULL;
}

CTaskListView::~CTaskListView()
{
}

BEGIN_MESSAGE_MAP(CTaskListView, CListView)
	//{{AFX_MSG_MAP(CTaskListView)
	ON_NOTIFY_REFLECT(HDN_ITEMCLICK, OnItemclick)
	ON_NOTIFY_REFLECT(NM_CLICK, OnClick)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	ON_COMMAND(ID_MENUITEM_CLOSE, OnMenuitemClose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTaskListView drawing

void CTaskListView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CTaskListView diagnostics

#ifdef _DEBUG
void CTaskListView::AssertValid() const
{
	CListView::AssertValid();
}

void CTaskListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTaskListView message handlers

void CTaskListView::OnInitialUpdate() 
{
	CListView::OnInitialUpdate();
	SetWindowLong(m_tree.GetSafeHwnd(), GWL_STYLE, 0x5031000D);	
	// TODO: Add your specialized code here and/or call the base class
	m_tree.InsertColumn(0, "映像名称", LVCFMT_LEFT, 100);
	m_tree.InsertColumn(1, "PID", LVCFMT_LEFT, 100);
	m_tree.InsertColumn(2, "线程数量", LVCFMT_LEFT, 100);
	m_tree.InsertColumn(3, "进程路径", LVCFMT_LEFT, 300);

	CListViewTaskMangerDoc* pDoc = GetDocument();
	m_pTaskMap = &(pDoc->m_TaskMap);

	ShowTask();
}

void CTaskListView::ShowTask()
{
	m_tree.DeleteAllItems();

	HANDLE hProcessSnap = NULL;
	PROCESSENTRY32 pe32 = {0}; 
	pe32.dwSize = sizeof(pe32);
	int nNum = 0;
	CString szTemp;

	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);	
	if (!Process32First(hProcessSnap, &pe32))
	{
		return;
	} 

	do 
	{
		CTaskInfo* pTaskInfo = new CTaskInfo;
		pTaskInfo->m_ProcessName = pe32.szExeFile;
		pTaskInfo->m_PID = pe32.th32ProcessID;
		pTaskInfo->m_ThreadCuts = pe32.cntThreads;

		m_tree.InsertItem(nNum, pe32.szExeFile);
		szTemp.Format("%d", pe32.th32ProcessID);
		m_tree.SetItemText(nNum, 1, szTemp);
		szTemp.Format("%d", pe32.cntThreads);
		m_tree.SetItemText(nNum, 2, szTemp);
		m_tree.SetItemData(nNum, (DWORD)pTaskInfo);

		// 加入到进程树中
		m_pTaskMap->insert(make_pair(pTaskInfo->m_PID, pTaskInfo));
		nNum++;
	} while (Process32Next(hProcessSnap, &pe32));

	szTemp.Format("进程数 = %d", nNum+1);
	m_tree.InsertItem(nNum, szTemp);
}

void CTaskListView::OnItemclick(NMHDR* pNMHDR, LRESULT* pResult) 
{

	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;
	// TODO: Add your control notification handler code here
	
	m_CurrentItem = phdn->iItem;
	*pResult = 0;
}

void CTaskListView::OnClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	m_CurrentItem = pNMListView->iItem;

	*pResult = 0;
}

void CTaskListView::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	m_CurrentItem = pNMListView->iItem;

	CMenu menu;
	if (m_CurrentItem != -1)
	{
		menu.LoadMenu(IDR_MENU1);
		DWORD dwPos = GetMessagePos();
        CPoint point( LOWORD(dwPos), HIWORD(dwPos) );

		CMenu *pSubMenu = menu.GetSubMenu(0);
		pSubMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
	}
	*pResult = 0;
}

void CTaskListView::OnMenuitemClose() 
{
	CTaskInfo *pTask = NULL;
	if ((pTask = (CTaskInfo *)m_tree.GetItemData(m_CurrentItem)) == NULL)
	{
		return;
	}

	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pTask->m_PID);
	if (hProcess == NULL)
	{
		AfxMessageBox("无此权限操作!");
		return;
	}
	if (::TerminateProcess(hProcess, 0))
	{
		m_tree.DeleteItem(m_CurrentItem);
		m_CurrentItem = -1;
	}
	else
	{		
		AfxMessageBox("结束进程失败!");
	}

	ShowTask();
}

// CListViewTaskMangerDoc* CTaskListView::GetDocument() // non-debug version is inline
// {
// 	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CListViewTaskMangerDoc)));
// 	return (CListViewTaskMangerDoc*)m_pDocument;
// }


CListViewTaskMangerDoc* CTaskListView::GetDocument()
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CListViewTaskMangerDoc)));
	return (CListViewTaskMangerDoc*)m_pDocument;
}
