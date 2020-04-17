#pragma once
#include"BasicHeader.h"

class Character {			//ĳ���� ������ Ŭ����
protected:
	char name[SIZE];		//ĳ������ �̸�
	char cid[SIZE];			//ĳ������ ���� ���̵�
public:
	Character(const char* name,const char* cid)		//�����ڿ��� �̸��� ���� ���̵� ����
	{
		strcpy(this->name, name);
		strcpy(this->cid, cid);
	};
	virtual ~Character() {};

	const char* GetCid()	//ĳ���� ���̵� ����
	{
		return cid;
	}

	//�����۰� ����������
	//��ӹ޴� ĳ���� Ŭ��������
	//��� ������ �ٸ��⶧���� �߻�ȭ
	virtual void ShowCInfo() = 0;
};