#include"ClothesManager.h"

const char* ClothesManager::Clothess[] = { "남성의류","여성의류" };
int ClothesManager::idcode[] = { 100,200 };

ClothesManager::ClothesManager()
{
	memset(ClothesList, 0, sizeof(ClothesList));
}

ClothesManager::~ClothesManager()
{
	for (int i = 0; i < CSIZE; i++)
	{
		delete ClothesList[i];
	}
}

void ClothesManager::Init()
{
	for (int i = 0; i < CSIZE; i++)
	{
		ClothesList[i] = new LinkedList<Clothes*>();
	}
}

void ClothesManager::Input()
{
	int select;
	char name[NAMESIZE];
	char date[NAMESIZE];
	int size;
	int price;
	char id[NAMESIZE];

	for (int i = 0; i < sizeof(Clothess) / sizeof(char*); i++)
	{
		cout << i << ". " << Clothess[i] << endl;
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

	cout << "싸이즈: ";
	cin >> size;

	cout << "제조일자: ";
	cin >> date;

	cout << "가격: ";
	cin >> price;

	sprintf(id, "%d%d", CODE::CLOTHES, idcode[select]++);
	ClothesList[select]->Insert(new Clothes(name, date, id, price, size));
}

void ClothesManager::Search()
{
	int select;
	char name[NAMESIZE];

	cout << "검색할 식품 종류를 선택하세요" << endl;
	for (int i = 0; i < sizeof(Clothess) / sizeof(char*); i++)
	{
		cout << i << ". " << Clothess[i] << endl;
	}
	cout << "선택: ";
	cin >> select;

	cout << "검색 상품 이름: ";
	cin >> name;

	Node<Clothes*>* nownode = ClothesList[select]->GetHead();

	cout << "검색 제품 리스트" << endl;
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetName(), name) == 0)
		{
			Clothes* Clothes = nownode->GetData();
			cout << "이름: " << Clothes->GetName() << "  ";
			cout << "싸이즈: " << Clothes->GetSize() << "  ";
			cout << "생산일자: " << Clothes->GetDate() << "  ";
			cout << "가격: " << Clothes->GetPrice() << endl;
		}
		nownode = nownode->GetLink();
	}
}

void ClothesManager::Delete()
{
	int select;
	char name[NAMESIZE];
	char id[NAMESIZE];

	cout << "삭제할 식품 종류를 선택하세요" << endl;
	for (int i = 0; i < sizeof(Clothess) / sizeof(char*); i++)
	{
		cout << i << ". " << Clothess[i] << endl;
	}
	cout << "선택: ";
	cin >> select;

	cout << "삭제상품이름: ";
	cin >> name;

	Node<Clothes*>* nownode = ClothesList[select]->GetHead();

	cout << "제품 리스트" << endl;
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetName(), name) == 0)
		{
			Clothes* Clothes = nownode->GetData();
			cout << "제품 아이디: " << Clothes->GetID() << "  ";
			cout << "이름: " << Clothes->GetName() << "  ";
			cout << "싸이즈: " << Clothes->GetSize() << "  ";
			cout << "생산일자: " << Clothes->GetDate() << "  ";
			cout << "가격: " << Clothes->GetPrice() << endl;
		}
		nownode = nownode->GetLink();
	}

	cout << "삭제상품 아이디: ";
	cin >> id;

	nownode = ClothesList[select]->GetHead();
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetID(), id) == 0)
		{
			ClothesList[select]->Delete(nownode->GetData());
			cout << "선택상품이 삭제되었습니다" << endl;
			return;
		}
		nownode = nownode->GetLink();
	}
}
