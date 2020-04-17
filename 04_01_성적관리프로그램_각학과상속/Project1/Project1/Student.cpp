#include"Student.h"

Student::Student(char * name, int classnum)
{
	strcpy(this->name, name);
	this->classnum = classnum;
}

Student::~Student()
{
}

void Student::SetMajor(int index, int score)
{
	this->majorscore[index] = score;

	if (index = 2) 
	{
		SetGrade();
	}
}

const char * Student::GetName()
{
	return this->name;
}

const int Student::GetClassnum()
{
	return this->classnum;
}

const float Student::GetGrade()
{
	return this->grade;
}

const int Student::GetMajor(int index)
{
	return majorscore[index];
}

void Student::SetGrade()
{
	int result=0;
	for (int i = 0; i < 3; i++) 
	{
		result += majorscore[i];
	}

	if (result == 300)
	{
		grade = 4;
	}
	else if (300 > result && result >= 250)
	{
		grade = 3.5;
	}
	else if (250 > result && result >= 200)
	{
		grade = 2;
	}
	else if (200 > result && result >= 100)
	{
		grade = 1;
	}
	else
	{
		grade = 0;
	}
}