#pragma once
#include<Windows.h>

class Mouse {
public:
	static Mouse* Create();
	static Mouse* GetInstance();
	void Destory();

	void SetMousePt(int x, int y);
	POINT GetMousePt();

private:
	Mouse() {};
	~Mouse() {};
	static Mouse* Pthis;

	POINT mousePt;
};