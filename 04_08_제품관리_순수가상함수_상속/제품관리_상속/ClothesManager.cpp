#include"ClothesManager.h"

const char* ClothesManager::Clothess[] = { "�����Ƿ�","�����Ƿ�" };
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
	cout << "����: ";
	cin >> select;

	if (select < 0 || select > 2)
	{
		cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
		return;
	}

	cout << "�̸�: ";
	cin >> name;

	cout << "������: ";
	cin >> size;

	cout << "��������: ";
	cin >> date;

	cout << "����: ";
	cin >> price;

	sprintf(id, "%d%d", CODE::CLOTHES, idcode[select]++);
	ClothesList[select]->Insert(new Clothes(name, date, id, price, size));
}

void ClothesManager::Search()
{
	int select;
	char name[NAMESIZE];

	cout << "�˻��� ��ǰ ������ �����ϼ���" << endl;
	for (int i = 0; i < sizeof(Clothess) / sizeof(char*); i++)
	{
		cout << i << ". " << Clothess[i] << endl;
	}
	cout << "����: ";
	cin >> select;

	cout << "�˻� ��ǰ �̸�: ";
	cin >> name;

	Node<Clothes*>* nownode = ClothesList[select]->GetHead();

	cout << "�˻� ��ǰ ����Ʈ" << endl;
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetName(), name) == 0)
		{
			Clothes* Clothes = nownode->GetData();
			cout << "�̸�: " << Clothes->GetName() << "  ";
			cout << "������: " << Clothes->GetSize() << "  ";
			cout << "��������: " << Clothes->GetDate() << "  ";
			cout << "����: " << Clothes->GetPrice() << endl;
		}
		nownode = nownode->GetLink();
	}
}

void ClothesManager::Delete()
{
	int select;
	char name[NAMESIZE];
	char id[NAMESIZE];

	cout << "������ ��ǰ ������ �����ϼ���" << endl;
	for (int i = 0; i < sizeof(Clothess) / sizeof(char*); i++)
	{
		cout << i << ". " << Clothess[i] << endl;
	}
	cout << "����: ";
	cin >> select;

	cout << "������ǰ�̸�: ";
	cin >> name;

	Node<Clothes*>* nownode = ClothesList[select]->GetHead();

	cout << "��ǰ ����Ʈ" << endl;
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetName(), name) == 0)
		{
			Clothes* Clothes = nownode->GetData();
			cout << "��ǰ ���̵�: " << Clothes->GetID() << "  ";
			cout << "�̸�: " << Clothes->GetName() << "  ";
			cout << "������: " << Clothes->GetSize() << "  ";
			cout << "��������: " << Clothes->GetDate() << "  ";
			cout << "����: " << Clothes->GetPrice() << endl;
		}
		nownode = nownode->GetLink();
	}

	cout << "������ǰ ���̵�: ";
	cin >> id;

	nownode = ClothesList[select]->GetHead();
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetID(), id) == 0)
		{
			ClothesList[select]->Delete(nownode->GetData());
			cout << "���û�ǰ�� �����Ǿ����ϴ�" << endl;
			return;
		}
		nownode = nownode->GetLink();
	}
}
