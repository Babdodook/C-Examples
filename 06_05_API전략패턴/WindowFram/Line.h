#pragma once
#include"DragDrawing.h"

class CLine : public CDragDrawing {
public:
	CLine() {}
	virtual ~CLine() {}

	virtual void Draw(CBackBit* _bit, CMouse* _mouse, int _drawmode) override
	{

		if (_mouse->GetClick())
		{
			if (_drawmode == REVERSE)
			{

				HDC hdc = _bit->GetBitmapDC();
				SetROP2(hdc, R2_NOT);
				MoveToEx(hdc, mStartp_x, mStartp_y, NULL);
				LineTo(hdc, _mouse->GetOldX(), _mouse->GetOldy());

				MoveToEx(hdc, mStartp_x, mStartp_y, NULL);
				LineTo(hdc, _mouse->GetX(), _mouse->Gety());
				_bit->DeleteBitmapDC(hdc);
				InvalidateRect(_mouse->GetHWnd(), NULL, false);
			}
			else
			{
				HDC hdc = _bit->GetBitmapDC();
				MoveToEx(hdc, mStartp_x, mStartp_y, NULL);
				LineTo(hdc, _mouse->GetX(), _mouse->Gety());
				_bit->DeleteBitmapDC(hdc);
				InvalidateRect(_mouse->GetHWnd(), NULL, false);

			}
		}


	}
};