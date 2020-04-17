#pragma once
#include"Item.h"

class Wand :public Item {	//완드 데이터 클래스, 아이템클래스 상속
private:
	int wis;				//아이템의 속성, 지혜 스탯을 나타냄
public:
	Wand(const char* name, int weight, int price, const char* itemid, int wis);
	~Wand();

	virtual void ShowItemInfo();	//아이템 정보 출력 메소드
};