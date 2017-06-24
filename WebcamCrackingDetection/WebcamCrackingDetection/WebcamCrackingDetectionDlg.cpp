// WebcamCrackingDetectionDlg.cpp : ���� ����
//
#include "stdafx.h"
#include "WebcamCrackingDetection.h"
#include "WebcamCrackingDetectionDlg.h"
#include "afxdialogex.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


#define MYSQL_HOST  "localhost"
#define MYSQL_USER  "root"
#define MYSQL_PWD   "autoset"
#define MYSQL_DB "webcam"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CWebcamCrackingDetectionDlg ��ȭ ����
CWebcamCrackingDetectionDlg::CWebcamCrackingDetectionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WEBCAMCRACKINGDETECTION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CWebcamCrackingDetectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, m_pic);
	DDX_Control(pDX, IDC_DETECTED, m_detectedList);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
}

BEGIN_MESSAGE_MAP(CWebcamCrackingDetectionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHOWLIST, &CWebcamCrackingDetectionDlg::OnBnClickedShowlist)
	ON_BN_CLICKED(IDC_BUTTON2, &CWebcamCrackingDetectionDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CWebcamCrackingDetectionDlg �޽��� ó����
BOOL CWebcamCrackingDetectionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	count = 0;
	finished = false;

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	
	HBITMAP hbit;
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1));
	m_pic.SetBitmap(hbit);
	
	

	m_detectedList.SetExtendedStyle(LVS_EX_GRIDLINES);

	m_detectedList.InsertColumn(0, _T("������"), LVCFMT_CENTER, 70, -1);
	m_detectedList.InsertColumn(1, _T("��������"), LVCFMT_CENTER, 170, -1);
	m_detectedList.InsertColumn(2, _T("��Ʈ��ȣ"), LVCFMT_CENTER, 170, -1);

	m_progress.SetRange(0, 100);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CWebcamCrackingDetectionDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.
void CWebcamCrackingDetectionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CWebcamCrackingDetectionDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CWebcamCrackingDetectionDlg::InspectNetwork() 
{
	int cnt = 4;
	int parseTo = 0;
	CString fileName = _T("netstat.txt");
	CStdioFile file;
	CString netstatLine = _T("");

	CString string;

	setlocale(LC_ALL, "korean");
	if (file.Open(fileName, CFile::modeRead))
	{
		UINT nBytes = file.GetLength();
		if (nBytes >= 0)
		{
			while (file.ReadString(netstatLine))
			{
				m_progress.SetPos(nBytes);
				if (cnt > 0) {
					cnt--;
					continue;
				}

				//rStr += strLine;
				protocol = "";
				localAddr = "";
				outAddr = "";
				status = "";
				pid = "";

				//60���� �Ұ�����?
				for (int i = 0; i < 60; i++)
				{
					AfxExtractSubString(string, netstatLine, i, ' ');
					if (string == "")
						continue;
					else
			{
						if (parseTo == 0)
							protocol = string;
						else if (parseTo == 1)
							localAddr = string;
						else if (parseTo == 2)
							outAddr = string;
						else if (parseTo == 3)
							status = string;
						else if (parseTo == 4)
							pid = string;

						parseTo++;
						if (parseTo == 5)
						{
							parseTo = 0;
							break;
						}
					}
				}

				CheckSafetyOfPort();
			}
		}
		file.Close();

		
		
		for (int i = 0; i < count; i++)
		{
			m_detectedList.InsertItem(0, "����");
		}

		for (int i = 0; i < count; i++)
		{

			//m_detectedList.SetItem(i, 0, LVIF_TEXT, "����", 0, 0, 0, NULL);
			m_detectedList.SetItem(i, 1, LVIF_TEXT, ptarray[i], 0, 0, 0, NULL);
			m_detectedList.SetItem(i, 2, LVIF_TEXT, ptNarray[i], 0, 0, 0, NULL);
		}

		for (int j = 0; j < count; j++)
		{
			ptarray[j] = "";
			ptNarray[j] = "";
		}

		KillTimer(1);
		count = 0;
		finished = false;
	}
}


void CWebcamCrackingDetectionDlg::OnBnClickedShowlist()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰���
	// AddAttackRecord �޼ҵ带 ���� ������ ������ ������ ����Ʈ�� ���� ���
	if (!finished)
	{
		SetTimer(1, 1000, 0);
		finished = true;
	}
	m_detectedList.DeleteAllItems();
	m_progress.SetPos(0);
}

void CWebcamCrackingDetectionDlg::CheckSafetyOfPort()
{
	// DB connection -> Select port_list �� protocol�� port_number ��
	//��ġ�� ��� return false; ������ return true;
	CString port_number = "";
	CString string;

	for (int i = 0; i < 2; i++)
{
		AfxExtractSubString(string, localAddr, i, ':');

		if (i == 1)
			port_number = string;
}
	mysql_init(&mysql);

	if (!mysql_real_connect(&mysql, MYSQL_HOST, MYSQL_USER, MYSQL_PWD, MYSQL_DB, 3306, 0, 0))
	{
		MessageBox(mysql_error(&mysql), MB_OK);
		mysql_close(&mysql);
	}
	else
	{
		strQuery.Format(_T("SELECT `type`, `port` FROM `dangerous` WHERE 1"));

		if (mysql_query(&mysql, CStringA(strQuery))) // ���� ��û
		{
			MessageBox("���� ����");
		}
		else
		{
			m_Res = mysql_store_result(&mysql);

			while (row = mysql_fetch_row(m_Res))
			{
				if ( (protocol == CString(row[0])) && (port_number == CString(row[1])) )
				{
					MessageBox("�����Ұ� ����Ǿ����ϴ�!","!����!");
					ptarray[count] = protocol;
					ptNarray[count] = port_number;

					count++;
				}
			}
			mysql_free_result(m_Res); // m_Res ����
		}
		mysql_close(&mysql);
	}

	mysql_close(&mysql);
	/*
	// DB�� �������ݰ� ��Ʈ �ѹ� ��
	if (protocol == "TCP" && port_number == "135") {
		//KillMaliciousProcess(pid);
		AddAttackRecord();
	}*/
}

void CWebcamCrackingDetectionDlg::KillMaliciousProcess(CString pid)
{
	CString tmpcmd = "C:\\windows\\system32\\cmd.exe /c Taskkill /PID " + pid ;
	CString cmd = tmpcmd + "/F";
	WinExec(cmd, SW_HIDE);
}

void CWebcamCrackingDetectionDlg::AddAttackRecord()
{
	// netstatLine (��������, �����ּ�, �ܺ��ּ�, ����, pid ��� ����)
	// �� listView�� �߰��Ѵ�.
}


void CWebcamCrackingDetectionDlg::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case 1:
		//system("netstat -ano >> netstat.txt");
		WinExec("C:\\windows\\system32\\cmd.exe /c netstat -ano > netstat.txt", SW_HIDE);
		InspectNetwork();
		
		break;
	}
	
	//KillTimer(1);
}

	

void CWebcamCrackingDetectionDlg::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	cv::VideoCapture vc(0); //0����ķ �ʱ�ȭ
	cv::Mat img;
	int webcam_time = 1;
	m_progress.SetPos(0);

	while (webcam_time) {
		vc >> img;
		if (img.empty())
		{
			m_progress.SetPos(100);
			MessageBox("��ķ�� �������Դϴ�. �����մϴ�!","���");
			break;
		}
		else
		{
			m_progress.SetPos(100);
			MessageBox("��ķ ����X, �Ƚ��ϼŵ� �˴ϴ�.", "�Ƚ�");
			break;
		}
	}
}
