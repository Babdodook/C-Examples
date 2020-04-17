#pragma once
#include"User.h"
#include"LinkedList.h"

class ItemManager {		//아이템 컨트롤 클래스
protected:
	static ItemManager* mPthis;

	static const char* Itemid[];	//각 아이템 종류마다 할당하기 위한 아이디 배열

	ItemManager();
	~ItemManager();
public:
	static ItemManager* Create();
	static ItemManager* GetInstance();
	static void Destroy();

	void Sell(User*);	//아이템 판매 메소드
	void Show(User*);	//정보 출력 메소드(미구현)
};