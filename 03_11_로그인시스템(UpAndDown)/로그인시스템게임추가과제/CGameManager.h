#pragma once

#include"Global.h"
#include"CUser.h"

class CGameManager {
public:
	CGameManager();
	~CGameManager();
	//void Init();
	int RunGame();
	bool Check(int correctNum,int i);
};