#pragma once
#include"Character.h"

class Human :public Character {		// 휴먼 데이터 클래스, 캐릭터 클래스 상속 받음
private:
	int wisdom;						// 인간은 지혜 스탯을 가지고 있다
public:
	Human(const char* name, const char* cid);
	virtual ~Human();

	virtual void ShowCInfo();		//캐릭터 정보 출력 메소드
};