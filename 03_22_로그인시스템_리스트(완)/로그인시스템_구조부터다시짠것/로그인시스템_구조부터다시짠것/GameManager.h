#pragma once

#include"User.h"

class GameManager {
private:
	User * nowuser;
	int correctNum;
	int score;
public:
	GameManager();
	~GameManager();
	void RunGame();
	void Init(User*);
	void EndGame();
};