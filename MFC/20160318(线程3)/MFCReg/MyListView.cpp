// MyListView.cpp : implementation file
//

#include "stdafx.h"
#include "MFCReg.h"
#include "MyListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyListView

IMPLEMENT_DYNCREATE(CMyListView, CListView)

CMyListView::CMyListView()
:m_tree(GetListCtrl())
{
}

CMyListView::~CMyListView()
{
}


BEGIN_MESSAGE_MAP(CMyListView, CListView)
//{{AFX_MSG_MAP(CMyListView)
ON_NOTIFY_REFLECT(HDN_ITEMCHANGED, OnItemchanged)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyListView drawing

void CMyListView::OnDraw(CDC* pDC)
{
	CMFCRegDoc* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CMyListView diagnostics

#ifdef _DEBUG
void CMyListView::AssertValid() const
{
	CListView::AssertValid();
}

void CMyListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyListView message handlers

void CMyListView::OnInitialUpdate() 
{
	::SetWindowLong(m_tree.GetSafeHwnd(), GWL_STYLE, 0x52018A41); 
	m_tree.InsertColumn( 0, "名称", LVCFMT_LEFT, 100 );
	m_tree.InsertColumn( 1, "类型", LVCFMT_LEFT, 100 );
	m_tree.InsertColumn( 2, "数据", LVCFMT_LEFT, 100 );
	CListView::OnInitialUpdate();	
	// TODO: Add your specialized code here and/or call the base class	
}

CMFCRegDoc* CMyListView::GetDocument()
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCRegDoc)));
	return (CMFCRegDoc*)m_pDocument;
}

void CMyListView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	CMFCRegDoc* pDoc = GetDocument();
	char szName[MAX_PATH];
	char szComName[MAX_PATH];
	unsigned long uNamesize= MAX_PATH;
	unsigned long uComNamesize= MAX_PATH;
	DWORD dwType;
	BYTE bDate;
	LONG ret1;
	m_tree.DeleteAllItems();
				m_tree.InsertItem(0, "(默认)");
				m_tree.SetItemText(0, 1, "MEG_SZ");
				m_tree.SetItemText(0, 2, "数值未更新");
	
				HKEY hRootKey = pDoc->m_hKey;
				CString szPath = pDoc->m_szPath;
				HKEY hChildKey;
				DWORD dwValues = 0;
				DWORD dwNumValue = 0;
	if (ERROR_SUCCESS != ::RegOpenKey(hRootKey, szPath, &hChildKey))
	{
		return;
	}
	if (ERROR_SUCCESS != ::RegQueryInfoKey(hRootKey, NULL, NULL, NULL, &dwValues, NULL, NULL, 
		&dwNumValue, NULL, NULL, NULL, NULL))
	{
		return;
	}
	

				if (dwNumValue)
				{
					for (DWORD i = 0; (ret1 = RegEnumValue(hRootKey, i, szName, &uNamesize,\
						NULL, &dwType, (unsigned char *)szComName, &uComNamesize)) != ERROR_NO_MORE_ITEMS; i++) 
					{
						if ( ERROR_SUCCESS == ret1)
						{
							m_tree.InsertItem(i, szName);
							switch(dwType)
							{
							case REG_SZ:
								m_tree.SetItemText(i, 1, "REG_SZ");
								break;
							case REG_DWORD:
								m_tree.SetItemText(i, 1, "REG_DWORD");
								break;
							}
							m_tree.SetItemText(i, 2, szComName);
						}
					}
				}
				
				CClientDC dc(this);
				OnDraw(&dc);	
}

void CMyListView::OnItemchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;
	// TODO: Add your control notification handler code here
	int a = 0;
	*pResult = 0;
}
