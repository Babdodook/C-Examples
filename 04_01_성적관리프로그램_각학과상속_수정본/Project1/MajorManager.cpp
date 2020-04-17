#pragma once
#include"MajorManager.h"

MajorManager::MajorManager()
{
	ListM = new ListManager();
}

MajorManager::~MajorManager()
{
	delete ListM;
}