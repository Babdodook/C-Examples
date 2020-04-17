#pragma once
#include"User.h"
#include"CharacterManager.h"
#include"SwordManager.h"
#include"WandManager.h"
#include"BowManager.h"
#include"LinkedList.h"

class UserManager {					//로그인된 유저의 활동을 관리하기 위한 컨트롤 클래스
private:
	static UserManager* mPthis;

	static const char* ItemMenu[];	//아이템 메뉴 출력을 위한 이름배열

	UserManager();
	~UserManager();
public:
	static UserManager* Create();
	static UserManager* GetInstance();
	static void Destroy();

	bool LoginMenu(Node<User*>*);	//로그인 성공 시 메뉴
	void DisplayMenu();				//메뉴출력
	void SelectItem(User*);			//아이템 선택 (검, 완드, 활)
};