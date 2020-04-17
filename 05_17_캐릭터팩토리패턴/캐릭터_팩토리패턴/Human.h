#pragma once
#include"Character.h"

class Human : public Character {
public:
	Human(JobItemFactory* factory, const char* job);
	virtual ~Human() {}

	virtual void Display();
};