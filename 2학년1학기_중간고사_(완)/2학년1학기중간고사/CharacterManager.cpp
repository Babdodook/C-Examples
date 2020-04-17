#include"CharacterManager.h"

const char* CharacterManager::Characters[] = { "오크","엘프","휴먼" };		
const char* CharacterManager::Cid[] = { "100","200","300" };

CharacterManager::CharacterManager()			//생성자에서 초기화
{
	memset(Cidcount, 0, sizeof(Cidcount));
}

CharacterManager::~CharacterManager()			//소멸자
{
}

void CharacterManager::Create(User* Nowuser)	//캐릭터 생성 메소드
{
	int select;
	char name[SIZE];
	char cid[SIZE];

	cout << "※Info※ 스텟은 랜덤 설정 됩니다" << endl;
	cout << "<종족 선택>" << endl;
	for (int i = 0; i < sizeof(Characters) / sizeof(char*); i++)		//캐릭터 이름 배열 출력
	{
		cout << i+1 << ". " << Characters[i] << " ";
	}
	cout << endl;
	cout << "선택: ";
	cin >> select;

	cout << "캐릭터의 이름을 입력해주세요" << endl;						//캐릭터의 이름을 입력받는다
	cout << "이름: ";
	cin >> name;

	cout << endl;

	switch (select)
	{
	case C::ORC:														//오크 선택 시
		sprintf(cid, "%s%d", Cid[ORC_CODE], Cidcount[ORC_CODE]++);		//고유 아이디 생성
		Nowuser->SetCharacter(new Orc(name,cid));						//캐릭터리스트에 오크 객체 업캐스팅으로 동적할당
		cout << "오크 캐릭터가 생성되었습니다" << endl << endl;
		break;
	case C::ELF:														//엘프 선택 시
		sprintf(cid, "%s%d", Cid[ELF_CODE], Cidcount[ELF_CODE]++);		//고유 아이디 생성
		Nowuser->SetCharacter(new Elf(name, cid));						//캐릭터리스트에 엘프 객체 업캐스팅으로 동적할당
		cout << "엘프 캐릭터가 생성되었습니다" << endl << endl;			
		break;
	case C::HUMAN:														//휴먼 선택 시
		sprintf(cid, "%s%d", Cid[HUM_CODE], Cidcount[HUM_CODE]++);		//고유 아이디 생성
		Nowuser->SetCharacter(new Human(name, cid));					//캐릭터리스트에 휴먼 객체 업캐스팅으로 동적할당
		cout << "인간 캐릭터가 생성되었습니다" << endl << endl;
		break;
	default:
		cout << "잘못 입력하셨습니다" << endl;
		Clear();
		break;
	}
}

void CharacterManager::Delete(User* Nowuser)							//캐릭터 삭제 메소드
{
	char cid[SIZE];

	Node<Character*>* temp = Nowuser->GetCharacter();					//캐릭터 리스트의 첫번째 노드를 가리키는 임시노드 포인터 temp

	while (temp != nullptr)												//전체 캐릭터 정보 출력
	{
		temp->GetData()->ShowCInfo();
		temp=temp->GetLink();
	}

	cout << "삭제하려는 캐릭터의 Slot Number를 입력하세요" << endl;		//삭제 하려는 캐릭터의 고유 아이디 입력
	cout << "Slot Number: ";
	cin >> cid;
	
	temp = Nowuser->GetCharacter();										//temp는 다시 처음의 노드를 가리키게 된다

	while (temp != nullptr)
	{
		if (strcmp(temp->GetData()->GetCid(), cid) == 0)				//아이디가 일치한다면?
		{
			Nowuser->DelCharacter(temp->GetData());						//현재 데이터가 있는 노드 삭제
			cout << "삭제되었습니다" << endl;
			return;
		}
		temp = temp->GetLink();											//아니면 다음 노드 가리킴
	}
}

void CharacterManager::Show(User* Nowuser)		//전체 캐릭터 출력 메소드(미구현)
{
}