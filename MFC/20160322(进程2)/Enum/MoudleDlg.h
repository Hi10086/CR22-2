#if !defined(AFX_MOUDLEDLG_H__854149FA_0D08_481F_B08C_38F76C22C214__INCLUDED_)
#define AFX_MOUDLEDLG_H__854149FA_0D08_481F_B08C_38F76C22C214__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MoudleDlg.h : header file
//
#include <Tlhelp32.h>

/////////////////////////////////////////////////////////////////////////////
// CMoudleDlg dialog

class CMoudleDlg : public CDialog
{
// Construction
public:
    DWORD  m_dwPID;
public:
	void EnumModule();
	void GetPID(DWORD pid);
    void CMoudleDlg::InitCtrl();
	CMoudleDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMoudleDlg)
	enum { IDD = IDD_DIALOG1 };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoudleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMoudleDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUDLEDLG_H__854149FA_0D08_481F_B08C_38F76C22C214__INCLUDED_)
