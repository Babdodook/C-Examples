#include"CGameManager.h"

CGameManager::CGameManager(){
}
CGameManager::~CGameManager(){}

int CGameManager::RunGame() {
	srand(time(nullptr));
	int correctNum = rand() % 101 + 1;
	int input=0;
	int i=1;

	cout << "Up Down Game�� �����մϴ�" << endl;

	while (1) {
		cout << i << "��° �õ��Դϴ�" << endl;
		cout << "1~100������ ���߿� �ϳ��� �Է��ϼ���: ";
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