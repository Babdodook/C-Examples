#include"TotalManager.h"

const char* TotalManager::Productname[] = { "��ǰ","�Ƿ�","����" };

TotalManager::TotalManager()
{
	FoodM = nullptr;
	ClothesM = nullptr;
	HomeAppM = nullptr;
}

TotalManager::~TotalManager()
{
	delete FoodM;
	delete ClothesM;
	delete HomeAppM;
}

void TotalManager::Init()
{
	FoodM = new FoodManager();
	ClothesM = new ClothesManager();
	HomeAppM = new HomeAppManager();

	FoodM->Init();
	ClothesM->Init();
	HomeAppM->Init();
}

void TotalManager::Run()
{
	Init();

	int select;

	while (1)
	{
		Mainmenu();
		cin >> select;
		switch (select)
		{
		case MENU::ADD:
			SelectProduct()->Input();
			break;
		case MENU::SEARCH:
			SelectProduct()->Search();
			break;
		case MENU::DELETE:
			SelectProduct()->Delete();
			break;
		case MENU::EXIT:
			exit(1);
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			Clear();
			continue;
		}
	}
}

void TotalManager::Mainmenu()
{
	cout << "<<    ��  ��    >>" << endl;
	cout << "1. ��ǰ �߰�" << endl;
	cout << "2. ��ǰ �˻�" << endl;
	cout << "3. ��ǰ ����" << endl;
	cout << "4. ����" << endl;
	cout << "����: ";
}

ProductManager* TotalManager::SelectProduct()
{
	int select;
	for (int i = 0; i < sizeof(Productname) / sizeof(char*); i++)
	{
		cout << i << ". " << Productname[i] << endl;
	}
	cout << "����: ";
	cin >> select;
	if (0 > select || select > 2)
	{
		cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
		Clear();
		return 0;
	}
	
	switch (select)
	{
	case PRODUCT::FOOD:
		return FoodM;
	case PRODUCT::CLOTES:
		return ClothesM;
	case PRODUCT::HOMEAPP:
		return HomeAppM;
	}
}

void TotalManager::Clear()
{
	if (cin.failbit)
	{
		cin.clear();
		cin.ignore(256, '\n');
	}
}