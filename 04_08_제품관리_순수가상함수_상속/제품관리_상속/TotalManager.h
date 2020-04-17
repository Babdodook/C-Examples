#pragma once
#include"FoodManager.h"
#include"ClothesManager.h"
#include"HomeAppManager.h"

class TotalManager {
private:
	FoodManager* FoodM;
	ClothesManager* ClothesM;
	HomeAppManager* HomeAppM;

	static const char* Productname[];
public:
	TotalManager();
	~TotalManager();

	void Init();
	void Mainmenu();
	ProductManager* SelectProduct();
	void Run();
	void Clear();
};