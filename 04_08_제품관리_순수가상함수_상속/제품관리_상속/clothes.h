#pragma once
#include"Product.h"

class Clothes : public Product {
private:
	int size;
public:
	Clothes(const char*, const char*, const char*, int, int);
	~Clothes();

	void SetSize(int);

	const int GetSize();
};