#pragma once
#include "ListaCircular.h"
#include <iostream>
#include <stdio.h>

using namespace std;


ListaCircular::ListaCircular()
{
}

void ListaCircular::agregar()
{
	string nombre, tlf; // Provisional

	Nodo* nuevoNodo = new Nodo(nombre, tlf);

	if (this->cabeza == NULL)
	{
		this->cabeza = nuevoNodo;
		return;
	}

	if (this->cabeza->getSig() == NULL)
	{
		if (this->tipo)
		{
			cabeza->setPrev(nuevoNodo);
			nuevoNodo->setPrev(cabeza);
		}

		nuevoNodo->setSig(cabeza);
		this->cabeza->setSig(nuevoNodo);

		return;
	}

	Nodo* temp = this->cabeza;

	while (temp->getSig() != this->cabeza)
	{
		if (this->tipo)
			temp->getSig()->setPrev(temp);

		temp = temp->getSig();
	}

	if (this->tipo)
	{
		nuevoNodo->setPrev(temp);
		this->cabeza->setPrev(nuevoNodo);
	}

	nuevoNodo->setSig(this->cabeza);
	temp->setSig(nuevoNodo);
}

void ListaCircular::eliminar()
{
	Nodo* temp = cabeza, * prev = cabeza;

	if (this->cabeza->getSig() == NULL)
	{
		this->cabeza = NULL;
		return;
	}

	while (temp->getSig() != this->cabeza)
	{
		prev = temp;

		temp = temp->getSig();
	}

	if (prev == this->cabeza)
	{
		if (this->tipo)
			this->cabeza->setPrev(NULL);

		this->cabeza->setSig(NULL);
		delete temp;

		return;
	}

	if (this->tipo)
	{
		temp->getPrev()->setSig(cabeza);
		this->cabeza->setPrev(temp->getPrev());
		delete temp;

		return;
	}

	prev->setSig(cabeza);

	delete temp;

}

void ListaCircular::mostrar()
{
	int i = 0;
	printf("\n\n N.| Nombre        | Numero          \n");
	// Iterate until the node is NULL
	for (Nodo* p = this->cabeza; p != this->cabeza || i == 0; p = p->getSig(), i++)
		printf("%2d | %-15s | %-15s \n", i + 1, p->getNombre().c_str(), p->getTlf().c_str());

	printf("\n");
}
