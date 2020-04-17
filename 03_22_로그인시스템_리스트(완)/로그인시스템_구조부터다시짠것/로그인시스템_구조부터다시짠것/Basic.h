#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<ctime>
using namespace std;

#define MAXSIZE 20

enum MAINMENU {
	SIGNUP=1,
	LOGIN,
	EXIT
};

enum LOGINMENU {
	RUNGAME=1,
	LOGOUT,
	DELETACC
};