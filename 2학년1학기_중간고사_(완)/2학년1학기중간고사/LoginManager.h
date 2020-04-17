#pragma once
#include"UserManager.h"

class LoginManager {				//���� ����,���� ��Ʈ�� Ŭ����
private:
	LinkedList<User*>* UserList;	//���� ��ü������ ���� ���� ����Ʈ
	Node<User*>* Nowuser;			//���� �α����� ����
	UserManager* UserM;				//�α����� ���� Ȱ�� ���� �Ŵ���
public:
	LoginManager();
	~LoginManager();

	void Init();					//�̴ϼȶ�����
	void CreateAcc();				//���� ���� ����
	void Login();					//�α��� ����
};