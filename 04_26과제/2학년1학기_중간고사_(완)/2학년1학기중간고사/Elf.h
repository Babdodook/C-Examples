#pragma once
#include"Character.h"

class Elf :public Character {		// ���� ������ Ŭ����, ĳ���� Ŭ���� ��� ����
private:
	int dex;						// ������ ���� ������ ������ �ִ�
public:
	Elf(const char* name, const char* cid);
	virtual ~Elf();

	virtual void ShowCInfo();		//ĳ���� ���� ��� �޼ҵ�
};