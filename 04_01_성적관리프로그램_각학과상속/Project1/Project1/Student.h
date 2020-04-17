#pragma once
#include"Basic.h"

class Student {
private:
	char name[SIZE];
	int classnum;
	int majorscore[3];
	float grade;
public:
	Student(char*,int);
	~Student();

	void SetMajor(int, int);

	const char * GetName();
	const int GetClassnum();
	const float GetGrade();
	const int GetMajor(int);

	void SetGrade();
};