#pragma once
#include"Student.h"

class Programming : public Student {
private:
	static const char* majorobject[];
	int majorscore[MAJORS];
	double grade;
public:
	Programming(const char*, const char*);
	~Programming();

	virtual void Input();
	virtual void Display();
};