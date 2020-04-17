#pragma once
#include"MajorManager.h"
#include"Student.h"

class Design : public MajorManager {
private:
	int classnum;
public:
	Design();
	~Design();

	virtual void Input();
	virtual void Output();
	virtual void Search();
};