//
// prueba de lista doblemente ligada usando template
// Autor: Alejandro Ponce
// Correo: alexponce36@hotmail.com
// Este codigo es libre
// main.cpp
//

#include <iostream>
#include "List.h"
#include "List.cpp"

using namespace std;

int main() {
	List<int> lista;
	
	lista.Push_back(7);
	lista.Push_back(9);
	lista.Push_back(6);
	lista.Push_back(1);

	for (int i = 0; i < lista.Size(); i++)
		cout << *lista[i] << "->";

	lista.Add_position(10, 0);
	lista.Add_position(15, 5);
	lista.Add_position(43, 2);
	cout << endl;
	cout << endl;

	for (int i = 0; i < lista.Size(); i++)
		cout << *lista[i] << "->";

	cout << endl;
	cout << endl;

	cout << lista.Front() << endl;
	cout << lista.Back() << endl;

	lista.Remove(43);

	cout << endl;
	cout << endl;

	for (int i = 0; i < lista.Size(); i++)
		cout << *lista[i] << "->";

	cout << endl;
	cout << endl;

	cout << lista.Front() << endl;
	cout << lista.Back() << endl;

	lista.Pop_back();

	cout << endl;

	cout << lista.Front() << endl;
	cout << lista.Back() << endl;

	lista.Pop_front();

	cout << endl;

	cout << lista.Front() << endl;
	cout << lista.Back() << endl;

	lista.Push_front(46);
	lista.Push_back(55);
	cout << endl;

	cout << lista.Front() << endl;
	cout << lista.Back() << endl;

	cout << endl;

	for (int i = 0; i < lista.Size(); i++)
		cout << *lista[i] << "->";

	cout << endl;
	cout << endl;

	lista.quicksort();

	for (int i = 0; i < lista.Size(); i++)
		cout << *lista[i] << "->";

	cout << endl;
	cout << endl;


	if (lista.Search(46))
		cout << lista.Search(46)->getData() << endl;
	else
		cout << " Error el dato no existe " << endl;

	cout << endl;

	if (lista.Search(11))
		cout << lista.Search(11)->getData() << endl;
	else
		cout << " Error el dato no existe " << endl;
	


	cin.get();
	return 0;
}
