// Test2.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Test2.h"
#include "Test2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest2App

BEGIN_MESSAGE_MAP(CTest2App, CWinApp)
	//{{AFX_MSG_MAP(CTest2App)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest2App construction

CTest2App::CTest2App()
{
  m_hAccel = NULL;
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTest2App object

CTest2App theApp;

/////////////////////////////////////////////////////////////////////////////
// CTest2App initialization

BOOL CTest2App::InitInstance()
{
  m_hAccel = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR1));


	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CTest2Dlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

BOOL CTest2App::PreTranslateMessage(MSG* pMsg) 
{
  if (TranslateAccelerator(AfxGetMainWnd()->m_hWnd, m_hAccel, pMsg))
  {
    return TRUE;
  }

	return CWinApp::PreTranslateMessage(pMsg);
}
