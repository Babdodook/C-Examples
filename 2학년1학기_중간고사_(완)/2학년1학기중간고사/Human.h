#pragma once
#include"Character.h"

class Human :public Character {		// �޸� ������ Ŭ����, ĳ���� Ŭ���� ��� ����
private:
	int wisdom;						// �ΰ��� ���� ������ ������ �ִ�
public:
	Human(const char* name, const char* cid);
	virtual ~Human();

	virtual void ShowCInfo();		//ĳ���� ���� ��� �޼ҵ�
};