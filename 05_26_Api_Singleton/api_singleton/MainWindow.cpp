#include"MainWindow.h"

MainWindow* MainWindow::Pthis = nullptr;

MainWindow* MainWindow::Create(HINSTANCE g_hInst, const char* className, const char* commandLine, int commandShow)
{
	if (Pthis == nullptr)
	{
		//생성자로 넘겨준다
		Pthis = new MainWindow(g_hInst,className,commandLine,commandShow);
	}
	return Pthis;
}

MainWindow* MainWindow::GetInstance()
{
	return Pthis;
}

void MainWindow::Destroy()
{
	if (Pthis)
		delete Pthis;
}

//생성자에서 필요한 핸들값, 인스턴스값, 윈도우 클래스 이름 초기화
MainWindow::MainWindow(HINSTANCE g_hInst, const char* className, const char* commandLine, int commandShow)
{
	this->hWnd = nullptr;
	this->g_hInst = g_hInst;
	strcpy(this->className, className);
	strcpy(this->commandLine, commandLine);
	this->commandShow = commandShow;
}

MainWindow::~MainWindow()
{
	if (hWnd != nullptr)		//윈도우가 생성되어 있다면 제거
	{
		DestroyWindow(hWnd);
	}
}

//윈도우 클래스 등록
void MainWindow::Init()
{
	WNDCLASS WndClass;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = g_hInst;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = className;
	WndClass.lpszMenuName = NULL;
	WndClass.style = NULL;

	RegisterClass(&WndClass);
}

//메인 윈도우 생성
void MainWindow::createWindow()
{
	hWnd = CreateWindow(className, className, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, g_hInst, NULL);

	ShowWindow(hWnd, commandShow);
}

//메시지 처리 수행부
int MainWindow::MessageLoop()
{
	MSG Message;

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

//윈도우 프로시저, 메시지 처리
LRESULT CALLBACK MainWindow::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}