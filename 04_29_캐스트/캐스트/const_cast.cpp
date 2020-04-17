#include<iostream>
using namespace std;

class Const_cast {
public:
	Const_cast() {}
	~Const_cast() {}

	void Function(int* num)
	{
		cout << *num << endl;
	}
};

int main()
{
	Const_cast* obj = new Const_cast();

	const int* num = new int(10);

	obj->Function(const_cast<int*>(num));

	delete obj;
	obj = nullptr;

	return 0;
}