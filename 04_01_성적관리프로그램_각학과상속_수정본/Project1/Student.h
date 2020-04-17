#pragma once
#include"Basic.h"

class Student {
private:
	char * name;
	int classnum;
	int majorscore[MAJORS];
	double grade;
public:
	Student(){}
	Student(Student*);
	~Student();

	void Setname(char*);
	void Setclassnum(int);
	void Setmscore(int, int);
	void Setgrade(double);

	char* Getname();
	int Getclassnum();
	int Getmscore(int);
	double Getgrade();
};