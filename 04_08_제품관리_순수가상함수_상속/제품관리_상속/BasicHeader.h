#pragma once
#include<iostream>
using namespace std;

#define NAMESIZE 10
#define FSIZE 4
#define CSIZE 2
#define HSIZE 3

namespace CODE {
	enum {
		FOOD=100,
		CLOTHES=200,
		HOMEAPP=300
	};
}

namespace MENU {
	enum {
		ADD=1,
		SEARCH,
		DELETE,
		EXIT
	};
}

namespace PRODUCT {
	enum {
		FOOD=0,
		CLOTES,
		HOMEAPP
	};
}