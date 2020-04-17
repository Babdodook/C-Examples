#pragma once
#include"JobItemFactory.h"

class MagicianFactory : public JobItemFactory {
public:
	MagicianFactory() {}
	~MagicianFactory() {}

	virtual const char* CreateWeapon();
	virtual const char* CreateDefense();
	virtual const char* CreateAccessory();
};