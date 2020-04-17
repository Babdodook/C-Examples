#include"Elf.h"

Elf::Elf(JobItemFactory* factory, const char* job) : Character(factory,job){}

void Elf::Display()
{
	cout << "종족: 엘프" << endl;
	cout << "직업: " << Character::Job << endl;
	cout << "무기: " << Character::Weapon << endl;
	cout << "방어구: " << Character::Defense << endl;
	cout << "악세사리: " << Character::Accessory << endl;
}