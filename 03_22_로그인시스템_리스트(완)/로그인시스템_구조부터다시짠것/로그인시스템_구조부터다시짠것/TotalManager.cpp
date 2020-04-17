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
			cout << "잘못 입력하셨습니다" << endl;
			break;
		}

		puts("");
	}
}

int TotalManager::Mainmenu() 
{
	int selectmenu;
	cout << "<메뉴>" << endl;
	cout << "1. 회원가입" << endl;
	cout << "2. 로그인" << endl;
	cout << "3. 종료" << endl;
	cout << "선택: ";
	cin >> selectmenu;
	return selectmenu;
}

int TotalManager::Loginmenu() 
{
	int selectmenu;
	cout << "1. 게임시작" << endl;
	cout << "2. 로그아웃" << endl;
	cout << "3. 회원탈퇴" << endl;
	cout << "선택: ";
	cin >> selectmenu;
	return selectmenu;
}