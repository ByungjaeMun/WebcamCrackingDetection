#include <string>
#include <fstream>
#include <locale.h> 
#include <Windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <stdio.h>
#include "Database_Interface.h"

#pragma warning(disable:4996)
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

#define MALLOC(x) HeapAlloc(GetProcessHeap(), 0, (x))
#define FREE(x) HeapFree(GetProcessHeap(), 0, (x))

// WebcamCrackingDetectionDlg.h : ��� ����
//

#pragma once


// CWebcamCrackingDetectionDlg ��ȭ ����
class CWebcamCrackingDetectionDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CWebcamCrackingDetectionDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

private:
	
	Database_Interface* db;

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WEBCAMCRACKINGDETECTION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedShowlist();
	afx_msg void OnTimer(UINT nIDEvent);
	BOOLEAN IsPortStatusSafe();
	void KillMalicioutProcess();
	void AddAttackRecord();
	//int windows_system(const char* prog, const char *cmd);
	//int SaveNetstat();
};
