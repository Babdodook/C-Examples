#pragma once
#include"ItemManager.h"

class SwordManager : public ItemManager {	//�� ������ ��Ʈ�� Ŭ����
private:
	static SwordManager* mPthis;

	static const char* Swords[];			//�� �̸� �迭
	static const int Sweight[];				//����
	static const int Sprice[];				//����
	static const int Spower[];				//�Ӽ� ��ġ

	int idcount;							//������ ���� ���̵� ī��Ʈ

	SwordManager();
	~SwordManager();
public:
	static SwordManager* Create();
	static SwordManager* GetInstance();
	static void Destroy();

	void Buy(User*);						//�Ǹ� �޼ҵ�
};