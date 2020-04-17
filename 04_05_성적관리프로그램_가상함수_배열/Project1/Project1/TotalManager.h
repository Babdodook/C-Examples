#pragma once
#include"Programming.h"
#include"Graphic.h"
#include"Design.h"

class TotalManager{
private:
	Student* ProgArr[MAX];
	Student* GraphicArr[MAX];
	Student* DesignArr[MAX];
	int pArrcount;
	int gArrcount;
	int dArrcount;

	int pscount;
	int dscount;
	int gscount;
public:
	TotalManager();
	~TotalManager();

	void Run();

	int Mainmenu();
	void Input();
	void Display();
	void Search();

	void clear();
};