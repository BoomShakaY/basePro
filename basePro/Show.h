#pragma once


// CShow 对话框

class CShow : public CDialogEx
{
	DECLARE_DYNAMIC(CShow)

public:
	CShow(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CShow();

// 对话框数据
	enum { IDD = IDD_SHOW_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
