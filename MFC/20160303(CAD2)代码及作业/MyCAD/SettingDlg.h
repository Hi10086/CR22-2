#if !defined(AFX_SETTINGDLG_H__20C76137_8E1B_4F4F_AD40_6425E490795A__INCLUDED_)
#define AFX_SETTINGDLG_H__20C76137_8E1B_4F4F_AD40_6425E490795A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SettingDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg dialog
#include "IShape.h"
#include "MyButton.h"

class CSettingDlg : public CDialog
{
// Construction
public:
	CSettingDlg(CWnd* pParent = NULL);   // standard constructor
  CMyPen GetPen()
  {
    return m_pen;
  }
  void SetPen(CMyPen pen)
  {
    m_pen = pen;
  }
// Dialog Data
	//{{AFX_DATA(CSettingDlg)
	enum { IDD = IDD_DIALOG1 };
	CMyButton	m_ctlPenColor;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSettingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSettingDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBtnColor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
  CMyPen m_pen;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTINGDLG_H__20C76137_8E1B_4F4F_AD40_6425E490795A__INCLUDED_)
