#include"Bow.h"

//�������� �̸�, ����, ����, �������̵�, �Ӽ��� ��������� ����
Bow::Bow(const char* name, int weight, int price, const char* itemid, int dex)
	:Item(name, weight, price, itemid), dex(dex)
{
}

Bow::~Bow()
{
}

void Bow::ShowItemInfo()					//�������� ���� ���
{
	cout << "------------------" << endl;
	cout << "Item Number: " << Itemid << endl;
	cout << "�̸�: " << name << endl;
	cout << "����: " << weight << endl;
	cout << "��ø+ " << dex << endl << endl;
}