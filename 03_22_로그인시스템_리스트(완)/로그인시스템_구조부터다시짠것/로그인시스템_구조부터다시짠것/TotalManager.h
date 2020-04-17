#pragma once

#include"LoginManager.h"
#include"GameManager.h"

class TotalManager {
private:
	LoginManager * LoginM;
	GameManager * GameM;
public:
	TotalManager();
	~TotalManager();

	void Init();
	void RunProgram();
	int Mainmenu();
	int Loginmenu();
};