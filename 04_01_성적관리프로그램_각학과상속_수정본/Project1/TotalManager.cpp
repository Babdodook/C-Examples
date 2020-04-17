#include"TotalManager.h"

TotalManager::TotalManager()
{
	Prog = nullptr;
	Des = nullptr;
	Grap = nullptr;
}

TotalManager::~TotalManager()
{
	delete Prog;
	delete Des;
	delete Grap;
}

void TotalManager::Init()
{
	Prog = new Programming();
	Des = new Design();
	Grap = new Graphic();
}

void TotalManager::clear()
{
	if (cin.failbit)
	{
		cin.clear();
		cin.ignore(256, '\n');
	}
}

void TotalManager::Run()
{
	Init();
	while (1)
	{
		switch (Mainmenu())
		{
		case MENU::INPUT:
			cout << "<<�����Է�>>" << endl;
			switch (SelectMajor())
			{
			case MAJOR::PROG:
				Prog->Input();
				break;
			case MAJOR::GRAPHIC:
				Grap->Input();
				break;
			case MAJOR::DESIGN:
				Des->Input();
				break;
			}
			break;
		case MENU::OUTPUT:
			cout << "<<�������>>" << endl;
			switch (SelectMajor())
			{
			case MAJOR::PROG:
				Prog->Output();
				break;
			case MAJOR::GRAPHIC:
				Grap->Output();
				break;
			case MAJOR::DESIGN:
				Des->Output();
				break;
			}
			break;
		case MENU::SEARCH:
			cout << "<<������ȸ>>" << endl;
			switch (SelectMajor())
			{
			case MAJOR::PROG:
				Prog->Search();
				break;
			case MAJOR::GRAPHIC:
				Grap->Search();
				break;
			case MAJOR::DESIGN:
				Des->Search();
				break;
			}
			break;
		case MENU::EXIT:
			exit(1);
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}
	}
}

int TotalManager::Mainmenu()
{
	int select;
	cout << "<�������α׷�>" << endl;
	cout << "1. �����Է�" << endl;
	cout << "2. �������" << endl;
	cout << "3. ������ȸ" << endl;
	cout << "4. ����" << endl;
	cout << "����: ";
	cin >> select;
	clear();
	return select;
}

int TotalManager::SelectMajor()
{
	int select;
	cout << "<���α׷���:1, �׷���:2, ��ȹ:3>" << endl;
	cout << "����: ";
	cin >> select;
	clear();
	return select;
}