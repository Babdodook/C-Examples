#pragma once
#include"Global.h"

class Ingredient {
public:
	Ingredient() {}
	~Ingredient() {}

	virtual void Prepare() = 0;
};