#pragma once
#include"BasicHeader.h"

// Node class
template <class T>		//노드 클래스 템플릿
class Node {
private:
	T data;				//노드에 저장할 데이터
	Node<T>* link;		//노드에 저장할 다음 데이터를 가리키는 링크
public:
	Node()				//기본 생성자
	{
		data = nullptr;
		link = nullptr;
	}
	Node(T data)			//데이터를 받는 생성자
	{
		this->data = data;
		link = nullptr;
	}
	~Node()					//소멸자
	{
	}

	void SetData(T data)			//데이터 쓰기 메소드
	{
		this->data = data;
	}
	void SetLink(Node<T>* link)		//링크 쓰기 메소드
	{
		this->link = link;
	}

	T GetData()						//데이터 읽기 메소드
	{
		return data;
	}
	Node<T>* GetLink()				//링크 읽기 메소드
	{
		return link;
	}
};

// LinkedList class
template <class T>					//노드를 저장할 링크드리스트 클래스 템플릿
class LinkedList {
private:
	Node<T>* Head;					//헤드를 가리키는 노드
	Node<T>* Tail;					//테일(추가된 노드)을 가리키는 노드
public:
	LinkedList()					//기본생성자
	{
		Head = new Node<T>();
		Tail = Head;
	}
	~LinkedList()					//소멸자
	{
		Node<T> * p = Head->GetLink();
		delete Head;

		while (p != nullptr)			//순차적으로 노드 삭제
		{
			Head = p;
			p = p->GetLink();
			delete Head;
		}
	}

	Node<T>* GetHead()					//헤드 노드 읽기 메소드 (첫번째 노드)
	{
		return Head->GetLink();			//사실상 첫번째 노드는 비어있기 때문에 값이 들어있는 '진짜' 첫번째 노드를 반환
	}
	Node<T>* GetTail()					//맨끝 노드(마지막에 추가된 노드) 읽기 메소드
	{
		return Tail;
	}
	void Insert(T data)							//추가 메소드, 노드에 데이터를 저장하고 리스트에 노드 추가
	{
		Node<T> * node = new Node<T>(data);		//매개변수로 받은 데이터를 새로운 노드를 할당하여 저장
		Tail->SetLink(node);					//테일노드(마지막으로 받은 데이터노드)의 다음에 이어 붙여준다
		Tail = node;							//테일은 현재 받은 노드를 가리키게 됨
	}
	void Delete(T data)							//삭제 메소드
	{
		Node<T> * p = Head->GetLink();			//첫번째 노드를 임시 노드 p에 저장
		Node<T> * prev = Head;					//그 전 노드를 알기위한 임시 노드 prev
		while (p != nullptr)
		{
			if (p->GetData() == data)			//데이터가 일치한다면?
			{
				prev->SetLink(p->GetLink());	//그 전 노드와 현재 일치한 노드의 다음 노드를 이어붙인다
				if (p->GetLink() == nullptr)	//마지막 노드인 경우
				{
					Tail = prev;				//그 전 노드가 테일이 된다
				}
				delete p;						//노드 삭제
				break;
			}
			prev = p;							//전의 노드가 현재 노드가 되고
			p = p->GetLink();					//현재 노드였던 p가 다음 노드를 가리키게 된다
		}
	}
};