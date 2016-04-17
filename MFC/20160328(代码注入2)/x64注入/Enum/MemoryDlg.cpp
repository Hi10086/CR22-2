// MemoryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Enum.h"
#include "MemoryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMemoryDlg dialog


CMemoryDlg::CMemoryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMemoryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMemoryDlg)
	m_strAddress = _T("0x00401000");
	m_nSize = 4;
	m_strValue = _T("");
	//}}AFX_DATA_INIT
}


void CMemoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMemoryDlg)
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_strAddress);
	DDX_Text(pDX, IDC_EDIT_SIZE, m_nSize);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_strValue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMemoryDlg, CDialog)
	//{{AFX_MSG_MAP(CMemoryDlg)
	ON_BN_CLICKED(IDC_BTN_READ, OnBtnRead)
	ON_BN_CLICKED(IDC_BTN_WRITE, OnBtnWrite)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMemoryDlg message handlers

BOOL CMemoryDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  CString strFmt;
  strFmt.Format("内存(%d)", m_dwPID);
  SetWindowText(strFmt);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void ShowError()
{
  LPVOID lpMsgBuf;
  ::FormatMessage( 
    FORMAT_MESSAGE_ALLOCATE_BUFFER | 
    FORMAT_MESSAGE_FROM_SYSTEM | 
    FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL,
    ::GetLastError(),
    0, // Default language
    (LPTSTR) &lpMsgBuf,
    0,
    NULL 
    );
  // Process any inserts in lpMsgBuf.
  // ...
  // Display the string.
  ::MessageBox( NULL, (LPCTSTR)lpMsgBuf, "Error", MB_OK | MB_ICONINFORMATION );
  // Free the buffer.
  ::LocalFree( lpMsgBuf );
}

void CMemoryDlg::OnBtnRead() 
{
  UpdateData(TRUE);
  m_strValue = "";
  if (m_strAddress.IsEmpty())
  {
    AfxMessageBox("请输入地址");
    return;
  }
  if (m_nSize == 0)
  {
    AfxMessageBox("请输入大小");
    return;
  }

  DWORD dwAddress = strtoul(m_strAddress, NULL, 16);
  unsigned char *pBuff = new unsigned char[m_nSize];
  CString strFmt;
  DWORD i;

  HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE,
                                  m_dwPID);
  if (hProcess == NULL)
  {
    ShowError();
    goto SAFE_EXIT;
  }

  if (pBuff == NULL)
  {
    AfxMessageBox("申请空间失败");
    goto SAFE_EXIT;
  }

  SIZE_T dwNumberOfBytesRead;
  if (!::ReadProcessMemory(hProcess, 
                          (LPCVOID)dwAddress, 
                          (LPVOID)pBuff, 
                          m_nSize, 
                          &dwNumberOfBytesRead) 
      || dwNumberOfBytesRead != m_nSize)
  {
    ShowError();
    goto SAFE_EXIT;
  }

  //显示数据
  for (i = 0; i < m_nSize; i++)
  {
    strFmt.Format("%02X ", pBuff[i]);
    m_strValue += strFmt;
  }

  UpdateData(FALSE);
SAFE_EXIT:
  if (pBuff != NULL)
   delete[] pBuff;
  if (hProcess != NULL)
    ::CloseHandle(hProcess);
}

void CMemoryDlg::OnBtnWrite() 
{
  UpdateData(TRUE);
  if (m_strAddress.IsEmpty())
  {
    AfxMessageBox("请输入地址");
    return;
  }
  if (m_nSize == 0)
  {
    AfxMessageBox("请输入大小");
    return;
  }
  
  DWORD dwAddress = strtoul(m_strAddress, NULL, 16);
  unsigned char *pBuff = new unsigned char[m_nSize];
  DWORD i;
  char *p  = NULL;
  DWORD dwOld;

  HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE,
                                  m_dwPID);
  if (hProcess == NULL)
  {
    ShowError();
    goto SAFE_EXIT;
  }
  
  if (pBuff == NULL)
  {
    AfxMessageBox("申请空间失败");
    goto SAFE_EXIT;
  }
  
  //转换数据
  //m_strValue.Replace(" ", "");
  p = m_strValue.GetBuffer(0);
  for (i = 0; i < m_nSize; i++)
  {
    pBuff[i] = (unsigned char)strtoul(p, NULL, 16);
    p +=3;
  }

  //修改内存保护属性
  ::VirtualProtectEx(hProcess, (LPVOID)dwAddress, m_nSize, PAGE_READWRITE, &dwOld);

  SIZE_T dwNumberOfBytesWrite;
  if (!::WriteProcessMemory(hProcess, 
                          (LPVOID)dwAddress, 
                          (LPVOID)pBuff, 
                          m_nSize, 
                          &dwNumberOfBytesWrite) 
    || dwNumberOfBytesWrite != m_nSize)
  {
    ShowError();
    ::VirtualProtectEx(hProcess, (LPVOID)dwAddress, m_nSize, dwOld, &dwOld);
    goto SAFE_EXIT;
  }

  //还原内存保护属性
  ::VirtualProtectEx(hProcess, (LPVOID)dwAddress, m_nSize, dwOld, &dwOld);
SAFE_EXIT:
  if (pBuff != NULL)
    delete[] pBuff;
  if (hProcess != NULL)
    ::CloseHandle(hProcess);
}
