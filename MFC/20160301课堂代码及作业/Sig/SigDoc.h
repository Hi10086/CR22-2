// SigDoc.h : interface of the CSigDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SIGDOC_H__A98F967A_E9F5_4A83_8D81_E129694A37E0__INCLUDED_)
#define AFX_SIGDOC_H__A98F967A_E9F5_4A83_8D81_E129694A37E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSigDoc : public CDocument
{
protected: // create from serialization only
	CSigDoc();
	DECLARE_DYNCREATE(CSigDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSigDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSigDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSigDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIGDOC_H__A98F967A_E9F5_4A83_8D81_E129694A37E0__INCLUDED_)
