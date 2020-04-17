#pragma once
#include"Product.h"

class Food : public Product {
private:
	int weight;
public:
	Food(const char*, const char*, const char*, int, int);
	~Food();

	void SetWeight(int);

	const int GetWeight();
};