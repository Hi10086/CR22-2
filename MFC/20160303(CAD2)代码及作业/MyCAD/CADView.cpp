// CADView.cpp : implementation of the CCADView class
//

#include "stdafx.h"
#include "CAD.h"
#include "SettingDlg.h"
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
	ON_COMMAND(IDM_SETTING, OnSetting)
	ON_COMMAND(IDM_SELECT, OnSelect)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(IDM_EDIT, OnEdit)
	ON_COMMAND(ID_MENU_DELITE, OnMenuDelite)
	ON_COMMAND(ID_MENU_MOVE, OnMenuMove)
	ON_COMMAND(ID_MENU_COPY, OnMenuCopy)
	ON_COMMAND(ID_MENU_PASTE, OnMenuPaste)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_COMMAND(ID_EDIT_REDO, OnEditRedo)
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
  m_pClassFactory =  NULL;
  m_isSelect = FALSE;
  m_pSelectShape = NULL;
  m_isMoving = FALSE;
  m_isEdit = FALSE;
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
    if (pShape == m_pSelectShape)
      pShape->OnDrawSelect(&memDC);
    else
      pShape->OnDraw(&memDC);
  }
  
  //绘制当前的图形
  if (m_pCurShape != NULL)
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
	m_pClassFactory = new CLineFactory();
	m_isSelect = FALSE;
	m_pSelectShape = NULL;
    m_isEdit = FALSE;

  //m_Type = SHAPE_LINE;
  //m_pCurShape = new CLine();
  
  //绘制直线
  //::MoveToEx();
  //::LineTo();
//   CClientDC dc(this);
// 
//   dc.MoveTo(0, 0);
//   dc.LineTo(100, 100);
}

//简单类工厂设计模式
IShape* MyCreateObject(enum TYPE type)
{
  return NULL;
}

void CCADView::OnLButtonDown(UINT nFlags, CPoint point) 
{
  if (m_isSelect || m_isMoving)
  {
    //遍历链表
    POSITION pos = m_Shapes.GetTailPosition();
    while(pos)
    {
      IShape *pShape = m_Shapes.GetPrev(pos);
      if (pShape->IsSelect(point))
      {
        m_pSelectShape = pShape;
        CClientDC dc(this);
        OnDraw(&dc);
        return;
      } 
    }

    return;
  }
  

  if (m_pClassFactory == NULL)
    return;

  if (m_pCurShape == NULL)
  {
    m_pCurShape = m_pClassFactory->CreateObject();
    if (m_pCurShape == NULL)
      return;

    m_pCurShape->SetPen(m_pen);
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

	if (m_isMoving)
	{
		m_isMoving = FALSE;
		m_isSelect = FALSE;
		m_pSelectShape = NULL;
		m_isDown = FALSE;
	}

  if (m_isDown)
  {
    m_pCurShape->OnLButtonUp(nFlags, point);
    m_isDown = FALSE;

    //保存图形
    m_Shapes.AddTail(m_pCurShape);
	m_Undo.AddHead(m_pCurShape);
    ReleaseCapture(); //释放

    m_pCurShape = NULL;
  }
	CClientDC dc(this);
    OnDraw(&dc);

	CView::OnLButtonUp(nFlags, point);
}

void CCADView::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (m_isSelect == TRUE && m_pSelectShape != NULL && m_isMoving == TRUE)
	{
		m_pSelectShape->ShapeMove(nFlags, point);
	}

	if (m_isDown)
	{
		m_pCurShape->OnMouseMove(nFlags, point);
	}

	CClientDC dc(this);
	OnDraw(&dc);
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
  //m_Type = SHAPE_RECT;
  m_pClassFactory = new CRectangleFactory();
  m_isSelect = FALSE;
  m_pSelectShape = NULL;
    m_isEdit = FALSE;
}

void CCADView::OnSetting() 
{
  CSettingDlg dlg;
  dlg.SetPen(m_pen);
  if (dlg.DoModal() == IDOK)
  {
    m_pen = dlg.GetPen();
  }
}

void CCADView::OnSelect() 
{
  m_isSelect = TRUE;
  m_isEdit = FALSE;
}

void CCADView::OnRButtonDown(UINT nFlags, CPoint point) 
{
  if (m_pSelectShape != NULL)
  {
    //弹出菜单
    CMenu menu;
    menu.LoadMenu(IDR_MENU1);

    //获取子菜单
    CMenu *pSubMenu = menu.GetSubMenu(0);

    //转换坐标
    //ScreenToClient(&point);
    ClientToScreen(&point);
    //CPoint pt;
    //GetCursorPos(&pt);  //获取光标桌边坐标

    //弹出菜单
    pSubMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
  }
	CView::OnRButtonDown(nFlags, point);
}

void CCADView::OnEdit() 
{
  CSettingDlg dlg;
  dlg.SetPen(m_pSelectShape->GetPen());
  if (dlg.DoModal() == IDOK)
  {
	  m_isEdit = TRUE;
	  IShape *old = m_pSelectShape->OnCopy();
	  m_Redo.AddHead(old);
	  m_pSelectShape->SetPen(dlg.GetPen());
	  m_Undo.AddHead(m_pSelectShape);
  }

  //重绘
  CClientDC dc(this);
  OnDraw(&dc);
}

// 删除
void CCADView::OnMenuDelite() 
{
	// TODO: Add your command handler code here
	//遍历链表
	POSITION pos = m_Shapes.GetHeadPosition();
	while(pos)
	{
		IShape *pShape = m_Shapes.GetAt(pos);
		if (pShape == m_pSelectShape)
		{
			m_Shapes.RemoveAt(pos);
			break;
		}
		++pos;
	}

	delete m_pSelectShape;
	m_pSelectShape = m_pCurShape = NULL;
	CClientDC dc(this);
	OnDraw(&dc);
}

void CCADView::OnMenuMove() 
{
	// TODO: Add your command handler code here
	m_isMoving = TRUE;
}

void CCADView::OnMenuCopy() 
{
	// TODO: Add your command handler code here 
	m_pSelectShape = m_pSelectShape->OnCopy();
	m_Shapes.AddTail(m_pSelectShape);
	OnMenuMove();
}

void CCADView::OnMenuPaste() 
{
	// TODO: Add your command handler code here
	OnMenuCopy();
	CClientDC dc(this);
	OnDraw(&dc);
}

void CCADView::OnMenuUndo() 
{
	// TODO: Add your command handler code here
}

void CCADView::OnEditUndo() 
{
	if (m_Undo.IsEmpty())
	{
		return;
	}
	// TODO: Add your command handler code here
	IShape *temp = 	m_Undo.GetHead();
	if (temp != NULL)
	{
		POSITION pos = m_Shapes.GetHeadPosition();
		while(pos)
		{
			POSITION CurPos = pos;
			IShape *pShape = m_Shapes.GetNext(pos);
			if (pShape == temp)
			{

				m_Shapes.RemoveAt(CurPos);
				m_Undo.RemoveHead();
				if (m_isEdit)
				{
					m_Shapes.AddTail(m_Redo.GetHead());
				}
				m_Redo.AddHead(temp);
				break;
			}
		}
		CClientDC dc(this);
		OnDraw(&dc);
	}
}

void CCADView::OnEditRedo() 
{
	// TODO: Add your command handler code here
	if (m_Redo.IsEmpty())
	{
		return;
	}
	IShape *temp = 	m_Redo.GetHead();
	if (temp != NULL)
	{
		m_Shapes.AddTail(temp);
		m_Undo.AddHead(temp);
		m_Redo.RemoveHead();
		CClientDC dc(this);
		OnDraw(&dc);
	}
}
