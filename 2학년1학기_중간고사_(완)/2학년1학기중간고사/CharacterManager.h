#pragma once
#include"User.h"
#include"LinkedList.h"

class CharacterManager {		//ĳ���� ����, ���� ��� ��Ʈ�� Ŭ����
private:
	static const char* Characters[];		//ĳ���� �̸� ���� �迭
	static const char* Cid[];				//ĳ���� ���� ���̵� ���� �迭
	int Cidcount[3];						//ĳ���� ���̵� ī��Ʈ �迭 
public:
	CharacterManager();
	~CharacterManager();

	void Create(User*);			//ĳ���� ����
	void Delete(User*);			//ĳ���� ����
	void Show(User*);			//��ü ĳ���� ���� ��� �޼ҵ�(�̱���)
};