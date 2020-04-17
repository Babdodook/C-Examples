#pragma once
#include"MajorManager.h"

class Graphic : public MajorManager {
private:
	int classnum;
	static const char * Majornames[];
public:
	Graphic();
	~Graphic();

	virtual void Input();
	virtual void Output();
	virtual void Search();
};