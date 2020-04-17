#include"Elf.h"

Elf::Elf(const char* name, const char* cid)		//이름, 고유아이디 저장
	:Character(name, cid)
{
	dex = rand() % 100 + 1;						//캐릭터의 스탯은 랜덤으로 생성된다
}

Elf::~Elf()
{
}

void Elf::ShowCInfo()							//캐릭터 정보 출력
{
	cout << "------------------" << endl;
	cout << "Slot Number: " << cid << endl;
	cout << "이름: " << name << endl;
	cout << "종족: 엘프" << endl;
	cout << "민첩: " << dex << endl << endl;
}