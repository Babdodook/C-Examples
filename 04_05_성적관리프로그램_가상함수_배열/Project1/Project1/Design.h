#pragma once
#include"Student.h"

class Design : public Student {
private:
	static const char* majorobject[];
	int majorscore[MAJORS];
	double grade;
public:
	Design(const char*, const char*);
	~Design();

	virtual void Input();
	virtual void Display();
};