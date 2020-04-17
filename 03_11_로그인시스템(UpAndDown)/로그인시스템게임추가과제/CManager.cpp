#include"CManager.h"

CManager::CManager() {
	Game = nullptr;
	memset(lst, 0, sizeof(lst));
	count = 0;
}

CManager::~CManager() {
	for (int i = 0; i < count; i++) {
		if (lst[i] != 0) {
			delete lst[i];
			lst[i] = nullptr;
		}
	}
}

void CManager::Run() {
	while (1) {
		cout << "<메뉴>" << endl;
		cout << "1. 회원가입" << endl;
		cout << "2. 로그인" << endl;
		cout << "3. 종료" << endl;
		cout << "선택: ";
		cin >> selectmenu;
		switch (selectmenu) {
		case MAINMENU::SIGNUP:
			Signup();
			break;
		case MAINMENU::LOGIN:
			Login();
			break;
		case MAINMENU::ESCAPE:
			exit(0);
			break;
		}
	}
}

void CManager::Signup() {
	cout << endl;

	char id[MAX];
	char pw[MAX];

	cout << "ID: ";
	cin >> id;

	for (int i = 0; i < count; i++) {
		if (!strcmp(lst[i]->GetID(), id)) {
			cout << "이미 존재하는 ID입니다" << endl << endl;
			return;
		}
	}

	cout << "PW: ";
	cin >> pw;

	lst[count++] = new CUser(id, pw);

	cout << endl;
}

void CManager::Login() {
	cout << endl;

	LoginUser = nullptr;

	int i = 0;
	int _score=0;
	char id[MAX];
	char pw[MAX];

	cout << "ID: ";
	cin >> id;

	for (i; i < count; i++) {
		if (strcmp(lst[i]->GetID(), id) == 0) {
			LoginUser = lst[i];
			break;
		}
		else {
			cout << "일치하는 ID가 없습니다" << endl << endl;
			return;
		}
	}

	cout << "PW: ";
	cin >> pw;

	if (strcmp(LoginUser->GetPW(), pw) == 0) {
		cout << "로그인 되었습니다" << endl;

		LoginUser->State();

		int select;
		while (1) {
			cout << "1. 게임시작" << endl;
			cout << "2. 로그아웃" << endl;
			cout << "3. 회원탈퇴" << endl;
			cout << "선택: ";
			cin >> select;

			switch (select) {
			case LOGIN::RUNGAME:
				_score=Game->RunGame();
				LoginUser->SetScore(_score);
				lst[i] = LoginUser;
				break;
			case LOGIN::LOGOUT:
				Logout();
				return;
			case LOGIN::DELETACC:
				DeleteAcc();
				return;
			}
			//if ((LoginUser->Getstate()) == false)
				//break;
		}
	}
	else
		cout << "패스워드가 일치하지 않습니다" << endl << endl;
}

void CManager::Logout() {
	LoginUser->State();
	LoginUser = nullptr;
	return;
}

void CManager::DeleteAcc() {
	for (int i = 0; i < count; i++) {
		if (lst[i] == LoginUser) {
			delete lst[i];
			for (int j = i; j < count; j++) {
				lst[j] = lst[j + 1];
			}
			lst[count] = nullptr;
			count--;
			break;
		}
	}
	return;
}