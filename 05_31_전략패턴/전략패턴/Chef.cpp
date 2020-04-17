#include"Chef.h"

Chef::Chef() : pIngredient(0) {}

Chef::~Chef()
{
	if (pIngredient)
		delete pIngredient;
}

void Chef::Prepare()
{
	pIngredient->Prepare();
}

void Chef::Prepare_Setting(Ingredient* ingredient)
{
	if (pIngredient)
		delete pIngredient;
	pIngredient = ingredient;
}