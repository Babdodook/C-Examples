#pragma once
#include"Item.h"

class Wand :public Item {	//�ϵ� ������ Ŭ����, ������Ŭ���� ���
private:
	int wis;				//�������� �Ӽ�, ���� ������ ��Ÿ��
public:
	Wand(const char* name, int weight, int price, const char* itemid, int wis);
	~Wand();

	virtual void ShowItemInfo();	//������ ���� ��� �޼ҵ�
};