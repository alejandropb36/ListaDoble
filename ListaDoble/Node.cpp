//
// Lista doblemente ligada usando template
// Autor: Alejandro Ponce
// Correo: alexponce36@hotmail.com
// Este codigo es libre
// Node.cpp
//
#include "Node.h"


template <class T1>
Node<T1>::Node()
{
	this->next = nullptr;
	this->before = nullptr;
}

template <class T1>
Node<T1>::Node(T1 data)
{
	this->data = data;
	this->next = nullptr;
	this->before = nullptr;
}

template <class T1>
Node<T1>::~Node()
{
}

template <class T1>
void Node<T1>::setData(T1 data)
{
	this->data = data;
}

template <class T1>
void Node<T1>::setNext(Node<T1>* next)
{
	this->next = next;
}

template <class T1>
void Node<T1>::setBefore(Node<T1>* before)
{
	this->before = before;
}

template <class T1>
T1 Node<T1>::getData()
{
	return data;
}

template <class T1>
Node<T1>* Node<T1>::getNext()
{
	return next;
}

template <class T1>
Node<T1>* Node<T1>::getBefore()
{
	return before;
}