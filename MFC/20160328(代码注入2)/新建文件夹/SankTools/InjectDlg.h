#if !defined(AFX_INJECTDLG_H__6FAC04A9_6E69_49AA_9867_D9FD0B44D7D7__INCLUDED_)
#define AFX_INJECTDLG_H__6FAC04A9_6E69_49AA_9867_D9FD0B44D7D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InjectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInjectDlg dialog

class CInjectDlg : public CDialog
{
// Construction
public:
	void SetPID(DWORD pid);
	DWORD m_dwPID;
	CString m_strDLL;
	CInjectDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInjectDlg)
	enum { IDD = IDD_INJECT_DIALOG };
	CButton	m_bMemMap;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInjectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInjectDlg)
	afx_msg void OnDllSel();
	afx_msg void OnButtonInject();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INJECTDLG_H__6FAC04A9_6E69_49AA_9867_D9FD0B44D7D7__INCLUDED_)
