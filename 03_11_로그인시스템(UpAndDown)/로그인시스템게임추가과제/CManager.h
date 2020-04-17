#pragma once

#include"Global.h"
#include"CGameManager.h"
#include"CUser.h"

class CManager {
private:
	CUser * lst[MAX];
	CUser * LoginUser;
	CGameManager * Game;
	int count = 0;
	int selectmenu;
public:
	CManager();
	~CManager();
	void Run();
	void Signup();
	void Login();
	void Logout();
	void DeleteAcc();
};