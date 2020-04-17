#include"MainWindow.h"

MainWindow* MainWindow::Pthis = nullptr;

MainWindow* MainWindow::Create(HINSTANCE g_hInst, const char* className, const char* commandLine, int commandShow)
{
	if (Pthis == nullptr)
	{
		//�����ڷ� �Ѱ��ش�
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

//�����ڿ��� �ʿ��� �ڵ鰪, �ν��Ͻ���, ������ Ŭ���� �̸� �ʱ�ȭ
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
	if (hWnd != nullptr)		//�����찡 �����Ǿ� �ִٸ� ����
	{
		DestroyWindow(hWnd);
	}
}

//������ Ŭ���� ���
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

//���� ������ ����
void MainWindow::createWindow()
{
	hWnd = CreateWindow(className, className, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, (HMENU)NULL, g_hInst, NULL);

	ShowWindow(hWnd, commandShow);
}

//�޽��� ó�� �����
int MainWindow::MessageLoop()
{
	MSG Message;

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return (int)Message.wParam;
}

//������ ���ν���, �޽��� ó��
LRESULT CALLBACK MainWindow::WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}