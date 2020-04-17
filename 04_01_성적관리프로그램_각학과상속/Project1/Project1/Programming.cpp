#include"Programming.h"

Programming::Programming()
{
	classnum = 2019302001;
}

Programming::~Programming()
{
}

void Programming::Input()
{
	char name[SIZE];
	int majorscore[3];

	cout << "이름: ";
	cin >> name;

	Student* student = new Student(name,classnum);
	classnum++;

	cout << "C++2: ";
	cin >> majorscore[0];

	cout << "C#: ";
	cin >> majorscore[1];

	cout << "API2: ";
	cin >> majorscore[2];

	for (int i = 0; i < 3; i++)
	{
		student->SetMajor(i, majorscore[i]);
	}

	listManager->Input(student, MAJOR::PROG);

}

void Programming::Output()
{
	Node<Student*> * nownode;

	nownode=listManager->GetNode(MAJOR::PROG);
	while (nownode != nullptr)
	{
		cout << endl;
		cout << "이름: " << nownode->GetData()->GetName() << endl;
		cout << "학번: " << nownode->GetData()->GetClassnum() << endl;
		cout << "C++2: " << nownode->GetData()->GetMajor(0) << endl;
		cout << "C#: " << nownode->GetData()->GetMajor(1) << endl;
		cout << "API2: " << nownode->GetData()->GetMajor(0) << endl;
		cout << "평점: " << nownode->GetData()->GetGrade() << endl;

		nownode = nownode->GetLink();
	}
}

void Programming::Search()
{
	int classnum;

	cout << "학번: ";
	cin >> classnum;
	
	Node<Student*>* nownode = listManager->GetNode(MAJOR::PROG);

	bool flag = false;
	while (nownode != nullptr)
	{
		if (nownode->GetData()->GetClassnum() == classnum)
		{
			cout << endl;
			cout << "이름: " << nownode->GetData()->GetName() << endl;
			cout << "학번: " << nownode->GetData()->GetClassnum() << endl;
			cout << "C++2: " << nownode->GetData()->GetMajor(0) << endl;
			cout << "C#: " << nownode->GetData()->GetMajor(1) << endl;
			cout << "API2: " << nownode->GetData()->GetMajor(0) << endl;
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