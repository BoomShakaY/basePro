#pragma once
#include "afxwin.h"


// mainDlg �Ի���

class mainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(mainDlg)

public:
	mainDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~mainDlg();

// �Ի�������
	enum { IDD = IDD_MAIN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	DECLARE_MESSAGE_MAP()
public:
	
	// ����
	CButton btnConnect;
	// ����
	CButton btnHelp;
	// �����IP
	CString etComputer;
	
	afx_msg void OnBnClickedButtonHelp();
	virtual BOOL OnInitDialog();
	

	afx_msg void OnBnClickedButtonConnect();
	afx_msg void OnPaint();
};
