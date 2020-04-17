#include"CharacterManager.h"

const char* CharacterManager::Characters[] = { "��ũ","����","�޸�" };		
const char* CharacterManager::Cid[] = { "100","200","300" };

CharacterManager::CharacterManager()			//�����ڿ��� �ʱ�ȭ
{
	memset(Cidcount, 0, sizeof(Cidcount));
}

CharacterManager::~CharacterManager()			//�Ҹ���
{
}

void CharacterManager::Create(User* Nowuser)	//ĳ���� ���� �޼ҵ�
{
	int select;
	char name[SIZE];
	char cid[SIZE];

	cout << "��Info�� ������ ���� ���� �˴ϴ�" << endl;
	cout << "<���� ����>" << endl;
	for (int i = 0; i < sizeof(Characters) / sizeof(char*); i++)		//ĳ���� �̸� �迭 ���
	{
		cout << i+1 << ". " << Characters[i] << " ";
	}
	cout << endl;
	cout << "����: ";
	cin >> select;

	cout << "ĳ������ �̸��� �Է����ּ���" << endl;						//ĳ������ �̸��� �Է¹޴´�
	cout << "�̸�: ";
	cin >> name;

	cout << endl;

	switch (select)
	{
	case C::ORC:														//��ũ ���� ��
		sprintf(cid, "%s%d", Cid[ORC_CODE], Cidcount[ORC_CODE]++);		//���� ���̵� ����
		Nowuser->SetCharacter(new Orc(name,cid));						//ĳ���͸���Ʈ�� ��ũ ��ü ��ĳ�������� �����Ҵ�
		cout << "��ũ ĳ���Ͱ� �����Ǿ����ϴ�" << endl << endl;
		break;
	case C::ELF:														//���� ���� ��
		sprintf(cid, "%s%d", Cid[ELF_CODE], Cidcount[ELF_CODE]++);		//���� ���̵� ����
		Nowuser->SetCharacter(new Elf(name, cid));						//ĳ���͸���Ʈ�� ���� ��ü ��ĳ�������� �����Ҵ�
		cout << "���� ĳ���Ͱ� �����Ǿ����ϴ�" << endl << endl;			
		break;
	case C::HUMAN:														//�޸� ���� ��
		sprintf(cid, "%s%d", Cid[HUM_CODE], Cidcount[HUM_CODE]++);		//���� ���̵� ����
		Nowuser->SetCharacter(new Human(name, cid));					//ĳ���͸���Ʈ�� �޸� ��ü ��ĳ�������� �����Ҵ�
		cout << "�ΰ� ĳ���Ͱ� �����Ǿ����ϴ�" << endl << endl;
		break;
	default:
		cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
		Clear();
		break;
	}
}

void CharacterManager::Delete(User* Nowuser)							//ĳ���� ���� �޼ҵ�
{
	char cid[SIZE];

	Node<Character*>* temp = Nowuser->GetCharacter();					//ĳ���� ����Ʈ�� ù��° ��带 ����Ű�� �ӽó�� ������ temp

	while (temp != nullptr)												//��ü ĳ���� ���� ���
	{
		temp->GetData()->ShowCInfo();
		temp=temp->GetLink();
	}

	cout << "�����Ϸ��� ĳ������ Slot Number�� �Է��ϼ���" << endl;		//���� �Ϸ��� ĳ������ ���� ���̵� �Է�
	cout << "Slot Number: ";
	cin >> cid;
	
	temp = Nowuser->GetCharacter();										//temp�� �ٽ� ó���� ��带 ����Ű�� �ȴ�

	while (temp != nullptr)
	{
		if (strcmp(temp->GetData()->GetCid(), cid) == 0)				//���̵� ��ġ�Ѵٸ�?
		{
			Nowuser->DelCharacter(temp->GetData());						//���� �����Ͱ� �ִ� ��� ����
			cout << "�����Ǿ����ϴ�" << endl;
			return;
		}
		temp = temp->GetLink();											//�ƴϸ� ���� ��� ����Ŵ
	}
}

void CharacterManager::Show(User* Nowuser)		//��ü ĳ���� ��� �޼ҵ�(�̱���)
{
}