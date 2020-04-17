#include"User.h"

User::User(const char* id, const char* pw)	//유저 생성
	:gold(1000)								//생성시 자동으로 1000골드 지급
{
	strcpy(this->id, id);
	strcpy(this->pw, pw);

	CharacterList = nullptr;				//초기화
	ItemList = nullptr;						//초기화

	Init();									//동적할당 메소드 호출
}

User::~User()								//소멸자에서 메모리 해제
{
	delete CharacterList;
	delete ItemList;
}

void User::Init()							//이니셜라이즈 메소드
											//캐릭터 리스트와 아이템 리스트 동적 할당
{
	CharacterList = new LinkedList<Character*>();
	ItemList = new LinkedList<Item*>();
}

const char* User::GetID()
{
	return id;
}

const char* User::GetPW()
{
	return pw;
}

Node<Character*>* User::GetCharacter()			//캐릭터 리스트의 헤드노드 반환
												//캐릭터의 삭제 과정에서 사용됨
{
	return CharacterList->GetHead();
}

void User::SetCharacter(Character* character)	//캐릭터 생성시 호출됨
{
	CharacterList->Insert(character);
}

void User::DelCharacter(Character* character)	//캐릭터 삭제시 호출됨
{
	CharacterList->Delete(character);
}

Node<Item*>* User::GetItem()					//아이템 리스트의 헤드노드 반환
												//아이템의 판매과정에서 사용됨
{
	return ItemList->GetHead();
}

void User::SetItem(Item* item)					//아이템 구매시 호출됨
{
	ItemList->Insert(item);
}

void User::DelItem(Item* item)					//아이템 판매시 호출됨
{
	ItemList->Delete(item);
}

const int User::GetGold()						//현재 유저가 가지고 있는 골드를 리턴
{
	return gold;
}

void User::SetGold(int gold, int action)
{
	if (action == PLUS_GOLD)	//아이템 판매 경우, 소지 골드 증가
	{
		this->gold += gold;
	}
	if (action == MINUS_GOLD)	//아이템 구매 경우, 소지 골드 감소
	{
		this->gold -= gold;
	}
}