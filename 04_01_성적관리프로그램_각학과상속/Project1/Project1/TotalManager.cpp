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
			cout << "<<성적입력>>" << endl;
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
				cout << "잘못 입력하셨습니다" << endl << endl;
				continue;
			}
			break;
		case MAINMENU::OUTPUT:
			cout << "<<성적출력>>" << endl;
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
				cout << "잘못 입력하셨습니다" << endl << endl;
				continue;
			}
			break;
		case MAINMENU::SEARCH:
			cout << "<<성적검색>>" << endl;
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
			cout << "잘못 입력하셨습니다" << endl << endl;
			continue;
		}
	}
}

int TotalM::Mainmenu()
{
	int select;
	cout << "<성적프로그램>" << endl;
	cout << "1. 성적입력" << endl;
	cout << "2. 성적출력" << endl;
	cout << "3. 성적조회" << endl;
	cout << "4. 종료" << endl;
	cout << "선택: ";
	cin >> select;
	return select;
}

int TotalM::SelectClass()
{
	int select;
	cout << "(프로그래밍:1, 그래픽:2, 기획:3)" << endl;
	cout << "선택: ";
	cin >> select;
	return select;
}