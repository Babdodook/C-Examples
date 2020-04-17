#pragma once
#include"User.h"
#include"LinkedList.h"

class CharacterManager {		//ĳ���� ����, ���� ��� ��Ʈ�� Ŭ����
private:
	static CharacterManager* mPthis;

	static const char* Characters[];		//ĳ���� �̸� ���� �迭
	static const char* Cid[];				//ĳ���� ���� ���̵� ���� �迭
	int Cidcount[3];						//ĳ���� ���̵� ī��Ʈ �迭 

	CharacterManager();
	~CharacterManager();
public:
	static CharacterManager* Create();
	static CharacterManager* GetInstance();
	static void Destroy();

	void Create(User*);			//ĳ���� ����
	void Delete(User*);			//ĳ���� ����
	void Show(User*);			//��ü ĳ���� ���� ��� �޼ҵ�(�̱���)
};