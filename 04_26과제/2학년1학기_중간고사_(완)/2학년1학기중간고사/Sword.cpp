#include"Sword.h"

//�������� �̸�, ����, ����, �������̵�, �Ӽ��� ��������� ����
Sword::Sword(const char* name, int weight, int price, const char* itemid, int power)
	:Item(name,weight,price,itemid), power(power)
{
}

Sword::~Sword()
{
}

void Sword::ShowItemInfo()					//�������� ���� ���
{
	cout << "------------------" << endl;
	cout << "Item Number: " << Itemid << endl;
	cout << "�̸�: " << name << endl;
	cout << "����: " << weight << endl;
	cout << "��+ " << power << endl << endl;
}