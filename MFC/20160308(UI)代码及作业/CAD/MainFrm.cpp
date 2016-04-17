// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "CAD.h"
#include "MyTree.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	//m_bAutoMenuEnable = FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}


	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

  OnMyCreate();
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

void CMainFrame::OnMyCreate()
{
  if (!m_wndShapeToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
    | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
    !m_wndShapeToolBar.LoadToolBar(IDR_TOOLBAR1))
  {
    TRACE0("Failed to create toolbar\n");
    //OutputDebugString();
	}

  m_wndShapeToolBar.EnableDocking(CBRS_ALIGN_ANY); //工具栏可以停靠的位置
  //m_wndShapeToolBar.SetBitmap(
  EnableDocking(CBRS_ALIGN_ANY); //窗口允许停靠的位置
	DockControlBar(&m_wndShapeToolBar);

  m_wndShapeToolBar.SetButtonInfo(0, IDM_LINE, TBBS_SEPARATOR, 200);

  CRect rc(0, 0, 200, 100);
  m_Combox.Create(CBS_DROPDOWNLIST, rc, &m_wndShapeToolBar, 0);
  m_Combox.ShowWindow(SW_SHOWNORMAL);
  m_Combox.AddString("test1");
  m_Combox.AddString("test2");
  m_Combox.AddString("test3");



}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
  //分割视图  2行一列
  m_SplitterWnd1.CreateStatic(this, 2, 1);

  m_SplitterWnd1.CreateView(1,0, 
                            RUNTIME_CLASS(CEditView), 
                            CSize(100,100), 
                            pContext);

  m_SplitterWnd2.CreateStatic(&m_SplitterWnd1, 
                              1, 
                              2,
                              WS_CHILD | WS_VISIBLE, 
                              m_SplitterWnd1.IdFromRowCol(0, 0));
  m_SplitterWnd2.CreateView(0,0, 
                            RUNTIME_CLASS(CMyTree), 
                            CSize(200,100), 
                            pContext);
  m_SplitterWnd2.CreateView(0,1, 
                            pContext->m_pNewViewClass, 
                            CSize(200,100), 
                            pContext);
  m_SplitterWnd1.SetRowInfo(0, 500, 0);
  return TRUE;

	return CFrameWnd::OnCreateClient(lpcs, pContext);
}
