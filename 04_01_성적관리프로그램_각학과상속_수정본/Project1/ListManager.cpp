#include"ListManager.h"

ListManager::ListManager()
{
	ProgList = new LinkedList<Student*>();
	DesignList = new LinkedList<Student*>();
	GraphicList = new LinkedList<Student*>();
	pcount = 0;
	dcount = 0;
	gcount = 0;
}

ListManager::~ListManager()
{
	delete ProgList;
	delete DesignList;
	delete GraphicList;
}

void ListManager::Insert(Student * student,int major)
{
	switch (major)
	{
	case MAJOR::PROG:
		ProgList->Insert(student);
		pcount++;
		break;
	case MAJOR::DESIGN:
		DesignList->Insert(student);
		dcount++;
		break;
	case MAJOR::GRAPHIC:
		GraphicList->Insert(student);
		gcount++;
		break;
	}
}

Node<Student*>* ListManager::GetNode(int major)
{
	switch (major)
	{
	case MAJOR::PROG:
		return ProgList->GetHead();
	case MAJOR::DESIGN:
		return DesignList->GetHead();
	case MAJOR::GRAPHIC:
		return GraphicList->GetHead();
	}
}