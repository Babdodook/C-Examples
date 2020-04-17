#include"Design.h"

const char * Design::Majornames[] = { "게임기획기초","게임시나리오","레벨디자인" };

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
	int score = 0;

	Student* student = new Student();

	cout << "이름: ";
	cin >> name;

	student->Setname(name);
	student->Setclassnum(classnum++);

	for (int i = 0; i < MAJORS; i++)
	{
		cout << Majornames[i] << ": ";
		cin >> score;
		student->Setmscore(score, i);
	}
	ListM->Insert(student, MAJOR::DESIGN);
}

void Design::Output()
{
	Node<Student*>* node = ListM->GetNode(MAJOR::DESIGN);

	while (node != nullptr)
	{
		cout << "이름: " << node->GetData()->Getname() << endl;
		cout << "학번: " << node->GetData()->Getclassnum() << endl;
		for (int i = 0; i < MAJORS; i++)
		{
			cout << Majornames[i] << ": " << node->GetData()->Getmscore(i) << endl;
		}
		cout << "평점: " << node->GetData()->Getgrade() << endl << endl;

		node = node->GetLink();
	}
}

void Design::Search()
{
	int classnum;
	cout << "학번: ";
	cin >> classnum;

	Node<Student*>* node = ListM->GetNode(MAJOR::DESIGN);

	while (node != nullptr)
	{
		if (node->GetData()->Getclassnum() == classnum)
		{
			cout << "이름: " << node->GetData()->Getname() << endl;
			cout << "학번: " << node->GetData()->Getclassnum() << endl;
			for (int i = 0; i < MAJORS; i++)
			{
				cout << Majornames[i] << ": " << node->GetData()->Getmscore(i) << endl;
			}
			cout << "평점: " << node->GetData()->Getgrade() << endl << endl;
			return;
		}
		node = node->GetLink();
	}
}