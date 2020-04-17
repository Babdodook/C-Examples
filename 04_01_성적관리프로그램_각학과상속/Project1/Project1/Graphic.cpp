#include"Graphic.h"

Graphic::Graphic()
{
	classnum = 2019303001;
}

Graphic::~Graphic()
{
}

void Graphic::Input()
{
	char name[SIZE];
	int majorscore[3];

	cout << "이름: ";
	cin >> name;

	Student* student = new Student(name, classnum);
	classnum++;

	cout << "2D: ";
	cin >> majorscore[0];

	cout << "3D: ";
	cin >> majorscore[1];

	cout << "드로잉: ";
	cin >> majorscore[2];

	for (int i = 0; i < 3; i++)
	{
		student->SetMajor(i, majorscore[i]);
	}

	listManager->Input(student, MAJOR::GRAPHIC);
}

void Graphic::Output()
{
	Node<Student*> * nownode;

	nownode = listManager->GetNode(MAJOR::GRAPHIC);
	while (nownode != nullptr)
	{
		cout << "이름: " << nownode->GetData()->GetName() << endl;
		cout << "학번: " << nownode->GetData()->GetClassnum() << endl;
		cout << "2D: " << nownode->GetData()->GetMajor(0) << endl;
		cout << "3D: " << nownode->GetData()->GetMajor(1) << endl;
		cout << "드로잉: " << nownode->GetData()->GetMajor(0) << endl;
		cout << "평점: " << nownode->GetData()->GetGrade() << endl;

		nownode = nownode->GetLink();
	}
}

void Graphic::Search()
{
	int classnum;

	cout << "학번: ";
	cin >> classnum;

	Node<Student*>* nownode = listManager->GetNode(MAJOR::GRAPHIC);

	bool flag = false;
	while (nownode != nullptr)
	{
		if (nownode->GetData()->GetClassnum() == classnum)
		{
			cout << "이름: " << nownode->GetData()->GetName() << endl;
			cout << "학번: " << nownode->GetData()->GetClassnum() << endl;
			cout << "2D: " << nownode->GetData()->GetMajor(0) << endl;
			cout << "3D: " << nownode->GetData()->GetMajor(1) << endl;
			cout << "드로잉: " << nownode->GetData()->GetMajor(0) << endl;
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