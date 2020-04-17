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

	cout << "�̸�: ";
	cin >> name;

	Student* student = new Student(name, classnum);
	classnum++;

	cout << "���ӱ�ȹ����: ";
	cin >> majorscore[0];

	cout << "���ӽó�����: ";
	cin >> majorscore[1];

	cout << "����������: ";
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
		cout << "�̸�: " << nownode->GetData()->GetName() << endl;
		cout << "�й�: " << nownode->GetData()->GetClassnum() << endl;
		cout << "���ӱ�ȹ����: " << nownode->GetData()->GetMajor(0) << endl;
		cout << "���ӽó�����: " << nownode->GetData()->GetMajor(1) << endl;
		cout << "����������: " << nownode->GetData()->GetMajor(0) << endl;
		cout << "����: " << nownode->GetData()->GetGrade() << endl;

		nownode = nownode->GetLink();
	}
}

void Design::Search()
{
	int classnum;

	cout << "�й�: ";
	cin >> classnum;

	Node<Student*>* nownode = listManager->GetNode(MAJOR::DESIGN);

	bool flag = false;
	while (nownode != nullptr)
	{
		if (nownode->GetData()->GetClassnum() == classnum)
		{
			cout << "�̸�: " << nownode->GetData()->GetName() << endl;
			cout << "�й�: " << nownode->GetData()->GetClassnum() << endl;
			cout << "���ӱ�ȹ����: " << nownode->GetData()->GetMajor(0) << endl;
			cout << "���ӽó�����: " << nownode->GetData()->GetMajor(1) << endl;
			cout << "����������: " << nownode->GetData()->GetMajor(0) << endl;
			cout << "����: " << nownode->GetData()->GetGrade() << endl;

			flag = true;
			return;
		}

		nownode = nownode->GetLink();
	}

	if (!flag)
	{
		cout << "�������� �ʴ� �й��Դϴ�." << endl;
	}
}