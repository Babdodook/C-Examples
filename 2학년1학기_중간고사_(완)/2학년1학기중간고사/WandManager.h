#pragma once
#include"ItemManager.h"

class WandManager : public ItemManager {	//완드 아이템 컨트롤 클래스
private:
	static const char* Wands[];				//완드 이름 배열
	static const int Wweight[];				//무게
	static const int Wprice[];				//가격
	static const int Wpower[];				//속성 수치

	int idcount;							//아이템 고유 아이디 카운트
public:
	WandManager();
	~WandManager();

	void Buy(User*);						//판매 메소드
};