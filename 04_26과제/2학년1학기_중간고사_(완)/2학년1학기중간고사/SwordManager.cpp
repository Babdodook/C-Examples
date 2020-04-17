#include"SwordManager.h"

const char* SwordManager::Swords[] = { "드래곤 소드","클레이모어","레이피어" };	// 이름
const int SwordManager::Sweight[] = { 70,60,50 };								// 무게
const int SwordManager::Sprice[] = { 150,120,100 };								// 가격
const int SwordManager::Spower[] = { 100,70,40 };								// 속성 수치

SwordManager* SwordManager::mPthis = nullptr;

SwordManager* SwordManager::Create()
{
	if (!mPthis)
	{
		mPthis = new SwordManager();
	}

	return mPthis;
}

SwordManager* SwordManager::GetInstance()
{
	return mPthis;
}

void SwordManager::Destroy()
{
	if (mPthis)
	{
		delete mPthis;
		mPthis = nullptr;
	}
}

SwordManager::SwordManager()
{
	idcount = 0;
}

SwordManager::~SwordManager()
{

}

void SwordManager::Buy(User* Nowuser)							//구매 메소드
{
	int select;
	char itemid[SIZE];

	for (int i = 0; i < sizeof(Swords) / sizeof(char*); i++)	//검 아이템 종류 출력
	{
		cout << i + 1 << ". " << Swords[i] << " 무게: " << Sweight[i] << " 힘 +" << Spower[i] << endl;
		cout << "가격: " << Sprice[i] << endl;
	}
	cout << "소지골드: " << Nowuser->GetGold() << endl;
	cout << "선택: ";
	cin >> select;

	if (Nowuser->GetGold() < Sprice[select - 1])				//소지 골드 부족 시 메뉴로 돌아간다
	{
		cout << "골드가 부족합니다." << endl;
		return;
	}
	else
	{
		Nowuser->SetGold(Sprice[select - 1], MINUS_GOLD);		//구매 성공시 유저의 골드 차감
		cout << "구매되었습니다. (남은 골드: " << Nowuser->GetGold() << ")" << endl;
	}

	sprintf(itemid, "%s%d", Itemid[SWORD_CODE], idcount++);		//아이템에 아이디 부여

	//유저의 아이템리스트에 아이템 추가
	Nowuser->SetItem(new Sword(Swords[select - 1], Sweight[select - 1], Sprice[select - 1], itemid, Spower[select - 1]));
}