#pragma once
#include"Character.h"

class Orc :public Character {		// 오크 데이터 클래스, 캐릭터 클래스 상속 받음
private:
	int power;						// 오크는 힘 스탯을 가지고 있다
public:
	Orc(const char* name,const char* cid);
	virtual ~Orc();

	virtual void ShowCInfo();		//캐릭터 정보 출력 메소드
};