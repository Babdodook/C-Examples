#pragma once
#include"Ingredient.h"

class Chef {
public:
	Chef();
	~Chef();

	void Prepare();
	void Prepare_Setting(Ingredient* ingredient);
private:
	Ingredient* pIngredient;
};