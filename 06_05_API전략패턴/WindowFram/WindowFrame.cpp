#include "WindowFrame.h"
#include "BackBit.h"
#include "Mouse.h"
#include "DragDrawing.h"

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
	RECT crt;

	static CBackBit* backbit=NULL;
	static CMenu* menu=NULL;
	DrawProcess* Draw = new DrawProcess();

	switch (iMessage) {
	case WM_CREATE:
		CMouse::GetInstance()->Initialize(hWnd);
		GetClientRect(hWnd, &crt);
	    backbit=new CBackBit(hWnd, crt.right , crt.bottom );
		menu=new CMenu();
		menu->MenuInitialize(IDR_MENU1);
		return 0;
	case WM_LBUTTONDOWN:
		CMouse::GetInstance()->SetclickDown();			
		CDragDrawing::SetStartp_x((int)LOWORD(lParam));
		CDragDrawing::SetStartp_y((int)HIWORD(lParam));
		return 0;
	case WM_LBUTTONUP:	
		switch(menu->GetSelectMenu())
		{
		case FREELINE:
			Draw->SetDraw(new CFreeLine());
			Draw->Draw(backbit, CMouse::GetInstance(), NORMAL);
			break;
		case LINE:
			Draw->SetDraw(new CLine());
			Draw->Draw(backbit, CMouse::GetInstance(), NORMAL);
			break;
		case CIRCLE:
			Draw->SetDraw(new CCircle());
			Draw->Draw(backbit, CMouse::GetInstance(), NORMAL);
			break;
		case RECTANGLE:
			Draw->SetDraw(new CRectangle());
			Draw->Draw(backbit, CMouse::GetInstance(), NORMAL);
			break;
		}
		CMouse::GetInstance()->SetclickUp();
		return 0;
	case WM_COMMAND:
		menu->PorcessCommandMeg(wParam);
		return 0;
	case WM_MOUSEMOVE:		
		CMouse::GetInstance()->SetXY(lParam);			
		switch(menu->GetSelectMenu())
		{
		case FREELINE:
			Draw->SetDraw(new CFreeLine());
			Draw->Draw(backbit, CMouse::GetInstance(), REVERSE);
			break;
		case LINE:
			Draw->SetDraw(new CLine());
			Draw->Draw(backbit, CMouse::GetInstance(), REVERSE);
			break;
		case CIRCLE:
			Draw->SetDraw(new CCircle());
			Draw->Draw(backbit, CMouse::GetInstance(), REVERSE);
			break;
		case RECTANGLE:
			Draw->SetDraw(new CRectangle());
			Draw->Draw(backbit, CMouse::GetInstance(), REVERSE);
			break;
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		delete backbit;
		delete menu;
		return 0;
	case WM_PAINT:		
		hdc=BeginPaint(hWnd, &ps);			
		backbit->SCreenDraw(hdc, 0,0);
		EndPaint(hWnd, &ps);
		return 0;
	}
	return(DefWindowProc(hWnd,iMessage,wParam,lParam));
}

void CWindowFrame::Run(MSG _message)
{	
	TranslateMessage(&_message);
	DispatchMessage(&_message);
	
}

void CWindowFrame::Initialize()
{
	this->BuildWindow();
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
	WndClass.lpszMenuName=MAKEINTRESOURCE(IDR_MENU1);
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	mhWnd=CreateWindow(TEXT("exam"),TEXT("exam"),WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
		NULL,(HMENU)NULL,mhInstance,NULL);

	ShowWindow(mhWnd, SW_SHOW);
}