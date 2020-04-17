#include"FoodManager.h"

const char* FoodManager::Foods[] = { "야채","과일","육류","곡물" };
int FoodManager::idcode[] = { 100,200,300,400 };

FoodManager::FoodManager()
{
	memset(FoodList, 0, sizeof(FoodList));
}

FoodManager::~FoodManager()
{
	for (int i = 0; i < FSIZE; i++)
	{
		delete FoodList[i];
	}
}

void FoodManager::Init()
{
	for (int i = 0; i < FSIZE; i++)
	{
		FoodList[i] = new LinkedList<Food*>();
	}
}

void FoodManager::Input()
{
	int select;
	char name[NAMESIZE];
	char date[NAMESIZE];
	int weight;
	int price;
	char id[NAMESIZE];

	for (int i = 0; i < sizeof(Foods) / sizeof(char*); i++)
	{
		cout << i << ". " << Foods[i] << endl;
	}
	cout << "선택: ";
	cin >> select;

	if (select < 0 || select > 3)
	{
		cout << "잘못 입력하셨습니다" << endl;
		return;
	}

	cout << "이름: ";
	cin >> name;

	cout << "무게: ";
	cin >> weight;

	cout << "제조일자: ";
	cin >> date;

	cout << "가격: ";
	cin >> price;

	sprintf(id, "%d%d", CODE::FOOD, idcode[select]++);
	FoodList[select]->Insert(new Food(name, date, id, price, weight));
}

void FoodManager::Search()
{
	int select;
	char name[NAMESIZE];

	cout << "검색할 식품 종류를 선택하세요" << endl;
	for (int i = 0; i < sizeof(Foods) / sizeof(char*); i++)
	{
		cout << i << ". " << Foods[i] << endl;
	}
	cout << "선택: ";
	cin >> select;

	cout << "검색 상품 이름: ";
	cin >> name;

	Node<Food*>* nownode = FoodList[select]->GetHead();
	
	cout << "검색 제품 리스트" << endl;
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetName(), name) == 0)
		{
			Food* food = nownode->GetData();
			cout << "이름: " << food->GetName() << "  ";
			cout << "무게: " << food->GetWeight() << "  ";
			cout << "생산일자: " << food->GetDate() << "  ";
			cout << "가격: " << food->GetPrice() << endl;
		}
		nownode = nownode->GetLink();
	}
}

void FoodManager::Delete()
{
	int select;
	char name[NAMESIZE];
	char id[NAMESIZE];

	cout << "삭제할 식품 종류를 선택하세요" << endl;
	for (int i = 0; i < sizeof(Foods) / sizeof(char*); i++)
	{
		cout << i << ". " << Foods[i] << endl;
	}
	cout << "선택: ";
	cin >> select;

	cout << "삭제상품이름: ";
	cin >> name;

	Node<Food*>* nownode = FoodList[select]->GetHead();

	cout << "제품 리스트" << endl;
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetName(), name) == 0)
		{
			Food* food = nownode->GetData();
			cout << "제품 아이디: " << food->GetID() << "  ";
			cout << "이름: " << food->GetName() << "  ";
			cout << "무게: " << food->GetWeight() << "  ";
			cout << "생산일자: " << food->GetDate() << "  ";
			cout << "가격: " << food->GetPrice() << endl;
		}
		nownode = nownode->GetLink();
	}

	cout << "삭제상품 아이디: ";
	cin >> id;

	nownode = FoodList[select]->GetHead();
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetID(), id) == 0)
		{
			FoodList[select]->Delete(nownode->GetData());
			cout << "선택상품이 삭제되었습니다" << endl;
			return;
		}
		nownode = nownode->GetLink();
	}
}
