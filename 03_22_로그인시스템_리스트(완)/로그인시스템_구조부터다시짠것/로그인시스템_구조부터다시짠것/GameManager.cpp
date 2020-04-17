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
		cout << score << "번째 시도입니다" << endl;
		cout << "1~100까지의 숫자 중 하나를 입력하세요" << endl;
		cout << "입력: ";
		cin >> input;

		if (1 > input || input > 100)
		{
			cout << "1~100사이의 숫자를 입력하세요" << endl;
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

			cout << "현재까지 최고 기록은 " << nowuser->GetScore() << "번째 시도만의 정답입니다" << endl;
			break;
		}
	}
}