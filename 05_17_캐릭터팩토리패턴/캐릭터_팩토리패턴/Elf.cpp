#include"Elf.h"

Elf::Elf(JobItemFactory* factory, const char* job) : Character(factory,job){}

void Elf::Display()
{
	cout << "����: ����" << endl;
	cout << "����: " << Character::Job << endl;
	cout << "����: " << Character::Weapon << endl;
	cout << "��: " << Character::Defense << endl;
	cout << "�Ǽ��縮: " << Character::Accessory << endl;
}