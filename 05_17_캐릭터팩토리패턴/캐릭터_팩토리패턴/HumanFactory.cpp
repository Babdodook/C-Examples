#include"HumanFactory.h"

Character* HumanFactory::makeCharacter(JobItemFactory* Job, const char* JobName)
{
	Character* newCharacter = new Human(Job, JobName);
	return newCharacter;
}