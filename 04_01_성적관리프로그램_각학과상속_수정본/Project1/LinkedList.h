#pragma once
#include"Basic.h"

// Node class
template <class T>
class Node {
private:
	T data;
	Node<T>* link;
public:
	Node()
	{
		data = nullptr;
		link = nullptr;
	}
	Node(T data)
	{
		this->data = data;
		link = nullptr;
	}
	~Node()
	{
	}

	void SetData(T data)
	{
		this->data = data;
	}
	void SetLink(Node<T>* link)
	{
		this->link = link;
	}

	T GetData()
	{
		return data;
	}
	Node<T>* GetLink()
	{
		return link;
	}
};

// LinkedList class
template <class T>
class LinkedList {
private:
	Node<T>* Head;
	Node<T>* Tail;
public:
	LinkedList()
	{
		Head = new Node<T>();
		Tail = Head;
	}
	~LinkedList()
	{
		Node<T> * p = Head->GetLink();
		delete Head;

		while (p != nullptr)
		{
			Head = p;
			p = p->GetLink();
			delete Head;
		}
	}

	Node<T>* GetHead()
	{
		return Head->GetLink();
	}
	Node<T>* GetTail()
	{
		return Tail;
	}
	void Insert(T data)
	{
		Node<T> * node = new Node<T>(data);
		Tail->SetLink(node);
		Tail = node;
	}
	void Delete(T data)
	{
		Node<T> * p = Head->GetLink();
		Node<T> * prev = Head;
		while (p != nullptr)
		{
			if (p->GetData() == data)
			{
				prev->SetLink(p->GetLink());
				delete p;
			}
			prev = p;
			p = p->GetLink();
		}
	}
};