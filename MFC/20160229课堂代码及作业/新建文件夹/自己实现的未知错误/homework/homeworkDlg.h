
// homeworkDlg.h : ͷ�ļ�
//

#pragma once
#include "MyButton.h"

// ChomeworkDlg �Ի���
class ChomeworkDlg : public CDialogEx
{
// ����
public:
	ChomeworkDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~ChomeworkDlg() 
	{
		if (m_pMyButton != NULL)
			delete[] m_pMyButton;
	}

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOMEWORK_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	CMyButton *m_pMyButton;
	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
