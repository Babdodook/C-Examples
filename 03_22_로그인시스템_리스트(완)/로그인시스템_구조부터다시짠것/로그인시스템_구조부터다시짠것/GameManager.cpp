#include"GameManager.h"

GameManager::GameManager() 
{
	nowuser = nullptr;
	correctNum = -1;
	score = 1;
}

GameManager::~GameManager() {}

void GameManager::Init(User * _nowuser) 
{
	nowuser = _nowuser;

	srand(time(NULL));
	correctNum = rand() % 100 + 1;
	score = 1;
}

void GameManager::EndGame() 
{
	nowuser = nullptr;
	correctNum = -1;
	score = 1;
}

void GameManager::RunGame() 
{
	int input;

	cout << "UpAndDown Game Start" << endl;

	while (1) 
	{
		cout << score << "��° �õ��Դϴ�" << endl;
		cout << "1~100������ ���� �� �ϳ��� �Է��ϼ���" << endl;
		cout << "�Է�: ";
		cin >> input;

		if (1 > input || input > 100)
		{
			cout << "1~100������ ���ڸ� �Է��ϼ���" << endl;
			if (score != 1)
				score--;
			continue;
		}
		if (input < correctNum)
		{
			cout << "UP" << endl;
			score++;
		}
		if (input > correctNum)
		{
			cout << "DOWN" << endl;
			score++;
		}
		if (input == correctNum) 
		{
			cout << "Correct Answer!" << endl;
			if (nowuser->GetScore() > score || nowuser->GetScore() == 0)
				nowuser->SetScore(score);

			cout << "������� �ְ� ����� " << nowuser->GetScore() << "��° �õ����� �����Դϴ�" << endl;
			break;
		}
	}
}