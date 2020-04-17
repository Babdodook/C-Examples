#pragma once
#include"Item.h"

class Sword :public Item {	//검 데이터 클래스, 아이템클래스 상속
private:
	int power;				//아이템의 속성, 힘 스탯을 나타냄
public:
	Sword(const char* name, int weight, int price, const char* itemid, int power);
	~Sword();

	virtual void ShowItemInfo();	//아이템 정보 출력 메소드
};