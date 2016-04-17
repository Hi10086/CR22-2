// SankCADDoc.h : interface of the CSankCADDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SANKCADDOC_H__37B2C6C1_E81A_431E_8D81_FE5E0D8E89ED__INCLUDED_)
#define AFX_SANKCADDOC_H__37B2C6C1_E81A_431E_8D81_FE5E0D8E89ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyList.h"
#include "IShape.h"

class CSankCADDoc : public CDocument
{
protected: // create from serialization only
	CSankCADDoc();
	DECLARE_DYNCREATE(CSankCADDoc)

// Attributes
public:
	CMyList<IShape *, IShape *> m_ShapeList;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSankCADDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSankCADDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSankCADDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SANKCADDOC_H__37B2C6C1_E81A_431E_8D81_FE5E0D8E89ED__INCLUDED_)
