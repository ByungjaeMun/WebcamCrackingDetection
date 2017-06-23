
// WebcamCrackingDetectionDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "WebcamCrackingDetection.h"
#include "WebcamCrackingDetectionDlg.h"
#include "afxdialogex.h"

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
}

BEGIN_MESSAGE_MAP(CWebcamCrackingDetectionDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHOWLIST, &CWebcamCrackingDetectionDlg::OnBnClickedShowlist)
END_MESSAGE_MAP()


// CWebcamCrackingDetectionDlg �޽��� ó����

BOOL CWebcamCrackingDetectionDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

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
	
	SetTimer(1, 5000, 0);
	
	//windows_system("C:\\windows\\system32\\cmd.exe","netstat -ano >> netstat.txt");

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



void CWebcamCrackingDetectionDlg::OnBnClickedShowlist()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	

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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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

		//file�� ����� ���ȴٸ�
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
				//str������ ���̸� ���� �� + 1�� �մϴ�.
				length = str.GetLength() + 1;

				//file�� integer ũ�⸸ŭ length���̸� ����
				file.Write(&length, sizeof(int));

				//file�� length ���̸�ŭ str�� ���ڿ��� �����մϴ�. 
				file.Write(str, length);

				
				str = "";
				tempStr = "";
			}

			//������ �ݽ��ϴ�.
			file.Close();

			//MessageBox�� ��� Ȯ���մϴ�.
			MessageBox("���忡 �����߽��ϴ�!", "�˸�", MB_OK | MB_ICONINFORMATION);
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
		// ..�� ���� ���� �� ������ ������ �����ϼ���.
		CWebcamCrackingDetectionDlg* pDlg = (CWebcamCrackingDetectionDlg*)AfxGetApp()->m_pMainWnd;
		pDlg->SaveNetstat();

		Sleep(1000);
	}
	return 0;
}
*/