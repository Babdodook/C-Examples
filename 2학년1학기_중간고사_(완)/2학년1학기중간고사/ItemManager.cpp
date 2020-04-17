#include"ItemManager.h"

const char* ItemManager::Itemid[] = { "100", "200", "300" };

ItemManager::ItemManager()
{
}

ItemManager::~ItemManager()
{
}

void ItemManager::Sell(User* Nowuser)			//아이템 판매 메소드
												//판매의 의미는 유저가 가지고 있는 아이템의 삭제와 동일하다
												//유저의 아이템 리스트에서 입력받은 아이디와 일치하는 아이템을
												//삭제하고 해당하는 아이템의 가격만큼 유저의 골드가 증가한다
{
	char id[SIZE];

	Node<Item*>* temp = Nowuser->GetItem();

	while (temp != nullptr)
	{
		temp->GetData()->ShowItemInfo();
		temp = temp->GetLink();
	}

	cout << "판매하려는 아이템의 id를 입력하세요" << endl;
	cout << "ID Number: ";
	cin >> id;

	temp = Nowuser->GetItem();

	while (temp != nullptr)
	{
		if (strcmp(temp->GetData()->Getid(), id) == 0)
		{
			Nowuser->SetGold(temp->GetData()->GetPrice(),PLUS_GOLD);
			Nowuser->DelItem(temp->GetData());
			cout << "판매되었습니다 (현재 소지 골드: " <<Nowuser->GetGold()<< ")" << endl;
			return;
		}
		temp = temp->GetLink();
	}
}

void ItemManager::Show(User* Nowuser)
{
}
