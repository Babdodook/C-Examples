#ifndef _CDRAGRECTANGLE_H
#define _CDRAGRECTANGLE_H

#include "Global.h"
#include "DragDrawing.h"

class CDragRectangleDrawing :public CDragDrawing
{
	static CDragRectangleDrawing*	mPthis;

	CDragRectangleDrawing(){};
	~CDragRectangleDrawing(){};

public:
	static void Create();
	static CDragRectangleDrawing* GetInstance();
	static void Destroy();

	void DragDrawing(CBackBit* _bit, COLORREF bColor, COLORREF pColor, int PenPt, int _drawmode);
	
};
#endif