#if !defined(AFX_MYBUTTON_H__23B97644_B70B_49AB_8810_AA9E06B2A81D__INCLUDED_)
#define AFX_MYBUTTON_H__23B97644_B70B_49AB_8810_AA9E06B2A81D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyButton window

class CMyButton : public CButton
{
// Construction
public:
	CMyButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyButton)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyButton)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
public:
  COLORREF m_crBackground;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYBUTTON_H__23B97644_B70B_49AB_8810_AA9E06B2A81D__INCLUDED_)
