#pragma once
#include"clothes.h"

Clothes::Clothes(const char* name, const char* date, const char* id, int price, int size)
	:Product(name, date, id, price), size(size)
{
}

Clothes::~Clothes()
{
}

void Clothes::SetSize(int size)
{
	this->size = size;
}

const int Clothes::GetSize()
{
	return size;
}