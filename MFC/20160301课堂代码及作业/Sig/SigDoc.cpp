// SigDoc.cpp : implementation of the CSigDoc class
//

#include "stdafx.h"
#include "Sig.h"

#include "SigDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSigDoc

IMPLEMENT_DYNCREATE(CSigDoc, CDocument)

BEGIN_MESSAGE_MAP(CSigDoc, CDocument)
	//{{AFX_MSG_MAP(CSigDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSigDoc construction/destruction

CSigDoc::CSigDoc()
{
	// TODO: add one-time construction code here

}

CSigDoc::~CSigDoc()
{
}

BOOL CSigDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSigDoc serialization

void CSigDoc::Serialize(CArchive& ar)
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
// CSigDoc diagnostics

#ifdef _DEBUG
void CSigDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSigDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSigDoc commands
