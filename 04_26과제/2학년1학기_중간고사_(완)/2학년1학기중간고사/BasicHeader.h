#pragma once
#include<iostream>
#include<time.h>
using namespace std;

#define SIZE 10			//�̸�, ���̵� ������
#define ORC_CODE 0		//��ũ ĳ���� �ڵ�
#define ELF_CODE 1		//���� ĳ���� �ڵ�
#define HUM_CODE 2		//�޸� ĳ���� �ڵ�
#define SWORD_CODE 0	//�� ������ �ڵ�
#define WAND_CODE 1		//�ϵ� ������ �ڵ�
#define BOW_CODE 2		//���� ������ �ڵ�
#define PLUS_GOLD 1		//������ �Ǹ� ���
#define MINUS_GOLD 2	//������ ���� ���

enum MAINMENU {			//���θ޴� ���� �ڵ�
	CREATE=1,			//ȸ������
	LOGIN,				//�α���
	EXIT				//����
};

enum LOGMENU {			//�α��� �� �޴� ���� �ڵ�
	CREATE_C=1,			//ĳ���� ����
	DELETE_C,			//ĳ���� ����
	BUY,				//������ ����
	SELL,				//������ �Ǹ�
	LOGOUT,				//�α׾ƿ�
	DELETE_ACC			//ȸ�� Ż��
};

enum C {				//ĳ���� ���� �ڵ�
	ORC=1,				//��ũ
	ELF,				//����
	HUMAN				//�޸�
};

enum ITEM {				//������ ���� �ڵ�
	SWORD=1,			//��
	WAND,				//�ϵ�
	BOW					//Ȱ
};

static void Clear()		//���� ����
{
	if (cin.failbit)
	{
		cin.clear();
		cin.ignore(256, '\n');
	}
}