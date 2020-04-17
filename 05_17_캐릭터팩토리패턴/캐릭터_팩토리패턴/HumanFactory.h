#pragma once
#include"CharacterFactory.h"
#include"Human.h"

class HumanFactory : public CharacterFactory {
public:
	HumanFactory() {};
	~HumanFactory() {};

	virtual Character* makeCharacter(JobItemFactory*, const char*);
};