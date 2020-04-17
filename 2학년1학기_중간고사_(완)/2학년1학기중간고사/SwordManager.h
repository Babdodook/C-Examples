#pragma once
#include"ItemManager.h"

class SwordManager : public ItemManager {	//검 아이템 컨트롤 클래스
private:
	static const char* Swords[];			//검 이름 배열
	static const int Sweight[];				//무게
	static const int Sprice[];				//가격
	static const int Spower[];				//속성 수치

	int idcount;							//아이템 고유 아이디 카운트
public:
	SwordManager();
	~SwordManager();

	void Buy(User*);						//판매 메소드
};