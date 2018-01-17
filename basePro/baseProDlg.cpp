
// baseProDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "basePro.h"
#include "baseProDlg.h"
#include "afxdialogex.h"
#include "mainDlg.h"
#include "winsock.h"    
#include "mysql.h"  
#include "cstring"
#pragma comment(lib,"libmysql.lib")
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


// CbaseProDlg �Ի���



CbaseProDlg::CbaseProDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CbaseProDlg::IDD, pParent)
	, etUsername(_T(""))
	, etPassword(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CbaseProDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_USERNAME, etUsername);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, etPassword);
	DDX_Control(pDX, IDC_BUTTON_LOGIN, btnLogin);
	DDX_Control(pDX, IDC_BUTTON_REGISTER, btnRegister);
}

BEGIN_MESSAGE_MAP(CbaseProDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LOGIN, &CbaseProDlg::OnClickedButtonLogin)
END_MESSAGE_MAP()


// CbaseProDlg ��Ϣ�������

BOOL CbaseProDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CbaseProDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CbaseProDlg::OnPaint()
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
		
		//��ȡ����dc����Ҫ���Ļ�
		CPaintDC dc(this); //��ȡ��ǰ���򴰿ڵ�dc
		//dc�����豸�����ģ�Ҳ�����豸���������豸����

		//��ȡ���ڵĴ�С,��Ҫ�����
		CRect clientRect;
		GetClientRect(&clientRect);

		//׼��ͼƬ����Ҫ��ʲô��ȥ
		CImage imgHero;  //ͼƬ�Ķ���
		//CImage imgSwore;
		//���·���;���·��,һ��Ҫע��ͼƬ�ĺ�׺��
		//��ͼ�ĳ��ֵ����⣬����������������
		imgHero.Load(_T("theme\\background_1.png"));
		//imgSwore.Load(_T("theme\\background.jpeg"));

		//imgHero.Draw(dc,0,0,clientRect.Width(),clientRect.Height());
		//imgHero.Draw(dc,0,0,imgHero.GetWidth(),imgHero.GetHeight());

		//imgSwore.Draw(dc,0,0,clientRect.Width(),clientRect.Height());
		//imgSwore.Draw(dc,0,0,imgSwore.GetWidth(),imgSwore.GetHeight());

		imgHero.BitBlt(dc,0,0,imgHero.GetWidth(),imgHero.GetHeight(),0,0,SRCCOPY);
		//imgSwore.BitBlt(dc,100,100,clientRect.Width(),clientRect.Height(),0,0,SRCCOPY);

		//����Ҫȥ�ܶ���ͼƬ��ʱ�����ܶ��ͼ���������кܶ�ͼҪˢ�µ�ʱ�����ʱ��ͻ������˸
		//˫�����ͼ����
		//�����Ƚ�ͼƬ�������ڴ��ϣ������ڴ濽����������
		//CDC memDC; //�ڴ�dc����Ҫ���ڽ�ͼƬ����������CDC,HDC CPaintDC
		//��������������һ������ݵ�λͼ���󣬿������Ϊ����
		//CBitmap hBitMap;

		//�������������봰��dc�����
		//hBitMap.CreateCompatibleBitmap(&dc, clientRect.Width(), clientRect.Height());

		//����һ������ݵ�DC,�����ڴ�dc�봰��dc�����
		//memDC.CreateCompatibleDC(&dc);

		//ѡ������������������ݵ�λͼ���󣬲�Ҫ����ԭ�е�λͼ����,��Ϊϵͳ
		//���ṩһ��ʮ�ּ򵥵�λͼ����
		//CBitmap* hOldMap = (CBitmap*)memDC.SelectObject(&hBitMap);
		//�Ƚ�ͼƬ�����ڴ�dc����
		//imgHero.BitBlt(memDC, 0, 0, clientRect.Width(), clientRect.Height(), 0, 0, SRCCOPY);
		//imgSwore.BitBlt(memDC, 0, 0, clientRect.Width(), clientRect.Height(), 0, 0, SRCCOPY);

		//�ٽ��ڴ�dc��������ݻ�������dc����
		//dc.BitBlt(0, 0, clientRect.Width(), clientRect.Height(), &memDC, 0, 0, SRCCOPY);

		//һЩ��Դ�ͷŵĲ���
		//��ԭ����λͼ����ԭ
		//memDC.SelectObject(hOldMap);  //ѡ��ԭ��ϵͳ�ṩ�����ǵ�λͼ����
		//hBitMap.DeleteObject();
		//memDC.DeleteDC();
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CbaseProDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CbaseProDlg::OnClickedButtonLogin()
{


	MYSQL m_sqlCon;
	CString dbUsername, dbPassword;
	CString etUsername,etPassword;
	MYSQL_RES *res;
	MYSQL_ROW row ;

	
	mysql_init(&m_sqlCon);
	   
	if (!mysql_real_connect(&m_sqlCon, "139.199.75.89", "root", "", "user", 3306, NULL, 0))
	{
		AfxMessageBox(_T("�������ݿ�ʧ��!"));
		return;
	}
	else
	{
		mysql_query(&m_sqlCon, "SET NAMES 'GB2312'");
		if (mysql_real_query(&m_sqlCon, "select * from user", (unsigned long)strlen("select * from user"))) 
		{
			return;
		}
		res = mysql_store_result(&m_sqlCon);
		if (NULL == res)
		{
			return;
		}
		while (row = mysql_fetch_row(res)){
			
			dbUsername = row[1];
			dbPassword = row[2];
			
			UpdateData(TRUE);
			GetDlgItemText(IDC_EDIT_USERNAME,etUsername);
			GetDlgItemText(IDC_EDIT_PASSWORD,etPassword);
		
			if (!etUsername.Compare(dbUsername) && !etPassword.Compare(dbPassword)){
				ShowWindow(SW_HIDE);

				//�����׽���
				m_mySocket.Create();
				//���ӷ�����
				m_mySocket.Connect(_T("100.64.238.119"), 6666);
				
			    //m_mySocket.Connect(_T("127.0.0.1"), 6666);
				mainDlg mainDlg;
				mainDlg.DoModal();
				break;

			}
			else
			{
				MessageBox(_T("�û�������������������ԣ�"), _T("��ܰ��ʾ"), MB_OKCANCEL|MB_ICONEXCLAMATION);
				break;
			}

		}

	}
	mysql_close(&m_sqlCon);
	mysql_server_end();
}
