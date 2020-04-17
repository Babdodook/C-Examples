#include"Design.h"

Design::Design()
{
	classnum = 2019301001;
}

Design::~Design()
{
}

void Design::Input()
{
	char name[SIZE];
	int majorscore[3];

	cout << "이름: ";
	cin >> name;

	Student* student = new Student(name, classnum);
	classnum++;

	cout << "게임기획기초: ";
	cin >> majorscore[0];

	cout << "게임시나리오: ";
	cin >> majorscore[1];

	cout << "레벨디자인: ";
	cin >> majorscore[2];

	for (int i = 0; i < 3; i++)
	{
		student->SetMajor(i, majorscore[i]);
	}

	listManager->Input(student, MAJOR::DESIGN);
}

void Design::Output()
{
	Node<Student*> * nownode;

	nownode = listManager->GetNode(MAJOR::DESIGN);
	while (nownode != nullptr)
	{
		cout << "이름: " << nownode->GetData()->GetName() << endl;
		cout << "학번: " << nownode->GetData()->GetClassnum() << endl;
		cout << "게임기획기초: " << nownode->GetData()->GetMajor(0) << endl;
		cout << "게임시나리오: " << nownode->GetData()->GetMajor(1) << endl;
		cout << "레벨디자인: " << nownode->GetData()->GetMajor(0) << endl;
		cout << "평점: " << nownode->GetData()->GetGrade() << endl;

		nownode = nownode->GetLink();
	}
}

void Design::Search()
{
	int classnum;

	cout << "학번: ";
	cin >> classnum;

	Node<Student*>* nownode = listManager->GetNode(MAJOR::DESIGN);

	bool flag = false;
	while (nownode != nullptr)
	{
		if (nownode->GetData()->GetClassnum() == classnum)
		{
			cout << "이름: " << nownode->GetData()->GetName() << endl;
			cout << "학번: " << nownode->GetData()->GetClassnum() << endl;
			cout << "게임기획기초: " << nownode->GetData()->GetMajor(0) << endl;
			cout << "게임시나리오: " << nownode->GetData()->GetMajor(1) << endl;
			cout << "레벨디자인: " << nownode->GetData()->GetMajor(0) << endl;
			cout << "평점: " << nownode->GetData()->GetGrade() << endl;

			flag = true;
			return;
		}

		nownode = nownode->GetLink();
	}

	if (!flag)
	{
		cout << "존재하지 않는 학번입니다." << endl;
	}
}