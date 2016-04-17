// CADView.cpp : implementation of the CCADView class
//

#include "stdafx.h"
#include "CAD.h"
#include "SettingDlg.h"
#include "CADDoc.h"
#include "CADView.h"
#include "Line.h"
#include "Rectangle.h"
#include "AddCommand.h"

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
	ON_COMMAND(IDM_SCREEN, OnScreen)
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
  CMyList<IShape*, IShape*>& m_Shapes = pDoc->m_Shapes;

	ASSERT_VALID(pDoc);

  CRect rc;
  GetClientRect(rc);

  //˫������
  //1.����һ���ڴ����dc
  CDC memDC;
  memDC.CreateCompatibleDC(pDC);

  //2.��������λͼ
  CBitmap bitmap;
  bitmap.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());

  //3.�ڴ�dcѡ��λͼ
  memDC.SelectObject(bitmap);
  CBrush brush(RGB(255, 255, 255));
  memDC.FillRect(rc, &brush);
  
  //4.����
  memDC.SelectObject(::GetStockObject(NULL_BRUSH));

  //��������
  POSITION pos = m_Shapes.GetHeadPosition();
  while(pos)
  {
    IShape *pShape = m_Shapes.GetNext(pos);
    if (pShape == m_pSelectShape)
      pShape->OnDrawSelect(&memDC);
    else
      pShape->OnDraw(&memDC);
  }
  
  //���Ƶ�ǰ��ͼ��
  if (m_pCurShape != NULL)
    m_pCurShape->OnDraw(&memDC);

 //5.������Ϣ��DC
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
//   //˫������
//   //1.����һ���ڴ����dc
//   CDC memDC;
//   memDC.CreateCompatibleDC(pDC);
// 
//   //2.��������λͼ
//   CBitmap bitmap;
//   bitmap.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
// 
//   //3.�ڴ�dcѡ��λͼ
//   memDC.SelectObject(bitmap);
//   CBrush brush(RGB(255, 255, 255));
//   memDC.FillRect(rc, &brush);
//   
//   //4.����
//   memDC.SelectObject(::GetStockObject(NULL_BRUSH));
// 
//   //��������
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
//   //���Ƶ�ǰ��ͼ��
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
//  //5.������Ϣ��DC
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

  //m_Type = SHAPE_LINE;
  //m_pCurShape = new CLine();
  
  //����ֱ��
  //::MoveToEx();
  //::LineTo();
//   CClientDC dc(this);
// 
//   dc.MoveTo(0, 0);
//   dc.LineTo(100, 100);
}

//���๤�����ģʽ
IShape* MyCreateObject(enum TYPE type)
{
  return NULL;
//     switch(type)
//     {
//     case SHAPE_LINE:
//       return new CLine();
//       break;
//     case SHAPE_RECT:
//       return new CRectangle();
//       break;
//     }
}

void CCADView::OnLButtonDown(UINT nFlags, CPoint point) 
{
  CMyList<IShape*, IShape*>& m_Shapes = GetDocument()->m_Shapes;
  if (m_isSelect)
  {
    //��������
    POSITION pos = m_Shapes.GetTailPosition();
    while(pos)
    {
      IShape *pShape = m_Shapes.GetPrev(pos);
      if (pShape->IsSelect(point))
      {
        m_pSelectShape = pShape;
        CClientDC dc(this);
        OnDraw(&dc);
        break;
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
    SetCapture();  //��Ӧ��������Ϣ
  }

	CView::OnLButtonDown(nFlags, point);
}

void CCADView::OnLButtonUp(UINT nFlags, CPoint point) 
{
  CMyList<IShape*, IShape*>& m_Shapes = GetDocument()->m_Shapes;

  if (m_isDown)
  {
    m_pCurShape->OnLButtonUp(nFlags, point);

    CClientDC dc(this);
    OnDraw(&dc);
    m_isDown = FALSE;

    //����ͼ��
    m_Shapes.AddTail(m_pCurShape);
    ReleaseCapture(); //�ͷ�

    //��¼��־
    m_CmdMgr.InsertCommand(new CAddCommand(m_pCurShape, m_Shapes));

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
  //m_Type = SHAPE_RECT;
  m_pClassFactory = new CRectangleFactory();
  m_isSelect = FALSE;
  m_pSelectShape = NULL;
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
}

void CCADView::OnRButtonDown(UINT nFlags, CPoint point) 
{
  if (m_pSelectShape != NULL)
  {
    //�����˵�
    CMenu menu;
    menu.LoadMenu(IDR_MENU1);

    //��ȡ�Ӳ˵�
    CMenu *pSubMenu = menu.GetSubMenu(0);

    //ת������
    //ScreenToClient(&point);
    ClientToScreen(&point);
    //CPoint pt;
    //GetCursorPos(&pt);  //��ȡ�����������

    //�����˵�
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
    m_pSelectShape->SetPen(dlg.GetPen());
  }

  //�ػ�
  CClientDC dc(this);
  OnDraw(&dc);
}

void CCADView::OnScreen() 
{
  CRect rc;
  GetClientRect(&rc);

  //��ͼ
  HWND hDesk = ::GetDesktopWindow();
  HDC hdc = ::GetDC(hDesk);
  CDC dc1;
  dc1.Attach(hdc);

  CClientDC dc(this);
  dc.BitBlt(0, 0, rc.Width(), rc.Height(), &dc1, 0, 0, NOTSRCCOPY);
  //dc.StretchBlt(0, 0, rc.Width(), rc.Height(), &dc1, 0, 0, 1280, 768, SRCCOPY);

  //˫������
  //1.����һ���ڴ����dc
  CDC memDC;
  memDC.CreateCompatibleDC(&dc1);
  
  //2.��������λͼ
  CBitmap bitmap;
  bitmap.CreateCompatibleBitmap(&dc1, rc.Width(), rc.Height());
  
  //3.�ڴ�dcѡ��λͼ
  memDC.SelectObject(bitmap);

  memDC.BitBlt(0, 0, 1280, 768, &dc1, 0, 0, SRCCOPY);
  
  //bitmap.GetBitmapBits();

  dc1.Detach();
}

void CCADView::OnEditUndo() 
{
  m_CmdMgr.Undo();

  CClientDC dc(this);
  OnDraw(&dc);
}

void CCADView::OnEditRedo() 
{
  m_CmdMgr.Redo();

  CClientDC dc(this);
  OnDraw(&dc);
}
