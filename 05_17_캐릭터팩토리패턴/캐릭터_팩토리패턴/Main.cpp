#include"OrcFactory.h"
#include"ElfFactory.h"
#include"HumanFactory.h"

int main()
{
	CharacterFactory* CFactory = nullptr;

	int select;
	cout << "ĳ���� ����" << endl;
	cout << "1.��ũ 2.���� 3.�ΰ�" << endl;
	cout << "����: ";
	cin >> select;

	switch (select)
	{
	case ORC:
		CFactory = new OrcFactory();
		break;
	case ELF:
		CFactory = new ElfFactory();
		break;
	case HUMAN:
		CFactory = new HumanFactory();
		break;
	}
	cout << endl;

	CFactory->CreateCharacter();

}