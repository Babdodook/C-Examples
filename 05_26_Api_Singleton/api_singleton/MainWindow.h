#pragma once
#include"Global.h"

/*	WinMain 클래스화
 *
 *			구현부
 *	윈도우 클래스 등록 함수
 *	메인 윈도우 생성 함수
 *	메시지 처리 수행부 (메시지 루프)
 *	WndProc 함수 (메시지 처리 함수)
 */


class MainWindow {
public:
	MainWindow(HINSTANCE, const char*, const char*, int);
	~MainWindow();

	static MainWindow* Create(HINSTANCE,const char*,const char*,int);
	static MainWindow* GetInstance();
	void Destroy();

	void Init();				//윈도우 클래스 등록
	void createWindow();		//메인 윈도우 생성
	int MessageLoop();			//메시지 처리 수행부

	//윈도우 클래스 등록 시 메모리에 올리기 위해 static으로 선언
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
private:
	static MainWindow* Pthis;

	HWND hWnd;				//윈도우 핸들 값
	char className[10];		//윈도우 클래스 이름
	HINSTANCE g_hInst;		//인스턴스 핸들 값
	char commandLine[10];		//IpCmdLine 값
	int commandShow;			//nCmdShow 값
};