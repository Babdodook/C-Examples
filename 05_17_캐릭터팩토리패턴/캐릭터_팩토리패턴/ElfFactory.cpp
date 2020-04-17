#include"ElfFactory.h"

Character* ElfFactory::makeCharacter(JobItemFactory* Job,const char* JobName)
{
	Character* newCharacter = new Elf(Job,JobName);
	return newCharacter;
}