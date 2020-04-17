#include"WandManager.h"


const char* WandManager::Wands[] = { "�巡�� �ϵ�","��� �ϵ�","�ǹ� �ϵ�" };	//������ �̸�
const int WandManager::Wweight[] = { 45,30,20 };								//����
const int WandManager::Wprice[] = { 150,120,100 };								//����
const int WandManager::Wpower[] = { 100,70,40 };								//�Ӽ� ��ġ

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

void WandManager::Buy(User* Nowuser)							//���� �޼ҵ�
{
	int select;
	char itemid[SIZE];

	for (int i = 0; i < sizeof(Wands) / sizeof(char*); i++)		//�ϵ� ������ ���� ���
	{
		cout << i + 1 << ". " << Wands[i] << " ����: " << Wweight[i] << " ���� +" << Wpower[i] << endl;
		cout << "����: " << Wprice[i] << endl;
	}
	cout << "�������: " << Nowuser->GetGold() << endl;
	cout << "����: ";
	cin >> select;

	if (Nowuser->GetGold() < Wprice[select - 1])				//���� ��� ���� �� �޴��� ���ư���
	{
		cout << "��尡 �����մϴ�." << endl;
		return;
	}
	else
	{
		Nowuser->SetGold(Wprice[select - 1], MINUS_GOLD);		//���� ������ ������ ��� ����
		cout << "���ŵǾ����ϴ�. (���� ���: " << Nowuser->GetGold() << ")" << endl;
	}

	sprintf(itemid, "%s%d", Itemid[WAND_CODE], idcount++);		//�����ۿ� ���̵� �ο�

	//������ �����۸���Ʈ�� ������ �߰�
	Nowuser->SetItem(new Wand(Wands[select - 1], Wweight[select - 1], Wprice[select - 1], itemid, Wpower[select - 1]));
}