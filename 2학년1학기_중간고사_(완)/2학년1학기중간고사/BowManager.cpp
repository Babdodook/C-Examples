#include"BowManager.h"

const char* BowManager::Bows[] = { "드래곤 보우","크로스보우","블랙 보우" };	// 이름
const int BowManager::Bweight[] = { 30,20,10 };									// 무게
const int BowManager::Bprice[] = { 150,120,100 };								// 가격
const int BowManager::Bpower[] = { 100,70,40 };									// 속성 수치

BowManager::BowManager()
{
	idcount = 0;
}

BowManager::~BowManager()
{

}

void BowManager::Buy(User* Nowuser)								//구매 메소드
{
	int select;
	char itemid[SIZE];

	for (int i = 0; i < sizeof(Bows) / sizeof(char*); i++)		//완드 아이템 종류 출력
	{
		cout << i + 1 << ". " << Bows[i] << " 무게: " << Bweight[i] << " 민첩 +" << Bpower[i] << endl;
		cout << "가격: " << Bprice[i] << endl;
	}
	cout << "소지골드: " << Nowuser->GetGold() << endl;
	cout << "선택: ";
	cin >> select;

	if (Nowuser->GetGold() < Bprice[select - 1])				//소지 골드 부족 시 메뉴로 돌아간다
	{
		cout << "골드가 부족합니다." << endl;
		return;
	}
	else
	{
		Nowuser->SetGold(Bprice[select - 1], MINUS_GOLD);		//구매 성공시 유저의 골드 차감
		cout << "구매되었습니다. (남은 골드: " << Nowuser->GetGold() << ")" << endl;
	}

	sprintf(itemid, "%s%d", Itemid[BOW_CODE], idcount++);		//아이템에 아이디 부여

	//유저의 아이템리스트에 아이템 추가
	Nowuser->SetItem(new Bow(Bows[select - 1], Bweight[select - 1], Bprice[select - 1], itemid, Bpower[select - 1]));
}