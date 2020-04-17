#include"HomeAppManager.h"

const char* HomeAppManager::HomeApps[] = { "TV","냉장고","세탁기" };
int HomeAppManager::idcode[] = { 100,200,300 };

HomeAppManager::HomeAppManager()
{
	memset(HomeAppList, 0, sizeof(HomeAppList));
}

HomeAppManager::~HomeAppManager()
{
	for (int i = 0; i < HSIZE; i++)
	{
		delete HomeAppList[i];
	}
}

void HomeAppManager::Init()
{
	for (int i = 0; i < HSIZE; i++)
	{
		HomeAppList[i] = new LinkedList<HomeApp*>();
	}
}

void HomeAppManager::Input()
{
	int select;
	char name[NAMESIZE];
	char date[NAMESIZE];
	char model[NAMESIZE];
	int price;
	char id[NAMESIZE];

	for (int i = 0; i < sizeof(HomeApps) / sizeof(char*); i++)
	{
		cout << i << ". " << HomeApps[i] << endl;
	}
	cout << "선택: ";
	cin >> select;

	if (select < 0 || select > 2)
	{
		cout << "잘못 입력하셨습니다" << endl;
		return;
	}

	cout << "이름: ";
	cin >> name;

	cout << "모델명: ";
	cin >> model;

	cout << "제조일자: ";
	cin >> date;

	cout << "가격: ";
	cin >> price;

	sprintf(id, "%d%d", CODE::HOMEAPP, idcode[select]++);
	HomeAppList[select]->Insert(new HomeApp(name, date, id, price, model));
}

void HomeAppManager::Search()
{
	int select;
	char name[NAMESIZE];

	cout << "검색할 식품 종류를 선택하세요" << endl;
	for (int i = 0; i < sizeof(HomeApps) / sizeof(char*); i++)
	{
		cout << i << ". " << HomeApps[i] << endl;
	}
	cout << "선택: ";
	cin >> select;

	cout << "검색 상품 이름: ";
	cin >> name;

	Node<HomeApp*>* nownode = HomeAppList[select]->GetHead();

	cout << "검색 제품 리스트" << endl;
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetName(), name) == 0)
		{
			HomeApp* homeapp = nownode->GetData();
			cout << "이름: " << homeapp->GetName() << "  ";
			cout << "모델명: " << homeapp->GetModel() << "  ";
			cout << "생산일자: " << homeapp->GetDate() << "  ";
			cout << "가격: " << homeapp->GetPrice() << endl;
		}
		nownode = nownode->GetLink();
	}
}

void HomeAppManager::Delete()
{
	int select;
	char name[NAMESIZE];
	char id[NAMESIZE];

	cout << "삭제할 식품 종류를 선택하세요" << endl;
	for (int i = 0; i < sizeof(HomeApps) / sizeof(char*); i++)
	{
		cout << i << ". " << HomeApps[i] << endl;
	}
	cout << "선택: ";
	cin >> select;

	cout << "삭제상품이름: ";
	cin >> name;

	Node<HomeApp*>* nownode = HomeAppList[select]->GetHead();

	cout << "제품 리스트" << endl;
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetName(), name) == 0)
		{
			HomeApp* homeapp = nownode->GetData();
			cout << "제품 아이디: " << homeapp->GetID() << "  ";
			cout << "이름: " << homeapp->GetName() << "  ";
			cout << "모델명: " << homeapp->GetModel() << "  ";
			cout << "생산일자: " << homeapp->GetDate() << "  ";
			cout << "가격: " << homeapp->GetPrice() << endl;
		}
		nownode = nownode->GetLink();
	}

	cout << "삭제상품 아이디: ";
	cin >> id;

	nownode = HomeAppList[select]->GetHead();
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetID(), id) == 0)
		{
			HomeAppList[select]->Delete(nownode->GetData());
			cout << "선택상품이 삭제되었습니다" << endl;
			return;
		}
		nownode = nownode->GetLink();
	}
}
