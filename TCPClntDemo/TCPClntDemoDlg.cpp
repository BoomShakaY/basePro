
// TCPClntDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TCPClntDemo.h"
#include "TCPClntDemoDlg.h"
#include "afxdialogex.h"
#include "Login.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTCPClntDemoDlg 对话框



CTCPClntDemoDlg::CTCPClntDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTCPClntDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTCPClntDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTCPClntDemoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CTCPClntDemoDlg 消息处理程序

BOOL CTCPClntDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码


	//客户端随机端口
	if(!m_socketClient.Create()){
		AfxMessageBox(_T("创建网络失败!"));
		return FALSE;
	}
	//开始链接
	else if(!m_socketClient.Connect(_T("127.0.0.1"),6666)){
		int nError = GetLastError();
		MessageBox(_T("连接服务器失败！"));
		return FALSE;
	}
	else
	{
	int nRes = 0;
	Login loginDlg;
	nRes = loginDlg.DoModal();
	if(nRes == 1002)
	{
		return FALSE;
	}
}	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTCPClntDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTCPClntDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

