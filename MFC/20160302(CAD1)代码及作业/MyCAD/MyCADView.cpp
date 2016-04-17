// MyCADView.cpp : implementation of the CMyCADView class
//

#include "stdafx.h"
#include "MyCAD.h"

#include "MyCADDoc.h"
#include "MyCADView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyCADView

IMPLEMENT_DYNCREATE(CMyCADView, CView)

BEGIN_MESSAGE_MAP(CMyCADView, CView)
	//{{AFX_MSG_MAP(CMyCADView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CANCELMODE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyCADView construction/destruction

CMyCADView::CMyCADView()
{
	// TODO: add construction code here
	m_isdown = FALSE;
	m_pShape = NULL;
}

CMyCADView::~CMyCADView()
{
}

BOOL CMyCADView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyCADView drawing

void CMyCADView::OnDraw(CDC* pDC)
{
	CMyCADDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect rc;
	GetClientRect(rc);

	// TODO: add draw code for native data here
	CDC memDC;
	memDC.CreateCompatibleDC(pDC);

	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());

	memDC.SelectObject(bitmap);
	CBrush brush(RGB(255, 255, 255));
	memDC.FillRect(rc, &brush);
	
	memDC.SelectObject(::GetStockObject(NULL_BRUSH));

	POSITION pos = m_list.GetHeadPosition();
	while (pos)
	{
		CShape *shape = m_list.GetNext(pos);
		shape->OnDraw(&memDC);
	}
	
	if (m_pShape != NULL)
	{
		m_pShape->OnDraw(&memDC);
	}

	pDC->BitBlt(0, 0, rc.Width(), rc.Height(), &memDC, 0, 0, SRCCOPY);
}

/////////////////////////////////////////////////////////////////////////////
// CMyCADView printing

BOOL CMyCADView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyCADView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyCADView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyCADView diagnostics

#ifdef _DEBUG
void CMyCADView::AssertValid() const
{
	CView::AssertValid();
}

void CMyCADView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyCADDoc* CMyCADView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyCADDoc)));
	return (CMyCADDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyCADView message handlers

void CMyCADView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_pShape == NULL)
	{

		m_pShape = new CLine();

	}

	if (m_pShape != NULL) 
	{
		m_isdown = TRUE;
		m_pShape->OnButtonDown(nFlags, point);
	}
	CView::OnLButtonDown(nFlags, point);
}

void CMyCADView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_isdown)
	{
		m_pShape->OnButtonUp(nFlags, point);
		CClientDC dc(this);
		OnDraw(&dc);

		m_isdown = FALSE;
		m_list.AddTail(m_pShape);
		m_pShape = NULL;
	}
	CView::OnLButtonUp(nFlags, point);
}

void CMyCADView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_isdown)
	{
		m_pShape->OnMouseMove(nFlags, point);
		CClientDC dc(this);
		OnDraw(&dc);
	}
	CView::OnMouseMove(nFlags, point);
}

void CMyCADView::OnCancelMode() 
{
	CView::OnCancelMode();
	
	// TODO: Add your message handler code here	
}

