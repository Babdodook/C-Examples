#pragma once
#include"Character.h"

class Orc :public Character {		// ��ũ ������ Ŭ����, ĳ���� Ŭ���� ��� ����
private:
	int power;						// ��ũ�� �� ������ ������ �ִ�
public:
	Orc(const char* name,const char* cid);
	virtual ~Orc();

	virtual void ShowCInfo();		//ĳ���� ���� ��� �޼ҵ�
};