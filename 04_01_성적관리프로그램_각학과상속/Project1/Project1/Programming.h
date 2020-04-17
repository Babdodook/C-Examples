#pragma once
#include"MajorManager.h"
#include"Student.h"

class Programming :public MajorManager {
private:
	int classnum;
public:
	Programming();
	~Programming();

	virtual void Input();
	virtual void Output();
	virtual void Search();
};