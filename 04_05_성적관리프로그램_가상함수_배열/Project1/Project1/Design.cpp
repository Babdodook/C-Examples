#include"Design.h"

const char* Design::majorobject[] = { "���ӱ�ȹ����","���ӽó�����","����������" };

Design::Design(const char* name, const char* id)
	:Student(name, id)
{
}

Design::~Design()
{
}

void Design::Input()
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

void Design::Display()
{
	cout << "�̸�: " << GetName() << endl;
	cout << "�й�: " << GetID() << endl;
	for (int i = 0; i < MAJORS; i++)
	{
		cout << majorobject[i] << ": " << majorscore[i] << endl;
	}
	cout << "����: " << grade << endl << endl;
}