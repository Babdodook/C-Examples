#pragma once

#include"Node.h"

template <class T>
class LinkedList {
private:
	Node<T> * head;
public:
	LinkedList();
	~LinkedList();
	Node<T>* GetHead();
	void insert(T data);
	void remove(T data);
	//void search(T data);
};

template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {}

template <class T>
Node<T>* LinkedList<T>::GetHead()
{
	return head;
}

template <class T>
void LinkedList<T>::insert(T data)
{
	Node<T> * nextnode = new Node<T>(data);
	
	if (head != nullptr)
	{
		nextnode->SetLink(head);
		head = nextnode;
	}
	if (head == nullptr)
	{
		head = nextnode;
	}
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

/*template <class T>
bool LinkedList<T>::search(T data)
{
	Node<T> * p = head;
	Node<T> * prev = nullptr;
	if (p == nullptr)
	{
		return false;
	}
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
*/