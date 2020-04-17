#include"TotalManager.h"

TotalManager::TotalManager()
{
	LoginM = nullptr;
	GameM = nullptr;
}
TotalManager::~TotalManager() 
{
	delete LoginM;
	delete GameM;
}

void TotalManager::Init() 
{
	LoginM = new LoginManager();
	GameM = new GameManager();
}

void TotalManager::RunProgram() 
{
	Init();
	LoginM->Init();
	while (1) 
	{
		switch (Mainmenu()) 
		{
		case MAINMENU::SIGNUP:
			LoginM->SignUp();
			break;
		case MAINMENU::LOGIN:
			if (LoginM->Login()) 
			{
				while (1) 
				{
					bool flag = true;

					switch (Loginmenu()) 
					{
					case LOGINMENU::RUNGAME:
						GameM->Init(LoginM->GetNowuser());
						GameM->RunGame();
						GameM->EndGame();
						continue;
					case LOGINMENU::LOGOUT:
						LoginM->Logout();
						flag = false;
						break;
					case LOGINMENU::DELETACC:
						LoginM->DeleteAcc();
						flag = false;
						break;
					}

					if (!flag)
						break;
				}
			}
			break;
		case MAINMENU::EXIT:
			exit(0);
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			break;
		}

		puts("");
	}
}

int TotalManager::Mainmenu() 
{
	int selectmenu;
	cout << "<�޴�>" << endl;
	cout << "1. ȸ������" << endl;
	cout << "2. �α���" << endl;
	cout << "3. ����" << endl;
	cout << "����: ";
	cin >> selectmenu;
	return selectmenu;
}

int TotalManager::Loginmenu() 
{
	int selectmenu;
	cout << "1. ���ӽ���" << endl;
	cout << "2. �α׾ƿ�" << endl;
	cout << "3. ȸ��Ż��" << endl;
	cout << "����: ";
	cin >> selectmenu;
	return selectmenu;
}