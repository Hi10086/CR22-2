// MFCRegDoc.h : interface of the CMFCRegDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCREGDOC_H__F18A6A9A_BEA2_40BB_A0A4_82E72A15D68D__INCLUDED_)
#define AFX_MFCREGDOC_H__F18A6A9A_BEA2_40BB_A0A4_82E72A15D68D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCRegDoc : public CDocument
{
protected: // create from serialization only
	CMFCRegDoc();
	DECLARE_DYNCREATE(CMFCRegDoc)

// Attributes
public:
	CString m_szPath;
	HKEY m_hKey;
	DWORD m_dValue;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCRegDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCRegDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCRegDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCREGDOC_H__F18A6A9A_BEA2_40BB_A0A4_82E72A15D68D__INCLUDED_)
