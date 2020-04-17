#include"Character.h"

Character::Character(JobItemFactory* factory, const char* job)
{
	strcpy(this->Job, job);

	strcpy(this->Weapon, factory->CreateWeapon());
	strcpy(this->Defense, factory->CreateDefense());
	strcpy(this->Accessory, factory->CreateAccessory());
}