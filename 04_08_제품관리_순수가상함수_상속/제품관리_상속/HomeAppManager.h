#pragma once
#include"homeapp.h"
#include"ProductManager.h"

class HomeAppManager : public ProductManager{
private:
	static const char* HomeApps[];
	LinkedList<HomeApp*>* HomeAppList[HSIZE];
	static int idcode[];
public:
	HomeAppManager();
	virtual ~HomeAppManager();

	void Init();
	virtual void Input();
	virtual void Search();
	virtual void Delete();
};