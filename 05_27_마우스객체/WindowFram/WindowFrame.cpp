#include "WindowFrame.h"

CWindowFrame* CWindowFrame::mPthis=NULL;

CWindowFrame* CWindowFrame::Create(HINSTANCE _hinstance)
{
	if(!mPthis)
	{
		mPthis=new CWindowFrame();
	}

	CWindowFrame::GetInstance()->mhInstance=_hinstance;

	return mPthis;
}

CWindowFrame* CWindowFrame::GetInstance()
{	
	return mPthis;
}

void CWindowFrame::Destroy()
{
	if(mPthis)
	{
		delete mPthis;
		mPthis=NULL;
	}
}

LRESULT CALLBACK CWindowFrame::WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static bool Draw;
	TCHAR str[128]=TEXT("윈도우 클래스화");

	switch (iMessage) {

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_RBUTTONDOWN:
		InvalidateRect(hWnd, NULL, TRUE);
		return 0;
	case WM_LBUTTONDOWN:
		Mouse::GetInstance()->SetMousePt(LOWORD(lParam), HIWORD(lParam));
		Draw = true;
		return 0;
	case WM_MOUSEMOVE:
		if (Draw)
		{
			hdc = GetDC(hWnd);
			MoveToEx(hdc, Mouse::GetInstance()->GetMousePt().x, Mouse::GetInstance()->GetMousePt().y, NULL);
			Mouse::GetInstance()->SetMousePt(LOWORD(lParam), HIWORD(lParam));
			LineTo(hdc, Mouse::GetInstance()->GetMousePt().x, Mouse::GetInstance()->GetMousePt().y);
			ReleaseDC(hWnd, hdc);
		}
		return 0;
	case WM_LBUTTONUP:
		Draw = false;
		return 0;
	case WM_PAINT:
		hdc=BeginPaint(hWnd, &ps);		
		TextOut(hdc, 10,10, str, lstrlen(str));
		EndPaint(hWnd, &ps);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}

int CWindowFrame::Run(MSG _msg)
{
	TranslateMessage(&_msg);
	DispatchMessage(&_msg);

	return _msg.wParam;
}

void CWindowFrame::Initialize()
{
}

void CWindowFrame::BuildWindow()
{	
	WNDCLASS WndClass;
	
	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	WndClass.hInstance=CWindowFrame::GetInstance()->mhInstance;
	WndClass.lpfnWndProc=CWindowFrame::GetInstance()->WndProc;
	WndClass.lpszClassName=TEXT("exam");
	WndClass.lpszMenuName=NULL;
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	mhWnd=CreateWindow(TEXT("exam"),TEXT("exam"),WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL,(HMENU)NULL,mhInstance,NULL);

	ShowWindow(mhWnd, SW_SHOW);
}