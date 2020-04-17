#pragma once
#include"LoginManager.h"

class CoreManager {			//최상위 컨트롤 클래스
private:
	static CoreManager* mPthis;

	CoreManager();
	~CoreManager();
public:
	static CoreManager* Create();
	static CoreManager* GetInstance();
	static void Destroy();

	void Run();				//프로그램 구동

	void Init();			//이니셜라이즈
	const int Mainmenu();	//메인 메뉴 출력
};