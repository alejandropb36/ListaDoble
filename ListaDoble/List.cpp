//
// Lista doblemente ligada usando template
// Autor: Alejandro Ponce
// Correo: alexponce36@hotmail.com
// Este codigo es libre
// List.cpp
//
#include "List.h"

template <class T1>
List<T1>::List()
{
	_begin = _end = nullptr;
	_size = 0;
}

template <class T1>
List<T1>::~List()
{
}

template <class T1>
bool List<T1>::Empty()
{
	if (_begin)
		return false;
	return true;
}

template <class T1>
void List<T1>::Push_front(T1 data) 
{
	Node<T1>* NewItem = new Node<T1>(data);

	if (Empty()) 
		_begin = _end = NewItem;
	else
	{
		NewItem->next = _begin;
		_begin->before = NewItem;
		_begin = NewItem;
	}
	_size++;
}

template <class T1>
void List<T1>::Push_back(T1 data)
{
	Node<T1>* NewItem = new Node<T1>(data);

	if (Empty())
		_begin = _end = NewItem;
	else 
	{
		NewItem->before = _end;
		_end->next = NewItem;
		_end = NewItem;
	}
	_size++;
}

template <class T1>
void List<T1>::Add_position(T1 data, int pos)
{
	if (pos <= _size)
	{
		if (pos == 0)
			Push_front(data);
		else if (pos == _size)
			Push_back(data);
		else
		{
			Node<T1>* NewItem = new Node<T1>(data);
			Node<T1>* aux = _begin;

			for (int i = 0; i < pos - 1; i++)
				aux = aux->next;

			NewItem->next = aux->next;
			aux->next->before = NewItem;
			NewItem->before = aux;
			aux->next = NewItem;
			if (aux == _end)
				_end = NewItem;
			_size++;
		}
	}
	else
		std::cout << "Invalid position!" << std::endl;
}

template <class T1>
void List<T1>::Add_norepeat(T1 data)
{
	if (!Search(data))
	{
		Push_back(data);
	}
}

template <class T1>
void List<T1>::Add_sortA(T1 data)
{
	Node<T1>* aux = _begin;

	if (!Empty())
	{
		while (aux)
		{
			if (aux->data < data)
				aux = aux->next;
			else
				break;
			
		}
		if (aux == _begin)
		{
			Push_front(data);
		}
		else if (!aux)
		{
			Push_back(data);
		}
		else
		{
			Node<T1>* NewItem = new Node<T1>(data);

			aux->before->next = NewItem;
			NewItem->before = aux->before;
			NewItem->next = aux;
			aux->before = NewItem;
			_size++;
		}
	}
	else
	{
		Push_front(data);
	}
}


/*
template <class T1>
void List<T1>::Add_sortD(T1 data)
{
	std::cout << "El metodo aun no funciona" << std::endl;
}*/

template <class T1>
Node<T1>* List<T1>::Search(T1 data)
{
	if (!Empty())
	{
		Node<T1>* aux = _begin;

		while (aux)
		{
			if (aux->data == data)
				return aux;
			aux = aux->next;
		}
	}
	return nullptr;
}

template <class T1>
void List<T1>::Pop_back()
{
	Node<T1>* aux = _end;
	if (aux == _begin)
		_begin = nullptr;
	_end = _end->before;
	_end->next = nullptr;
	delete(aux);
	_size--;
}

template <class T1>
void List<T1>::Pop_front()
{
	Node<T1>* aux = _begin;
	if (aux == _end)
		_end = nullptr;
	_begin = _begin->next;
	_begin->before = nullptr;
	delete(aux);
	_size--;
}

template <class T1>
void List<T1>::Remove(T1 data)
{
	Node<T1>* aux = Search(data);
	if (aux)
	{
		if (aux == _begin)
			Pop_front();
		else if (aux == _end)
			Pop_back();
		else
		{
			aux->before->next = aux->next;
			aux->next->before = aux->before;
			delete(aux);
			_size--;
		}
	}
	else
		std::cout << "Invalid data!" << endl;
}

template <class T1>
void List<T1>::Remove_all()
{
	while (_begin)
	{
		Node<T1>* aux = _begin;
		_begin = _begin->next;
		delete (aux);
	}
	_end = nullptr;
	_size = 0;
}

template <class T1>
T1 List<T1>::Front()
{
	return _begin->data;
}

template <class T1>
T1 List<T1>::Back()
{
	return _end->data;
}

template <class T1>
Node<T1>* List<T1>::Front_node()
{
	return _begin;
}

template <class T1>
Node<T1>* List<T1>::Back_node()
{
	return _begin;
}

template <class T1>
int List<T1>::Size()
{
	return _size;
}

template <class T1>
T1* List<T1>::operator[](int pos)
{
	if (pos < _size && pos >= 0)
	{
		Node<T1>* aux = _begin;
		for (int i = 0; i < pos; i++)
			aux = aux->next;
		return &aux->data;
	}
	else
		return nullptr;
}



template <class T1>
void List<T1>::quicksort()
{
	if (!Empty())
	{
		_quicksort(0, _size - 1);
	}
	else
		cout << "Empty list!" << endl;

}

template <class T1>
void List<T1>::swap(int ind1, int ind2)
{
	T1 aux;
	aux = *this->operator[](ind1);
	Search(*this->operator[](ind1))->setData(*this->operator[](ind2));
	Search(*this->operator[](ind2))->setData(aux);
}

template <class T1>
void List<T1>::_quicksort(int start, int endd)
{
	int izq, der, pivote;
	bool bandera = true;
	izq = start;
	der = endd;
	pivote = start;

	while (bandera)
	{
		bandera = false;
		while ((*this->operator[](pivote) <= *this->operator[](der)) && (pivote != der))
		{
			der--;
		}
		if (pivote != der)
		{
			swap(pivote, der);
			pivote = der;
			while ((*this->operator[](pivote) >= *this->operator[](izq)) && (pivote != izq))
			{
				izq++;
			}
			if (pivote != izq)
			{
				bandera = true;
				swap(pivote, izq);
				pivote = izq;
			}
		}
	}
	if ((pivote - 1) > start)
	{
		_quicksort(start, pivote - 1);
	}
	if (endd > (pivote + 1))
	{
		_quicksort(pivote + 1, endd);
	}
}