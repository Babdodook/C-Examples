#pragma once
#include"LinkedList.h"
#include"Student.h"

class ListManager {
private:
	LinkedList<Student*>* ProgList;
	LinkedList<Student*>* DesignList;
	LinkedList<Student*>* GraphicList;
	int pcount;
	int dcount;
	int gcount;
public:
	ListManager();
	~ListManager();

	void Insert(Student*,int);
	Node<Student*>* GetNode(int);
};