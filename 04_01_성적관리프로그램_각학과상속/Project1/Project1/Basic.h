#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

#define SIZE 10
#define MAXSIZE 50

namespace MAINMENU {
	enum {
		INPUT=1,
		OUTPUT,
		SEARCH,
		EXIT
	};
}

namespace MAJOR {
	enum {
		PROG=1,
		GRAPHIC,
		DESIGN
	};
}