#pragma once
#include"JobItemFactory.h"

class KnightFactory : public JobItemFactory {
public:
	KnightFactory() {}
	~KnightFactory() {}

	virtual const char* CreateWeapon();
	virtual const char* CreateDefense();
	virtual const char* CreateAccessory();
};