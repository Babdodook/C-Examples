#pragma once
#include"LoginManager.h"

class CoreManager {			//�ֻ��� ��Ʈ�� Ŭ����
private:
	static CoreManager* mPthis;

	CoreManager();
	~CoreManager();
public:
	static CoreManager* Create();
	static CoreManager* GetInstance();
	static void Destroy();

	void Run();				//���α׷� ����

	void Init();			//�̴ϼȶ�����
	const int Mainmenu();	//���� �޴� ���
};