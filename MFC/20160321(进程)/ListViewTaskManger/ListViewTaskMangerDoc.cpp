// ListViewTaskMangerDoc.cpp : implementation of the CListViewTaskMangerDoc class
//

#include "stdafx.h"
#include "ListViewTaskManger.h"

#include "ListViewTaskMangerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CListViewTaskMangerDoc

IMPLEMENT_DYNCREATE(CListViewTaskMangerDoc, CDocument)

BEGIN_MESSAGE_MAP(CListViewTaskMangerDoc, CDocument)
	//{{AFX_MSG_MAP(CListViewTaskMangerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListViewTaskMangerDoc construction/destruction

CListViewTaskMangerDoc::CListViewTaskMangerDoc()
{
	// TODO: add one-time construction code here

}

CListViewTaskMangerDoc::~CListViewTaskMangerDoc()
{
}

BOOL CListViewTaskMangerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CListViewTaskMangerDoc serialization

void CListViewTaskMangerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CListViewTaskMangerDoc diagnostics

#ifdef _DEBUG
void CListViewTaskMangerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CListViewTaskMangerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CListViewTaskMangerDoc commands
