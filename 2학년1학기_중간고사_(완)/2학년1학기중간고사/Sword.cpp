#include"Sword.h"

//아이템의 이름, 무게, 가격, 고유아이디, 속성을 멤버변수에 저장
Sword::Sword(const char* name, int weight, int price, const char* itemid, int power)
	:Item(name,weight,price,itemid), power(power)
{
}

Sword::~Sword()
{
}

void Sword::ShowItemInfo()					//아이템의 정보 출력
{
	cout << "------------------" << endl;
	cout << "Item Number: " << Itemid << endl;
	cout << "이름: " << name << endl;
	cout << "무게: " << weight << endl;
	cout << "힘+ " << power << endl << endl;
}