#include"Human.h"

Human::Human(JobItemFactory* factory, const char* job) : Character(factory, job) {}

void Human::Display()
{
	cout << "����: �ΰ�" << endl;
	cout << "����: " << Character::Job << endl;
	cout << "����: " << Character::Weapon << endl;
	cout << "��: " << Character::Defense << endl;
	cout << "�Ǽ��縮: " << Character::Accessory << endl;
}