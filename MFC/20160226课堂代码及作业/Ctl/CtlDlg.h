// CtlDlg.h : header file
//

#if !defined(AFX_CTLDLG_H__CF41D20B_5640_491F_A31E_8B48934E5282__INCLUDED_)
#define AFX_CTLDLG_H__CF41D20B_5640_491F_A31E_8B48934E5282__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCtlDlg dialog

class CCtlDlg : public CDialog
{
// Construction
public:
	void InitCtrl();
	CCtlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCtlDlg)
	enum { IDD = IDD_CTL_DIALOG };
	CTreeCtrl	m_TreeCtrl;
	CListBox	m_ListBox;
	CComboBox	m_Combo;
  CImageList m_ImageList;
	int		m_nSex;
	int		m_nCourse;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCtlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnSelchangeList1();
	afx_msg void OnItemexpandingTree1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTLDLG_H__CF41D20B_5640_491F_A31E_8B48934E5282__INCLUDED_)
