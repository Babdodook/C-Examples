#include"CGameManager.h"

CGameManager::CGameManager(){
}
CGameManager::~CGameManager(){}

int CGameManager::RunGame() {
	srand(time(nullptr));
	int correctNum = rand() % 101 + 1;
	int input=0;
	int i=1;

	cout << "Up Down Game을 시작합니다" << endl;

	while (1) {
		cout << i << "번째 시도입니다" << endl;
		cout << "1~100까지의 수중에 하나를 입력하세요: ";
		cin >> input;

		if (Check(correctNum, input)) {
			return i;
		}
		i++;
	}
}

bool CGameManager::Check(int correctNum,int input) {
	if (correctNum > input) {
		cout << "Up!" << endl;
	}
	else if (correctNum < input) {
		cout << "Down!" << endl;
	}

	if (correctNum == input) {
		cout << "Correct Answer!!" << endl;
		return true;
	}
	else {
		return false;
	}
}