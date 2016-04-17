// CADDoc.cpp : implementation of the CCADDoc class
//

#include "stdafx.h"
#include "CAD.h"

#include "CADDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCADDoc

IMPLEMENT_DYNCREATE(CCADDoc, CDocument)

BEGIN_MESSAGE_MAP(CCADDoc, CDocument)
	//{{AFX_MSG_MAP(CCADDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCADDoc construction/destruction

CCADDoc::CCADDoc()
{
	// TODO: add one-time construction code here

}

CCADDoc::~CCADDoc()
{
}

BOOL CCADDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCADDoc serialization

void CCADDoc::Serialize(CArchive& ar)
{
  m_Shapes.Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CCADDoc diagnostics

#ifdef _DEBUG
void CCADDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCADDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}


#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCADDoc commands
