#pragma once
#include"Character.h"

class Orc : public Character {
public:
	Orc(JobItemFactory* factory, const char* job);
	virtual ~Orc() {}

	virtual void Display();
};