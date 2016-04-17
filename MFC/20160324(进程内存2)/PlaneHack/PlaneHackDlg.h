// PlaneHackDlg.h : header file
//

#if !defined(AFX_PLANEHACKDLG_H__0EA66B5F_4E0C_49B4_A693_F5A0F7978A09__INCLUDED_)
#define AFX_PLANEHACKDLG_H__0EA66B5F_4E0C_49B4_A693_F5A0F7978A09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Plane.h"
/////////////////////////////////////////////////////////////////////////////
// CPlaneHackDlg dialog

class CPlaneHackDlg : public CDialog
{
public:
	HWND m_hwnd;
	DWORD m_dwPID;
	HANDLE m_hGame;
// Construction
public:
	void GetBulletNum(UINT wNum);
	tagPlane GetPlanePos();
	void SetPlanePos(tagPlane pos);
	CPlaneHackDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPlaneHackDlg)
	enum { IDD = IDD_PLANEHACK_DIALOG };
	int		m_nPlaneX;
	int		m_nPlaneY;
	UINT	m_wBullet;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlaneHackDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPlaneHackDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonBegin();
	afx_msg void OnButtonAuto();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLANEHACKDLG_H__0EA66B5F_4E0C_49B4_A693_F5A0F7978A09__INCLUDED_)
