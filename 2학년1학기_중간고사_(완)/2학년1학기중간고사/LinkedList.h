#pragma once
#include"BasicHeader.h"

// Node class
template <class T>		//��� Ŭ���� ���ø�
class Node {
private:
	T data;				//��忡 ������ ������
	Node<T>* link;		//��忡 ������ ���� �����͸� ����Ű�� ��ũ
public:
	Node()				//�⺻ ������
	{
		data = nullptr;
		link = nullptr;
	}
	Node(T data)			//�����͸� �޴� ������
	{
		this->data = data;
		link = nullptr;
	}
	~Node()					//�Ҹ���
	{
	}

	void SetData(T data)			//������ ���� �޼ҵ�
	{
		this->data = data;
	}
	void SetLink(Node<T>* link)		//��ũ ���� �޼ҵ�
	{
		this->link = link;
	}

	T GetData()						//������ �б� �޼ҵ�
	{
		return data;
	}
	Node<T>* GetLink()				//��ũ �б� �޼ҵ�
	{
		return link;
	}
};

// LinkedList class
template <class T>					//��带 ������ ��ũ�帮��Ʈ Ŭ���� ���ø�
class LinkedList {
private:
	Node<T>* Head;					//��带 ����Ű�� ���
	Node<T>* Tail;					//����(�߰��� ���)�� ����Ű�� ���
public:
	LinkedList()					//�⺻������
	{
		Head = new Node<T>();
		Tail = Head;
	}
	~LinkedList()					//�Ҹ���
	{
		Node<T> * p = Head->GetLink();
		delete Head;

		while (p != nullptr)			//���������� ��� ����
		{
			Head = p;
			p = p->GetLink();
			delete Head;
		}
	}

	Node<T>* GetHead()					//��� ��� �б� �޼ҵ� (ù��° ���)
	{
		return Head->GetLink();			//��ǻ� ù��° ���� ����ֱ� ������ ���� ����ִ� '��¥' ù��° ��带 ��ȯ
	}
	Node<T>* GetTail()					//�ǳ� ���(�������� �߰��� ���) �б� �޼ҵ�
	{
		return Tail;
	}
	void Insert(T data)							//�߰� �޼ҵ�, ��忡 �����͸� �����ϰ� ����Ʈ�� ��� �߰�
	{
		Node<T> * node = new Node<T>(data);		//�Ű������� ���� �����͸� ���ο� ��带 �Ҵ��Ͽ� ����
		Tail->SetLink(node);					//���ϳ��(���������� ���� �����ͳ��)�� ������ �̾� �ٿ��ش�
		Tail = node;							//������ ���� ���� ��带 ����Ű�� ��
	}
	void Delete(T data)							//���� �޼ҵ�
	{
		Node<T> * p = Head->GetLink();			//ù��° ��带 �ӽ� ��� p�� ����
		Node<T> * prev = Head;					//�� �� ��带 �˱����� �ӽ� ��� prev
		while (p != nullptr)
		{
			if (p->GetData() == data)			//�����Ͱ� ��ġ�Ѵٸ�?
			{
				prev->SetLink(p->GetLink());	//�� �� ���� ���� ��ġ�� ����� ���� ��带 �̾���δ�
				if (p->GetLink() == nullptr)	//������ ����� ���
				{
					Tail = prev;				//�� �� ��尡 ������ �ȴ�
				}
				delete p;						//��� ����
				break;
			}
			prev = p;							//���� ��尡 ���� ��尡 �ǰ�
			p = p->GetLink();					//���� ��忴�� p�� ���� ��带 ����Ű�� �ȴ�
		}
	}
};