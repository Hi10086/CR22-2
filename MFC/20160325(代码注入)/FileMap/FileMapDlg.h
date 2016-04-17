// FileMapDlg.h : header file
//

#if !defined(AFX_FILEMAPDLG_H__3F067FFD_AEB5_47A5_8052_F6E43CE1962C__INCLUDED_)
#define AFX_FILEMAPDLG_H__3F067FFD_AEB5_47A5_8052_F6E43CE1962C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileMapDlg dialog

class CFileMapDlg : public CDialog
{
// Construction
public:
	CFileMapDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileMapDlg)
	enum { IDD = IDD_FILEMAP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileMapDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFileMapDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEMAPDLG_H__3F067FFD_AEB5_47A5_8052_F6E43CE1962C__INCLUDED_)
