#pragma once
#include"Circle.h"
#include"Rectangle.h"
#include"Line.h"
#include"FreeLine.h"

class DrawProcess {
public:
	void SetDraw(CDragDrawing* _pDraw)
	{
		if (pDraw != nullptr)
		{
			delete pDraw;
		}
		pDraw = _pDraw;
	}

	void Draw(CBackBit* _bit, CMouse* _mouse, int _drawmode)
	{
		pDraw->Draw(_bit,_mouse,_drawmode);
	}

	CDragDrawing* GetDraw()
	{
		return pDraw;
	}

private:
	CDragDrawing* pDraw;
};