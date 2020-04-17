#pragma once
#include"UserManager.h"

const char* UserManager::ItemMenu[] = { "검","완드","활" };

UserManager::UserManager()	//생성자에서 초기화
{
	CharacterM = nullptr;
	ItemM = nullptr;
	SwordM = nullptr;
	WandM = nullptr;
	BowM = nullptr;
}

UserManager::~UserManager()	//소멸자에서 메모리 해제
{
	delete CharacterM;
	delete SwordM;
	delete WandM;
	delete BowM;
	delete ItemM;
}

void UserManager::Init()	//이니셜라이즈에서 동적할당
{
	CharacterM = new CharacterManager();
	ItemM = new ItemManager();
	SwordM = new SwordManager();
	WandM = new WandManager();
	BowM = new BowManager();
}

bool UserManager::LoginMenu(Node<User*>* Nowuser)	//로그인메뉴
													//1. 캐릭터 생성
													//2. 캐릭터 삭제
													//3. 아이템 구매
													//4. 아이템 판매
													//5. 로그아웃
													//6. 회원탈퇴
{
	int select;
	while (1)
	{
		DisplayMenu();
		cin >> select;

		switch (select)
		{
		case LOGMENU::CREATE_C:
			CharacterM->Create(Nowuser->GetData());		//캐릭터 생성 메소드 호출, 매개변수로 현재유저를 넘겨줌
			break;
		case LOGMENU::DELETE_C:						
			CharacterM->Delete(Nowuser->GetData());		//캐릭터 삭제 메소드 호출
			break;
		case LOGMENU::BUY:
			SelectItem(Nowuser->GetData());				//아이템선택 메소드 호출
			break;
		case LOGMENU::SELL:
			ItemM->Sell(Nowuser->GetData());			//아이템 판매 메소드 호출
			break;
		case LOGMENU::LOGOUT:							//로그아웃시 true반환
			return true;
		case LOGMENU::DELETE_ACC:						//회원 탈퇴시 false반환
			return false;
		}
	}
}

void UserManager::SelectItem(User* Nowuser)				//아이템 구매화면에서 선택을 위한 메소드
{
	int select;

	for (int i = 0; i < sizeof(ItemMenu) / sizeof(char*); i++)	//검, 완드, 활 메뉴 출력
	{
		cout << i + 1 << ". " << ItemMenu[i] << endl;
	}
	cout << "선택: ";
	cin >> select;

	//아이템 선택 시
	//해당아이템을 담당하는 매니저로
	//현재유저 정보를 넘겨준다
	switch (select)
	{
	case ITEM::SWORD:
		return SwordM->Buy(Nowuser);
	case ITEM::WAND:
		return WandM->Buy(Nowuser);
	case ITEM::BOW:
		return BowM->Buy(Nowuser);
	}
}

void UserManager::DisplayMenu()			//메뉴 출력
{
	cout << "<메뉴>" << endl;
	cout << "1. 캐릭터 생성" << endl;
	cout << "2. 캐릭터 삭제" << endl;
	cout << "3. 아이템 구입" << endl;
	cout << "4. 아이템 판매" << endl;
	cout << "5. 로그아웃" << endl;
	cout << "6. 회원 탈퇴" << endl;
	cout << "선택: ";
}