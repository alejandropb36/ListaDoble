//
// Lista doblemente ligada usando template
// Autor: Alejandro Ponce
// Correo: alexponce36@hotmail.com
// Este codigo es libre
// List.h
//
#pragma once

#include <iostream>
#include "Node.h"
#include "Node.cpp"

template <class T1>
class List
{
public:
	List();
	~List();

	bool Empty();
	void Push_front(T1);
	void Push_back(T1);
	void Add_position(T1, int);
	void Add_norepeat(T1);
	void Add_sortA(T1); // Agrega orden acedente. no sirve
	//void Add_sortD(T1); // Agrega orden decendente. no sirve
	Node<T1>* Search(T1);
	void Pop_back();
	void Pop_front();
	void Remove(T1);
	void Remove_all();
	T1 Front();
	T1 Back();
	Node<T1>* Front_node();
	Node<T1>* Back_node();
	int Size();
	T1* operator[](int);

	void quicksort();

protected:
	int _size;

private:
	Node<T1>* _begin;
	Node<T1>* _end;

	void swap(int,int);
	void _quicksort(int,int);
};

