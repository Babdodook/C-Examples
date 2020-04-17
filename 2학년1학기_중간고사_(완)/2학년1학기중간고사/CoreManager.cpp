#include"CoreManager.h"

CoreManager::CoreManager()		//�����ڿ��� �ʱ�ȭ
{
	LoginM = nullptr;
}

CoreManager::~CoreManager()		//�Ҹ��ڿ��� �޸� ����
{
	delete LoginM;
}

void CoreManager::Init()		//�̴ϼȶ����� �Լ����� �޸� ���� �Ҵ�
{
	LoginM = new LoginManager();
	LoginM->Init();				//�α��θŴ����� �����ϴ� ��������Ʈ �����Ҵ� �ϱ����� ȣ��
}

void CoreManager::Run()
{
	Init();
	while (1)
	{
		switch (Mainmenu())
		{
		case MAINMENU::CREATE:		//ȸ������
			LoginM->CreateAcc();	//�α��θŴ��� ȸ������ �޼ҵ� ȣ��
			break;
		case MAINMENU::LOGIN:		//�α���
			LoginM->Login();		//�α��θŴ��� �α��� �޼ҵ� ȣ��
			break;
		case MAINMENU::EXIT:		//����
			exit(1);
			break;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			Clear();
			continue;
		}
	}
}

const int CoreManager::Mainmenu()	//���θ޴� ��� �޼ҵ�
{
	int select;
	cout << "<�޴�>" << endl;
	cout << "1. ȸ������" << endl;
	cout << "2. �α���" << endl;
	cout << "3. ����" << endl;
	cout << "����: ";
	cin >> select;
	return select;
}