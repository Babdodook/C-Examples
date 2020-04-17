#include"Design.h"

const char * Design::Majornames[] = { "���ӱ�ȹ����","���ӽó�����","����������" };

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

	cout << "�̸�: ";
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
		cout << "�̸�: " << node->GetData()->Getname() << endl;
		cout << "�й�: " << node->GetData()->Getclassnum() << endl;
		for (int i = 0; i < MAJORS; i++)
		{
			cout << Majornames[i] << ": " << node->GetData()->Getmscore(i) << endl;
		}
		cout << "����: " << node->GetData()->Getgrade() << endl << endl;

		node = node->GetLink();
	}
}

void Design::Search()
{
	int classnum;
	cout << "�й�: ";
	cin >> classnum;

	Node<Student*>* node = ListM->GetNode(MAJOR::DESIGN);

	while (node != nullptr)
	{
		if (node->GetData()->Getclassnum() == classnum)
		{
			cout << "�̸�: " << node->GetData()->Getname() << endl;
			cout << "�й�: " << node->GetData()->Getclassnum() << endl;
			for (int i = 0; i < MAJORS; i++)
			{
				cout << Majornames[i] << ": " << node->GetData()->Getmscore(i) << endl;
			}
			cout << "����: " << node->GetData()->Getgrade() << endl << endl;
			return;
		}
		node = node->GetLink();
	}
}