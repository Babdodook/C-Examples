#include"TotalManager.h"

TotalM::TotalM()
{
	design = nullptr;
	graphic = nullptr;
	prog = nullptr;
}

TotalM::~TotalM()
{
	delete design;
	delete graphic;
	delete prog;
}

void TotalM::Init()
{
	design = new Design();
	graphic = new Graphic();
	prog = new Programming();
}

void TotalM::Run()
{
	Init();
	while (1)
	{
		switch (Mainmenu())
		{
		case MAINMENU::INPUT:
			cout << "<<�����Է�>>" << endl;
			switch (SelectClass())
			{
			case MAJOR::PROG:
				prog->Input();
				break;
			case MAJOR::GRAPHIC:
				graphic->Input();
				break;
			case MAJOR::DESIGN:
				design->Input();
				break;
			default:
				cout << "�߸� �Է��ϼ̽��ϴ�" << endl << endl;
				continue;
			}
			break;
		case MAINMENU::OUTPUT:
			cout << "<<�������>>" << endl;
			switch (SelectClass())
			{
			case MAJOR::PROG:
				prog->Output();
				break;
			case MAJOR::GRAPHIC:
				graphic->Output();
				break;
			case MAJOR::DESIGN:
				design->Output();
				break;
			default:
				cout << "�߸� �Է��ϼ̽��ϴ�" << endl << endl;
				continue;
			}
			break;
		case MAINMENU::SEARCH:
			cout << "<<�����˻�>>" << endl;
			switch (SelectClass())
			{
			case MAJOR::PROG:
				prog->Search();
				break;
			case MAJOR::GRAPHIC:
				graphic->Search();
				break;
			case MAJOR::DESIGN:
				design->Search();
				break;
			}
			break;
		case MAINMENU::EXIT:
			exit(1);
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl << endl;
			continue;
		}
	}
}

int TotalM::Mainmenu()
{
	int select;
	cout << "<�������α׷�>" << endl;
	cout << "1. �����Է�" << endl;
	cout << "2. �������" << endl;
	cout << "3. ������ȸ" << endl;
	cout << "4. ����" << endl;
	cout << "����: ";
	cin >> select;
	return select;
}

int TotalM::SelectClass()
{
	int select;
	cout << "(���α׷���:1, �׷���:2, ��ȹ:3)" << endl;
	cout << "����: ";
	cin >> select;
	return select;
}