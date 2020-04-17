#include"Mouse.h"

Mouse* Mouse::Pthis = nullptr;

Mouse* Mouse::Create()
{
	if (Pthis == nullptr)
	{
		Pthis = new Mouse();
	}
	return Pthis;
}

Mouse* Mouse::GetInstance()
{
	return Pthis;
}

void Mouse::Destory()
{
	if (Pthis != nullptr)
	{
		delete Pthis;
		Pthis = nullptr;
	}
}

void Mouse::SetMousePt(int x,int y)
{
	this->mousePt.x = x;
	this->mousePt.y = y;
}

POINT Mouse::GetMousePt()
{
	return mousePt;
}