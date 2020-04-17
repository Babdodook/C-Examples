#pragma once
#include"Ingredient.h"

class Carrot : public Ingredient {
public:
	Carrot() {}
	~Carrot() {}

	virtual void Prepare() override
	{
		cout << "Carrot prepared" << endl;
	}
};