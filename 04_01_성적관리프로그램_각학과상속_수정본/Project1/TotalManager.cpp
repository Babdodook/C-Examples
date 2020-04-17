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
			cout << "<<성적입력>>" << endl;
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
			cout << "<<성적출력>>" << endl;
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
			cout << "<<성적조회>>" << endl;
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
			cout << "잘못 입력하셨습니다" << endl;
			continue;
		}
	}
}

int TotalManager::Mainmenu()
{
	int select;
	cout << "<성적프로그램>" << endl;
	cout << "1. 성적입력" << endl;
	cout << "2. 성적출력" << endl;
	cout << "3. 성적조회" << endl;
	cout << "4. 종료" << endl;
	cout << "선택: ";
	cin >> select;
	clear();
	return select;
}

int TotalManager::SelectMajor()
{
	int select;
	cout << "<프로그래밍:1, 그래픽:2, 기획:3>" << endl;
	cout << "선택: ";
	cin >> select;
	clear();
	return select;
}