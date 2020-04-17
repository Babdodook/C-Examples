#pragma once
#include"MajorManager.h"

class Programming : public MajorManager {
private:
	int classnum;
	static const char * Majornames[];
public:
	Programming();
	~Programming();

	virtual void Input();
	virtual void Output();
	virtual void Search();
};