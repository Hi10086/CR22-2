// CADView.cpp : implementation of the CCADView class
//

#include "stdafx.h"
#include "CAD.h"

#include "CADDoc.h"
#include "CADView.h"
#include "Line.h"
#include "Rectangle.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCADView

IMPLEMENT_DYNCREATE(CCADView, CView)

BEGIN_MESSAGE_MAP(CCADView, CView)
	//{{AFX_MSG_MAP(CCADView)
	ON_COMMAND(IDM_LINE, OnLine)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CANCELMODE()
	ON_COMMAND(IDM_RECT, OnRect)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCADView construction/destruction

CCADView::CCADView()
{
	// TODO: add construction code here
  m_isDown = FALSE;
  m_pCurShape = NULL;
  m_Type = SHAPE_UNKNOWN;
}

CCADView::~CCADView()
{
}

BOOL CCADView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCADView drawing
void CCADView::OnDraw(CDC* pDC)
{
	CCADDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

  CRect rc;
  GetClientRect(rc);

  //双缓冲区
  //1.创建一个内存兼容dc
  CDC memDC;
  memDC.CreateCompatibleDC(pDC);

  //2.创建兼容位图
  CBitmap bitmap;
  bitmap.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());

  //3.内存dc选择位图
  memDC.SelectObject(bitmap);
  CBrush brush(RGB(255, 255, 255));
  memDC.FillRect(rc, &brush);
  
  //4.绘制
  memDC.SelectObject(::GetStockObject(NULL_BRUSH));

  //遍历链表
  POSITION pos = m_Shapes.GetHeadPosition();
  while(pos)
  {
    IShape *pShape = m_Shapes.GetNext(pos);
    pShape->OnDraw(&memDC);
  }
  
  //绘制当前的图形
  m_pCurShape->OnDraw(&memDC);

 //5.复制信息到DC
  pDC->BitBlt(0, 0, rc.Width(), rc.Height(), &memDC, 0, 0, SRCCOPY);
}

void CCADView::OnDrawOld(CDC* pDC)
{
// 	CCADDoc* pDoc = GetDocument();
// 	ASSERT_VALID(pDoc);
// 
//   CRect rc;
//   GetClientRect(rc);
// 
//   //双缓冲区
//   //1.创建一个内存兼容dc
//   CDC memDC;
//   memDC.CreateCompatibleDC(pDC);
// 
//   //2.创建兼容位图
//   CBitmap bitmap;
//   bitmap.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
// 
//   //3.内存dc选择位图
//   memDC.SelectObject(bitmap);
//   CBrush brush(RGB(255, 255, 255));
//   memDC.FillRect(rc, &brush);
//   
//   //4.绘制
//   memDC.SelectObject(::GetStockObject(NULL_BRUSH));
// 
//   //遍历链表
//   POSITION pos = m_Shapes.GetHeadPosition();
//   while(pos)
//   {
//     tagShape Shape = m_Shapes.GetNext(pos);
//     switch(Shape.m_Type)
//     {
//     case SHAPE_LINE:
//       {
//         memDC.MoveTo(Shape.m_ptBegin);
//         memDC.LineTo(Shape.m_ptEnd);
//       }
//       break;
//     case SHAPE_RECT:
//       {
//         memDC.Rectangle(Shape.m_ptBegin.x, Shape.m_ptBegin.y, 
//                         Shape.m_ptEnd.x, Shape.m_ptEnd.y);
//       }
//       break;
//     }
//   }
//   
//   //绘制当前的图形
//   switch(m_CurShape.m_Type)
//   {
//   case SHAPE_LINE:
//     {
//       memDC.MoveTo(m_CurShape.m_ptBegin);
//       memDC.LineTo(m_CurShape.m_ptEnd);
//     }
//     break;
//   case SHAPE_RECT:
//     {
//       memDC.Rectangle(m_CurShape.m_ptBegin.x, m_CurShape.m_ptBegin.y, 
//         m_CurShape.m_ptEnd.x, m_CurShape.m_ptEnd.y);
//     }
//     break;
//   }
// 
//  //5.复制信息到DC
//   pDC->BitBlt(0, 0, rc.Width(), rc.Height(), &memDC, 0, 0, SRCCOPY);
}

/////////////////////////////////////////////////////////////////////////////
// CCADView printing

BOOL CCADView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCADView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCADView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCADView diagnostics

#ifdef _DEBUG
void CCADView::AssertValid() const
{
	CView::AssertValid();
}

void CCADView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCADDoc* CCADView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCADDoc)));
	return (CCADDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCADView message handlers

void CCADView::OnLine() 
{
  m_Type = SHAPE_LINE;
  //m_pCurShape = new CLine();
  
  //绘制直线
  //::MoveToEx();
  //::LineTo();
//   CClientDC dc(this);
// 
//   dc.MoveTo(0, 0);
//   dc.LineTo(100, 100);
}

void CCADView::OnLButtonDown(UINT nFlags, CPoint point) 
{
  if (m_pCurShape == NULL)
  {
    switch(m_Type)
    {
    case SHAPE_LINE:
      m_pCurShape = new CLine();
      break;
    case SHAPE_RECT:
      m_pCurShape = new CRectangle();
      break;
    }
  }


  if (m_pCurShape != NULL)
  {
    m_pCurShape->OnLButtonDown(nFlags, point);
    m_isDown = TRUE;
    SetCapture();  //响应窗口外消息
  }

	CView::OnLButtonDown(nFlags, point);
}

void CCADView::OnLButtonUp(UINT nFlags, CPoint point) 
{
  if (m_isDown)
  {
    m_pCurShape->OnLButtonUp(nFlags, point);

    CClientDC dc(this);
    OnDraw(&dc);
    m_isDown = FALSE;

    //保存图形
    m_Shapes.AddTail(m_pCurShape);
    ReleaseCapture(); //释放

    m_pCurShape = NULL;
  }


	CView::OnLButtonUp(nFlags, point);
}

void CCADView::OnMouseMove(UINT nFlags, CPoint point) 
{
  if (m_isDown)
  {
    m_pCurShape->OnMouseMove(nFlags, point);
    CClientDC dc(this);
    OnDraw(&dc);
  }

	CView::OnMouseMove(nFlags, point);
}

void CCADView::OnCancelMode() 
{
	CView::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CCADView::OnRect() 
{
  //m_pCurShape = new CRectangle();
  m_Type = SHAPE_RECT;
}
