#pragma once

#include"LinkedList.h"
#include"Student.h"

class ListManager
{
private:
	LinkedList<Student*>* Designlist;
	LinkedList<Student*>* Graphiclist;
	LinkedList<Student*>* Proglist;
public:
	ListManager();
	~ListManager();

	void Input(Student*, int);
	Node<Student*>* GetNode(int);
	//Node<Student*>* Search(Student*,int);
};