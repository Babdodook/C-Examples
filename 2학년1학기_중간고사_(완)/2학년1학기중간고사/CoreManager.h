#pragma once
#include"LoginManager.h"

class CoreManager {			//최상위 컨트롤 클래스
private:
	LoginManager* LoginM;	//로그인 관리 매니저(유저 회원가입, 유저 로그인 기능 관리, 유저리스트 소유)
public:
	CoreManager();
	~CoreManager();

	void Run();				//프로그램 구동

	void Init();			//이니셜라이즈
	const int Mainmenu();	//메인 메뉴 출력
};