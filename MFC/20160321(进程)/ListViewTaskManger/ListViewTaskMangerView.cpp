// ListViewTaskMangerView.cpp : implementation of the CListViewTaskMangerView class
//

#include "stdafx.h"
#include "ListViewTaskManger.h"

#include "ListViewTaskMangerDoc.h"
#include "ListViewTaskMangerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListViewTaskMangerView

IMPLEMENT_DYNCREATE(CListViewTaskMangerView, CView)

BEGIN_MESSAGE_MAP(CListViewTaskMangerView, CView)
	//{{AFX_MSG_MAP(CListViewTaskMangerView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListViewTaskMangerView construction/destruction

CListViewTaskMangerView::CListViewTaskMangerView()
{
	// TODO: add construction code here

}

CListViewTaskMangerView::~CListViewTaskMangerView()
{
}

BOOL CListViewTaskMangerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CListViewTaskMangerView drawing

void CListViewTaskMangerView::OnDraw(CDC* pDC)
{
	CListViewTaskMangerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CListViewTaskMangerView printing

BOOL CListViewTaskMangerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CListViewTaskMangerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CListViewTaskMangerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CListViewTaskMangerView diagnostics

#ifdef _DEBUG
void CListViewTaskMangerView::AssertValid() const
{
	CView::AssertValid();
}

void CListViewTaskMangerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CListViewTaskMangerDoc* CListViewTaskMangerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CListViewTaskMangerDoc)));
	return (CListViewTaskMangerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CListViewTaskMangerView message handlers
