#include"Programming.h"

const char* Programming::majorobject[] = { "C++2","C#","API2" };

Programming::Programming(const char* name, const char* id)
	:Student(name, id)
{
}

Programming::~Programming()
{
}

void Programming::Input()
{
	int score;
	int temp = 0;
	for (int i = 0; i < MAJORS; i++)
	{
		cout << majorobject[i] << ": ";
		cin >> score;
		majorscore[i] = score;
		temp += score;
	}

	if (300 == temp)
	{
		grade = 4;
	}
	else if (300 > temp && temp >= 250)
	{
		grade = 3.5;
	}
	else if (250 > temp && temp >= 200)
	{
		grade = 3;
	}
	else if (200 > temp && temp >= 100)
	{
		grade = 2;
	}
	else if (100 > temp && temp > 0)
	{
		grade = 1;
	}
	else if (0 > grade)
	{
		grade = 0;
	}
}

void Programming::Display()
{
	cout << "이름: " << GetName() << endl;
	cout << "학번: " << GetID() << endl;
	for (int i = 0; i < MAJORS; i++)
	{
		cout << majorobject[i] << ": " << majorscore[i] << endl;
	}
	cout << "평점: " << grade << endl << endl;
}