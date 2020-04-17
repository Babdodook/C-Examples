#include"TotalManager.h"

TotalManager::TotalManager()
{
	memset(ProgArr, 0, sizeof(ProgArr));
	memset(GraphicArr, 0, sizeof(GraphicArr));
	memset(DesignArr, 0, sizeof(DesignArr));
	pArrcount=0;
	gArrcount=0;
	dArrcount=0;

	pscount=1;
	dscount=1;
	gscount=1;
}

TotalManager::~TotalManager()
{
	for (int i = 0; i < MAX; i++)
	{
		if (ProgArr[i] != nullptr)
		{
			delete ProgArr[i];
			ProgArr[i] = nullptr;
		}
		if (GraphicArr[i] != nullptr)
		{
			delete GraphicArr[i];
			GraphicArr[i] = nullptr;
		}
		if (DesignArr[i] != nullptr)
		{
			delete DesignArr[i];
			DesignArr[i] = nullptr;
		}
	}
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
	while (1)
	{
		switch (Mainmenu())
		{
		case MENU::INPUT:
			Input();
			break;
		case MENU::DISPLAY:
			Display();
			break;
		case MENU::SEARCH:
			Search();
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

void TotalManager::Input()
{
	int select;
	char name[SIZE];
	char id[SIZE];

	cout << "<<성적입력>>" << endl;
	cout << "<프로그래밍:1, 그래픽:2, 기획:3>>" << endl;
	cout << "선택: ";
	cin >> select;
	clear();

	switch (select)
	{
	case MAJOR::PROG:
		cout << "이름: ";
		cin >> name;

		sprintf(id, "2019%s%03d", PROG_CODE, pscount++);
		ProgArr[pArrcount] = new Programming(name, id);
		
		ProgArr[pArrcount]->Input();
		pArrcount++;
		break;
	case MAJOR::GRAPHIC:
		cout << "이름: ";
		cin >> name;

		sprintf(id, "2019%s%03d", GRAPHIC_CODE, gscount++);
		GraphicArr[gArrcount] = new Programming(name, id);

		GraphicArr[gArrcount]->Input();
		gArrcount++;
		break;
	case MAJOR::DESIGN:
		cout << "이름: ";
		cin >> name;

		sprintf(id, "2019%s%03d", DESIGN_CODE, dscount++);
		DesignArr[dArrcount] = new Programming(name, id);

		DesignArr[dArrcount]->Input();
		dArrcount++;
		break;
	default:
		cout << "잘못 입력하셨습니다" << endl;
		return;
	}
}

void TotalManager::Display()
{
	int select;

	cout << "<<성적출력>>" << endl;
	cout << "<프로그래밍:1, 그래픽:2, 기획:3>>" << endl;
	cout << "선택: ";
	cin >> select;
	clear();

	switch (select)
	{
	case MAJOR::PROG:
		for (int i = 0; i < pArrcount; i++)
		{
			ProgArr[i]->Display();
		}
		break;
	case MAJOR::GRAPHIC:
		for (int i = 0; i < gArrcount; i++)
		{
			GraphicArr[i]->Display();
		}
		break;
	case MAJOR::DESIGN:
		for (int i = 0; i < dArrcount; i++)
		{
			DesignArr[i]->Display();
		}
		break;
	default:
		cout << "잘못 입력하셨습니다" << endl;
		return;
	}
}

void TotalManager::Search()
{
	int select;
	char id[SIZE];

	cout << "<<성적조회>>" << endl;
	cout << "<프로그래밍:1, 그래픽:2, 기획:3>>" << endl;
	cout << "선택: ";
	cin >> select;
	clear();

	cout << "학번: ";
	cin >> id;

	switch (select)
	{
	case MAJOR::PROG:
		for (int i = 0; i < pArrcount; i++)
		{
			if (strcmp(ProgArr[i]->GetID(), id)==0)
			{
				ProgArr[i]->Display();
			}
		}
		break;
	case MAJOR::GRAPHIC:
		for (int i = 0; i < gArrcount; i++)
		{
			if (strcmp(GraphicArr[i]->GetID(), id) == 0)
			{
				GraphicArr[i]->Display();
			}
		}
		break;
	case MAJOR::DESIGN:
		for (int i = 0; i < dArrcount; i++)
		{
			if (strcmp(DesignArr[i]->GetID(), id) == 0)
			{
				DesignArr[i]->Display();
			}
		}
		break;
	default:
		cout << "잘못 입력하셨습니다" << endl;
		return;
	}
}