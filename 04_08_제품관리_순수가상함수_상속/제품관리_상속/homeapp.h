#pragma once
#include"Product.h"

class HomeApp : public Product {
private:
	char model[NAMESIZE];
public:
	HomeApp(const char*, const char*, const char*, int, const char*);
	~HomeApp();

	void SetModel(const char*);

	const char* GetModel();
};