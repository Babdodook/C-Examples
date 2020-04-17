#include"ListManager.h"

ListManager::ListManager()
{
	Designlist = new LinkedList<Student*>();
	Graphiclist = new LinkedList<Student*>();
	Proglist = new LinkedList<Student*>();
}

ListManager::~ListManager()
{
	delete Designlist;
	delete Graphiclist;
	delete Proglist;
}

void ListManager::Input(Student* student,int majornum)
{
	switch (majornum)
	{
	case MAJOR::PROG:
		Proglist->insert(student);
		break;
	case MAJOR::GRAPHIC:
		Graphiclist->insert(student);
		break;
	case MAJOR::DESIGN:
		Designlist->insert(student);
		break;
	}
}

Node<Student*>* ListManager::GetNode(int majornum)
{
	Node<Student*> * nownode;
	switch (majornum)
	{
	case MAJOR::PROG:
		nownode=Proglist->GetHead();
		return nownode;
	case MAJOR::GRAPHIC:
		nownode = Graphiclist->GetHead();
		return nownode;
	case MAJOR::DESIGN:
		nownode = Designlist->GetHead();
		return nownode;
	}
}