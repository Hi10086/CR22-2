#if !defined(AFX_MYPROCESSDLG_H__00EF8BD9_4B98_4E38_B0A5_0664DD93E0E0__INCLUDED_)
#define AFX_MYPROCESSDLG_H__00EF8BD9_4B98_4E38_B0A5_0664DD93E0E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyProcessDlg.h : header file
//
#include <Tlhelp32.h>
#include <Psapi.h>
#include "ModuleDlg.h"
#include "InjectDlg.h"
#include "ThreadDlg.h"

#pragma comment(lib, "psapi.lib")
/////////////////////////////////////////////////////////////////////////////
// CMyProcessDlg dialog

class CMyProcessDlg : public CDialog
{
// Construction
public:
	CImageList m_ImageList;
	CMyProcessDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMyProcessDlg)
	enum { IDD = IDD_PRO_DLG };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyProcessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void InitCtrl();
	void EnumProcess();
	// Generated message map functions
	//{{AFX_MSG(CMyProcessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuProFlush();
	afx_msg void OnMenuProModule();
	afx_msg void OnMenuProInject();
	afx_msg void OnMenuProThread();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYPROCESSDLG_H__00EF8BD9_4B98_4E38_B0A5_0664DD93E0E0__INCLUDED_)
