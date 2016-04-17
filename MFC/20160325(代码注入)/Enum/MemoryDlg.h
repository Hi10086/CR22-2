#if !defined(AFX_MEMORYDLG_H__51C7F063_AF38_49D7_9E89_F99620EC75CD__INCLUDED_)
#define AFX_MEMORYDLG_H__51C7F063_AF38_49D7_9E89_F99620EC75CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MemoryDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMemoryDlg dialog

class CMemoryDlg : public CDialog
{
// Construction
public:
	CMemoryDlg(CWnd* pParent = NULL);   // standard constructor

  DWORD GetPID()
  {
    return m_dwPID;
  }

  void SetPID(DWORD dwPID)
  {
    m_dwPID = dwPID;
  }

// Dialog Data
	//{{AFX_DATA(CMemoryDlg)
	enum { IDD = IDD_DIALOG1 };
	CString	m_strAddress;
	UINT	m_nSize;
	CString	m_strValue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMemoryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMemoryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnRead();
	afx_msg void OnBtnWrite();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
  DWORD m_dwPID;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEMORYDLG_H__51C7F063_AF38_49D7_9E89_F99620EC75CD__INCLUDED_)
