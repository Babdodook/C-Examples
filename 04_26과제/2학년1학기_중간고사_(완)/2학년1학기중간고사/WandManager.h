#pragma once
#include"ItemManager.h"

class WandManager : public ItemManager {	//�ϵ� ������ ��Ʈ�� Ŭ����
private:
	static WandManager* mPthis;

	static const char* Wands[];				//�ϵ� �̸� �迭
	static const int Wweight[];				//����
	static const int Wprice[];				//����
	static const int Wpower[];				//�Ӽ� ��ġ

	int idcount;							//������ ���� ���̵� ī��Ʈ

	WandManager();
	~WandManager();
public:
	static WandManager* Create();
	static WandManager* GetInstance();
	static void Destroy();

	void Buy(User*);						//�Ǹ� �޼ҵ�
};