// MyCADDoc.h : interface of the CMyCADDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCADDOC_H__2294377C_F9B3_42E6_ABA5_572F884BC10A__INCLUDED_)
#define AFX_MYCADDOC_H__2294377C_F9B3_42E6_ABA5_572F884BC10A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyCADDoc : public CDocument
{
protected: // create from serialization only
	CMyCADDoc();
	DECLARE_DYNCREATE(CMyCADDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCADDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyCADDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyCADDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCADDOC_H__2294377C_F9B3_42E6_ABA5_572F884BC10A__INCLUDED_)
