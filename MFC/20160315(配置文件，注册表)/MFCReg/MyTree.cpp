// MyTree.cpp : implementation file
//

#include "stdafx.h"
#include "MFCReg.h"
#include "MyTree.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyTree

IMPLEMENT_DYNCREATE(CMyTree, CTreeView)

CMyTree::CMyTree()
{
}

CMyTree::~CMyTree()
{
}


BEGIN_MESSAGE_MAP(CMyTree, CTreeView)
	//{{AFX_MSG_MAP(CMyTree)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTree drawing

void CMyTree::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CMyTree diagnostics

#ifdef _DEBUG
void CMyTree::AssertValid() const
{
	CTreeView::AssertValid();
}

void CMyTree::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyTree message handlers

void CMyTree::OnInitialUpdate() 
{
	CTreeCtrl& tree = GetTreeCtrl();
	::SetWindowLong(tree.GetSafeHwnd(), GWL_STYLE, 0x50010007);  
	CString str1("");

	HTREEITEM hRoot = tree.InsertItem("HKEY_CURRENT_CONFIG");	
	LayerQuery(tree, hRoot, HKEY_CURRENT_CONFIG, str1);

// 	HTREEITEM hRoot = tree.InsertItem("HKEY_CLASSES_ROOT");	
// 	LayerQuery(tree, hRoot, HKEY_CLASSES_ROOT, str1);

// 	hRoot = tree.InsertItem("HKEY_CURRENT_USER");	
// 	LayerQuery(hRoot, HKEY_CURRENT_USER, str1);
// 
// 	hRoot = tree.InsertItem("HKEY_LOCAL_MACHINE");	
// 	LayerQuery(hRoot, HKEY_LOCAL_MACHINE, str1);
// 

}

void CMyTree::LayerQuery(CTreeCtrl& tree, HTREEITEM hRoot, HKEY hRootKey, CString szPath)
{
	CList<CString, CString> stack_c;
	CList<HTREEITEM, HTREEITEM> stack_h;
	CList<HKEY, HKEY> stack_k;

	HKEY hChildKey;
	DWORD dwValues;
	CHAR  szValueName[MAXBYTE];
	DWORD dwValueSize = sizeof(szValueName);
	CString szNewPath;	

	while (TRUE)
	{
		::RegOpenKey(hRootKey, szPath, &hChildKey);
		::RegQueryInfoKey(hRootKey, NULL, NULL, NULL, &dwValues, NULL, NULL, 
		NULL, NULL, NULL, NULL, NULL);

		for (DWORD i = 0; i < dwValues; i++)
		{
			szValueName[0] = '\0';
			DWORD dwValueSize = sizeof(szValueName);

			if (ERROR_SUCCESS == ::RegEnumKeyEx(hChildKey, i, szValueName, &dwValueSize, NULL, 
				NULL, NULL, NULL))
			{
				HTREEITEM hNewRoot = tree.InsertItem(szValueName, hRoot);
				if (szPath == "")
				{
					szNewPath = szValueName;
				}else
				{
					szNewPath = szPath + "\\" + szValueName;
				}
				stack_c.AddHead(szNewPath);
				stack_h.AddHead(hNewRoot);
				stack_k.AddHead(hChildKey);
			}
		}

		if (stack_c.IsEmpty())
		{
			break;
		}

		szPath = stack_c.GetHead();
		hRoot = stack_h.GetHead();
		hRootKey = stack_k.GetHead();

		stack_c.RemoveHead();
		stack_h.RemoveHead();
		stack_k.RemoveHead();
	}
}
