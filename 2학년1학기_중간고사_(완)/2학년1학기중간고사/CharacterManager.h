#pragma once
#include"User.h"
#include"LinkedList.h"

class CharacterManager {		//캐릭터 생성, 삭제 담당 컨트롤 클래스
private:
	static const char* Characters[];		//캐릭터 이름 저장 배열
	static const char* Cid[];				//캐릭터 고유 아이디 저장 배열
	int Cidcount[3];						//캐릭터 아이디 카운트 배열 
public:
	CharacterManager();
	~CharacterManager();

	void Create(User*);			//캐릭터 생성
	void Delete(User*);			//캐릭터 삭제
	void Show(User*);			//전체 캐릭터 정보 출력 메소드(미구현)
};