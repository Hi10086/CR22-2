#if !defined(AFX_SETDIALOG_H__BC6B36DC_B86A_42D8_9E97_18963E0DBBDB__INCLUDED_)
#define AFX_SETDIALOG_H__BC6B36DC_B86A_42D8_9E97_18963E0DBBDB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SetDialog dialog

class SetDialog : public CDialog
{
// Construction
public:
	SetDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SetDialog)
	enum { IDD = IDD_DIALOG1 };
	int		m_PenType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SetDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SetDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETDIALOG_H__BC6B36DC_B86A_42D8_9E97_18963E0DBBDB__INCLUDED_)
