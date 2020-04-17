#include"User.h"

User::User()
{
	memset(id, 0, NULL);
	memset(pw, 0, NULL);
	score = 0;
	loginstate = 0;
}

User::User(char * _id, char * _pw)
{
	strcpy(id, _id);
	strcpy(pw, _pw);
	score = 0;
	loginstate = false;
}

User::~User() {}

void User::SetID(char * _id) 
{
	strcpy(id, _id);
}

void User::SetPW(char * _pw) 
{
	strcpy(pw, _pw);
}

const char * User::GetID() 
{
	return id;
}

const char * User::GetPW()
{
	return pw;
}

void User::SetScore(int _score)
{
	score = _score;
}

const int User::GetScore()
{
	return score;
}

void User::SetState(bool _state)
{
	loginstate = _state;
}

const bool User::GetState() 
{
	return loginstate;
}