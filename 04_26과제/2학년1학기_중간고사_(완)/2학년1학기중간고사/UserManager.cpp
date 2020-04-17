#pragma once
#include"UserManager.h"

const char* UserManager::ItemMenu[] = { "��","�ϵ�","Ȱ" };

UserManager* UserManager::mPthis = nullptr;

UserManager* UserManager::Create()
{
	if (!mPthis)
	{
		mPthis = new UserManager();
	}

	CharacterManager::Create();
	SwordManager::Create();
	WandManager::Create();
	BowManager::Create();
	ItemManager::Create();

	return mPthis;
}

UserManager* UserManager::GetInstance()
{
	return mPthis;
}

void UserManager::Destroy()
{
	if (mPthis)
	{
		delete mPthis;
		mPthis = nullptr;
	}

	CharacterManager::Destroy();
	SwordManager::Destroy();
	WandManager::Destroy();
	BowManager::Destroy();
	ItemManager::Destroy();
}

UserManager::UserManager()	//�����ڿ��� �ʱ�ȭ
{
}

UserManager::~UserManager()	//�Ҹ��ڿ��� �޸� ����
{
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
			CharacterManager::GetInstance()->Create(Nowuser->GetData());		//ĳ���� ���� �޼ҵ� ȣ��, �Ű������� ���������� �Ѱ���
			break;
		case LOGMENU::DELETE_C:						
			CharacterManager::GetInstance()->Delete(Nowuser->GetData());		//ĳ���� ���� �޼ҵ� ȣ��
			break;
		case LOGMENU::BUY:
			SelectItem(Nowuser->GetData());				//�����ۼ��� �޼ҵ� ȣ��
			break;
		case LOGMENU::SELL:
			ItemManager::GetInstance()->Sell(Nowuser->GetData());			//������ �Ǹ� �޼ҵ� ȣ��
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
		return SwordManager::GetInstance()->Buy(Nowuser);
	case ITEM::WAND:
		return WandManager::GetInstance()->Buy(Nowuser);
	case ITEM::BOW:
		return BowManager::GetInstance()->Buy(Nowuser);
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