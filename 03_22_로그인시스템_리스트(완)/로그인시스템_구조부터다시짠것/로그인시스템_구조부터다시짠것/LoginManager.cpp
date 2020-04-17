#include"LoginManager.h"

LoginManager::LoginManager() 
{
	nowuser = nullptr;
	List = nullptr;
}

LoginManager::~LoginManager() 
{
	delete List;
}

void LoginManager::Init()
{
	List = new LinkedList<User*>();
}

void LoginManager::SignUp()
{
	puts("");

	char id[MAXSIZE];
	char pw[MAXSIZE];

	cout << "ID: ";
	cin >> id;

	Node<User*>* node = List->GetHead();

	while (node != nullptr)
	{
		if (strcmp(node->GetData()->GetID(), id) == 0)
		{
			cout << "이미 존재하는 ID입니다" << endl;
			return;
		}
		node = node->GetLink();
	}

	cout << "PW: ";
	cin >> pw;

	List->insert(new User(id,pw));
}

bool LoginManager::Login()
{
	char id[MAXSIZE];
	char pw[MAXSIZE];

	cout << "ID: ";
	cin >> id;
	
	Node<User*>* node = List->GetHead();

	bool flag = false;
	while (node != nullptr)
	{
		if(strcmp(node->GetData()->GetID(), id) == 0)
		{
			flag = true;
			break;
		}
		node = node->GetLink();
	}

	if (!flag)
	{
		cout << "일치하는 ID가 없습니다" << endl;
		return false;
	}

	cout << "PW: ";
	cin >> pw;
	
	if (strcmp(node->GetData()->GetPW(),pw)==0)
	{
		nowuser = node->GetData();
		nowuser->SetState(true);
		cout << "로그인 되었습니다" << endl;
		return true;
	}
	else
	{
		cout << "PW가 일치하지 않습니다" << endl;
		return false;
	}
}

void LoginManager::Logout()
{
	nowuser->SetState(false);
	nowuser = nullptr;
}

void LoginManager::DeleteAcc()
{
	List->remove(nowuser);
}

void LoginManager::SetNowuser(User * _user) 
{
	nowuser = _user;
}

User * LoginManager::GetNowuser() 
{
	return nowuser;
}