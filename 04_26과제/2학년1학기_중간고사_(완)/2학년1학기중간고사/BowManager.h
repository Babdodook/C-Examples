#pragma once
#include"ItemManager.h"

class BowManager : public ItemManager {		//활 아이템 컨트롤 클래스
private:
	static BowManager* mPthis;

	static const char* Bows[];				//활 이름 배열
	static const int Bweight[];				//무게
	static const int Bprice[];				//가격
	static const int Bpower[];				//속성 수치

	int idcount;							//아이템 고유 아이디 카운트

	BowManager();
	~BowManager();
public:
	static BowManager* Create();
	static BowManager* GetInstance();
	static void Destroy();

	void Buy(User*);						//판매 메소드
};