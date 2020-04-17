#pragma once
#include"CharacterFactory.h"
#include"Elf.h"

class ElfFactory : public CharacterFactory {
public:
	ElfFactory() {};
	~ElfFactory() {};

	virtual Character* makeCharacter(JobItemFactory*,const char*);
};