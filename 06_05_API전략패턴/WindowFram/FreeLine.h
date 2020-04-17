#pragma once
#include"DragDrawing.h"

class CFreeLine : public CDragDrawing {
public:
	CFreeLine() {}
	virtual ~CFreeLine() {}

	virtual void Draw(CBackBit* _bit, CMouse* _mouse, int _drawmode) override
	{
		if (_mouse->GetClick()) {

			HDC hdc = _bit->GetBitmapDC();
			MoveToEx(hdc, _mouse->GetOldX(), _mouse->GetOldy(), NULL);
			LineTo(hdc, _mouse->GetX(), _mouse->Gety());
			_bit->DeleteBitmapDC(hdc);
			InvalidateRect(_mouse->GetHWnd(), NULL, false);
		}

	}
};