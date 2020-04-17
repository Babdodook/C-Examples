#pragma once
#include"CharacterFactory.h"
#include"Orc.h"

class OrcFactory : public CharacterFactory {
public:
	OrcFactory() {};
	~OrcFactory() {};

	virtual Character* makeCharacter(JobItemFactory*, const char*);
};