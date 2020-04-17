#pragma once
#include"MajorManager.h"

class Design : public MajorManager {
private:
	int classnum;
	static const char * Majornames[];
public:
	Design();
	~Design();

	virtual void Input();
	virtual void Output();
	virtual void Search();
};