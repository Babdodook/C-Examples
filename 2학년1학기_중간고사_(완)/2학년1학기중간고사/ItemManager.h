#pragma once
#include"User.h"
#include"LinkedList.h"

class ItemManager {		//������ ��Ʈ�� Ŭ����
protected:
	static const char* Itemid[];	//�� ������ �������� �Ҵ��ϱ� ���� ���̵� �迭
public:
	ItemManager();
	~ItemManager();

	void Sell(User*);	//������ �Ǹ� �޼ҵ�
	void Show(User*);	//���� ��� �޼ҵ�(�̱���)
};