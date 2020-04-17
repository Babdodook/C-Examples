#pragma once
#include"Global.h"

class JobItemFactory {
public:
	JobItemFactory() {}
	~JobItemFactory() {}

	virtual const char* CreateWeapon() = 0;
	virtual const char* CreateDefense() = 0;
	virtual const char* CreateAccessory() = 0;
};