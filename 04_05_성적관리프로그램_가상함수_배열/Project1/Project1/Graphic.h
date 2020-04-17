#pragma once
#include"Student.h"

class Graphic : public Student {
private:
	static const char* majorobject[];
	int majorscore[MAJORS];
	double grade;
public:
	Graphic(const char*, const char*);
	~Graphic();

	virtual void Input();
	virtual void Display();
};