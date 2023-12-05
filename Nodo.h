#pragma once
#include <string>
using namespace std;

class Nodo {

	string nombre, tlf;

	Nodo* sig;

	Nodo* prev;

public:
	Nodo(string nombre, string tlf);

	void setSig(Nodo* nodo);

	void setPrev(Nodo* nodo);

	string getNombre();

	string getTlf();

	Nodo* getSig();

	Nodo* getPrev();
};
