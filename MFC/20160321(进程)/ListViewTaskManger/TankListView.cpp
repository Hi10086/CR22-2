// TankListView.cpp : implementation file
//

#include "stdafx.h"
#include "ListViewTaskManger.h"
#include "TankListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTankListView

IMPLEMENT_DYNCREATE(CTaskListView, CListView)

CTaskListView::CTaskListView()
	:m_tree(GetListCtrl())
{

}

CTaskListView::~CTaskListView()
{
}


BEGIN_MESSAGE_MAP(CTaskListView, CListView)
	//{{AFX_MSG_MAP(CTankListView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTankListView drawing

void CTaskListView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CTankListView diagnostics

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
// CTankListView message handlers
