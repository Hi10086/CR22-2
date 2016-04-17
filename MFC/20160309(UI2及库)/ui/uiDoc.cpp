// uiDoc.cpp : implementation of the CUiDoc class
//

#include "stdafx.h"
#include "ui.h"

#include "uiDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUiDoc

IMPLEMENT_DYNCREATE(CUiDoc, CDocument)

BEGIN_MESSAGE_MAP(CUiDoc, CDocument)
	//{{AFX_MSG_MAP(CUiDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUiDoc construction/destruction

CUiDoc::CUiDoc()
{
	// TODO: add one-time construction code here

}

CUiDoc::~CUiDoc()
{
}

BOOL CUiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CUiDoc serialization

void CUiDoc::Serialize(CArchive& ar)
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
// CUiDoc diagnostics

#ifdef _DEBUG
void CUiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CUiDoc commands
