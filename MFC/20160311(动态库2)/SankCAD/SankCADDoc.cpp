// SankCADDoc.cpp : implementation of the CSankCADDoc class
//

#include "stdafx.h"
#include "SankCAD.h"

#include "SankCADDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSankCADDoc

IMPLEMENT_DYNCREATE(CSankCADDoc, CDocument)

BEGIN_MESSAGE_MAP(CSankCADDoc, CDocument)
	//{{AFX_MSG_MAP(CSankCADDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSankCADDoc construction/destruction

CSankCADDoc::CSankCADDoc()
{
	// TODO: add one-time construction code here

}

CSankCADDoc::~CSankCADDoc()
{
}

BOOL CSankCADDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSankCADDoc serialization

void CSankCADDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		int nCount = m_ShapeList.GetCount();
		ar.Write((char *)&nCount, sizeof(nCount));
		POSITION pos = m_ShapeList.GetHeadPosition();
		while (pos)
		{
			CObject *pObj = m_ShapeList.GetNext(pos);
			ar << pObj;
		}
	}
	else
	{
		int nCount = 0;
		ar.Read((char *)&nCount, sizeof(nCount));
		CObject *pObj = NULL;
		for (int i = 0; i < nCount; i++)
		{
			ar >> pObj;
			m_ShapeList.AddTail((IShape*)pObj);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSankCADDoc diagnostics

#ifdef _DEBUG
void CSankCADDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSankCADDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSankCADDoc commands
