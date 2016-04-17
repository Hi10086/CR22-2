// EnumDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Enum.h"
#include "EnumDlg.h"
#include <TLHELP32.H>
#include <Psapi.h>

#pragma comment(lib, "psapi.lib")

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
// CEnumDlg dialog

CEnumDlg::CEnumDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEnumDlg::IDD, pParent)
{
  m_IsStop = FALSE;
	//{{AFX_DATA_INIT(CEnumDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEnumDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEnumDlg)
	DDX_Control(pDX, IDC_MY_STATIC, m_MyStatic);
	DDX_Control(pDX, IDC_LIST1, m_ListCtrl);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CEnumDlg, CDialog)
	//{{AFX_MSG_MAP(CEnumDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CONTEXTMENU()
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_COMMAND(IDM_ENUM_PROCESS, OnEnumProcess)
	ON_COMMAND(IDM_WINDOW, OnWindow)
	ON_BN_CLICKED(IDC_MY_STATIC, OnMyStatic)
	ON_COMMAND(IDM_MEMORY, OnMemory)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BTN_INJECT, OnBtnInject)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BTN_PATH, OnBtnPath)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnumDlg message handlers

BOOL CEnumDlg::OnInitDialog()
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
	
	InitCtrl();
  EnumProcess();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CEnumDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CEnumDlg::OnPaint() 
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
HCURSOR CEnumDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CEnumDlg::InitCtrl()
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

void CEnumDlg::EnumProcess()
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
  //m_ListCtrl.GetItemText(
}

void CEnumDlg::OnContextMenu(CWnd* pWnd, CPoint point) 
{
}

void CEnumDlg::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{

  CMenu menu;
  menu.LoadMenu(IDR_MENU1);
  //CHECK

  CMenu *pSubMenu = menu.GetSubMenu(0);
  //check

  CPoint pt;
  GetCursorPos(&pt);
  pSubMenu->TrackPopupMenu(TPM_LEFTALIGN, pt.x, pt.y, this);
	*pResult = 0;
}

void CEnumDlg::OnEnumProcess() 
{
	EnumProcess();
}

BOOL CALLBACK EnumWindowsProc(HWND hwnd,  LPARAM lParam)
{
  DWORD dwPID;
  ::GetWindowThreadProcessId(hwnd, &dwPID);

  if (dwPID == (DWORD)lParam)
  {
    char szClassName[MAXBYTE];
    ::GetClassName(hwnd, szClassName, sizeof(szClassName));
    CString str;
    str.Format("HWND:%p ClassName:%s", hwnd, szClassName);
    OutputDebugString(str);
  }

  return TRUE;
}

void CEnumDlg::OnWindow() 
{
//   int nIndex = m_ListCtrl.GetSelectionMark();
//   if (nIndex != -1)
//   {
//     CString strPID = m_ListCtrl.GetItemText(nIndex, 1);
//     EnumWindows(EnumWindowsProc, atoi(strPID));
//   }
  //Z序遍历
  HWND hDeskTop = ::GetDesktopWindow();
  HWND hChild = ::GetWindow(hDeskTop, GW_CHILD);
  do 
  {
    char szClassName[MAXBYTE];
    ::GetClassName(hChild, szClassName, sizeof(szClassName));
    CString str;
    str.Format("HWND:%p ClassName:%s", hChild, szClassName);
    OutputDebugString(str);

    //下一个
    hChild = ::GetWindow(hChild, GW_HWNDNEXT);
  } while (hChild != NULL);
}

void CEnumDlg::OnMyStatic() 
{
}

void CEnumDlg::OnMemory() 
{
  int nIndex = m_ListCtrl.GetSelectionMark();
  if (nIndex != -1)
  {
    CMemoryDlg dlg;
    CString strPID = m_ListCtrl.GetItemText(nIndex, 1);
    dlg.SetPID(atoi(strPID));
    dlg.DoModal();
  }
}

#define PLAN_POINT 0x00406D6C
#define BULL_COUNT 0x00406DA8
#define BULL_ARRAY 0x00406E10

#pragma pack(1)

struct tagPlan
{
  int x;
  int y;
};

struct tagBull
{
  int x;
  int y;
  char rev[7];
};
#pragma pack(8)


bool IsSafe(int x, int y, tagBull *pBulls, int nBullCount)
{
  CRgn rgn;
  rgn.CreateRectRgn(x - 15, y - 15, x + 15, y + 15);
  for (int i = 0 ; i < nBullCount; i++)
  {
    int x1 = (pBulls[i].x >> 6) - 4;
    int y1 = (pBulls[i].y >> 6) - 4;
    if (rgn.PtInRegion(x1, y1))
      return false;
  }

  return true;
}

UINT AFX_CDECL GameProc(LPVOID lpParam)
{
  CEnumDlg *lpDlg = (CEnumDlg*)lpParam;
  HWND hGame = ::FindWindow(NULL, "摿孭");
  RECT rc;
  ::GetClientRect(hGame, &rc);
  int nHeight = rc.bottom - rc.top;
  int nWidth = rc.right - rc.left;
  HDC hdc = ::GetDC(hGame);
  HPEN hPen = ::CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
  ::SelectObject(hdc, hPen);
  ::SelectObject(hdc, ::GetStockObject(NULL_BRUSH));

  DWORD dwPID;
  ::GetWindowThreadProcessId(hGame, &dwPID);
  HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);

  int nBullCount = 0;
  tagBull Bulls[0x10000];
  tagPlan plan;

  while(!lpDlg->m_IsStop)
  {
    ::ReadProcessMemory(hProcess, (LPVOID)PLAN_POINT, (LPVOID)&plan, sizeof(plan), NULL);
    
    //获取子弹数量
    ::ReadProcessMemory(hProcess, (LPVOID)BULL_COUNT, (LPVOID)&nBullCount, sizeof(nBullCount), NULL);

    //读取子弹
    ::ReadProcessMemory(hProcess, (LPVOID)BULL_ARRAY, (LPVOID)&Bulls, sizeof(tagBull) * nBullCount, NULL);

    if (!IsSafe(plan.x, plan.y, Bulls, nBullCount))
    {
      for (int y = 30; y < nHeight - 30; y++)
      {
        for (int x = 30; x < nWidth - 30; x++)
        {
          plan.x = x;
          plan.y = y;
          if (IsSafe(plan.x, plan.y, Bulls, nBullCount))
          {
            ::WriteProcessMemory(hProcess, (LPVOID)PLAN_POINT, (LPVOID)&plan, sizeof(plan), NULL);
            break;
          }
        }

      }
    }



    //遍历子弹
//     for (int i = 0 ; i < nBullCount; i++)
//     {
//       int x = (Bulls[i].x >> 6) - 4;
//       int y = (Bulls[i].y >> 6) - 4;
//       ::Rectangle(hdc, x - 5, nHeight - y + 5, x + 5, nHeight - y  - 5);
//     }

   // ::Rectangle(hdc, plan.x - 5, nHeight - plan.y + 5, plan.x + 15 + 5, nHeight - plan.y - 15 - 5);
  }

  ::CloseHandle(hProcess);
  ::ReleaseDC(hGame, hdc);
  ::DeleteObject(hPen);
  return 0;
}

void CEnumDlg::OnButton1() 
{
  AfxBeginThread(GameProc, this);
}

void CEnumDlg::OnButton2() 
{
  m_IsStop = TRUE;
}
typedef int (WINAPI* FUNTYPE)(
            __in_opt HWND hWnd,
            __in_opt LPCSTR lpText,
            __in_opt LPCSTR lpCaption,
             __in UINT uType);

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
  FUNTYPE pfn = (FUNTYPE)(0x75a50000 + 0x6fd1e);
  char sz[] = {'h', 'e', 'l', 'l','o', '\0'};
  //FUNTYPE pfn = MessageBoxA;
  pfn(NULL, sz, NULL, NULL);
  return 0;
}

void CEnumDlg::OnBtnInject() 
{
  //ThreadProc(NULL);
  AfxMessageBox("Release运行");

  //1.打开进程
  CString strPID = m_ListCtrl.GetItemText(m_ListCtrl.GetSelectionMark(), 1);
  DWORD dwPID = atoi(strPID);
  HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);
  //check


  //2.申请空间
  LPVOID  lpBuff = VirtualAllocEx(hProcess, 
                                 NULL, 
                                 0x1000, 
                                 MEM_COMMIT/*提交内存*/, 
                                 PAGE_EXECUTE_READWRITE);

  strPID.Format("%p %p", lpBuff, ThreadProc);
  //AfxMessageBox(strPID);
  //3.写入代码
  if (lpBuff != NULL)
  {
    DWORD dwWriteBytes;
    ::WriteProcessMemory(hProcess, lpBuff, ThreadProc, 0x1000, &dwWriteBytes);
  }


  //dll注入
  //4.创建远程线程
  HANDLE hThread = ::CreateRemoteThread(hProcess, 
                                        NULL,
                                        0, 
                                        (LPTHREAD_START_ROUTINE)LoadLibrary,
                                        NULL, 
                                        0, 
                                        NULL);
 
  ::CloseHandle(hThread);
  ::CloseHandle(hProcess);
}

void CEnumDlg::OnButton4() 
{
  /*
   1.打开进程
   2.申请空间
   3.写入dll路径
   4.创建远程线程

  APC注入，输入法注入
  */

  //1.打开进程
  CString strPID = m_ListCtrl.GetItemText(m_ListCtrl.GetSelectionMark(), 1);
  DWORD dwPID = atoi(strPID);
  HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);
  //check


  //2.申请空间
  LPVOID  lpBuff = ::VirtualAllocEx(hProcess, 
                                 NULL, 
                                 0x1000, 
                                 MEM_COMMIT/*提交内存*/, 
                                 PAGE_EXECUTE_READWRITE);
  //3.写入dll路径
  if (lpBuff != NULL)
  {
    CString strPath;
    GetDlgItemText(IDC_EDIT1, strPath);
    DWORD dwWriteBytes;
    ::WriteProcessMemory(hProcess, 
                         lpBuff, 
                         strPath.GetBuffer(0), 
                         strPath.GetLength(),
                         &dwWriteBytes);
  }
  
  
  //dll注入
  //4.创建远程线程
  HMODULE hModule = GetModuleHandle("kernel32.dll");
  void *pfnLoadLibraryA = GetProcAddress(hModule, "LoadLibraryA");
  HANDLE hThread = ::CreateRemoteThread(hProcess, 
                                        NULL,
                                        0, 
                                        (LPTHREAD_START_ROUTINE)pfnLoadLibraryA,
                                        lpBuff, 
                                        0, 
                                        NULL);
  ::WaitForSingleObject(hThread, -1);
  DWORD dwExitCode;
  ::GetExitCodeThread(hThread, &dwExitCode);
  if ((HMODULE)dwExitCode == NULL)
  {
    AfxMessageBox("注入失败");
  }

  m_hModule = (HMODULE)dwExitCode;
  ::CloseHandle(hThread);
  ::CloseHandle(hProcess);
}

void CEnumDlg::OnBtnPath() 
{
  static char  szFilter[] = "Dll Files (*.dll)|*.dll|All Files (*.*)|*.*||";
 
  CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter);
  if (dlg.DoModal() == IDOK)
  {
    SetDlgItemText(IDC_EDIT1, dlg.GetPathName());
  }
}
