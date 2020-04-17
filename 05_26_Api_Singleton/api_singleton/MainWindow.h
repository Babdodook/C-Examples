#pragma once
#include"Global.h"

/*	WinMain Ŭ����ȭ
 *
 *			������
 *	������ Ŭ���� ��� �Լ�
 *	���� ������ ���� �Լ�
 *	�޽��� ó�� ����� (�޽��� ����)
 *	WndProc �Լ� (�޽��� ó�� �Լ�)
 */


class MainWindow {
public:
	MainWindow(HINSTANCE, const char*, const char*, int);
	~MainWindow();

	static MainWindow* Create(HINSTANCE,const char*,const char*,int);
	static MainWindow* GetInstance();
	void Destroy();

	void Init();				//������ Ŭ���� ���
	void createWindow();		//���� ������ ����
	int MessageLoop();			//�޽��� ó�� �����

	//������ Ŭ���� ��� �� �޸𸮿� �ø��� ���� static���� ����
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
private:
	static MainWindow* Pthis;

	HWND hWnd;				//������ �ڵ� ��
	char className[10];		//������ Ŭ���� �̸�
	HINSTANCE g_hInst;		//�ν��Ͻ� �ڵ� ��
	char commandLine[10];		//IpCmdLine ��
	int commandShow;			//nCmdShow ��
};