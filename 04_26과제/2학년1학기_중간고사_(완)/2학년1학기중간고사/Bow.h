#pragma once
#include"Item.h"

class Bow :public Item {	//Ȱ ������ Ŭ����, ������Ŭ���� ���
private:
	int dex;				//�������� �Ӽ�, �� ������ ��Ÿ��
public:
	Bow(const char* name, int weight, int price, const char* itemid, int dex);
	~Bow();

	virtual void ShowItemInfo();	//������ ���� ��� �޼ҵ�
};