#include"Human.h"

Human::Human(JobItemFactory* factory, const char* job) : Character(factory, job) {}

void Human::Display()
{
	cout << "종족: 인간" << endl;
	cout << "직업: " << Character::Job << endl;
	cout << "무기: " << Character::Weapon << endl;
	cout << "방어구: " << Character::Defense << endl;
	cout << "악세사리: " << Character::Accessory << endl;
}