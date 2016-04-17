// MFCRegView.cpp : implementation of the CMFCRegView class
//

#include "stdafx.h"
#include "MFCReg.h"

#include "MFCRegDoc.h"
#include "MFCRegView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCRegView

IMPLEMENT_DYNCREATE(CMFCRegView, CView)

BEGIN_MESSAGE_MAP(CMFCRegView, CView)
	//{{AFX_MSG_MAP(CMFCRegView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCRegView construction/destruction

CMFCRegView::CMFCRegView()
{
	// TODO: add construction code here

}

CMFCRegView::~CMFCRegView()
{
}

BOOL CMFCRegView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMFCRegView drawing

void CMFCRegView::OnDraw(CDC* pDC)
{
	CMFCRegDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMFCRegView printing

BOOL CMFCRegView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCRegView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCRegView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMFCRegView diagnostics

#ifdef _DEBUG
void CMFCRegView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCRegView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCRegDoc* CMFCRegView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCRegDoc)));
	return (CMFCRegDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCRegView message handlers
