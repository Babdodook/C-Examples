#pragma once
#include"UserManager.h"

class LoginManager {				//유저 생성,삭제 컨트롤 클래스
private:
	static LoginManager* mPthis;

	LinkedList<User*>* UserList;	//유저 객체저장을 위한 유저 리스트
	Node<User*>* Nowuser;			//현재 로그인한 유저

	LoginManager();
	~LoginManager();
public:
	static LoginManager* Create();
	static LoginManager* GetInstance();
	static void Destroy();

	void Init();					//이니셜라이즈
	void CreateAcc();				//유저 계정 생성
	void Login();					//로그인 관리
};