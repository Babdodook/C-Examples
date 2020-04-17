#include"Graphic.h"

const char * Graphic::Majornames[] = { "2D","3D","드로잉" };

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
	ListM->Insert(student, MAJOR::GRAPHIC);
}

void Graphic::Output()
{
	Node<Student*>* node = ListM->GetNode(MAJOR::GRAPHIC);

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

void Graphic::Search()
{
	int classnum;
	cout << "학번: ";
	cin >> classnum;

	Node<Student*>* node = ListM->GetNode(MAJOR::GRAPHIC);

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