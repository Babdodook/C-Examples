#pragma once
#include"ItemManager.h"

class BowManager : public ItemManager {		//Ȱ ������ ��Ʈ�� Ŭ����
private:
	static const char* Bows[];				//Ȱ �̸� �迭
	static const int Bweight[];				//����
	static const int Bprice[];				//����
	static const int Bpower[];				//�Ӽ� ��ġ

	int idcount;							//������ ���� ���̵� ī��Ʈ
public:
	BowManager();
	~BowManager();

	void Buy(User*);						//�Ǹ� �޼ҵ�
};