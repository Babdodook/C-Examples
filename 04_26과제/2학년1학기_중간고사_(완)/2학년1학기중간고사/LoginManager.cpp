#include"LoginManager.h"

LoginManager* LoginManager::mPthis = nullptr;

LoginManager* LoginManager::Create()
{
	if (!mPthis)
	{
		mPthis = new LoginManager();
	}

	UserManager::Create();

	return mPthis;
}

LoginManager* LoginManager::GetInstance()
{
	return mPthis;
}

void LoginManager::Destroy()
{
	if (mPthis)
	{
		delete mPthis;
		mPthis = nullptr;
	}

	UserManager::Destroy();
}

LoginManager::LoginManager()			//�����ڿ��� �ʱ�ȭ
{
	UserList = nullptr;
	Nowuser = nullptr;
}

LoginManager::~LoginManager()			//�Ҹ��ڿ��� �޸� ����
{
	delete UserList;
}

void LoginManager::Init()				//�޸� ���� �Ҵ�
{
	UserList = new LinkedList<User*>();	//���� ��ü ������ ���� ��������Ʈ �����Ҵ�
}

void LoginManager::CreateAcc()			//ȸ������ �޼ҵ�
{
	char id[SIZE];
	char pw[SIZE];

	cout << "<ȸ�� ����>" << endl;
	cout << "ID: ";
	cin >> id;

	Node<User*>* temp = UserList->GetHead();	//�ߺ� üũ�� ���� �ӽó�� ������ temp

	while (temp != nullptr)				//���̵� �ߺ� üũ
	{
		if (strcmp(temp->GetData()->GetID(), id) == 0)
		{
			cout << "�̹� �����ϴ� ���̵��Դϴ�." << endl;
			return;						//�ߺ��� ��� ���θ޴��� ���ư�
		}
		temp = temp->GetLink();			//�ߺ��ƴ� ��� ���� ��� ����Ŵ
	}

	cout << "PW: ";
	cin >> pw;

	UserList->Insert(new User(id, pw));	//�ߺ����� �ʴ� ��� �����Ҵ��Ͽ� ���� ��ü ����
}

void LoginManager::Login()				//�α��� �޼ҵ�
{
	char id[SIZE];
	char pw[SIZE];

	cout << "<�α���>" << endl;
	cout << "ID: ";
	cin >> id;

	Node<User*>* temp = UserList->GetHead();	//�ӽ� ��� ������ temp

	bool flag = false;
	while (temp != nullptr)
	{
		if (strcmp(temp->GetData()->GetID(), id) == 0)		//�Է��� ���̵� �����ϴ��� Ȯ��
		{
			flag = true;
			break;
		}
		temp = temp->GetLink();
	}

	if (!flag)												//�������� �ʴ� ��� ���θ޴���
	{
		cout << "�������� �ʴ� ���̵��Դϴ�" << endl;
		return;
	}

	cout << "PW: ";
	cin >> pw;

	if (strcmp(temp->GetData()->GetPW(), pw) == 0)			//��й�ȣ���� ��ġ�� ��� �α��� ����
	{
		Nowuser = temp;										//���� ������ �α���
		if (UserManager::GetInstance()->LoginMenu(Nowuser))			//true�� ��� ���� ���� �α׾ƿ��ϰ�
												//���θ޴��� ���ư���
		{
			return;
		}
		else									//false�� ��� ���� ���� ����
		{
			UserList->Delete(Nowuser->GetData());
			return;
		}
	}
	else
	{
		cout << "PW�� ��ġ���� �ʽ��ϴ�" << endl;
		return;
	}
}