#include<iostream>
using namespace std;

class Parentclass {
public:
	Parentclass() {}
	virtual ~Parentclass() {}
	virtual void Display()
	{
		cout << "Parent" << endl;
	}
};

class ChildSon : public Parentclass
{
public:
	ChildSon() {}
	virtual ~ChildSon() {}
	virtual void Display()
	{
		cout << "Son" << endl;
	}

};

class ChildDaughter : public Parentclass
{
public:
	ChildDaughter() {}
	virtual ~ChildDaughter() {}
	virtual void Display()
	{
		cout << "Daughter" << endl;
	}
};

int main()
{
	int select;

	Parentclass* Parent = nullptr;
	cout << "자식 성별 1.남 2. 여" << endl;
	cout << "선택: ";
	cin >> select;

	switch (select)
	{
	case 1:
		Parent = new ChildSon();
		break;
	case 2:
		Parent = new ChildDaughter();
		break;
	}

	ChildSon* Son = static_cast<ChildSon*>(Parent);
	Son->Display();

	ChildDaughter* Daughter = static_cast<ChildDaughter*>(Parent);
	Daughter->Display();
}