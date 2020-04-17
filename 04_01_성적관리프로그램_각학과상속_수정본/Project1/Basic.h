#pragma once
#include<iostream>
using namespace std;

#define SIZE 10
#define MAJORS 3

namespace MENU
{
	enum {
		INPUT=1,
		OUTPUT,
		SEARCH,
		EXIT
	};
}

namespace MAJOR
{
	enum {
		PROG=1,
		GRAPHIC,
		DESIGN
	};
}