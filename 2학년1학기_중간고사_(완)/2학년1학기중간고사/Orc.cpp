#include"Orc.h"

Orc::Orc(const char* name,const char* cid)		//이름, 고유아이디 저장
	:Character(name,cid)
{
	power = rand() % 100 + 1;					//캐릭터의 스탯은 랜덤으로 생성된다
}

Orc::~Orc() 
{
}

void Orc::ShowCInfo()							//캐릭터 정보 출력
{
	cout << "------------------" << endl;
	cout << "Slot Number: " << cid << endl;
	cout << "이름: " << name << endl;
	cout << "종족: 오크" << endl;
	cout << "힘: " << power << endl << endl;
}