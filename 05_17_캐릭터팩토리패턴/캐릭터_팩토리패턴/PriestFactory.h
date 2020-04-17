#pragma once
#include"JobItemFactory.h"

class PriestFactory : public JobItemFactory {
public:
	PriestFactory() {}
	~PriestFactory() {}

	virtual const char* CreateWeapon();
	virtual const char* CreateDefense();
	virtual const char* CreateAccessory();
};