#include"Human.h"

Human::Human(const char* name, const char* cid)		//�̸�, �������̵� ����
	:Character(name, cid)
{
	wisdom = rand() % 100 + 1;						//ĳ������ ������ �������� �����ȴ�
}

Human::~Human()
{
}

void Human::ShowCInfo()								//ĳ���� ���� ���
{
	cout << "------------------" << endl;
	cout << "Slot Number: " << cid << endl;
	cout << "�̸�: " << name << endl;
	cout << "����: �ΰ�" << endl;
	cout << "����: " << wisdom << endl << endl;
}