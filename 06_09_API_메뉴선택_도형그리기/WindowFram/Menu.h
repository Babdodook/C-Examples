#ifndef _CMENU_H
#define _CMENU_H
#include "Global.h"
#include "DragCircleDrawing.h"
#include "DragFreeLineDrawing.h"
#include "DragRectangleDrawing.h"
#include "DragLineDrawing.h"

class CMenu
{
	HWND		mHmainWnd;
	HMENU		mHmenu;	
	int			mMenuId;
	int			mSelectMenu;

	CDragDrawing*		mDrawing;
	COLORREF PenColor;
	COLORREF BrushColor;
	int PenPt = 5;

public:
	CMenu(){}
	~CMenu(){}

	void	MenuInitialize(int _id, HWND _hwnd);

	void	ProcessCommandMeg(WPARAM _wparam);
	void	RectangleCmd(WPARAM _wparam);
	void	EllipseCmd(WPARAM _wparam);
	void	LineCmd(WPARAM _wparam);
	void	FreeLineCmd(WPARAM _wparam);

	HMENU	GetMenuHandle() const{return mHmenu;}
	int		GetSelectMenu() const{return mSelectMenu;}
	int		GetMenuId()const {return mMenuId;}

	void	SetMenuHandle(HMENU _hmenu);
	void	SetSelectMenu(int _menu);
	void	SetMenuId(int _id){mMenuId=_id;}

	void	SetDrawing(CDragDrawing* _draw)
	{
		mDrawing = _draw;
	}

	void	Drawing(CBackBit* _backbit, int _drawmode)
	{
		mDrawing->DragDrawing(_backbit, this->BrushColor, this->PenColor, this->PenPt, _drawmode);
	}

	void  SetDrawStartPoint(int _x, int _y)
	{
		mDrawing->SetStartp_x(_x);
		mDrawing->SetStartp_y(_y);
	}

	bool IsSelectDraw()
	{
		if (mDrawing != nullptr)
		{
			return true;
		}

		return false;
	}

};

#endif