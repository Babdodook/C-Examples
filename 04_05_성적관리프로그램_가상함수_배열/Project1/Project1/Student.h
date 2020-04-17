#pragma once
#include"Basic.h"

class Student {
private:
	char name[SIZE];
	char classID[SIZE];
public:
	Student(const char*, const char*);
	~Student();

	const char* GetName();
	const char* GetID();

	virtual void Input() = 0;
	virtual void Display() = 0;
};