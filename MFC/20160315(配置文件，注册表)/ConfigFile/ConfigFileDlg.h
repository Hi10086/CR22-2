// ConfigFileDlg.h : header file
//

#if !defined(AFX_CONFIGFILEDLG_H__480E3B28_A392_4BF0_9209_1F207F5F3931__INCLUDED_)
#define AFX_CONFIGFILEDLG_H__480E3B28_A392_4BF0_9209_1F207F5F3931__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CConfigFileDlg dialog
struct tagPen
{
  int m_nColor;
};


class CConfigFileDlg : public CDialog
{
// Construction
public:
	CConfigFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CConfigFileDlg)
	enum { IDD = IDD_CONFIGFILE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConfigFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CConfigFileDlg)
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

#endif // !defined(AFX_CONFIGFILEDLG_H__480E3B28_A392_4BF0_9209_1F207F5F3931__INCLUDED_)
