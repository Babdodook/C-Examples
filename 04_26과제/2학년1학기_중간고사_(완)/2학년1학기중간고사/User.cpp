#include"User.h"

User::User(const char* id, const char* pw)	//���� ����
	:gold(1000)								//������ �ڵ����� 1000��� ����
{
	strcpy(this->id, id);
	strcpy(this->pw, pw);

	CharacterList = nullptr;				//�ʱ�ȭ
	ItemList = nullptr;						//�ʱ�ȭ

	Init();									//�����Ҵ� �޼ҵ� ȣ��
}

User::~User()								//�Ҹ��ڿ��� �޸� ����
{
	delete CharacterList;
	delete ItemList;
}

void User::Init()							//�̴ϼȶ����� �޼ҵ�
											//ĳ���� ����Ʈ�� ������ ����Ʈ ���� �Ҵ�
{
	CharacterList = new LinkedList<Character*>();
	ItemList = new LinkedList<Item*>();
}

const char* User::GetID()
{
	return id;
}

const char* User::GetPW()
{
	return pw;
}

Node<Character*>* User::GetCharacter()			//ĳ���� ����Ʈ�� ����� ��ȯ
												//ĳ������ ���� �������� ����
{
	return CharacterList->GetHead();
}

void User::SetCharacter(Character* character)	//ĳ���� ������ ȣ���
{
	CharacterList->Insert(character);
}

void User::DelCharacter(Character* character)	//ĳ���� ������ ȣ���
{
	CharacterList->Delete(character);
}

Node<Item*>* User::GetItem()					//������ ����Ʈ�� ����� ��ȯ
												//�������� �ǸŰ������� ����
{
	return ItemList->GetHead();
}

void User::SetItem(Item* item)					//������ ���Ž� ȣ���
{
	ItemList->Insert(item);
}

void User::DelItem(Item* item)					//������ �ǸŽ� ȣ���
{
	ItemList->Delete(item);
}

const int User::GetGold()						//���� ������ ������ �ִ� ��带 ����
{
	return gold;
}

void User::SetGold(int gold, int action)
{
	if (action == PLUS_GOLD)	//������ �Ǹ� ���, ���� ��� ����
	{
		this->gold += gold;
	}
	if (action == MINUS_GOLD)	//������ ���� ���, ���� ��� ����
	{
		this->gold -= gold;
	}
}