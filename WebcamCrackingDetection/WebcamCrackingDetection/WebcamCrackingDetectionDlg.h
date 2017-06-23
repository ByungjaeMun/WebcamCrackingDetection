#include <string>
#include <fstream>
#include <locale.h> 
#include <Windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>
#include "Database_Interface.h"
#include "afxwin.h"

#pragma warning(disable:4996)
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

// WebcamCrackingDetectionDlg.h : 헤더 파일
//

#pragma once


// CWebcamCrackingDetectionDlg 대화 상자
class CWebcamCrackingDetectionDlg : public CDialogEx
{
// 생성입니다.
public:
	CWebcamCrackingDetectionDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

private:
	
//	Database_Interface* db;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WEBCAMCRACKINGDETECTION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedShowlist();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	BOOLEAN IsPortStatusSafe();
	void KillMalicioutProcess();
	void AddAttackRecord();
	//int windows_system(const char* prog, const char *cmd);
	//int SaveNetstat();
	afx_msg void OnBnClickedButton2();
	CStatic m_pic;
};
