// CADDoc.h : interface of the CCADDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CADDOC_H__A9C93387_591B_4A7C_BAE2_AA49436A8F33__INCLUDED_)
#define AFX_CADDOC_H__A9C93387_591B_4A7C_BAE2_AA49436A8F33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MyList.h"
#include "IShape.h"

class CCADDoc : public CDocument
{
protected: // create from serialization only
	CCADDoc();
	DECLARE_DYNCREATE(CCADDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCADDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCADDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCADDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
    CMyList<IShape*, IShape*> m_Shapes;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CADDOC_H__A9C93387_591B_4A7C_BAE2_AA49436A8F33__INCLUDED_)
