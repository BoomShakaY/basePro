
// baseProDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "MySocket.h"

// CbaseProDlg �Ի���
class CbaseProDlg : public CDialogEx
{
// ����
public:
	CbaseProDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_BASEPRO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//����ͻ��˵��׽��־�������ͨ�ŵ�
	MySocket m_mySocket;
	// �û���
	CString etUsername;
	// ����
	CString etPassword;
	// ��¼��ť
	CButton btnLogin;
	// ע��
	CButton btnRegister;
	afx_msg void OnClickedButtonLogin();
};
