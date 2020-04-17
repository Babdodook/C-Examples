#pragma once
#include"User.h"
#include"CharacterManager.h"
#include"SwordManager.h"
#include"WandManager.h"
#include"BowManager.h"
#include"LinkedList.h"

class UserManager {					//�α��ε� ������ Ȱ���� �����ϱ� ���� ��Ʈ�� Ŭ����
private:
	static UserManager* mPthis;

	static const char* ItemMenu[];	//������ �޴� ����� ���� �̸��迭

	UserManager();
	~UserManager();
public:
	static UserManager* Create();
	static UserManager* GetInstance();
	static void Destroy();

	bool LoginMenu(Node<User*>*);	//�α��� ���� �� �޴�
	void DisplayMenu();				//�޴����
	void SelectItem(User*);			//������ ���� (��, �ϵ�, Ȱ)
};