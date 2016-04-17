// SheetDlg.h : header file
//

#if !defined(AFX_SHEETDLG_H__DBEFC317_574F_4A33_A99E_C690243F4A1D__INCLUDED_)
#define AFX_SHEETDLG_H__DBEFC317_574F_4A33_A99E_C690243F4A1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Page1.h"
#include "Page2.h"
#include "Page3.h"

/////////////////////////////////////////////////////////////////////////////
// CSheetDlg dialog

class CSheetDlg : public CDialog
{
// Construction
public:
	CSheetDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSheetDlg)
	enum { IDD = IDD_SHEET_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSheetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSheetDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHEETDLG_H__DBEFC317_574F_4A33_A99E_C690243F4A1D__INCLUDED_)
