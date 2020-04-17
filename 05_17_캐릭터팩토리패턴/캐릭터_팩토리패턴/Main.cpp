#include"OrcFactory.h"
#include"ElfFactory.h"
#include"HumanFactory.h"

int main()
{
	CharacterFactory* CFactory = nullptr;

	int select;
	cout << "캐릭터 생성" << endl;
	cout << "1.오크 2.엘프 3.인간" << endl;
	cout << "선택: ";
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