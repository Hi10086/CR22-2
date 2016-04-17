// MyCADDoc.cpp : implementation of the CMyCADDoc class
//

#include "stdafx.h"
#include "MyCAD.h"

#include "MyCADDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyCADDoc

IMPLEMENT_DYNCREATE(CMyCADDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyCADDoc, CDocument)
	//{{AFX_MSG_MAP(CMyCADDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyCADDoc construction/destruction

CMyCADDoc::CMyCADDoc()
{
	// TODO: add one-time construction code here

}

CMyCADDoc::~CMyCADDoc()
{
}

BOOL CMyCADDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyCADDoc serialization

void CMyCADDoc::Serialize(CArchive& ar)
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
// CMyCADDoc diagnostics

#ifdef _DEBUG
void CMyCADDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyCADDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyCADDoc commands
