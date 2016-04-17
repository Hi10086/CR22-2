// InjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "sanktools.h"
#include "InjectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInjectDlg dialog


CInjectDlg::CInjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInjectDlg::IDD, pParent)
{
	m_dwPID = 0;
	//{{AFX_DATA_INIT(CInjectDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CInjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInjectDlg)
	DDX_Control(pDX, IDC_CHECK_MEM_MAP, m_bMemMap);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInjectDlg, CDialog)
	//{{AFX_MSG_MAP(CInjectDlg)
	ON_BN_CLICKED(IDC_DLL_SEL, OnDllSel)
	ON_BN_CLICKED(IDC_BUTTON_INJECT, OnButtonInject)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInjectDlg message handlers

void CInjectDlg::OnDllSel() 
{
	static char BASED_CODE szFilter[] = "DLL Files (*.DLL)|*.DLL|All Files (*.*)|*.*||";
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter);
	if (dlg.DoModal() == IDOK)
	{
		m_strDLL = dlg.GetPathName();
		SetDlgItemText(IDC_EDIT_DLL_PATH, m_strDLL);
	}
}

void CInjectDlg::OnButtonInject() 
{
	HANDLE hMap = NULL;
	LPVOID lpMap = NULL;

	HANDLE handle = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, m_dwPID);
	if (handle == INVALID_HANDLE_VALUE)
	{
		AfxMessageBox("打开进程失败");
		return;
	}
	LPVOID lpParam = ::VirtualAllocEx(handle, NULL, 1024, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (lpParam == NULL)
	{
		AfxMessageBox("申请空间失败!");
	}
	
	// 写入DLL路径
	SIZE_T NumberOfBytesWritten;
	if (!::WriteProcessMemory(handle, \
		lpParam, \
		m_strDLL.GetBuffer(0), \
		m_strDLL.GetLength(), \
		&NumberOfBytesWritten))
	{
		AfxMessageBox("WriteProcessMemory");
	}
	
	// 内存映射
	if (m_bMemMap.GetCheck() == 1)
	{
		CString str;
		GetDlgItemText(IDC_EDIT_MAPOBJ_NAME, str);

		hMap = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 0x1000, str);
		if (hMap == NULL)
		{
			AfxMessageBox("CreateFileMapping");
		}
		
		lpMap = ::MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);
		if (lpMap == NULL)
		{
			AfxMessageBox("MapViewOfFile");
		}

		GetDlgItemText(IDC_EDIT_MAP_VALUE, str);
		strcpy((char*)lpMap, str.GetBuffer(0));
	}

	// 创建远程线程
	HMODULE hMoudle = ::GetModuleHandle("kernel32.dll");
	FARPROC pFun = ::GetProcAddress(hMoudle, "LoadLibraryA");
	DWORD dwThreadID;
	HANDLE hThread = ::CreateRemoteThread(handle, NULL, 0, (LPTHREAD_START_ROUTINE)pFun, (LPVOID)lpParam, 0, &dwThreadID);
	if (hThread == NULL)
	{
		AfxMessageBox("CreateRemoteThread");
	}

	::WaitForSingleObject(hThread, -1);
	DWORD dwExitCode;
	::GetExitCodeThread(hThread, &dwExitCode);
	if ((HMODULE)dwExitCode == NULL)
	{
		AfxMessageBox("注入失败!");
	}

	::CloseHandle(handle);
	::CloseHandle(hThread);

	if (m_bMemMap.GetCheck() == 1)
	{
		CString str;
		str.Format("%x", *(DWORD*)lpMap);
		SetDlgItemText(IDC_EDIT_MAP_VALUE_RETURN, str);
	}

	::UnmapViewOfFile(lpMap);
	::CloseHandle(hMap);
}

void CInjectDlg::SetPID(DWORD pid)
{
	m_dwPID = pid;
}

BOOL CInjectDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	SetDlgItemText(IDC_EDIT_MAP_VALUE, "写入映射内容");
	SetDlgItemText(IDC_EDIT_MAP_VALUE_RETURN, "返回映射内容");
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
