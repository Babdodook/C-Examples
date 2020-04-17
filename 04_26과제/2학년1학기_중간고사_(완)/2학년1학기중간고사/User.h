#pragma once
#include"Elf.h"
#include"Human.h"
#include"Orc.h"
#include"Sword.h"
#include"Wand.h"
#include"Bow.h"
#include"LinkedList.h"

class User {								//유저 데이터 클래스
private:
	char id[SIZE];							//아이디
	char pw[SIZE];							//패스워드
	int gold;								//소지 골드
	LinkedList<Character*>* CharacterList;	//캐릭터 리스트
	LinkedList<Item*>* ItemList;			//아이템 리스트
public:
	User(const char*,const char*);
	~User();

	void Init();

	//아이디, 패스워드 읽기 메소드
	const char* GetID();
	const char* GetPW();

	//골드 읽기, 쓰기 메소드
	void SetGold(int,int);
	const int GetGold();

	//캐릭터 읽기, 쓰기 및 리스트의 헤드노드 반환 메소드
	void SetCharacter(Character*);
	Node<Character*>* GetCharacter();
	void DelCharacter(Character*);

	//아이템 읽기, 쓰기 및 리스트의 헤드노드 반환 메소드
	void SetItem(Item*);
	Node<Item*>* GetItem();
	void DelItem(Item*); 
};