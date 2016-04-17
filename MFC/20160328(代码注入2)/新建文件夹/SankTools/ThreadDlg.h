#if !defined(AFX_THREADDLG_H__E92FD5E6_E0F4_465C_AF52_C1BF2F6BB8DE__INCLUDED_)
#define AFX_THREADDLG_H__E92FD5E6_E0F4_465C_AF52_C1BF2F6BB8DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ThreadDlg.h : header file
//
#include <Tlhelp32.h>
#include <Psapi.h>

#pragma comment(lib, "psapi.lib")
/////////////////////////////////////////////////////////////////////////////
// CThreadDlg dialog

class CThreadDlg : public CDialog
{
// Construction
public:
	DWORD m_dwPID;
	void InitCtrl();
	void SetPID(DWORD pid);
	void EnumThread();
	CThreadDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CThreadDlg)
	enum { IDD = IDD_THREAD_DLG };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CThreadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADDLG_H__E92FD5E6_E0F4_465C_AF52_C1BF2F6BB8DE__INCLUDED_)
