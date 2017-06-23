// WebcamCrackingDetectionDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "WebcamCrackingDetection.h"
#include "WebcamCrackingDetectionDlg.h"
#include "afxdialogex.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CWebcamCrackingDetectionDlg 대화 상자



CWebcamCrackingDetectionDlg::CWebcamCrackingDetectionDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WEBCAMCRACKINGDETECTION_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CWebcamCrackingDetectionDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, m_pic);
}

BEGIN_MESSAGE_MAP(CWebcamCrackingDetectionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHOWLIST, &CWebcamCrackingDetectionDlg::OnBnClickedShowlist)
	ON_BN_CLICKED(IDC_BUTTON2, &CWebcamCrackingDetectionDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CWebcamCrackingDetectionDlg 메시지 처리기

BOOL CWebcamCrackingDetectionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.


	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	
	HBITMAP hbit;
	hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1));
	m_pic.SetBitmap(hbit);
	
	SetTimer(1, 5000, 0);
	
	//windows_system("C:\\windows\\system32\\cmd.exe","netstat -ano >> netstat.txt");

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CWebcamCrackingDetectionDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		
		/*
		CBitmap bmp;
		bmp.LoadBitmap(IDB_BITMAP1);
		((CStatic *)GetDlgItem(IDC_PIC))->SetBitmap((HBITMAP)bmp.GetSafeHandle());
		*/
		/*
		CStatic* PictureControlt = (CStatic*)GetDlgItem(IDC_PIC);
		CBitmap image;
		image.LoadBitmap(IDB_BITMAP1);
		PictureControlt->SetBitmap(image);
		*/
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
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
							break;
					}
				}

				CheckSafetyOfPort();
			}
		}
		file.Close();
	}

	//MessageBox(rStr, _T("Error"),MB_ICONERROR | MB_OK);
}


void CWebcamCrackingDetectionDlg::OnBnClickedShowlist()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// AddAttackRecord 메소드를 통해 저장한 공격자 정보를 리스트를 통해 출력

}

void CWebcamCrackingDetectionDlg::CheckSafetyOfPort()
{
	// DB connection -> Select port_list 후 protocol과 port_number 비교 일치할 경우 return false; 없으면 return true;
	CString port_number = "";
	CString string;

	for (int i = 0; i < 2; i++)
{
		AfxExtractSubString(string, localAddr, i, ':');

		if (i == 1)
			port_number = string;
}

	// DB의 프로토콜과 포트 넘버 비교
	if (protocol == "TCP" && port_number == "135") {
		//KillMaliciousProcess(pid);
		AddAttackRecord();
	}
}

void CWebcamCrackingDetectionDlg::KillMaliciousProcess(CString pid)
{
	CString tmpcmd = "C:\\windows\\system32\\cmd.exe /c Taskkill /PID " + pid ;
	CString cmd = tmpcmd + "/F";
	WinExec(cmd, SW_HIDE);
}

void CWebcamCrackingDetectionDlg::AddAttackRecord()
{
	// netstatLine (프로토콜, 로컬주소, 외부주소, 상태, pid 모두 있음)
	// 을 listView에 추가한다.
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
	KillTimer(1);
}

	
// db select example
/*

/*


mysql_init(&m_MySql);



if (mysql_real_connect(&m_MySql, DB_ADDRESS, DB_ID, DB_PASS, DB_NAME, 3306, NULL, 0) == NULL)
{ // 디비 접속
return;
}

strQuery.Format(_T("SELECT id FROM user WHERE id ='%s' "), _T("CL"));

if (mysql_query(&m_MySql, CStringA(strQuery))) // 쿼리 요청
{
AfxMessageBox(_T("쿼리 에러"));
return;
}

if ((m_Res = mysql_store_result(&m_MySql)) == NULL) // 결과를 m_Res에 저장
{
return;
}
row = mysql_fetch_row(m_Res); //m_Res의 값을 row로 저장해서 하나씩 갖고 오기


중략.....


mysql_free_result(m_Res); // m_Res 삭제
mysql_close(&m_MySql); // m_MySql 삭제



*/

void CWebcamCrackingDetectionDlg::OnBnClickedButton2()
{
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	cv::VideoCapture vc(0); //0번웹캠 초기화
	cv::Mat img;
	while (1) {
		vc >> img;
		if (img.empty())
		{
			/*
			if (IDYES == MessageBox("해킹중입니다. 웹캠을 끄시겠습니까?", "경고", MB_YESNO))
			{
				MessageBox("네 꺼주세요");
			}
			else
				if (IDNO)
				{
					MessageBox("아니요");
				}
*/
			MessageBox("웹캠이 실행중입니다. 위험합니다!","경고");
			break;
		}
		else
		{
			MessageBox("웹캠 실행X, 안심하셔도 됩니다.");
			break;
		}
	}
}
