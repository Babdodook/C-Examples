#include "MainWindow.h"

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	MainWindow::Create(hInstance, "MainWindow", lpszCmdParam, nCmdShow);
	MainWindow::GetInstance()->Init();
	MainWindow::GetInstance()->createWindow();
	MainWindow::GetInstance()->MessageLoop();
	MainWindow::GetInstance()->Destroy();
}