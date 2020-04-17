#pragma once
#include"Programming.h"
#include"Design.h"
#include"Graphic.h"

class TotalManager {
private:
	Programming * Prog;
	Design * Des;
	Graphic * Grap;
public:
	TotalManager();
	~TotalManager();

	void Run();
	void Init();
	void clear();
	int Mainmenu();
	int SelectMajor();
};