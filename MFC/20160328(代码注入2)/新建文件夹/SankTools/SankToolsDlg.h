// SankToolsDlg.h : header file
//

#if !defined(AFX_SANKTOOLSDLG_H__4E42D056_4274_4087_A3DC_2D90D51E798C__INCLUDED_)
#define AFX_SANKTOOLSDLG_H__4E42D056_4274_4087_A3DC_2D90D51E798C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MyProcessDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CSankToolsDlg dialog

class CSankToolsDlg : public CDialog
{
public:
	CMyProcessDlg m_ProcessDlg;
	void OnMyInitDlg();
// Construction
public:
	CSankToolsDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSankToolsDlg)
	enum { IDD = IDD_SANKTOOLS_DIALOG };
	CTabCtrl	m_Tab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSankToolsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSankToolsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SANKTOOLSDLG_H__4E42D056_4274_4087_A3DC_2D90D51E798C__INCLUDED_)
