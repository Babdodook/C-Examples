#ifndef _CDRAGDRAWING_H
#define _CDRAGDRAWING_H
#include "Global.h"
#include "Mouse.h"
#include "BackBit.h"

class CDragDrawing
{
protected:
	int mStartp_x;
	int mStartp_y;

public:

	int GetStartp_x() {return mStartp_x;}
	int GetStartp_y() {return mStartp_y;}

	void SetStartp_x(int _x){ mStartp_x=_x;}
	void SetStartp_y(int _y){ mStartp_y=_y;}

	virtual void DragDrawing(CBackBit* _bit, COLORREF bColor, COLORREF pColor, int PenPt, int _drawmode) = 0;

};

#endif