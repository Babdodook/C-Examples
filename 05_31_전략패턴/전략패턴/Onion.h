#pragma once
#include"Ingredient.h"

class Onion : public Ingredient {
public:
	Onion() {}
	~Onion() {}

	virtual void Prepare() override
	{
		cout << "Onion prepared" << endl;
	}
};