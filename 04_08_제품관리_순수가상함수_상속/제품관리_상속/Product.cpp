#pragma once
#include"Product.h"

Product::Product(const char* name, const char* date, const char* id, int price)
{
	strcpy(this->name, name);
	strcpy(this->date, date);
	strcpy(this->id, id);
	this->price = price;
}

Product::~Product()
{
}

void Product::SetName(const char* name)
{
	strcpy(this->name, name);
}

void Product::SetDate(const char* date)
{
	strcpy(this->date, date);
}

void Product::SetID(const char* id)
{
	strcpy(this->id, id);
}

void Product::SetPrice(int price)
{
	this->price = price;
}

const char* Product::GetName()
{
	return name;
}

const char* Product::GetDate()
{
	return date;
}

const char* Product::GetID()
{
	return id;
}

const int Product::GetPrice()
{
	return price;
}