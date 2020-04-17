#pragma once
#include"ListManager.h"

class MajorManager {
protected:
	ListManager * ListM;
public:
	MajorManager();
	~MajorManager();

	virtual void Input()=0;
	virtual void Output()=0;
	virtual void Search()=0;
};