#pragma once
#include"Item.h"

class Sword :public Item {	//�� ������ Ŭ����, ������Ŭ���� ���
private:
	int power;				//�������� �Ӽ�, �� ������ ��Ÿ��
public:
	Sword(const char* name, int weight, int price, const char* itemid, int power);
	~Sword();

	virtual void ShowItemInfo();	//������ ���� ��� �޼ҵ�
};