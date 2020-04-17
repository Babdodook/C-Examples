#pragma once
#include"MajorManager.h"
#include"Student.h"

class Graphic : public MajorManager{
private:
	int classnum;
public:
	Graphic();
	~Graphic();

	virtual void Input();
	virtual void Output();
	virtual void Search();
};