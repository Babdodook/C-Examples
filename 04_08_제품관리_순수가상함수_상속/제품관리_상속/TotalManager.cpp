#include"TotalManager.h"

const char* TotalManager::Productname[] = { "식품","의류","가전" };

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
			cout << "잘못 입력하셨습니다" << endl;
			Clear();
			continue;
		}
	}
}

void TotalManager::Mainmenu()
{
	cout << "<<    선  택    >>" << endl;
	cout << "1. 상품 추가" << endl;
	cout << "2. 상품 검색" << endl;
	cout << "3. 상품 삭제" << endl;
	cout << "4. 종료" << endl;
	cout << "선택: ";
}

ProductManager* TotalManager::SelectProduct()
{
	int select;
	for (int i = 0; i < sizeof(Productname) / sizeof(char*); i++)
	{
		cout << i << ". " << Productname[i] << endl;
	}
	cout << "선택: ";
	cin >> select;
	if (0 > select || select > 2)
	{
		cout << "잘못 입력하셨습니다" << endl;
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