#include"Elf.h"

Elf::Elf(const char* name, const char* cid)		//�̸�, �������̵� ����
	:Character(name, cid)
{
	dex = rand() % 100 + 1;						//ĳ������ ������ �������� �����ȴ�
}

Elf::~Elf()
{
}

void Elf::ShowCInfo()							//ĳ���� ���� ���
{
	cout << "------------------" << endl;
	cout << "Slot Number: " << cid << endl;
	cout << "�̸�: " << name << endl;
	cout << "����: ����" << endl;
	cout << "��ø: " << dex << endl << endl;
}