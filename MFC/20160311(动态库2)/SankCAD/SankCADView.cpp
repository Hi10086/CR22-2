// SankCADView.cpp : implementation of the CSankCADView class
//

#include "stdafx.h"
#include "SankCAD.h"

#include "SankCADDoc.h"
#include "SankCADView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSankCADView

IMPLEMENT_DYNCREATE(CSankCADView, CView)

BEGIN_MESSAGE_MAP(CSankCADView, CView)
	//{{AFX_MSG_MAP(CSankCADView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_TOOL_LINE, OnToolLine)
	ON_COMMAND(ID_TOOL_POLYGON, OnToolPolygon)
	ON_COMMAND(ID_EDIT_SELECT, OnEditSelect)
	ON_COMMAND(ID_RIGHT_MOVE, OnRightMove)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_COMMAND(ID_EDIT_REDO, OnEditRedo)
	ON_COMMAND(ID_RIGHT_COPY, OnRightCopy)
	ON_COMMAND(ID_RIGHT_PATES, OnRightPates)
	ON_COMMAND(ID_RIGHT_DEL, OnRightDel)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSankCADView construction/destruction

CSankCADView::CSankCADView()
{
	
	// TODO: add construction code here
	m_SelectShape = m_CurShape = NULL;
	m_Factory = NULL;
	m_isCopy = m_isMoving = m_isSelect = FALSE;
	m_pCommand = NULL;

	HMODULE hModule = LoadLibrary("../ShapeDll/Debug/ShapeDll.dll");
	if (hModule == NULL)
	{
		AfxMessageBox("LoadLibrary");
	}
}

CSankCADView::~CSankCADView()
{

}

BOOL CSankCADView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSankCADView drawing

void CSankCADView::OnDraw(CDC* pDC)
{
	CSankCADDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CMyList<IShape *, IShape *>& m_ShapeList = pDoc->m_ShapeList;

	CRect rc;
	GetClientRect(rc);

	CDC memDC;
	memDC.CreateCompatibleDC(pDC);

	CBitmap bitmap;
	bitmap.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());

	memDC.SelectObject(bitmap);
	CBrush brush(RGB(255, 255, 255));
	memDC.FillRect(rc, &brush);
	memDC.SelectObject(::GetStockObject(NULL_BRUSH));

	POSITION pos = m_ShapeList.GetHeadPosition();
	while (pos)
	{
		IShape *pShape = m_ShapeList.GetNext(pos);
		if (pShape == m_SelectShape)
		{
			pShape->OnDrawSelect(&memDC);
		}
		else
		{
			pShape->OnDraw(&memDC);
		}
	}

	if (m_CurShape != NULL)
	{
		m_CurShape->OnDraw(&memDC);
	}

	pDC->BitBlt(0, 0, rc.Width(), rc.Height(), &memDC, 0, 0, SRCCOPY);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CSankCADView printing

BOOL CSankCADView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSankCADView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSankCADView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSankCADView diagnostics

#ifdef _DEBUG
void CSankCADView::AssertValid() const
{
	CView::AssertValid();
}

void CSankCADView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSankCADDoc* CSankCADView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSankCADDoc)));
	return (CSankCADDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSankCADView message handlers

void CSankCADView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CSankCADDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CMyList<IShape *, IShape *>& m_ShapeList = pDoc->m_ShapeList;

	if (m_isMoving)
	{
		m_CommandMrg.AddCommand(new MoveCommand(m_SelectShape ,m_OldDate, &m_ShapeList));
		m_isMoving = FALSE;
		m_SelectShape = NULL;
		//m_isSelect = FALSE;
		return;
	}

	if (m_isSelect)
	{
		POSITION pos = m_ShapeList.GetHeadPosition();
		while (pos)
		{
			IShape *pShape = m_ShapeList.GetNext(pos);
			if (pShape->IsSelect(nFlags, point))
			{
				m_SelectShape = pShape;
				m_OldDate = m_SelectShape->GetData();
				CClientDC dc(this);
				OnDraw(&dc);
				break;
			}
		}
		return;
	}

	// TODO: Add your message handler code here and/or call default
	if (m_Factory != NULL && m_CurShape == NULL)
	{
		m_CurShape = m_Factory->CreateShape();
	}

	if (m_CurShape != NULL)
	{
		m_CurShape->OnButtonDown(nFlags, point);
	}

	CView::OnLButtonDown(nFlags, point);
}

void CSankCADView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CSankCADDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CMyList<IShape *, IShape *>& m_ShapeList = pDoc->m_ShapeList;

	if (m_CurShape == NULL)
	{
		return;
	}

	if (m_CurShape->OnButtonUp(nFlags, point) == 0)
	{
		m_ShapeList.AddTail(m_CurShape);
		m_CommandMrg.AddCommand(new AddCommand(m_CurShape, &m_ShapeList));
		m_CurShape = NULL;
	}
	
	CClientDC dc(this);
	OnDraw(&dc);
	CView::OnLButtonUp(nFlags, point);
}

void CSankCADView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_isCopy)
	{		
		m_SelectShape->OnMove(nFlags, point);
		return;
	}
	if (m_isMoving)
	{
		m_SelectShape->OnMove(nFlags, point);
		CClientDC dc(this);
		OnDraw(&dc);
		return;
	}

	else if (m_CurShape != NULL)
	{
		m_CurShape->OnMouseMove(nFlags, point);
		
		CClientDC dc(this);
		OnDraw(&dc);
	}

	CView::OnMouseMove(nFlags, point);
}

void CSankCADView::OnToolLine() 
{
	// TODO: Add your command handler code here
	m_Factory = new CLineFactory();
	m_isCopy = m_isMoving = m_isSelect = FALSE;
}

void CSankCADView::OnToolPolygon() 
{
	m_Factory = new CPolyFactory();
	m_isCopy = m_isMoving = m_isSelect = FALSE;
}

void CSankCADView::OnEditSelect() 
{
	// TODO: Add your command handler code here
	m_isSelect = TRUE;
}

void CSankCADView::OnRightMove() 
{
	m_isMoving = TRUE;
	m_isCopy = FALSE;
}

void CSankCADView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_SelectShape != NULL)
	{
		CMenu menu;
		menu.LoadMenu(IDR_MENU1);		
		//获取子菜单
		CMenu *pSubMenu = menu.GetSubMenu(0);
		ClientToScreen(&point);		
		//弹出菜单
		pSubMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
  }	CView::OnRButtonDown(nFlags, point);
}

void CSankCADView::OnEditUndo() 
{
	// TODO: Add your command handler code here
	m_CommandMrg.Undo();
	
	CClientDC dc(this);
	OnDraw(&dc);
}

void CSankCADView::OnEditRedo() 
{
	// TODO: Add your command handler code here
	m_pCommand = m_CommandMrg.Redo();
	
	CClientDC dc(this);
	OnDraw(&dc);
}

void CSankCADView::OnRightCopy() 
{
	// TODO: Add your command handler code here
	m_SelectShape = m_SelectShape->OnCopy();
	m_isCopy = TRUE;
}

void CSankCADView::OnRightPates() 
{
	CSankCADDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CMyList<IShape *, IShape *>& m_ShapeList = pDoc->m_ShapeList;

	m_isCopy = FALSE;
	m_ShapeList.AddTail(m_SelectShape);

	CClientDC dc(this);
	OnDraw(&dc);
	OnRightCopy();
}

void CSankCADView::OnRightDel() 
{
	// TODO: Add your command handler code here
	CSankCADDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CMyList<IShape *, IShape *>& m_ShapeList = pDoc->m_ShapeList;

	POSITION pos = m_ShapeList.Find(m_SelectShape);
	m_ShapeList.RemoveAt(pos);
	
	m_CommandMrg.AddCommand(new DelCommand(m_SelectShape, &m_ShapeList));
	m_SelectShape = NULL;

	CClientDC dc(this);
	OnDraw(&dc);
}

BOOL CSankCADView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}
