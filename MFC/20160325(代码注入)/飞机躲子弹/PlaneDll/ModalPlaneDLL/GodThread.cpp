// GodThread.cpp : implementation file
//

#include "stdafx.h"
#include "ModalPlaneDLL.h"
#include "GodThread.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGodThread

IMPLEMENT_DYNCREATE(CGodThread, CWinThread)

CGodThread::CGodThread()
{
}

CGodThread::~CGodThread()
{
}

BOOL CGodThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	m_pGodDlg = NULL;
	m_pGodDlg = new CGodPlaneDlg();
	m_pGodDlg->Create(IDD_DIALOG_GODPLANE);
	m_pGodDlg->ShowWindow(SW_SHOWNORMAL);
	m_pGodDlg->UpdateWindow();

	return TRUE;
}

int CGodThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here
	if (m_pGodDlg != NULL)
	{
		if (m_pGodDlg->m_pScanThread != NULL)
		{
			::TerminateThread(m_pGodDlg->m_pScanThread->m_hThread, 0);
		}
		//m_pGodDlg->DestroyWindow();
		delete m_pGodDlg;
	}
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CGodThread, CWinThread)
	//{{AFX_MSG_MAP(CGodThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGodThread message handlers

int CGodThread::Run() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CWinThread::Run();
}
