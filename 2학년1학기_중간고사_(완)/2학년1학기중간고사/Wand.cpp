#include"Wand.h"

//�������� �̸�, ����, ����, �������̵�, �Ӽ��� ��������� ����
Wand::Wand(const char* name, int weight, int price, const char* itemid, int wis)
	:Item(name, weight, price, itemid), wis(wis)
{
}

Wand::~Wand()
{
}

void Wand::ShowItemInfo()					//�������� ���� ���
{
	cout << "------------------" << endl;
	cout << "Item Number: " << Itemid << endl;
	cout << "�̸�: " << name << endl;
	cout << "����: " << weight << endl;
	cout << "����+ " << wis << endl << endl;
}