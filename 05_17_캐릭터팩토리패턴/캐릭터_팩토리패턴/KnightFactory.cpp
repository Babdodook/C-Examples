#include"KnightFactory.h"

const char* KnightFactory::CreateWeapon()
{
	return "클레이모어";
}

const char* KnightFactory::CreateDefense()
{
	return "은빛 사슬 갑옷";
}

const char* KnightFactory::CreateAccessory()
{
	return "기사단 명예 브로치";
}