
// FileClientDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "FileClient.h"
#include "FileClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFileClientDlg �Ի���



CFileClientDlg::CFileClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFileClientDlg::IDD, pParent)
    , m_strFilename(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFileClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BTN_SELECT, &CFileClientDlg::OnBnClickedBtnSelect)
    ON_BN_CLICKED(IDC_BTN_Send, &CFileClientDlg::OnBnClickedBtnSend)
END_MESSAGE_MAP()


// CFileClientDlg ��Ϣ�������

BOOL CFileClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CFileClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFileClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CFileClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFileClientDlg::OnBnClickedBtnSelect()
{
    CFileDialog dlg(TRUE, NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT);
    if (dlg.DoModal() == IDOK)
    {
        SetDlgItemText(IDC_EDIT1, dlg.GetPathName());
        m_strFilename = dlg.GetFileName();
    }
}

UINT WorkThread(LPVOID lpwarem)
{
    int nResult;
    DWORD nByteReaded = 0;
    tagFpSock *pFp = (tagFpSock *)lpwarem;
    int sendSize;
    int nLen = sizeof(sendSize);
    ::getsockopt(pFp->socket, SO_SNDBUF, NULL, (char*)&sendSize, &nLen);
    char *pBuf = new char[sendSize];

    for (int i = 0; i < pFp->nCopys; i++)
    {
        ::ReadFile(pFp->hFile, pBuf, sendSize, &nByteReaded, NULL);
        nResult = ::send(pFp->socket, pBuf, nByteReaded, 0);
        if (nResult == SOCKET_ERROR)
        {
            AfxMessageBox(TEXT("����"));
            break;
        }
    }

    delete[] pBuf;
    delete pFp;
}

void CFileClientDlg::OnBnClickedBtnSend()
{
    int nResult;
    m_socket = ClientStart(SOCK_STREAM);
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5566);
    addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    if (m_socket != SOCKET_ERROR)
    {
        nResult = ::connect(m_socket, (sockaddr*)&addr, sizeof(addr));
        if (nResult == -1)
        {
            return ;
        }

        SendFile();
    }
}

void CFileClientDlg::SendFile()
{
    int nResult;
    int nCopys = 0;
    tagPacket **ppPacket = NULL;
    DWORD dwLowSize;
    DWORD dwHighSize;

    HANDLE hFile = ::CreateFile(m_pathName,
        GENERIC_READ,
        FILE_SHARE_READ,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL);

    if (hFile != INVALID_HANDLE_VALUE)
    {   
        dwLowSize = ::GetFileSize(hFile, &dwHighSize);

        nCopys = dwLowSize / 0x2000;
        //CBigInt big;
        
        char buf[MAXBYTE];
        CString str;
        str.Format(TEXT("cmd:file\nfilename:%s\filecopys:%d"), m_strFilename, nCopys);
        MySend(m_socket, (char*)str.GetBuffer(0));

        nResult = MyRecv(ppPacket, m_socket);
        if (nResult > 0)
        {
            ParmeCommand((*ppPacket)->m_data, m_socket);
        }
    }
 
}

void CFileClientDlg::ParmeCommand(char *msg, SOCKET curSocket)
{

}