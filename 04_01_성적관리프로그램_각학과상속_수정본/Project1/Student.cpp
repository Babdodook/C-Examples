#include"Student.h"

Student::Student(Student * student)
{
	this->name = new char[strlen(student->Getname()) + 1];
	strcpy(name, student->Getname());
	this->classnum = student->Getclassnum();
	for (int i = 0; i < MAJORS; i++)
	{
		this->majorscore[i] = student->Getmscore(i);
	}
	this->grade = student->Getgrade();
}

Student::~Student()
{
	delete name;
}

void Student::Setname(char * name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name,name);
}

void Student::Setclassnum(int num)
{
	this->classnum = num;
}

void Student::Setmscore(int score, int index)
{
	this->majorscore[index] = score;

	if (index == 2)
	{
		int result=0;
		for (int i = 0; i < MAJORS; i++)
		{
			result += majorscore[i];
		}

		if (300 == result)
		{
			grade = 4;
		}
		else if (300 > result && result >= 250)
		{
			grade = 3.5;
		}
		else if (250 > result && result >= 200)
		{
			grade = 3;
		}
		else if (200 > result && result >= 100)
		{
			grade = 2;
		}
		else if (100 > result && result > 0)
		{
			grade = 1;
		}
		else if (0 >= result)
		{
			grade = 0;
		}
	}
}

void Student::Setgrade(double grade)
{
	this->grade = grade;
}

char * Student::Getname()
{
	return name;
}

int Student::Getclassnum()
{
	return classnum;
}

int Student::Getmscore(int index)
{
	return majorscore[index];
}

double Student::Getgrade()
{
	return grade;
}