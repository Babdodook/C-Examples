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
	cout << "현재까지 당신의 최고성적은:" << score << "번 시도만에 정답입니다" << endl;
}

const int CUser::GetScore() {
	return score;
}