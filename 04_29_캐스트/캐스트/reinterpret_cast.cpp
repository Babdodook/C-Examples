#include<iostream>
using namespace std;

class Base
{
public:
	Base() {}
	~Base() {}

	void Display()
	{
		cout << "Base class" << endl;
	}
};

class Ex1
{
public:
	Ex1() {}
	~Ex1() {}

	void Display()
	{
		cout << "Ex1 class" << endl;
	}
};

class Ex2
{
public:
	Ex2() {}
	~Ex2() {}

	void Display()
	{
		cout << "Ex2 class" << endl;
	}
};

int main()
{
	Base* base = nullptr;

	Ex1* ex1 = new Ex1();
	Ex2* ex2 = new Ex2();

	ex1->Display();
	ex2->Display();

	base = reinterpret_cast<Base*>(ex1);
	base->Display();

	base = reinterpret_cast<Base*>(ex2);
	base->Display();

	delete ex1;
	delete ex2;

	return 0;
}