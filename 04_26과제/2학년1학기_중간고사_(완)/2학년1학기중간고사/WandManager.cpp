#include"WandManager.h"


const char* WandManager::Wands[] = { "드래곤 완드","골드 완드","실버 완드" };	//아이템 이름
const int WandManager::Wweight[] = { 45,30,20 };								//무게
const int WandManager::Wprice[] = { 150,120,100 };								//가격
const int WandManager::Wpower[] = { 100,70,40 };								//속성 수치

WandManager* WandManager::mPthis = nullptr;

WandManager* WandManager::Create()
{
	if (!mPthis)
	{
		mPthis = new WandManager();
	}

	return mPthis;
}

WandManager* WandManager::GetInstance()
{
	return mPthis;
}

void WandManager::Destroy()
{
	if (mPthis)
	{
		delete mPthis;
		mPthis = nullptr;
	}
}

WandManager::WandManager()
{
	idcount = 0;
}

WandManager::~WandManager()
{

}

void WandManager::Buy(User* Nowuser)							//구매 메소드
{
	int select;
	char itemid[SIZE];

	for (int i = 0; i < sizeof(Wands) / sizeof(char*); i++)		//완드 아이템 종류 출력
	{
		cout << i + 1 << ". " << Wands[i] << " 무게: " << Wweight[i] << " 지혜 +" << Wpower[i] << endl;
		cout << "가격: " << Wprice[i] << endl;
	}
	cout << "소지골드: " << Nowuser->GetGold() << endl;
	cout << "선택: ";
	cin >> select;

	if (Nowuser->GetGold() < Wprice[select - 1])				//소지 골드 부족 시 메뉴로 돌아간다
	{
		cout << "골드가 부족합니다." << endl;
		return;
	}
	else
	{
		Nowuser->SetGold(Wprice[select - 1], MINUS_GOLD);		//구매 성공시 유저의 골드 차감
		cout << "구매되었습니다. (남은 골드: " << Nowuser->GetGold() << ")" << endl;
	}

	sprintf(itemid, "%s%d", Itemid[WAND_CODE], idcount++);		//아이템에 아이디 부여

	//유저의 아이템리스트에 아이템 추가
	Nowuser->SetItem(new Wand(Wands[select - 1], Wweight[select - 1], Wprice[select - 1], itemid, Wpower[select - 1]));
}