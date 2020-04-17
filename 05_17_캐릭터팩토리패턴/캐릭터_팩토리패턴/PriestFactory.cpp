#include"PriestFactory.h"

const char* PriestFactory::CreateWeapon()
{
	return "하얀 십자 로브";
}

const char* PriestFactory::CreateDefense()
{
	return "고목나무 스태프";
}

const char* PriestFactory::CreateAccessory()
{
	return "은빛 십자 목걸이";
}