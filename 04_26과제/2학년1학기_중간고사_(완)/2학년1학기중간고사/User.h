#pragma once
#include"Elf.h"
#include"Human.h"
#include"Orc.h"
#include"Sword.h"
#include"Wand.h"
#include"Bow.h"
#include"LinkedList.h"

class User {								//���� ������ Ŭ����
private:
	char id[SIZE];							//���̵�
	char pw[SIZE];							//�н�����
	int gold;								//���� ���
	LinkedList<Character*>* CharacterList;	//ĳ���� ����Ʈ
	LinkedList<Item*>* ItemList;			//������ ����Ʈ
public:
	User(const char*,const char*);
	~User();

	void Init();

	//���̵�, �н����� �б� �޼ҵ�
	const char* GetID();
	const char* GetPW();

	//��� �б�, ���� �޼ҵ�
	void SetGold(int,int);
	const int GetGold();

	//ĳ���� �б�, ���� �� ����Ʈ�� ����� ��ȯ �޼ҵ�
	void SetCharacter(Character*);
	Node<Character*>* GetCharacter();
	void DelCharacter(Character*);

	//������ �б�, ���� �� ����Ʈ�� ����� ��ȯ �޼ҵ�
	void SetItem(Item*);
	Node<Item*>* GetItem();
	void DelItem(Item*); 
};