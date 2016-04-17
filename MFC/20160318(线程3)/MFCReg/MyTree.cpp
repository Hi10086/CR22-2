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
	:m_tree(GetTreeCtrl())
{
	m_hKey = NULL;
	m_hItem = NULL;
	m_dwValues = 0;
	m_hChildKey = NULL;
}

CMyTree::~CMyTree()
{
}


BEGIN_MESSAGE_MAP(CMyTree, CTreeView)
	//{{AFX_MSG_MAP(CMyTree)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDING, OnItemexpanding)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED, OnItemexpanded)
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
/*	TVS_HASBUTTONS*/
 	::SetWindowLong(m_tree.GetSafeHwnd(), GWL_STYLE, 0x5031001F);  
	InitReg();
}

void CMyTree::InitReg()
{
	HKEY hChildKey;
	CString szPath;

// 	HTREEITEM hRoot = m_tree.InsertItem("HKEY_CLASSES_ROOT");
// 	::RegOpenKey(HKEY_CLASSES_ROOT, szPath, &hChildKey);	
// 	m_tree.SetItemData(hRoot, (unsigned long)HKEY_CLASSES_ROOT);
// 	RegCloseKey(hChildKey);
// 	QueryRegKey(hRoot, HKEY_CLASSES_ROOT,"");
// 
// 	hRoot = m_tree.InsertItem("HKEY_CURRENT_USER");
// 	::RegOpenKey(HKEY_CURRENT_USER, szPath, &hChildKey);	
// 	m_tree.SetItemData(hRoot, (unsigned long)HKEY_CURRENT_USER);
// 	RegCloseKey(hChildKey);
// 	QueryRegKey(hRoot, HKEY_CURRENT_USER,"");
// 
// 	hRoot = m_tree.InsertItem("HKEY_LOCAL_MACHINE");
// 	::RegOpenKey(HKEY_LOCAL_MACHINE, NULL, &hChildKey);	
// 	m_tree.SetItemData(hRoot, (unsigned long)HKEY_LOCAL_MACHINE);
// 	RegCloseKey(hChildKey);

	HTREEITEM hRoot = m_tree.InsertItem("HKEY_CURRENT_CONFIG");
	::RegOpenKey(HKEY_CURRENT_CONFIG, szPath, &hChildKey);
	CString *pName = new CString("HKEY_CURRENT_CONFIG");
	m_tree.SetItemData(hRoot, (DWORD)pName);
	RegCloseKey(hChildKey);
	QueryRegKey(hRoot, HKEY_CURRENT_CONFIG,"");
}


UINT AFX_CDECL ThreadProc(LPVOID lpParam)
{
	CMyTree *lpTree = (CMyTree*)lpParam;
	HKEY hKey = lpTree->m_hKey;
	CString szPath = lpTree->m_szPath;
	HTREEITEM hItem = lpTree->m_hItem;

	HKEY hChildKey;
	DWORD dwValues;
	CHAR  szValueName[MAXBYTE];
	DWORD dwValueSize = MAXBYTE;
	DWORD dwNumValue;


	::RegOpenKey(hKey, szPath, &hChildKey);
	::RegQueryInfoKey(hKey, NULL, NULL, NULL, &dwValues, NULL, NULL, 
		&dwNumValue, NULL, NULL, NULL, NULL);

	for (DWORD i = 0; i < dwValues; i++)
	{
		szValueName[0] = '\0';
		DWORD dwValueSize = MAXBYTE;
		
		if (ERROR_SUCCESS == ::RegEnumKeyEx(hChildKey, i, szValueName, &dwValueSize, NULL, 
			NULL, NULL, NULL))
		{
			HTREEITEM hNewRoot = lpTree->m_tree.InsertItem(szValueName, hItem);
			lpTree->m_tree.SetItemData(hNewRoot, (unsigned long)hChildKey);		
		}
	}

	RegCloseKey(lpTree->m_hKey);
	lpTree->m_ListItem.AddHead(hItem);
	return 0;
}

void CMyTree::QueryRegKey(HTREEITEM hRootItem, HKEY hRootKey, CString szPath)
{
	DWORD dwValues;
	DWORD dwNumValue;
	HKEY hChildKey;
	CHAR  szValueName[MAXBYTE];
	DWORD dwValueSize = sizeof(szValueName);
	//CString szPath = m_tree.GetItemText(hRootItem);

	if (ERROR_SUCCESS != ::RegOpenKey(hRootKey, szPath, &hChildKey))
	{
// 		FormatMessage
// 		AfxMessageBox("RegOpenKey Failed!");
		LPVOID lpMsgBuf;
		FormatMessage( 
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM | 
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			GetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			(LPTSTR) &lpMsgBuf,
			0,
			NULL 
			);
		// Process any inserts in lpMsgBuf.
		// ...
		// Display the string.
		AfxMessageBox((char *)lpMsgBuf);
		// Free the buffer.
		LocalFree( lpMsgBuf );
	}
	if (ERROR_SUCCESS != ::RegQueryInfoKey(hRootKey, NULL, NULL, NULL, &dwValues, NULL, NULL, 
		&dwNumValue, NULL, NULL, NULL, NULL))
	{
		LPVOID lpMsgBuf;
		FormatMessage( 
			FORMAT_MESSAGE_ALLOCATE_BUFFER | 
			FORMAT_MESSAGE_FROM_SYSTEM | 
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			GetLastError(),
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
			(LPTSTR) &lpMsgBuf,
			0,
			NULL 
			);
		// Process any inserts in lpMsgBuf.
		// ...
		// Display the string.
		AfxMessageBox((char *)lpMsgBuf);
		// Free the buffer.
		LocalFree( lpMsgBuf );
	}

	for (DWORD i = 0; i < dwValues; i++)
	{
		szValueName[0] = '\0';
		DWORD dwValueSize = sizeof(szValueName);

		if (ERROR_SUCCESS == ::RegEnumKeyEx(hChildKey, i, szValueName, &dwValueSize, NULL, 
			NULL, NULL, NULL))
		{
			HTREEITEM hNewItem = m_tree.InsertItem(szValueName, hRootItem);
			CString *pParent = (CString *)m_tree.GetItemData(hRootItem);
			CString *pName;
			if (pParent != NULL)
			{
				pName = new CString(*pParent + "\\" + szValueName);
			}
			else
			{
				pName = new CString(szValueName);
			}
			m_tree.SetItemData(hNewItem, (unsigned long)pName);		
		}
	}
	RegCloseKey(hRootKey);
}

void CMyTree::LayerSearch(HTREEITEM hItem)
{

	//lpThread->Run();

	HKEY hChildKey;
	DWORD dwValues;
	CHAR  szValueName[MAXBYTE];
	DWORD dwValueSize = sizeof(szValueName);
	DWORD dwNumValue;

	::RegOpenKey(m_hKey, m_szPath, &m_hChildKey);
	::RegQueryInfoKey(m_hKey, NULL, NULL, NULL, &m_dwValues, NULL, NULL, 
		&dwNumValue, NULL, NULL, NULL, NULL);

// 	for (DWORD i = 0; i < dwValues; i++)
// 	{
// 		szValueName[0] = '\0';
// 		DWORD dwValueSize = sizeof(szValueName);
// 		
// 		if (ERROR_SUCCESS == ::RegEnumKeyEx(hChildKey, i, szValueName, &dwValueSize, NULL, 
// 			NULL, NULL, NULL))
// 		{
// 			HTREEITEM hNewRoot = m_tree.InsertItem(szValueName, hItem);
// 			m_tree.SetItemData(hNewRoot, (unsigned long)hChildKey);		
// 		}
// 	}
// 	RegCloseKey(m_hKey);
	CMFCRegDoc* pDoc = GetDocument();

// 	pDoc->m_szPath = m_tree.GetItemText(hItem);	
// 	pDoc->m_hKey = (HKEY)m_tree.GetItemData(hItem);
// 	pDoc->m_dValue = dwNumValue;
	pDoc->UpdateAllViews(this);
}

void CMyTree::LayerQuery(HTREEITEM hRoot, HKEY hRootKey, CString szPath)
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
				HTREEITEM hNewRoot = m_tree.InsertItem(szValueName, hRoot);
				m_tree.SetItemData(hNewRoot, hChildKey->unused);

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


void CMyTree::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	HTREEITEM hItem = m_tree.GetSelectedItem();
	CString szPath;
	HKEY hKey = GetPath(hItem, szPath);

	CMFCRegDoc *pDoc = GetDocument();
	pDoc->m_szPath = szPath;	
	pDoc->m_hKey = hKey;
	//pDoc->m_dValue = dwNumValue;
	pDoc->UpdateAllViews(NULL);
}

CMFCRegDoc* CMyTree::GetDocument()
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCRegDoc)));
	return (CMFCRegDoc*)m_pDocument;
}

void CMyTree::OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
// 	HTREEITEM hItem = m_tree.GetSelectedItem();
// 	POSITION pos;
// 	if ((pos = m_ListItem.Find(hItem)) != NULL)
// 	{
// 		HTREEITEM hChildItem = m_tree.GetChildItem(hItem);
// 		while (hChildItem != NULL)
// 		{
// 			DeleteChildItem(hChildItem);
// 			hChildItem = m_tree.GetNextItem(hChildItem, TVGN_NEXT);
// 		}
// 		m_ListItem.RemoveAt(pos);
// 	}
// 	else
// 	{
// 		HKEY hKey;
// 		CString szPath;
// 		HTREEITEM hChildItem = m_tree.GetChildItem(hItem);
// 		while (hChildItem != NULL)
// 		{
// 			hKey = (HKEY)m_tree.GetItemData(hChildItem); 
// 			szPath = m_tree.GetItemText(hChildItem);
// 			QueryRegKey(hChildItem, hKey, szPath);
// 			hChildItem = m_tree.GetNextItem(hChildItem, TVGN_NEXT);
// 		}
// 		m_ListItem.AddHead(hItem);
// 	}
	*pResult = 0;
}

void CMyTree::DeleteChildItem(HTREEITEM hRootItem)
{
	HTREEITEM hNextItem;
	HTREEITEM hChildItem = m_tree.GetChildItem(hRootItem);
	while (hChildItem != NULL)
	{
		hNextItem = m_tree.GetNextItem(hChildItem, TVGN_NEXT);
		m_tree.DeleteItem(hChildItem);
		hChildItem = hNextItem;
	}
}

void CMyTree::OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	HTREEITEM hItem = pNMTreeView->itemNew.hItem;
	// ´ò¿ª
	if (pNMTreeView->action == 2)
	{
		CString szPath;
		HKEY hKey = GetPath(hItem, szPath);
		DeleteChildItem(hItem);
		QueryRegKey(hItem, hKey, szPath);

		HTREEITEM hChildItem = m_tree.GetChildItem(hItem);
		while (hChildItem != NULL)
		{
			hKey = GetPath(hItem, szPath);
			DeleteChildItem(hChildItem);
			QueryRegKey(hChildItem, hKey, szPath);
			hChildItem = m_tree.GetNextItem(hChildItem, TVGN_NEXT);
		}
	}
	// É¾³ý
	else if (pNMTreeView->action == 1)
	{
		HTREEITEM hChildItem = m_tree.GetChildItem(hItem);
		while (hChildItem != NULL)
		{
			DeleteChildItem(hChildItem);
			hChildItem = m_tree.GetNextItem(hChildItem, TVGN_NEXT);
		}
	}
	// TODO: Add your control notification handler code here
	//HTREEITEM hItem = m_tree.GetSelectedItem();
	*pResult = 0;
}

CString CMyTree::GetRegPath(HTREEITEM hItem)
{
	CString szPath = m_tree.GetItemText(hItem);
	HKEY hKey = (HKEY)m_tree.GetItemData(hItem); 

	if (hKey == HKEY_CLASSES_ROOT || \
		hKey == HKEY_LOCAL_MACHINE || \
		hKey == HKEY_CURRENT_USER || \
		hKey == HKEY_CURRENT_CONFIG)
	{
		if (szPath == "HKEY_CLASSES_ROOT" || \
		szPath == "HKEY_LOCAL_MACHINE" || \
		szPath == "HKEY_CURRENT_USER" || \
		szPath == "HKEY_CURRENT_CONFIG")
		{
			szPath = "";
		}
	}
	else
	{
		//szPath = "\\" + szPath;
	}
	return szPath;
}

HKEY CMyTree::GetPath(HTREEITEM hItem, CString& szPath)
{
	HKEY hKey;
	CString szKey;
	szPath = *(CString*)m_tree.GetItemData(hItem);
	int pos = szPath.Find("\\");
	int nCounts = szPath.GetLength();
	if (pos == -1)
	{
		szKey = szPath;
		szPath = "";
	}else
	{
		szKey = szPath.Left(pos);
		szPath = szPath.Mid(pos + 1, nCounts);
	}	

	if (szKey == "HKEY_CLASSES_ROOT")
	{
		hKey = HKEY_CLASSES_ROOT;
	}else if (szKey == "HKEY_LOCAL_MACHINE")
	{
		hKey = HKEY_LOCAL_MACHINE;
	}else if (szKey == "HKEY_CURRENT_USER")
	{
		hKey = HKEY_CURRENT_USER;
	}else if (szKey == "HKEY_CURRENT_CONFIG")
	{
		hKey = HKEY_CURRENT_CONFIG;
	}else
	{
		szPath = "";
	}
	return hKey;
}

