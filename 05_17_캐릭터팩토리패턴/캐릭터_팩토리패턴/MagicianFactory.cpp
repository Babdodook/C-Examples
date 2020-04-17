#include"MagicianFactory.h"

const char* MagicianFactory::CreateWeapon()
{
	return "ºÓÀº È­¿° ·Îºê";
}

const char* MagicianFactory::CreateDefense()
{
	return "°í¸ñ³ª¹« ½ºÅÂÇÁ";
}

const char* MagicianFactory::CreateAccessory()
{
	return "Çª¸¥ºû ¿Àºê";
}