//
// Lista doblemente ligada usando template
// Autor: Alejandro Ponce
// Correo: alexponce36@hotmail.com
// Este codigo es libre
// Node.h
//
#pragma once

template <class T1>
class List;

template <class T1>
class Node
{
public:
	Node();
	Node(T1);
	~Node();

	void setData(T1);
	void setNext(Node*);
	void setBefore(Node*);

	T1 getData();
	Node<T1>* getNext();
	Node<T1>* getBefore();

	friend class List<T1>;

private:
	T1 data;
	Node* next;
	Node* before;
};

