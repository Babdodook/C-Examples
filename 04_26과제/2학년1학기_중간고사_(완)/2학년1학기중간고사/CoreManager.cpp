#include"CoreManager.h"

CoreManager* CoreManager::mPthis = nullptr;

CoreManager* CoreManager::Create()
{
	if (!mPthis)
	{
		mPthis = new CoreManager();
	}

	LoginManager::Create();

	return mPthis;
}

CoreManager* CoreManager::GetInstance()
{
	return mPthis;
}

void CoreManager::Destroy()
{
	if (mPthis)
	{
		delete mPthis;
		mPthis = nullptr;
	}

	LoginManager::Destroy();
}

CoreManager::CoreManager()		//�����ڿ��� �ʱ�ȭ
{
}

CoreManager::~CoreManager()		//�Ҹ��ڿ��� �޸� ����
{
}

void CoreManager::Init()		//�̴ϼȶ����� �Լ����� �޸� ���� �Ҵ�
{
	LoginManager::GetInstance()->Init();				//�α��θŴ����� �����ϴ� ��������Ʈ �����Ҵ� �ϱ����� ȣ��
}

void CoreManager::Run()
{
	Init();
	while (1)
	{
		switch (Mainmenu())
		{
		case MAINMENU::CREATE:		//ȸ������
			LoginManager::GetInstance()->CreateAcc();	//�α��θŴ��� ȸ������ �޼ҵ� ȣ��
			break;
		case MAINMENU::LOGIN:		//�α���
			LoginManager::GetInstance()->Login();		//�α��θŴ��� �α��� �޼ҵ� ȣ��
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