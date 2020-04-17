#pragma once
#include"Character.h"

class Elf : public Character {
public:
	Elf(JobItemFactory* factory, const char* job);
	virtual ~Elf() {}

	virtual void Display();	
};