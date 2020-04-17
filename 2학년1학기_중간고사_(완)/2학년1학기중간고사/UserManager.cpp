#pragma once
#include"UserManager.h"

const char* UserManager::ItemMenu[] = { "��","�ϵ�","Ȱ" };

UserManager::UserManager()	//�����ڿ��� �ʱ�ȭ
{
	CharacterM = nullptr;
	ItemM = nullptr;
	SwordM = nullptr;
	WandM = nullptr;
	BowM = nullptr;
}

UserManager::~UserManager()	//�Ҹ��ڿ��� �޸� ����
{
	delete CharacterM;
	delete SwordM;
	delete WandM;
	delete BowM;
	delete ItemM;
}

void UserManager::Init()	//�̴ϼȶ������ �����Ҵ�
{
	CharacterM = new CharacterManager();
	ItemM = new ItemManager();
	SwordM = new SwordManager();
	WandM = new WandManager();
	BowM = new BowManager();
}

bool UserManager::LoginMenu(Node<User*>* Nowuser)	//�α��θ޴�
													//1. ĳ���� ����
													//2. ĳ���� ����
													//3. ������ ����
													//4. ������ �Ǹ�
													//5. �α׾ƿ�
													//6. ȸ��Ż��
{
	int select;
	while (1)
	{
		DisplayMenu();
		cin >> select;

		switch (select)
		{
		case LOGMENU::CREATE_C:
			CharacterM->Create(Nowuser->GetData());		//ĳ���� ���� �޼ҵ� ȣ��, �Ű������� ���������� �Ѱ���
			break;
		case LOGMENU::DELETE_C:						
			CharacterM->Delete(Nowuser->GetData());		//ĳ���� ���� �޼ҵ� ȣ��
			break;
		case LOGMENU::BUY:
			SelectItem(Nowuser->GetData());				//�����ۼ��� �޼ҵ� ȣ��
			break;
		case LOGMENU::SELL:
			ItemM->Sell(Nowuser->GetData());			//������ �Ǹ� �޼ҵ� ȣ��
			break;
		case LOGMENU::LOGOUT:							//�α׾ƿ��� true��ȯ
			return true;
		case LOGMENU::DELETE_ACC:						//ȸ�� Ż��� false��ȯ
			return false;
		}
	}
}

void UserManager::SelectItem(User* Nowuser)				//������ ����ȭ�鿡�� ������ ���� �޼ҵ�
{
	int select;

	for (int i = 0; i < sizeof(ItemMenu) / sizeof(char*); i++)	//��, �ϵ�, Ȱ �޴� ���
	{
		cout << i + 1 << ". " << ItemMenu[i] << endl;
	}
	cout << "����: ";
	cin >> select;

	//������ ���� ��
	//�ش�������� ����ϴ� �Ŵ�����
	//�������� ������ �Ѱ��ش�
	switch (select)
	{
	case ITEM::SWORD:
		return SwordM->Buy(Nowuser);
	case ITEM::WAND:
		return WandM->Buy(Nowuser);
	case ITEM::BOW:
		return BowM->Buy(Nowuser);
	}
}

void UserManager::DisplayMenu()			//�޴� ���
{
	cout << "<�޴�>" << endl;
	cout << "1. ĳ���� ����" << endl;
	cout << "2. ĳ���� ����" << endl;
	cout << "3. ������ ����" << endl;
	cout << "4. ������ �Ǹ�" << endl;
	cout << "5. �α׾ƿ�" << endl;
	cout << "6. ȸ�� Ż��" << endl;
	cout << "����: ";
}