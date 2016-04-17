// SigView.cpp : implementation of the CSigView class
//

#include "stdafx.h"
#include "Sig.h"

#include "SigDoc.h"
#include "SigView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSigView

IMPLEMENT_DYNCREATE(CSigView, CView)

BEGIN_MESSAGE_MAP(CSigView, CView)
	//{{AFX_MSG_MAP(CSigView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSigView construction/destruction

CSigView::CSigView()
{
	// TODO: add construction code here

}

CSigView::~CSigView()
{
}

BOOL CSigView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSigView drawing

void CSigView::OnDraw(CDC* pDC)
{
	CSigDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSigView printing

BOOL CSigView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSigView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSigView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSigView diagnostics

#ifdef _DEBUG
void CSigView::AssertValid() const
{
	CView::AssertValid();
}

void CSigView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSigDoc* CSigView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSigDoc)));
	return (CSigDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSigView message handlers
