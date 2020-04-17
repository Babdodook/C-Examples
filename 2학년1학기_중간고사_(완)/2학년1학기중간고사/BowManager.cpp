#include"BowManager.h"

const char* BowManager::Bows[] = { "�巡�� ����","ũ�ν�����","�� ����" };	// �̸�
const int BowManager::Bweight[] = { 30,20,10 };									// ����
const int BowManager::Bprice[] = { 150,120,100 };								// ����
const int BowManager::Bpower[] = { 100,70,40 };									// �Ӽ� ��ġ

BowManager::BowManager()
{
	idcount = 0;
}

BowManager::~BowManager()
{

}

void BowManager::Buy(User* Nowuser)								//���� �޼ҵ�
{
	int select;
	char itemid[SIZE];

	for (int i = 0; i < sizeof(Bows) / sizeof(char*); i++)		//�ϵ� ������ ���� ���
	{
		cout << i + 1 << ". " << Bows[i] << " ����: " << Bweight[i] << " ��ø +" << Bpower[i] << endl;
		cout << "����: " << Bprice[i] << endl;
	}
	cout << "�������: " << Nowuser->GetGold() << endl;
	cout << "����: ";
	cin >> select;

	if (Nowuser->GetGold() < Bprice[select - 1])				//���� ��� ���� �� �޴��� ���ư���
	{
		cout << "��尡 �����մϴ�." << endl;
		return;
	}
	else
	{
		Nowuser->SetGold(Bprice[select - 1], MINUS_GOLD);		//���� ������ ������ ��� ����
		cout << "���ŵǾ����ϴ�. (���� ���: " << Nowuser->GetGold() << ")" << endl;
	}

	sprintf(itemid, "%s%d", Itemid[BOW_CODE], idcount++);		//�����ۿ� ���̵� �ο�

	//������ �����۸���Ʈ�� ������ �߰�
	Nowuser->SetItem(new Bow(Bows[select - 1], Bweight[select - 1], Bprice[select - 1], itemid, Bpower[select - 1]));
}