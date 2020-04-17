#pragma once
#include"food.h"

Food::Food(const char* name, const char* date, const char* id, int price, int weight)
	:Product(name, date, id, price), weight(weight)
{
}

Food::~Food()
{
}

void Food::SetWeight(int weight)
{
	this->weight = weight;
}

const int Food::GetWeight()
{
	return weight;
}