#pragma once
#include"Basic.h"

template <class T>
class LinkedList;

template <class T>
class Node 
{
private:
	T data;
	Node<T> * link;
public:
	Node();
	Node(T data);
	~Node();

	T GetData();
	Node<T>* GetLink();

	void SetData(T);
	void SetLink(Node<T>*);
};

template <class T>
Node<T>::Node()
{
	data = nullptr;
	link = nullptr;
}

template <class T>
Node<T>::Node(T data)
{
	this->data = data;
	link = nullptr;
}

template <class T>
Node<T>::~Node() {}

template <class T>
T Node<T>::GetData()
{
	return data;
}

template <class T>
Node<T>* Node<T>::GetLink()
{
	return link;
}

template <class T>
void Node<T>::SetData(T data)
{
	this->data = data;
}

template <class T>
void Node<T>::SetLink(Node<T>* link)
{
	this->link = link;
}


template <class T>
class LinkedList 
{
private:
	Node<T> * head;
	Node<T> * tail;
public:
	LinkedList();
	~LinkedList();
	Node<T>* GetHead();
	Node<T>* GetTail();
	void insert(T data);
	void remove(T data);
	bool search(T data);
};

template <class T>
LinkedList<T>::LinkedList()
{
	head = new Node<T>();
	tail = head;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	Node<T> * p = head->GetLink();
	delete head;

	while (p != nullptr)
	{
		head = p;
		p = p->GetLink();
		delete head;
	}
}

template <class T>
Node<T>* LinkedList<T>::GetHead()
{
	Node<T>*p = head->GetLink();
	return p;
}

template <class T>
Node<T>* LinkedList<T>::GetTail()
{
	return tail;
}

template <class T>
void LinkedList<T>::insert(T data)
{
	Node<T> * nextnode = new Node<T>(data);

	tail->SetLink(nextnode);
	tail = nextnode;

	/*
	if (head != nullptr)
	{
		nextnode->SetLink(head);
		head = nextnode;
	}
	if (head == nullptr)
	{
		head = nextnode;
	}
	*/
}

template <class T>
void LinkedList<T>::remove(T data)
{
	Node<T> * p = head;
	Node<T> * prev = nullptr;
	if (p->GetLink() == nullptr)
	{
		head = nullptr;
		return;
	}
	if (p->GetLink() != nullptr)
	{
		while (p != nullptr)
		{
			if (p->GetData() == data)
			{
				if (prev == nullptr) //노드가 2개인 경우 헤드노드에 있는 데이터를 삭제할 경우
				{
					head = p->GetLink();
					delete p;
					return;
				}
				prev->SetLink(p->GetLink());
				delete p;
				return;
			}
			prev = p;
			p = p->GetLink();
		}
	}
}

template <class T>
bool LinkedList<T>::search(T data)
{
	Node<T> * p = head->GetLink();
	Node<T> * prev = nullptr;
	while (p != nullptr)
	{
		if (p->data == data)
		{
			return true;
		}
		prev = p;
		p = p->link;
	}
	return false;
}
