#pragma once
#include"Basic.h"

template <class T>
class LinkedList;

template <class T>
class Node {
private:
	T data;
	Node<T> * link;
public:
	Node(T data);
	~Node();

	T GetData();
	Node<T>* GetLink();

	void SetData(T);
	void SetLink(Node<T>*);
};

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