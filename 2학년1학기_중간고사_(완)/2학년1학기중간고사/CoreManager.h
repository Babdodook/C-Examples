#pragma once
#include"LoginManager.h"

class CoreManager {			//�ֻ��� ��Ʈ�� Ŭ����
private:
	LoginManager* LoginM;	//�α��� ���� �Ŵ���(���� ȸ������, ���� �α��� ��� ����, ��������Ʈ ����)
public:
	CoreManager();
	~CoreManager();

	void Run();				//���α׷� ����

	void Init();			//�̴ϼȶ�����
	const int Mainmenu();	//���� �޴� ���
};