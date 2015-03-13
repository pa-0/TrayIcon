
// TrayIconDlg.h : ͷ�ļ�
//

#pragma once

#define WM_TRAYICON WM_USER + 101

// CTrayIconDlg �Ի���
class CTrayIconDlg : public CDialogEx
{
// ����
public:
	CTrayIconDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TRAYICON_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct); // ���ش���Ϣ���ڴ��������ʱ��Add����ͼ��
	afx_msg void OnClose();		// ���ش���Ϣ���ڹرմ��ڵ�ʱ��Delete����ͼ��
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnHide();
	afx_msg void OnDisplay();
	afx_msg void OnAbout();
	afx_msg void OnExit();
	afx_msg LRESULT OnTrayIcon(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedTraytestbtn();
public:
	NOTIFYICONDATA m_nid;
	CMenu m_menu;
};
