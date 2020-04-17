#pragma once
#include"User.h"
#include"LinkedList.h"

class ItemManager {		//������ ��Ʈ�� Ŭ����
protected:
	static ItemManager* mPthis;

	static const char* Itemid[];	//�� ������ �������� �Ҵ��ϱ� ���� ���̵� �迭

	ItemManager();
	~ItemManager();
public:
	static ItemManager* Create();
	static ItemManager* GetInstance();
	static void Destroy();

	void Sell(User*);	//������ �Ǹ� �޼ҵ�
	void Show(User*);	//���� ��� �޼ҵ�(�̱���)
};