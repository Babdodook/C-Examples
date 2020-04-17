#ifndef _CDRAGCIRCLE_H
#define _CDRAGCIRCLE_H

#include "Global.h"
#include "DragDrawing.h"

class CDragCircleDrawing:public CDragDrawing
{
	static CDragCircleDrawing*	mPthis;

	CDragCircleDrawing(){};
	~CDragCircleDrawing(){};

public:
	static void Create();
	static CDragCircleDrawing* GetInstance();
	static void Destroy();

	void DragDrawing(CBackBit* _bit, COLORREF bColor, COLORREF pColor, int PenPt, int _drawmode);

};
#endif