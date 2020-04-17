#pragma once
#include"User.h"
#include"CharacterManager.h"
#include"SwordManager.h"
#include"WandManager.h"
#include"BowManager.h"
#include"LinkedList.h"

class UserManager {					//로그인된 유저의 활동을 관리하기 위한 컨트롤 클래스
private:
	static const char* ItemMenu[];	//아이템 메뉴 출력을 위한 이름배열

	CharacterManager* CharacterM;	//캐릭터 생성과 삭제를 위한 캐릭터매니저

	//부모클래스
	ItemManager* ItemM;				//부모클래스 ItemManager의 Sell 메소드를 호출하기 위한 아이템매니저

	//자식클래스
	SwordManager* SwordM;			//검 아이템 구매를 위한 소드매니저
	WandManager* WandM;				//완드 아이템 구매를 위한 완드매니저
	BowManager* BowM;				//보우 아이템 구매를 위한 보우매니저

public:
	UserManager();
	~UserManager();

	void Init();					//이니셜라이즈

	bool LoginMenu(Node<User*>*);	//로그인 성공 시 메뉴
	void DisplayMenu();				//메뉴출력
	void SelectItem(User*);			//아이템 선택 (검, 완드, 활)
};