#include "Menu.h"

void CMenu::MenuInitialize(int _id, HWND _hwnd)
{
	mHmainWnd = _hwnd;
	mHmenu = GetMenu(mHmainWnd);
	mMenuId=_id;
	mDrawing = nullptr;

	BrushColor = RGB(255, 0, 0);
	PenColor = RGB(255, 0, 0);
	PenPt = 1;
}
void CMenu::ProcessCommandMeg(WPARAM _wparam)
{
	RectangleCmd(_wparam);
	EllipseCmd(_wparam);
	LineCmd(_wparam);
	FreeLineCmd(_wparam);
}

void CMenu::RectangleCmd(WPARAM _wparam)
{
	switch (LOWORD(_wparam))
	{
	case ID_Rect1_RED:
		PenColor = RGB(255, 0, 0);
		mSelectMenu = RECTANGLE;
		mDrawing = CDragRectangleDrawing::GetInstance();
		break;
	case ID_Rect1_BLUE:
		PenColor = RGB(0, 0, 255);
		mSelectMenu = RECTANGLE;
		mDrawing = CDragRectangleDrawing::GetInstance();
		break;
	case ID_Rect1_GREEN:
		PenColor = RGB(0, 255, 0);
		mSelectMenu = RECTANGLE;
		mDrawing = CDragRectangleDrawing::GetInstance();
		break;
	case ID_Rect2_RED:
		BrushColor = RGB(255, 0, 0);
		mSelectMenu = RECTANGLE;
		mDrawing = CDragRectangleDrawing::GetInstance();
		break;
	case ID_Rect2_BLUE:
		BrushColor = RGB(0, 0, 255);
		mSelectMenu = RECTANGLE;
		mDrawing = CDragRectangleDrawing::GetInstance();
		break;
	case ID_Rect2_GREEN:
		BrushColor = RGB(0, 255, 0);
		mSelectMenu = RECTANGLE;
		mDrawing = CDragRectangleDrawing::GetInstance();
		break;
	case ID_Rect3_1:
		PenPt = 1;
		mSelectMenu = RECTANGLE;
		mDrawing = CDragRectangleDrawing::GetInstance();
		break;
	case ID_Rect3_3:
		PenPt = 3;
		mSelectMenu = RECTANGLE;
		mDrawing = CDragRectangleDrawing::GetInstance();
		break;
	case ID_Rect3_5:
		PenPt = 5;
		mSelectMenu = RECTANGLE;
		mDrawing = CDragRectangleDrawing::GetInstance();
		break;
	}
}

void CMenu::EllipseCmd(WPARAM _wparam)
{
	switch (LOWORD(_wparam))
	{
	case ID_EL1_RED:
		PenColor = RGB(255, 0, 0);
		mSelectMenu = CIRCLE;
		mDrawing = CDragCircleDrawing::GetInstance();
		break;
	case ID_EL1_BLUE:
		PenColor = RGB(0, 0, 255);
		mSelectMenu = CIRCLE;
		mDrawing = CDragCircleDrawing::GetInstance();
		break;
	case ID_EL1_GREEN:
		PenColor = RGB(0, 255, 0);
		mSelectMenu = CIRCLE;
		mDrawing = CDragCircleDrawing::GetInstance();
		break;
	case ID_EL2_RED:
		BrushColor = RGB(255, 0, 0);
		mSelectMenu = CIRCLE;
		mDrawing = CDragCircleDrawing::GetInstance();
		break;
	case ID_EL2_BLUE:
		BrushColor = RGB(0, 0, 255);
		mSelectMenu = CIRCLE;
		mDrawing = CDragCircleDrawing::GetInstance();
		break;
	case ID_EL2_GREEN:
		BrushColor = RGB(0, 255, 0);
		mSelectMenu = CIRCLE;
		mDrawing = CDragCircleDrawing::GetInstance();
		break;
	case ID_EL3_1:
		PenPt = 1;
		mSelectMenu = CIRCLE;
		mDrawing = CDragCircleDrawing::GetInstance();
		break;
	case ID_EL3_3:
		PenPt = 3;
		mSelectMenu = CIRCLE;
		mDrawing = CDragCircleDrawing::GetInstance();
		break;
	case ID_EL3_5:
		PenPt = 5;
		mSelectMenu = CIRCLE;
		mDrawing = CDragCircleDrawing::GetInstance();
		break;
	}
}

void CMenu::LineCmd(WPARAM _wparam)
{
	switch (LOWORD(_wparam))
	{
	case ID_LINE1_RED:
		PenColor = RGB(255, 0, 0);
		mSelectMenu = LINE;
		mDrawing = CDragLineDrawing::GetInstance();
		break;
	case ID_LINE1_BLUE:
		PenColor = RGB(0, 0, 255);
		mSelectMenu = LINE;
		mDrawing = CDragLineDrawing::GetInstance();
		break;
	case ID_LINE1_GREEN:
		PenColor = RGB(0, 255, 0);
		mSelectMenu = LINE;
		mDrawing = CDragLineDrawing::GetInstance();
		break;
	case ID_LINE2_1:
		PenPt = 1;
		mSelectMenu = LINE;
		mDrawing = CDragLineDrawing::GetInstance();
		break;
	case ID_LINE2_3:
		PenPt = 3;
		mSelectMenu = LINE;
		mDrawing = CDragLineDrawing::GetInstance();
		break;
	case ID_LINE2_5:
		PenPt = 5;
		mSelectMenu = LINE;
		mDrawing = CDragLineDrawing::GetInstance();
		break;
	}
}

void CMenu::FreeLineCmd(WPARAM _wparam)
{
	switch (LOWORD(_wparam))
	{
	case ID_FLINE1_RED:
		PenColor = RGB(255, 0, 0);
		mSelectMenu = FREELINE;
		mDrawing = CDragFreeLineDrawing::GetInstance();
		break;
	case ID_FLINE1_BLUE:
		PenColor = RGB(0, 0, 255);
		mSelectMenu = FREELINE;
		mDrawing = CDragFreeLineDrawing::GetInstance();
		break;
	case ID_FLINE1_GREEN:
		PenColor = RGB(0, 255, 0);
		mSelectMenu = FREELINE;
		mDrawing = CDragFreeLineDrawing::GetInstance();
		break;
	case ID_FLINE2_1:
		PenPt = 1;
		mSelectMenu = FREELINE;
		mDrawing = CDragFreeLineDrawing::GetInstance();
		break;
	case ID_FLINE2_3:
		PenPt = 3;
		mSelectMenu = FREELINE;
		mDrawing = CDragFreeLineDrawing::GetInstance();
		break;
	case ID_FLINE2_5:
		PenPt = 5;
		mSelectMenu = FREELINE;
		mDrawing = CDragFreeLineDrawing::GetInstance();
		break;
	}
}

void CMenu::SetMenuHandle(HMENU _hmenu)
{
	mHmenu=_hmenu;
}

void CMenu::SetSelectMenu(int _menu)
{
	mSelectMenu=_menu;
}