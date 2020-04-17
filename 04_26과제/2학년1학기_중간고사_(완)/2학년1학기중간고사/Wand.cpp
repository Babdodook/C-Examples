#include"Wand.h"

//아이템의 이름, 무게, 가격, 고유아이디, 속성을 멤버변수에 저장
Wand::Wand(const char* name, int weight, int price, const char* itemid, int wis)
	:Item(name, weight, price, itemid), wis(wis)
{
}

Wand::~Wand()
{
}

void Wand::ShowItemInfo()					//아이템의 정보 출력
{
	cout << "------------------" << endl;
	cout << "Item Number: " << Itemid << endl;
	cout << "이름: " << name << endl;
	cout << "무게: " << weight << endl;
	cout << "지혜+ " << wis << endl << endl;
}