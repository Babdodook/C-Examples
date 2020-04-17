#pragma once
#include"BasicHeader.h"

class Item {								//아이템 데이터 클래스
protected:
	char name[SIZE];						//아이템 이름
	int weight;								//무게
	int price;								//가격
	char Itemid[SIZE];						//아이템의 고유 아이디
public:
	//생성자에서 이름, 무게, 가격, 아이템을 멤버변수에 저장
	Item(const char* name, int weight, int price, const char* Itemid)
		:weight(weight), price(price)
	{
		strcpy(this->name, name);
		strcpy(this->Itemid, Itemid);
	}

	//소멸자 가상함수
	virtual ~Item() {}

	//고유 아이디 리턴
	const char* Getid()
	{
		return Itemid;
	}

	//아이템의 가격 리턴
	const int GetPrice()
	{
		return price;
	}

	//상속받는 각 아이템 클래스마다 출력이 다르기때문에
	//메소드를 추상화시킨다
	virtual void ShowItemInfo() = 0;
};