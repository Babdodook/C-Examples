#include"CUser.h"

CUser::CUser(const char * id, const char * pw) {
	strcpy(ID, id);
	strcpy(PW, pw);
	score = 0;
}
CUser::~CUser() {}

const char * CUser::GetID() {
	return ID;
}

const char * CUser::GetPW() {
	return PW;
}

void CUser::State() { 
	if (state)
		state = false;
	else if (!state)
		state = true;
}

const bool CUser::Getstate() {
	return state;
}

void CUser::SetScore(int i) {
	if(score>i || score==0)
		score = i;
	cout << "������� ����� �ְ�����:" << score << "�� �õ����� �����Դϴ�" << endl;
}

const int CUser::GetScore() {
	return score;
}