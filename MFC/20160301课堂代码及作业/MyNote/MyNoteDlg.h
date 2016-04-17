// MyNoteDlg.h : header file
//

#if !defined(AFX_MYNOTEDLG_H__3B629FC3_0921_4141_9AD2_39DE19708B48__INCLUDED_)
#define AFX_MYNOTEDLG_H__3B629FC3_0921_4141_9AD2_39DE19708B48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyNoteDlg dialog

class CMyNoteDlg : public CDialog
{
// Construction
public:
	CMyNoteDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyNoteDlg)
	enum { IDD = IDD_MYNOTE_DIALOG };
	CEdit	m_edit;
	CString m_filename;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyNoteDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyNoteDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMenuOpen();
	afx_msg void OnClose();
	afx_msg void OnMenuSave();
	afx_msg void OnMenuSave2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYNOTEDLG_H__3B629FC3_0921_4141_9AD2_39DE19708B48__INCLUDED_)
