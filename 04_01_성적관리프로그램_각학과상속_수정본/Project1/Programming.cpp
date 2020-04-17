#include"Programming.h"

const char * Programming::Majornames[] = { "C++2","C#","API2" };

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
	ListM->Insert(student, MAJOR::PROG);
}

void Programming::Output()
{
	Node<Student*>* node = ListM->GetNode(MAJOR::PROG);
	
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

void Programming::Search()
{
	int classnum;
	cout << "학번: ";
	cin >> classnum;

	Node<Student*>* node = ListM->GetNode(MAJOR::PROG);

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