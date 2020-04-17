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

LoginManager::LoginManager()			//생성자에서 초기화
{
	UserList = nullptr;
	Nowuser = nullptr;
}

LoginManager::~LoginManager()			//소멸자에서 메모리 해제
{
	delete UserList;
}

void LoginManager::Init()				//메모리 동적 할당
{
	UserList = new LinkedList<User*>();	//유저 객체 저장을 위한 유저리스트 동적할당
}

void LoginManager::CreateAcc()			//회원가입 메소드
{
	char id[SIZE];
	char pw[SIZE];

	cout << "<회원 가입>" << endl;
	cout << "ID: ";
	cin >> id;

	Node<User*>* temp = UserList->GetHead();	//중복 체크를 위한 임시노드 포인터 temp

	while (temp != nullptr)				//아이디 중복 체크
	{
		if (strcmp(temp->GetData()->GetID(), id) == 0)
		{
			cout << "이미 존재하는 아이디입니다." << endl;
			return;						//중복될 경우 메인메뉴로 돌아감
		}
		temp = temp->GetLink();			//중복아닌 경우 다음 노드 가리킴
	}

	cout << "PW: ";
	cin >> pw;

	UserList->Insert(new User(id, pw));	//중복되지 않는 경우 동적할당하여 유저 객체 생성
}

void LoginManager::Login()				//로그인 메소드
{
	char id[SIZE];
	char pw[SIZE];

	cout << "<로그인>" << endl;
	cout << "ID: ";
	cin >> id;

	Node<User*>* temp = UserList->GetHead();	//임시 노드 포인터 temp

	bool flag = false;
	while (temp != nullptr)
	{
		if (strcmp(temp->GetData()->GetID(), id) == 0)		//입력한 아이디가 존재하는지 확인
		{
			flag = true;
			break;
		}
		temp = temp->GetLink();
	}

	if (!flag)												//존재하지 않는 경우 메인메뉴로
	{
		cout << "존재하지 않는 아이디입니다" << endl;
		return;
	}

	cout << "PW: ";
	cin >> pw;

	if (strcmp(temp->GetData()->GetPW(), pw) == 0)			//비밀번호까지 일치할 경우 로그인 성공
	{
		Nowuser = temp;										//현재 유저로 로그인
		if (UserManager::GetInstance()->LoginMenu(Nowuser))			//true일 경우 현재 유저 로그아웃하고
												//메인메뉴로 돌아간다
		{
			return;
		}
		else									//false일 경우 현재 유저 삭제
		{
			UserList->Delete(Nowuser->GetData());
			return;
		}
	}
	else
	{
		cout << "PW가 일치하지 않습니다" << endl;
		return;
	}
}