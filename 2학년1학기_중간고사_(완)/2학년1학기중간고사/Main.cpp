#include"CoreManager.h"

int main()			//메인 메소드
{
	CoreManager* CoreM = new CoreManager();		//코어매니저 객체 생성
	CoreM->Run();								//프로그램 구동 메소드인 Run 호출
	delete CoreM;								//프로그램 종료시 메모리 해제

	return 0;
}