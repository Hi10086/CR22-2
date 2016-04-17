// uiView.cpp : implementation of the CUiView class
//

#include "stdafx.h"
#include "ui.h"

#include "uiDoc.h"
#include "uiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUiView

IMPLEMENT_DYNCREATE(CUiView, CView)

BEGIN_MESSAGE_MAP(CUiView, CView)
	//{{AFX_MSG_MAP(CUiView)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUiView construction/destruction

CUiView::CUiView()
{
	// TODO: add construction code here

}

CUiView::~CUiView()
{
}

BOOL CUiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CUiView drawing

void CUiView::OnDraw(CDC* pDC)
{
	CUiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CUiView printing

BOOL CUiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CUiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CUiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CUiView diagnostics

#ifdef _DEBUG
void CUiView::AssertValid() const
{
	CView::AssertValid();
}

void CUiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUiDoc* CUiView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUiDoc)));
	return (CUiDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUiView message handlers

void CUiView::OnButton1() 
{
	// TODO: Add your control notification handler code here
	INT N = 0;
}
