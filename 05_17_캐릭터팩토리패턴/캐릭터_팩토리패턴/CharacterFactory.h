#pragma once
#include"Character.h"
#include"KnightFactory.h"
#include"MagicianFactory.h"
#include"PriestFactory.h"

class CharacterFactory {
public:
	CharacterFactory() {}
	~CharacterFactory() {}

	void CreateCharacter();
	virtual Character* makeCharacter(JobItemFactory*, const char*) = 0;
};