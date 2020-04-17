#include"CharacterFactory.h"

void CharacterFactory::CreateCharacter()
{
	Character* newCharacter = nullptr;
	JobItemFactory* JobFactory = nullptr;;

	int select;
	cout << "��������" << endl;
	cout << "1.��� 2.������ 3.������" << endl;
	cout << "����: ";
	cin >> select;

	char Job[SIZE];

	switch (select)
	{
	case JOB::KNIGHT:
		JobFactory = new KnightFactory();
		strcpy(Job, "���");
		break;
	case JOB::MAGICIAN:
		JobFactory = new MagicianFactory();
		strcpy(Job, "������");
		break;
	case JOB::PRIEST:
		JobFactory = new PriestFactory();
		strcpy(Job, "������Ʈ");
		break;
	}
	cout << endl;

	newCharacter = makeCharacter(JobFactory,Job);

	newCharacter->Display();
}