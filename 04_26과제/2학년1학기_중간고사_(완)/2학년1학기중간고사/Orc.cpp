#include"Orc.h"

Orc::Orc(const char* name,const char* cid)		//�̸�, �������̵� ����
	:Character(name,cid)
{
	power = rand() % 100 + 1;					//ĳ������ ������ �������� �����ȴ�
}

Orc::~Orc() 
{
}

void Orc::ShowCInfo()							//ĳ���� ���� ���
{
	cout << "------------------" << endl;
	cout << "Slot Number: " << cid << endl;
	cout << "�̸�: " << name << endl;
	cout << "����: ��ũ" << endl;
	cout << "��: " << power << endl << endl;
}