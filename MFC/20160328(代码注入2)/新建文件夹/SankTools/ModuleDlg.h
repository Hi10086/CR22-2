#if !defined(AFX_MODULEDLG_H__FD1AEB18_C07C_43E6_BB67_A21FEFDC02FC__INCLUDED_)
#define AFX_MODULEDLG_H__FD1AEB18_C07C_43E6_BB67_A21FEFDC02FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ModuleDlg.h : header file
//
#include <Tlhelp32.h>
#include <Psapi.h>

#pragma comment(lib, "psapi.lib")
/////////////////////////////////////////////////////////////////////////////
// CModuleDlg dialog

class CModuleDlg : public CDialog
{
// Construction

public:
	void SetProcessName(CString name);
	CString m_strName;
	DWORD m_dwPID;
	void InitCtrl();
	void EnumModule();
	void SetPID(DWORD pid);
	CModuleDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CModuleDlg)
	enum { IDD = IDD_MODULE_DLG };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModuleDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CModuleDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnMenuModuleFlush();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODULEDLG_H__FD1AEB18_C07C_43E6_BB67_A21FEFDC02FC__INCLUDED_)
