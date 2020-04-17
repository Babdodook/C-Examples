#pragma once
#include"clothes.h"
#include"ProductManager.h"

class ClothesManager : public ProductManager{
private:
	static const char* Clothess[];
	LinkedList<Clothes*>* ClothesList[CSIZE];
	static int idcode[];
public:
	ClothesManager();
	virtual ~ClothesManager();

	void Init();
	virtual void Input();
	virtual void Search();
	virtual void Delete();
};