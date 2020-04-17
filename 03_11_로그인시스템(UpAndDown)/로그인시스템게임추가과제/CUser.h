#pragma once

#include"Global.h"

class CUser {
private:
	char ID[MAX];
	char PW[MAX];
	int score;
	bool state = false;
public:
	CUser(const char * id, const char * pw);
	~CUser();
	const char * GetID();
	const char * GetPW();
	void State();
	const bool Getstate();
	void SetScore(int i);
	const int GetScore();
};