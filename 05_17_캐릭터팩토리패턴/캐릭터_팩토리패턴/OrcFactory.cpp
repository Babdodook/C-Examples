#include"OrcFactory.h"

Character* OrcFactory::makeCharacter(JobItemFactory* Job, const char* JobName)
{
	Character* newCharacter = new Orc(Job, JobName);
	return newCharacter;
}