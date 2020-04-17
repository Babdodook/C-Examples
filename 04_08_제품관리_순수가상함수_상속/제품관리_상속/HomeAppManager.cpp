#include"HomeAppManager.h"

const char* HomeAppManager::HomeApps[] = { "TV","�����","��Ź��" };
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
	cout << "����: ";
	cin >> select;

	if (select < 0 || select > 2)
	{
		cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
		return;
	}

	cout << "�̸�: ";
	cin >> name;

	cout << "�𵨸�: ";
	cin >> model;

	cout << "��������: ";
	cin >> date;

	cout << "����: ";
	cin >> price;

	sprintf(id, "%d%d", CODE::HOMEAPP, idcode[select]++);
	HomeAppList[select]->Insert(new HomeApp(name, date, id, price, model));
}

void HomeAppManager::Search()
{
	int select;
	char name[NAMESIZE];

	cout << "�˻��� ��ǰ ������ �����ϼ���" << endl;
	for (int i = 0; i < sizeof(HomeApps) / sizeof(char*); i++)
	{
		cout << i << ". " << HomeApps[i] << endl;
	}
	cout << "����: ";
	cin >> select;

	cout << "�˻� ��ǰ �̸�: ";
	cin >> name;

	Node<HomeApp*>* nownode = HomeAppList[select]->GetHead();

	cout << "�˻� ��ǰ ����Ʈ" << endl;
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetName(), name) == 0)
		{
			HomeApp* homeapp = nownode->GetData();
			cout << "�̸�: " << homeapp->GetName() << "  ";
			cout << "�𵨸�: " << homeapp->GetModel() << "  ";
			cout << "��������: " << homeapp->GetDate() << "  ";
			cout << "����: " << homeapp->GetPrice() << endl;
		}
		nownode = nownode->GetLink();
	}
}

void HomeAppManager::Delete()
{
	int select;
	char name[NAMESIZE];
	char id[NAMESIZE];

	cout << "������ ��ǰ ������ �����ϼ���" << endl;
	for (int i = 0; i < sizeof(HomeApps) / sizeof(char*); i++)
	{
		cout << i << ". " << HomeApps[i] << endl;
	}
	cout << "����: ";
	cin >> select;

	cout << "������ǰ�̸�: ";
	cin >> name;

	Node<HomeApp*>* nownode = HomeAppList[select]->GetHead();

	cout << "��ǰ ����Ʈ" << endl;
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetName(), name) == 0)
		{
			HomeApp* homeapp = nownode->GetData();
			cout << "��ǰ ���̵�: " << homeapp->GetID() << "  ";
			cout << "�̸�: " << homeapp->GetName() << "  ";
			cout << "�𵨸�: " << homeapp->GetModel() << "  ";
			cout << "��������: " << homeapp->GetDate() << "  ";
			cout << "����: " << homeapp->GetPrice() << endl;
		}
		nownode = nownode->GetLink();
	}

	cout << "������ǰ ���̵�: ";
	cin >> id;

	nownode = HomeAppList[select]->GetHead();
	while (nownode != nullptr)
	{
		if (strcmp(nownode->GetData()->GetID(), id) == 0)
		{
			HomeAppList[select]->Delete(nownode->GetData());
			cout << "���û�ǰ�� �����Ǿ����ϴ�" << endl;
			return;
		}
		nownode = nownode->GetLink();
	}
}
