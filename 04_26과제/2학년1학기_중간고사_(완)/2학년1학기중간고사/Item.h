#pragma once
#include"BasicHeader.h"

class Item {								//������ ������ Ŭ����
protected:
	char name[SIZE];						//������ �̸�
	int weight;								//����
	int price;								//����
	char Itemid[SIZE];						//�������� ���� ���̵�
public:
	//�����ڿ��� �̸�, ����, ����, �������� ��������� ����
	Item(const char* name, int weight, int price, const char* Itemid)
		:weight(weight), price(price)
	{
		strcpy(this->name, name);
		strcpy(this->Itemid, Itemid);
	}

	//�Ҹ��� �����Լ�
	virtual ~Item() {}

	//���� ���̵� ����
	const char* Getid()
	{
		return Itemid;
	}

	//�������� ���� ����
	const int GetPrice()
	{
		return price;
	}

	//��ӹ޴� �� ������ Ŭ�������� ����� �ٸ��⶧����
	//�޼ҵ带 �߻�ȭ��Ų��
	virtual void ShowItemInfo() = 0;
};