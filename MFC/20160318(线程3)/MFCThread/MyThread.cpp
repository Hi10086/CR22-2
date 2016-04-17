// MyThread.cpp : implementation file
//

#include "stdafx.h"
#include "MFCThread.h"
#include "MyThread.h"
#include <afxmt.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyThread

IMPLEMENT_DYNCREATE(CMyThread, CWinThread)

CMyThread::CMyThread()
{
  m_isStop = FALSE;
}

CMyThread::~CMyThread()
{
}

BOOL CMyThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CMyThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CMyThread, CWinThread)
	//{{AFX_MSG_MAP(CMyThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyThread message handlers
//CEvent event;
//CMutex g_Object;
//CSemaphore g_Object;
CCriticalSection g_Object;

int CMyThread::Run() 
{
  while(!m_isStop)
  {
    g_Object.Lock();
    OutputDebugString("run...");
    g_Object.Unlock();
    Sleep(1000);
  }
	return CWinThread::Run();
}
