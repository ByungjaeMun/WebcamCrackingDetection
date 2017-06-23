
// WebcamCrackingDetectionDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "WebcamCrackingDetection.h"
#include "WebcamCrackingDetectionDlg.h"
#include "afxdialogex.h"

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
}

BEGIN_MESSAGE_MAP(CWebcamCrackingDetectionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHOWLIST, &CWebcamCrackingDetectionDlg::OnBnClickedShowlist)
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



void CWebcamCrackingDetectionDlg::OnBnClickedShowlist()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	

	CString fileName = _T("netstat.txt");
	CStdioFile file;
	CString rStr = _T("");
	CString strLine = _T("");

	setlocale(LC_ALL, "korean");
	if (file.Open(fileName, CFile::modeRead))
	{
		UINT nBytes = file.GetLength();
		if (nBytes >= 0)
		{
			while (file.ReadString(strLine))
			{
				rStr += strLine;
			}
		}
		file.Close();
	}

	MessageBox(rStr, _T("Error"),MB_ICONERROR | MB_OK);
}


void CWebcamCrackingDetectionDlg::OnTimer(UINT nIDEvent)
{
	switch (nIDEvent)
	{
	case 1:
		//system("netstat -ano >> netstat.txt");
		WinExec("C:\\windows\\system32\\cmd.exe /c netstat -ano >> netstat.txt", SW_HIDE);
		break;
	}
	KillTimer(1);
}

/*
int CWebcamCrackingDetectionDlg::SaveNetstat() 
{
	
	return 0;
}

int CWebcamCrackingDetectionDlg::windows_system(const char* prog,  const char *cmd)
{
	PROCESS_INFORMATION p_info;
	STARTUPINFO s_info;
	LPSTR cmdline, programpath;

	memset(&s_info, 0, sizeof(s_info));
	memset(&p_info, 0, sizeof(p_info));
	s_info.cb = sizeof(s_info);

	cmdline = _tcsdup(TEXT(cmd));
	programpath = _tcsdup(TEXT(prog));

	if (CreateProcess(programpath, cmdline, NULL, NULL, 0, 0, NULL, NULL, &s_info, &p_info))
	{
		WaitForSingleObject(p_info.hProcess, INFINITE);
		CloseHandle(p_info.hProcess);
		CloseHandle(p_info.hThread);
	}
	return 0;
}
int CWebcamCrackingDetectionDlg::SaveNetstat()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str="", tempStr ="";
	CFile file;
	int length;

	// Declare and initialize variables
	PMIB_TCPTABLE pTcpTable;
	DWORD dwSize = 0;
	DWORD dwRetVal = 0;


	char szLocalAddr[128];
	char szRemoteAddr[128];

	struct in_addr IpAddr;

	int i;

	pTcpTable = (MIB_TCPTABLE *)MALLOC(sizeof(MIB_TCPTABLE));
	if (pTcpTable == NULL) {
		//printf("Error allocating memory\n");
		MessageBox("Error allocating memory\n", "", NULL);
		return 1;
	}

	dwSize = sizeof(MIB_TCPTABLE);
	// Make an initial call to GetTcpTable to
	// get the necessary size into the dwSize variable
	if ((dwRetVal = GetTcpTable(pTcpTable, &dwSize, TRUE)) ==
		ERROR_INSUFFICIENT_BUFFER) {
		FREE(pTcpTable);
		pTcpTable = (MIB_TCPTABLE *)MALLOC(dwSize);
		if (pTcpTable == NULL) {
			//printf("Error allocating memory\n");
			MessageBox("Error allocating memory\n", "", NULL);
			return 1;
		}
	}

	
	// Make a second call to GetTcpTable to get
	// the actual data we require
	if ((dwRetVal = GetTcpTable(pTcpTable, &dwSize, TRUE)) == NO_ERROR) {
		printf("\tNumber of entries: %d\r\n", (int)pTcpTable->dwNumEntries);

		//file이 제대로 열렸다면
		if (file.Open("netstat.txt", CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate))
		{

			for (i = 0; i < (int)pTcpTable->dwNumEntries; i++) {
				IpAddr.S_un.S_addr = (u_long)pTcpTable->table[i].dwLocalAddr;
				strcpy_s(szLocalAddr, sizeof(szLocalAddr), inet_ntoa(IpAddr));
				IpAddr.S_un.S_addr = (u_long)pTcpTable->table[i].dwRemoteAddr;
				strcpy_s(szRemoteAddr, sizeof(szRemoteAddr), inet_ntoa(IpAddr));

				str.Format("\r\n\tTCP[%d] State: %ld - ", i,pTcpTable->table[i].dwState);
				//printf("\n\tTCP[%d] State: %ld - ", i,
				//	pTcpTable->table[i].dwState);
				switch (pTcpTable->table[i].dwState) {
				case MIB_TCP_STATE_CLOSED:
					//printf("CLOSED\n");
					str += "CLOSED\r\n";
					break;
				case MIB_TCP_STATE_LISTEN:
					//printf("LISTEN\n");
					str += "LISTEN\r\n";
					break;
				case MIB_TCP_STATE_SYN_SENT:
					//printf("SYN-SENT\n");
					str += "SYN-SENT\r\n";
					break;
				case MIB_TCP_STATE_SYN_RCVD:
					//printf("SYN-RECEIVED\n");
					str += "SYN-RECEIVED\r\n";
					break;
				case MIB_TCP_STATE_ESTAB:
					//printf("ESTABLISHED\n");
					str += "ESTABLISHED\r\n";
					break;
				case MIB_TCP_STATE_FIN_WAIT1:
					//printf("FIN-WAIT-1\n");
					str += "FIN-WAIT-1\r\n";
					break;
				case MIB_TCP_STATE_FIN_WAIT2:
					//printf("FIN-WAIT-2 \n");
					str += "FIN-WAIT-2\r\n";
					break;
				case MIB_TCP_STATE_CLOSE_WAIT:
					//printf("CLOSE-WAIT\n");
					str += "CLOSE-WAIT\r\n";
					break;
				case MIB_TCP_STATE_CLOSING:
					//printf("CLOSING\n");
					str += "CLOSING\r\n";
					break;
				case MIB_TCP_STATE_LAST_ACK:
					//printf("LAST-ACK\n");
					str += "LAST-ACK\r\n";
					break;
				case MIB_TCP_STATE_TIME_WAIT:
					//printf("TIME-WAIT\n");
					str += "TIME-WAIT\r\n";
					break;
				case MIB_TCP_STATE_DELETE_TCB:
					//printf("DELETE-TCB\n");
					str += "DELETE-TCB\r\n";
					break;
				default:
					//printf("UNKNOWN dwState value\n");
					str += "UNKNOWN dwState value\r\n";
					break;
				}


				tempStr.Format("\tTCP[%d] Local Addr: %s\r\n\tTCP[%d] Local Port: %d \r\n\tTCP[%d] Remote Addr: %s\r\n\tTCP[%d] Remote Port: %d\r\n", i, szLocalAddr, i,
					ntohs((u_short)pTcpTable->table[i].dwLocalPort), i, szRemoteAddr, i,
					ntohs((u_short)pTcpTable->table[i].dwRemotePort));
				//printf("\tTCP[%d] Local Addr: %s\n", i, szLocalAddr);
				//printf("\tTCP[%d] Local Port: %d \n", i,
				//	ntohs((u_short)pTcpTable->table[i].dwLocalPort));
				//printf("\tTCP[%d] Remote Addr: %s\n", i, szRemoteAddr);
				//printf("\tTCP[%d] Remote Port: %d\n", i,
				//	ntohs((u_short)pTcpTable->table[i].dwRemotePort));
				
				str += tempStr;
				//str변수의 길이를 구한 후 + 1을 합니다.
				length = str.GetLength() + 1;

				//file에 integer 크기만큼 length길이를 쓰고
				file.Write(&length, sizeof(int));

				//file에 length 길이만큼 str의 문자열을 저장합니다. 
				file.Write(str, length);

				
				str = "";
				tempStr = "";
			}

			//파일을 닫습니다.
			file.Close();

			//MessageBox를 띄워 확인합니다.
			MessageBox("저장에 성공했습니다!", "알림", MB_OK | MB_ICONINFORMATION);
		}
	}
	else {
		//printf("\tGetTcpTable failed with %d\n", dwRetVal);
		MessageBox("\tGetTcpTable failed with"+ dwRetVal, "", NULL);
		FREE(pTcpTable);
		return 1;
	}

	if (pTcpTable != NULL) {
		FREE(pTcpTable);
		pTcpTable = NULL;
	}
	
}


UINT CWebcamCrackingDetectionDlg::ThreadFirst(LPVOID _mothod)
{
	CWebcamCrackingDetectionDlg *fir = (CWebcamCrackingDetectionDlg*)_mothod;

	while (1)
	{
		// ..이 곳에 루프 시 수행할 동작을 선언하세요.
		CWebcamCrackingDetectionDlg* pDlg = (CWebcamCrackingDetectionDlg*)AfxGetApp()->m_pMainWnd;
		pDlg->SaveNetstat();

		Sleep(1000);
	}
	return 0;
}
*/