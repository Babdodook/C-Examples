#pragma once
#include"BasicHeader.h"

class Product {
private:
	char name[NAMESIZE];
	char date[NAMESIZE];
	char id[NAMESIZE];
	int price;
public:
	Product(const char*, const char*, const char*, int);
	~Product();

	void SetName(const char*);
	void SetDate(const char*);
	void SetID(const char*);
	void SetPrice(int);

	const char * GetName();
	const char * GetDate();
	const char * GetID();
	const int GetPrice();
};