#pragma once
#include<iostream>
#include<time.h>
using namespace std;

#define SIZE 10			//이름, 아이디 사이즈
#define ORC_CODE 0		//오크 캐릭터 코드
#define ELF_CODE 1		//엘프 캐릭터 코드
#define HUM_CODE 2		//휴먼 캐릭터 코드
#define SWORD_CODE 0	//검 아이템 코드
#define WAND_CODE 1		//완드 아이템 코드
#define BOW_CODE 2		//보우 아이템 코드
#define PLUS_GOLD 1		//아이템 판매 경우
#define MINUS_GOLD 2	//아이템 구매 경우

enum MAINMENU {			//메인메뉴 선택 코드
	CREATE=1,			//회원가입
	LOGIN,				//로그인
	EXIT				//종료
};

enum LOGMENU {			//로그인 후 메뉴 선택 코드
	CREATE_C=1,			//캐릭터 생성
	DELETE_C,			//캐릭터 삭제
	BUY,				//아이템 구매
	SELL,				//아이템 판매
	LOGOUT,				//로그아웃
	DELETE_ACC			//회원 탈퇴
};

enum C {				//캐릭터 선택 코드
	ORC=1,				//오크
	ELF,				//엘프
	HUMAN				//휴먼
};

enum ITEM {				//아이템 선택 코드
	SWORD=1,			//검
	WAND,				//완드
	BOW					//활
};

static void Clear()		//버퍼 비우기
{
	if (cin.failbit)
	{
		cin.clear();
		cin.ignore(256, '\n');
	}
}