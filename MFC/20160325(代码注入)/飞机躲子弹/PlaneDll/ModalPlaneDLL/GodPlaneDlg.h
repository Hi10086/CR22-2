#if !defined(AFX_GODPLANEDLG_H__4495482E_596C_49AF_9B89_FFBA28D9F8A1__INCLUDED_)
#define AFX_GODPLANEDLG_H__4495482E_596C_49AF_9B89_FFBA28D9F8A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GodPlaneDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGodPlaneDlg dialog

class CGodPlaneDlg : public CDialog
{
// Construction
public:
	BOOL m_bScanStop;
	CWinThread* m_pScanThread;
	CGodPlaneDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGodPlaneDlg)
	enum { IDD = IDD_DIALOG_GODPLANE };
	int		m_nPlaneX;
	int		m_nPlaneY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGodPlaneDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGodPlaneDlg)
	afx_msg void OnButtonScan();
	afx_msg void OnButtonStop();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GODPLANEDLG_H__4495482E_596C_49AF_9B89_FFBA28D9F8A1__INCLUDED_)
