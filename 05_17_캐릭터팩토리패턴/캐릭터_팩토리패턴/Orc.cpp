#include"Orc.h"

Orc::Orc(JobItemFactory* factory, const char* job) : Character(factory, job) {}

void Orc::Display()
{
	cout << "����: ��ũ" << endl;
	cout << "����: " << Character::Job << endl;
	cout << "����: " << Character::Weapon << endl;
	cout << "��: " << Character::Defense << endl;
	cout << "�Ǽ��縮: " << Character::Accessory << endl;
}