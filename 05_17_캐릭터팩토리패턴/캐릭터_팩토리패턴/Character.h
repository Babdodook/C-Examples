#pragma once
#include"Global.h"
#include"JobItemFactory.h"

class Character {
public:
	Character(JobItemFactory*, const char*);
	virtual ~Character() {}

	virtual void Display() = 0;

protected:
	char Job[SIZE];

	char Weapon[SIZE];
	char Defense[SIZE];
	char Accessory[SIZE];
};