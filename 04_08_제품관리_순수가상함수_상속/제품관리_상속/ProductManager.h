#pragma once
#include"LinkedList.h"

class ProductManager {
private:
public:
	ProductManager() {};
	virtual ~ProductManager() {};

	virtual void Input() = 0;
	virtual void Search() = 0;
	virtual void Delete() = 0;
};