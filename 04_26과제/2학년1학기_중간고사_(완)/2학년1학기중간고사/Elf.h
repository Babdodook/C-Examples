#pragma once
#include"Character.h"

class Elf :public Character {		// 엘프 데이터 클래스, 캐릭터 클래스 상속 받음
private:
	int dex;						// 엘프는 지혜 스탯을 가지고 있다
public:
	Elf(const char* name, const char* cid);
	virtual ~Elf();

	virtual void ShowCInfo();		//캐릭터 정보 출력 메소드
};