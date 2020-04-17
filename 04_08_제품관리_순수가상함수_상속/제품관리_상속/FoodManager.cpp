#include"FoodManager.h"

const char* FoodManager::Foods[] = { "��ä","����","����","�" };
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
	cout << "����: ";
	cin >> select;

	if (select < 0 || select > 3)
	{
		cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
		return;
	}

	cout << "�̸�: ";
	cin >> name;

	cout << "����: ";
	cin >> weight;

	cout << "��������: ";
	cin >> date;

	cout << "����: ";
	cin >> price;

	sprintf(id, "%d%d", CODE::FOOD, idcode[select]++);
	FoodList[select]->Insert(new Food(name, date, id, price, weight));
}

void FoodManager::Search()
{
	int select;
	char name[NAMESIZE];

	cout << "�˻��� ��ǰ ������ �����ϼ���" << endl;
	for (int i = 0; i < sizeof(Foods) / sizeof(char*); i++)
	{
		cout << i << ". " << Foods[i] << endl;
	}
	cout << "����: ";
	cin >> select;

	cout << "�˻� ��ǰ �̸�: ";
	cin >> name;

	Node<Food*>* nownode = FoodList[select]->GetHead();
	
	cout << "�˻� ��ǰ ����Ʈ" << endl;
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetName(), name) == 0)
		{
			Food* food = nownode->GetData();
			cout << "�̸�: " << food->GetName() << "  ";
			cout << "����: " << food->GetWeight() << "  ";
			cout << "��������: " << food->GetDate() << "  ";
			cout << "����: " << food->GetPrice() << endl;
		}
		nownode = nownode->GetLink();
	}
}

void FoodManager::Delete()
{
	int select;
	char name[NAMESIZE];
	char id[NAMESIZE];

	cout << "������ ��ǰ ������ �����ϼ���" << endl;
	for (int i = 0; i < sizeof(Foods) / sizeof(char*); i++)
	{
		cout << i << ". " << Foods[i] << endl;
	}
	cout << "����: ";
	cin >> select;

	cout << "������ǰ�̸�: ";
	cin >> name;

	Node<Food*>* nownode = FoodList[select]->GetHead();

	cout << "��ǰ ����Ʈ" << endl;
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetName(), name) == 0)
		{
			Food* food = nownode->GetData();
			cout << "��ǰ ���̵�: " << food->GetID() << "  ";
			cout << "�̸�: " << food->GetName() << "  ";
			cout << "����: " << food->GetWeight() << "  ";
			cout << "��������: " << food->GetDate() << "  ";
			cout << "����: " << food->GetPrice() << endl;
		}
		nownode = nownode->GetLink();
	}

	cout << "������ǰ ���̵�: ";
	cin >> id;

	nownode = FoodList[select]->GetHead();
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetID(), id) == 0)
		{
			FoodList[select]->Delete(nownode->GetData());
			cout << "���û�ǰ�� �����Ǿ����ϴ�" << endl;
			return;
		}
		nownode = nownode->GetLink();
	}
}
