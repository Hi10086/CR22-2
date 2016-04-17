// UDPClientDlg.h : header file
//

#if !defined(AFX_UDPCLIENTDLG_H__1CA9938B_47DD_4908_8F57_5DAF961170E9__INCLUDED_)
#define AFX_UDPCLIENTDLG_H__1CA9938B_47DD_4908_8F57_5DAF961170E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CUDPClientDlg dialog

class CUDPClientDlg : public CDialog
{
// Construction
public:
	CUDPClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CUDPClientDlg)
	enum { IDD = IDD_UDPCLIENT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUDPClientDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
  SOCKET m_socket;
	// Generated message map functions
	//{{AFX_MSG(CUDPClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UDPCLIENTDLG_H__1CA9938B_47DD_4908_8F57_5DAF961170E9__INCLUDED_)
