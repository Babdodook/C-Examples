#pragma once
#include"ItemManager.h"

class SwordManager : public ItemManager {	//�� ������ ��Ʈ�� Ŭ����
private:
	static const char* Swords[];			//�� �̸� �迭
	static const int Sweight[];				//����
	static const int Sprice[];				//����
	static const int Spower[];				//�Ӽ� ��ġ

	int idcount;							//������ ���� ���̵� ī��Ʈ
public:
	SwordManager();
	~SwordManager();

	void Buy(User*);						//�Ǹ� �޼ҵ�
};