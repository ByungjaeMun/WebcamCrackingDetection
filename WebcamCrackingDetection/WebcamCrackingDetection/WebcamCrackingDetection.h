
// WebcamCrackingDetection.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CWebcamCrackingDetectionApp:
// �� Ŭ������ ������ ���ؼ��� WebcamCrackingDetection.cpp�� �����Ͻʽÿ�.
//

class CWebcamCrackingDetectionApp : public CWinApp
{
public:
	CWebcamCrackingDetectionApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CWebcamCrackingDetectionApp theApp;