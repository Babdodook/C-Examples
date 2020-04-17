#pragma once
#include"Design.h"
#include"Programming.h"
#include"Graphic.h"

class TotalM {
private:
	Design * design;
	Graphic * graphic;
	Programming * prog;
public:
	TotalM();
	~TotalM();

	void Init();
	void Run();

	int Mainmenu();
	int SelectClass();
};