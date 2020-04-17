#include"ItemManager.h"

const char* ItemManager::Itemid[] = { "100", "200", "300" };

ItemManager::ItemManager()
{
}

ItemManager::~ItemManager()
{
}

void ItemManager::Sell(User* Nowuser)			//������ �Ǹ� �޼ҵ�
												//�Ǹ��� �ǹ̴� ������ ������ �ִ� �������� ������ �����ϴ�
												//������ ������ ����Ʈ���� �Է¹��� ���̵�� ��ġ�ϴ� ��������
												//�����ϰ� �ش��ϴ� �������� ���ݸ�ŭ ������ ��尡 �����Ѵ�
{
	char id[SIZE];

	Node<Item*>* temp = Nowuser->GetItem();

	while (temp != nullptr)
	{
		temp->GetData()->ShowItemInfo();
		temp = temp->GetLink();
	}

	cout << "�Ǹ��Ϸ��� �������� id�� �Է��ϼ���" << endl;
	cout << "ID Number: ";
	cin >> id;

	temp = Nowuser->GetItem();

	while (temp != nullptr)
	{
		if (strcmp(temp->GetData()->Getid(), id) == 0)
		{
			Nowuser->SetGold(temp->GetData()->GetPrice(),PLUS_GOLD);
			Nowuser->DelItem(temp->GetData());
			cout << "�ǸŵǾ����ϴ� (���� ���� ���: " <<Nowuser->GetGold()<< ")" << endl;
			return;
		}
		temp = temp->GetLink();
	}
}

void ItemManager::Show(User* Nowuser)
{
}
