#pragma once
#include"DragDrawing.h"

class CRectangle : public CDragDrawing {
public:
	CRectangle() {}
	virtual ~CRectangle() {}

	virtual void Draw(CBackBit* _bit, CMouse* _mouse, int _drawmode) override
	{
		if (_mouse->GetClick())
		{
			if (_drawmode == REVERSE)
			{
				HDC hdc = _bit->GetBitmapDC();
				HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, (HBRUSH)NULL_BRUSH);
				SetROP2(hdc, R2_NOT);
				Rectangle(hdc, mStartp_x, mStartp_y, _mouse->GetOldX(), _mouse->GetOldy());
				Rectangle(hdc, mStartp_x, mStartp_y, _mouse->GetX(), _mouse->Gety());
				DeleteObject(SelectObject(hdc, hOldBrush));
				_bit->DeleteBitmapDC(hdc);
				InvalidateRect(_mouse->GetHWnd(), NULL, false);
			}
			else
			{
				HDC hdc = _bit->GetBitmapDC();
				HBRUSH hOldBrush = (HBRUSH)SelectObject(hdc, (HBRUSH)NULL_BRUSH);
				Rectangle(hdc, mStartp_x, mStartp_y, _mouse->GetX(), _mouse->Gety());
				DeleteObject(SelectObject(hdc, hOldBrush));
				_bit->DeleteBitmapDC(hdc);
				InvalidateRect(_mouse->GetHWnd(), NULL, false);
			}
		}

	}
};