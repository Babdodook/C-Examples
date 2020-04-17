#pragma once
#include"User.h"
#include"CharacterManager.h"
#include"SwordManager.h"
#include"WandManager.h"
#include"BowManager.h"
#include"LinkedList.h"

class UserManager {					//�α��ε� ������ Ȱ���� �����ϱ� ���� ��Ʈ�� Ŭ����
private:
	static const char* ItemMenu[];	//������ �޴� ����� ���� �̸��迭

	CharacterManager* CharacterM;	//ĳ���� ������ ������ ���� ĳ���͸Ŵ���

	//�θ�Ŭ����
	ItemManager* ItemM;				//�θ�Ŭ���� ItemManager�� Sell �޼ҵ带 ȣ���ϱ� ���� �����۸Ŵ���

	//�ڽ�Ŭ����
	SwordManager* SwordM;			//�� ������ ���Ÿ� ���� �ҵ�Ŵ���
	WandManager* WandM;				//�ϵ� ������ ���Ÿ� ���� �ϵ�Ŵ���
	BowManager* BowM;				//���� ������ ���Ÿ� ���� ����Ŵ���

public:
	UserManager();
	~UserManager();

	void Init();					//�̴ϼȶ�����

	bool LoginMenu(Node<User*>*);	//�α��� ���� �� �޴�
	void DisplayMenu();				//�޴����
	void SelectItem(User*);			//������ ���� (��, �ϵ�, Ȱ)
};