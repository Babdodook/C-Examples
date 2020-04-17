#pragma once

#include"Basic.h"

class User {
private:
	char id[MAXSIZE];
	char pw[MAXSIZE];
	int score;
	bool loginstate;
public:
	User();
	User(char *,char *);
	~User();

	void SetID(char *);
	void SetPW(char *);

	const char * GetID();
	const char * GetPW();

	void SetScore(int);
	const int GetScore();

	void SetState(bool);
	const bool GetState();
};