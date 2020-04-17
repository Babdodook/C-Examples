#pragma once
#include"Ingredient.h"

class Potato : public Ingredient {
public:
	Potato() {}
	~Potato() {}

	virtual void Prepare() override
	{
		cout << "Potato prepared" << endl;
	}
};