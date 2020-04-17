#include"SwordManager.h"

const char* SwordManager::Swords[] = { "�巡�� �ҵ�","Ŭ���̸��","�����Ǿ�" };	// �̸�
const int SwordManager::Sweight[] = { 70,60,50 };								// ����
const int SwordManager::Sprice[] = { 150,120,100 };								// ����
const int SwordManager::Spower[] = { 100,70,40 };								// �Ӽ� ��ġ

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

void SwordManager::Buy(User* Nowuser)							//���� �޼ҵ�
{
	int select;
	char itemid[SIZE];

	for (int i = 0; i < sizeof(Swords) / sizeof(char*); i++)	//�� ������ ���� ���
	{
		cout << i + 1 << ". " << Swords[i] << " ����: " << Sweight[i] << " �� +" << Spower[i] << endl;
		cout << "����: " << Sprice[i] << endl;
	}
	cout << "�������: " << Nowuser->GetGold() << endl;
	cout << "����: ";
	cin >> select;

	if (Nowuser->GetGold() < Sprice[select - 1])				//���� ��� ���� �� �޴��� ���ư���
	{
		cout << "��尡 �����մϴ�." << endl;
		return;
	}
	else
	{
		Nowuser->SetGold(Sprice[select - 1], MINUS_GOLD);		//���� ������ ������ ��� ����
		cout << "���ŵǾ����ϴ�. (���� ���: " << Nowuser->GetGold() << ")" << endl;
	}

	sprintf(itemid, "%s%d", Itemid[SWORD_CODE], idcount++);		//�����ۿ� ���̵� �ο�

	//������ �����۸���Ʈ�� ������ �߰�
	Nowuser->SetItem(new Sword(Swords[select - 1], Sweight[select - 1], Sprice[select - 1], itemid, Spower[select - 1]));
}