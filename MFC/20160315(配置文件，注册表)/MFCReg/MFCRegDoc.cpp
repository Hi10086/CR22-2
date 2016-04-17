// MFCRegDoc.cpp : implementation of the CMFCRegDoc class
//

#include "stdafx.h"
#include "MFCReg.h"

#include "MFCRegDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMFCRegDoc

IMPLEMENT_DYNCREATE(CMFCRegDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCRegDoc, CDocument)
	//{{AFX_MSG_MAP(CMFCRegDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMFCRegDoc construction/destruction

CMFCRegDoc::CMFCRegDoc()
{
	// TODO: add one-time construction code here

}

CMFCRegDoc::~CMFCRegDoc()
{
}

BOOL CMFCRegDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMFCRegDoc serialization

void CMFCRegDoc::Serialize(CArchive& ar)
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
// CMFCRegDoc diagnostics

#ifdef _DEBUG
void CMFCRegDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCRegDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMFCRegDoc commands
