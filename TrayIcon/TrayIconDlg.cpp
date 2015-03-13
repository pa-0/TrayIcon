
// TrayIconDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TrayIcon.h"
#include "TrayIconDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CTrayIconDlg *g_AuE; // ��ShowBallon�����ȫ�ֺ������������ȫ�ֱ���ȥ��Ի�������������Ϳ���������ʹ�á�
									// ��������л��������࣬Ҫ������Щ���п�������ͼ�����Ϣ��ʾ���Ϳ���ͨ��extern����ShowBallon������ʵ�֡�
void ShowBallon(LPCTSTR szMsg=L"��ã�ILLI�����µ���Ϣ��ʾ����鿴!", 
	LPCTSTR szTitle=L"��ʾ��Ϣ", UINT uTimeout=5000, DWORD dwInfoFlgs=0x01);

void ShowBallon(LPCTSTR szMsg, LPCTSTR szTitle, UINT uTimeout, DWORD dwInfoFlags)
{
	g_AuE->m_nid.uTimeout = uTimeout;
	g_AuE->m_nid.dwInfoFlags = (DWORD)dwInfoFlags; // None=0x00, Info=0x01, Warning=0x02, Error=0x03
	g_AuE->m_nid.uFlags |=  NIF_INFO ;
	lstrcpy(g_AuE->m_nid.szInfo, szMsg);
	lstrcpy(g_AuE->m_nid.szInfoTitle, szTitle);
	Shell_NotifyIcon(0x01, &g_AuE->m_nid); // Add=0x00, Delete=0x02, Modify=0x01;
}



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


// CTrayIconDlg �Ի���




CTrayIconDlg::CTrayIconDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTrayIconDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrayIconDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTrayIconDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_HIDE, &CTrayIconDlg::OnHide)
	ON_COMMAND(ID_DISPLAY, &CTrayIconDlg::OnDisplay)
	ON_COMMAND(ID_ABOUT, &CTrayIconDlg::OnAbout)
	ON_COMMAND(ID_EXIT, &CTrayIconDlg::OnExit)
	ON_MESSAGE(WM_TRAYICON, OnTrayIcon)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_TRAYTESTBTN, &CTrayIconDlg::OnBnClickedTraytestbtn)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CTrayIconDlg ��Ϣ�������

BOOL CTrayIconDlg::OnInitDialog()
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

	//ModifyStyleEx(WS_EX_APPWINDOW, WS_EX_TOOLWINDOW);   // ���ϴ˾䣬��Ӧ�ó�������ʾ��С����ť����˲�����С��������
	m_menu.LoadMenu(IDR_TRAYMENU); // �����Զ���������Ҽ��˵�
	g_AuE = (CTrayIconDlg*)this;  // ��ʼ��ȫ�ֱ���

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTrayIconDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else if((nID & 0xFFF0) == SC_MINIMIZE)  // ��С��������
	{
		ShowWindow(SW_HIDE);
	}
	else if(nID == WM_DESTROY)  // �رմ���ʱ ɾ������
	{
		Shell_NotifyIcon(NIM_DELETE, &m_nid);
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTrayIconDlg::OnPaint()
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
HCURSOR CTrayIconDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int CTrayIconDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	m_nid.cbSize = (DWORD)sizeof(NOTIFYICONDATA);
	m_nid.hWnd = this->m_hWnd;
	m_nid.uID = IDR_MAINFRAME;  // ����ͼ��ID������ʹ���Զ����ͼ�꣬����Ϊͼ��㣬��ֱ��ʹ����ϵͳͼ��
	m_nid.uFlags =NIF_ICON | NIF_MESSAGE | NIF_TIP ;
	m_nid.uTimeout = 5000;
	m_nid.uVersion = NULL;
	m_nid.dwStateMask = 0;
	m_nid.dwInfoFlags = (DWORD)0x01; // None=0x00, Info=0x01, Warning=0x02, Error=0x03
	m_nid.uCallbackMessage = WM_TRAYICON;  // ������Ϣ�������Ա�������ͼ�������Ӧ��Ϣ
	m_nid.hIcon = LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAINFRAME));
	lstrcpy(m_nid.szTip, L"����ͼ����ʾ��Ϣ");
	Shell_NotifyIcon(NIM_ADD, &m_nid); // Add=0x00, Delete=0x02, Modify=0x01;

	return 0;
}

void CTrayIconDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	Shell_NotifyIcon(NIM_DELETE, &m_nid);  // �رմ���ʱɾ������ͼ��
	CDialogEx::OnClose();
}

// �����ĸ��������������Ҽ��˵�����Ӧ���¼�
void CTrayIconDlg::OnHide()
{
	// TODO: �ڴ���������������
	ShowWindow(SW_HIDE);
}

void CTrayIconDlg::OnDisplay()
{
	// TODO: �ڴ���������������
	ShowWindow(SW_SHOWNORMAL);
}

void CTrayIconDlg::OnAbout()
{
	// TODO: �ڴ���������������
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}

void CTrayIconDlg::OnExit()
{
	// TODO: �ڴ���������������
	if(MessageBox(L"ȷ��Ҫ�˳�Ӧ�ó�����", L"ϵͳ��ʾ", MB_OKCANCEL | MB_ICONQUESTION) != 1)
		return;
	Shell_NotifyIcon(NIM_DELETE, &m_nid);
	CDialogEx::OnCancel();
}

LRESULT CTrayIconDlg::OnTrayIcon( WPARAM wParam, LPARAM lParam )
{
	UINT uID;
	UINT uMsgID;
	POINT pt;
	uID = (UINT)wParam;
	uMsgID = (UINT)lParam;

	if(uID == IDR_MAINFRAME)
	{
		switch(uMsgID)
		{
		case WM_RBUTTONDOWN:
			{
				GetCursorPos(&pt);
				CMenu* m_subMenu = (CMenu*)m_menu.GetSubMenu(0);  // ������ͼ���ϵ����Ҽ�����ʾ�Զ�����Ҽ��˵�
				m_subMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pt.x, pt.y, AfxGetApp()->m_pMainWnd, TPM_LEFTALIGN);
				break;
			}
		case WM_LBUTTONDOWN:  // ������ͼ���ϵ���������������ʾ�����ش���
			if(!IsWindowVisible())
				AfxGetApp()->m_pMainWnd->ShowWindow(SW_SHOWNORMAL);
			else
				AfxGetApp()->m_pMainWnd->ShowWindow(SW_HIDE);
			break;
		case NIN_BALLOONSHOW:// ��ʾ��ʾ��Ϣ
			//AfxMessageBox("��ʾ��ʾ��");
			break;
		case NIN_BALLOONUSERCLICK:// ����Ϣ���е��������������߰��¹���
			AfxMessageBox(L"�㵥��������ͼ����Ϣ��ʾ��");
			break;
		case NIN_BALLOONTIMEOUT:// �����رգ����߳�ʱ���أ� ��������ʾ���е����Ҽ�
			//AfxMessageBox("��ʾ�ѳ�ʱ��"); 
			break;
		case NIN_BALLOONHIDE:// ��ʱ��ת������Ϣ��
			//AfxMessageBox("��ʾ���أ�");
			break;
		default:
			break;
		}
	}
	return 0;
}

void CTrayIconDlg::OnBnClickedTraytestbtn()  // ������ť����ʾ������ʾ��Ϣ
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowBallon();
}
