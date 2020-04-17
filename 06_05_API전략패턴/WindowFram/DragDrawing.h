#ifndef _CDRAGDRAWING_H
#define _CDRAGDRAWING_H
#include "Global.h"
#include "Mouse.h"
#include "BackBit.h"

class CDragDrawing
{
protected:
	static int mStartp_x;
	static int mStartp_y;

public:	
	virtual void Draw(CBackBit* _bit, CMouse* _mouse, int _drawmode) = 0;

	/*static int GetStartp_x() const {return mStartp_x;}
	static int GetStartp_y() const {return mStartp_y;}*/

	static void SetStartp_x(int _x){ mStartp_x=_x;}
	static void SetStartp_y(int _y){ mStartp_y=_y;}

};

#endif