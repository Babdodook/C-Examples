#pragma once
#pragma warning(disable:4996)
#include<iostream>
using namespace std;



#define MAX 30
#define SIZE 20
#define MAJORS 3
#define DESIGN_CODE "301"
#define PROG_CODE "302"
#define GRAPHIC_CODE "303"

namespace MENU {
	enum {
		INPUT=1,
		DISPLAY,
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