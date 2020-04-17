#include"CoreManager.h"

int main()			//메인 메소드
{
	CoreManager::Create();		//코어매니저 객체 생성
	CoreManager::GetInstance()->Run();								//프로그램 구동 메소드인 Run 호출
	CoreManager::Destroy();								//프로그램 종료시 메모리 해제

	return 0;
}