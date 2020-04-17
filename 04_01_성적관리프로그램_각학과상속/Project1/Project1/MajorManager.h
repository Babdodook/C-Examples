#pragma once

#include"ListManager.h"
#include"Basic.h"

class MajorManager
{
public:
	ListManager * listManager;
	MajorManager();
	~MajorManager();

	virtual void Input()=0;
	virtual void Output()=0;
	virtual void Search()=0;
};