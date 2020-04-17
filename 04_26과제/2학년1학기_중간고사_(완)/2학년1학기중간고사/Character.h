#pragma once
#include"BasicHeader.h"

class Character {			//캐릭터 데이터 클래스
protected:
	char name[SIZE];		//캐릭터의 이름
	char cid[SIZE];			//캐릭터의 고유 아이디
public:
	Character(const char* name,const char* cid)		//생성자에서 이름과 고유 아이디 저장
	{
		strcpy(this->name, name);
		strcpy(this->cid, cid);
	};
	virtual ~Character() {};

	const char* GetCid()	//캐릭터 아이디 리턴
	{
		return cid;
	}

	//아이템과 마찬가지로
	//상속받는 캐릭터 클래스마다
	//출력 정보가 다르기때문에 추상화
	virtual void ShowCInfo() = 0;
};