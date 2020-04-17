#pragma once
#include"food.h"
#include"ProductManager.h"

class FoodManager : public ProductManager{
private:
	static const char* Foods[];
	LinkedList<Food*>* FoodList[FSIZE];
	static int idcode[];
public:
	FoodManager();
	virtual ~FoodManager();

	void Init();
	virtual void Input();
	virtual void Search();
	virtual void Delete();
};