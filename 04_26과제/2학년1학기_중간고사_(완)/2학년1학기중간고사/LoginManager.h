#pragma once
#include"UserManager.h"

class LoginManager {				//���� ����,���� ��Ʈ�� Ŭ����
private:
	static LoginManager* mPthis;

	LinkedList<User*>* UserList;	//���� ��ü������ ���� ���� ����Ʈ
	Node<User*>* Nowuser;			//���� �α����� ����

	LoginManager();
	~LoginManager();
public:
	static LoginManager* Create();
	static LoginManager* GetInstance();
	static void Destroy();

	void Init();					//�̴ϼȶ�����
	void CreateAcc();				//���� ���� ����
	void Login();					//�α��� ����
};