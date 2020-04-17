#include"CharacterFactory.h"

void CharacterFactory::CreateCharacter()
{
	Character* newCharacter = nullptr;
	JobItemFactory* JobFactory = nullptr;;

	int select;
	cout << "직업선택" << endl;
	cout << "1.기사 2.마법사 3.성직자" << endl;
	cout << "선택: ";
	cin >> select;

	char Job[SIZE];

	switch (select)
	{
	case JOB::KNIGHT:
		JobFactory = new KnightFactory();
		strcpy(Job, "기사");
		break;
	case JOB::MAGICIAN:
		JobFactory = new MagicianFactory();
		strcpy(Job, "마법사");
		break;
	case JOB::PRIEST:
		JobFactory = new PriestFactory();
		strcpy(Job, "프리스트");
		break;
	}
	cout << endl;

	newCharacter = makeCharacter(JobFactory,Job);

	newCharacter->Display();
}