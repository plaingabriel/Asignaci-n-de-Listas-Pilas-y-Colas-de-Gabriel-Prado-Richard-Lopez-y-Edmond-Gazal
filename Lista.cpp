#include "Lista.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

Lista::Lista() {
	this->cabeza = NULL;
	this->pila = true;
	this->circular = false;
	this->doble = false;
}

Lista::Lista(bool pila, bool circular, bool doble) {
	this->pila = pila;
	this->circular = circular;
	this->doble = doble;
	this->cabeza = NULL;
}

Nodo* Lista::crearNodo() {

	string nombre, tlf;
	bool val = false;
	Nodo* nodo;

	cout << "Escriba un nombre:";
	cin >> nombre;

	do {

		cout << "Escriba el numero de telefono:";
		cin >> tlf;

		val = tlf.length() == LONGITUDNUMERO;

		if (!val)
			cout << "El numero ingresado debe tener " << LONGITUDNUMERO
			<< " digitos.\n";

	} while (!val);

	return nodo = new Nodo(nombre, tlf);
}

void Lista::convertir(int opc) {
	switch (opc) {
	case 1:

		// Lista Simple
		this->doble = false;
		this->circular = false;
		break;

	case 2:

		// Lista Doble
		this->doble = true;
		this->circular = false;
		break;

	case 3:

		// Lista Circular
		this->doble = false;
		this->circular = true;
		break;

	case 4:

		// Lista Circular Doble
		this->doble = true;
		this->circular = true;
		break;

	case 5:

		// Pila
		this->pila = true;
		break;

	case 6:

		// Cola
		this->pila = false;
		break;
	}

	cout << "Conversion realizada\n";
	actualizar();
}

void Lista::PUSH() {

	Nodo* nuevoNodo = crearNodo();

	// Caso: Lista vacia
	if (this->cabeza == NULL) {
		this->cabeza = nuevoNodo;
		return;
	}

	// Caso: Lista circular con un elemento
	if (this->circular) {

		if (this->cabeza->getSig() == NULL) {

			// Caso: Lista doble
			if (this->doble) {
				this->cabeza->setPrev(nuevoNodo);
				nuevoNodo->setPrev(cabeza);
			}
			// Caso: Lista simple
			nuevoNodo->setSig(cabeza);
			this->cabeza->setSig(nuevoNodo);

			return;
		}
	}

	// Caso: Lista no vacia
	Nodo* temp = this->cabeza, * ultimo = NULL;

	// Ultimo elemento si es lista circular
	if (this->circular)
		ultimo = this->cabeza;

	// Recorrer lista hasta el final
	while (temp->getSig() != ultimo) {

		if (this->doble)
			temp->getSig()->setPrev(temp);

		temp = temp->getSig();
	}

	if (this->doble) {
		nuevoNodo->setPrev(temp);

		if (this->circular)
			this->cabeza->setPrev(nuevoNodo);
	}

	if (this->circular)
		nuevoNodo->setSig(this->cabeza);

	temp->setSig(nuevoNodo);
}

void Lista::POP() {

	// Logica de POP
	if (this->pila)
		eliminarUltimo();

	else
		eliminarPrimero();
}

void Lista::eliminarUltimo() {

	if (cabeza == NULL) {
		cout << "La lista ya se encuentra vacia\n";
		return;
	}

	if (this->cabeza->getSig() == NULL) {
		delete cabeza;
		cabeza = NULL;
		return;
	}

	Nodo* aux = cabeza;

	// Caso: Lista circular
	if (this->circular) {

		// Caso: Circular doble
		if (this->doble) {

			// Caso: El ultimo elemento de la lista es el segundo
			if (aux->getSig() == aux->getPrev()) {

				aux = aux->getSig();

				// Eliminar ultimo elemento
				this->cabeza->setPrev(NULL);
				this->cabeza->setSig(NULL);

				delete aux;

				return;
			}

			// Guardar el elemento previo a la cabeza (Ultimo elemento)
			aux = this->cabeza->getPrev();
			aux->getPrev()->setSig(cabeza);

			// Enlazar el penultimo elemento con la cabeza
			this->cabeza->setPrev(aux->getPrev());

			// Borrar ultimo elemento
			aux->setPrev(NULL);
			aux->setSig(NULL);

			delete aux;

			return;

			// Caso: Circular simple
		}
		else {

			// Caso: El ultimo elemento es el segundo
			if (aux->getSig()->getSig() == aux) {

				aux = aux->getSig();

				this->cabeza->setSig(NULL);

				delete aux;

				return;
			}

			// Caso: Llegar hasta el ultimo elemento
			Nodo* tempPrev = this->cabeza;

			aux = aux->getSig();

			// Recorrer la lista
			while (aux->getSig() != cabeza) {

				tempPrev = tempPrev->getSig();
				aux = aux->getSig();
			}

			// Eliminar ultimo elemento
			tempPrev->setSig(cabeza);

			aux->setSig(NULL);

			delete aux;

			return;
		}

		// Listas no circulares
	}
	else {

		// Caso: Enlace doble
		if (this->doble) {

			// Recorrer lista
			while (aux->getSig() != NULL)
				aux = aux->getSig();

			// Eliminar ultimo elemento
			aux->getPrev()->setSig(NULL);
			aux->setPrev(NULL);

			delete aux;

			return;

			// Enlace simple
		}
		else {

			Nodo* temp = aux;

			aux = aux->getSig();

			// Recorrer lista
			while (aux->getSig() != NULL) {
				temp = aux;
				aux = aux->getSig();
			}

			// Eliminar ultimo elemento
			temp->setSig(NULL);

			delete aux;

			return;
		}
	}
}

void Lista::eliminarPrimero() {

	// Caso: Lista vacia
	if (cabeza == NULL) {
		cout << "La lista ya se encuentra vacia\n";
		return;
	}

	// Caso: Lista con un elemento
	if (this->cabeza->getSig() == NULL) {
		delete cabeza;
		cabeza = NULL;
		return;
	}

	if (this->circular) {

		if (this->doble) {

			if (this->cabeza->getPrev() == this->cabeza->getSig()) {

				this->cabeza = cabeza->getSig();
				this->cabeza->setPrev(NULL);

				delete this->cabeza->getSig();

				this->cabeza->setSig(NULL);

				return;
			}

			Nodo* aux = this->cabeza->getPrev();

			this->cabeza = cabeza->getSig();
			aux->setSig(cabeza);

			delete this->cabeza->getPrev();

			this->cabeza->setPrev(aux);

			return;

		}
		else {

			if (this->cabeza == this->cabeza->getSig()->getSig()) {

				this->cabeza = cabeza->getSig();

				delete this->cabeza->getSig();

				this->cabeza->setSig(NULL);

				return;
			}

			Nodo* aux = this->cabeza->getSig();

			while (aux->getSig() != this->cabeza)
				aux = aux->getSig();

			this->cabeza = this->cabeza->getSig();

			delete aux->getSig();

			aux->setSig(this->cabeza);

			return;
		}

	}
	else {

		if (this->doble) {

			this->cabeza = this->cabeza->getSig();
			this->cabeza->getPrev()->setSig(NULL);

			delete this->cabeza->getPrev();

			this->cabeza->setPrev(NULL);

			return;

		}
		else {

			Nodo* aux = this->cabeza;

			this->cabeza = this->cabeza->getSig();

			aux->setSig(NULL);

			delete aux;

			return;
		}
	}
}

void Lista::mostrarLista() {

	if (this->cabeza == NULL) {
		cout << "La lista ya se encuentra vacia\n";
		return;
	}

	printf("%2s | %-15s | %-15s\n", "N°", "Nombre", "Telefono");
	printf("\n");
	Nodo* nodo = this->cabeza, * finDelCiclo = NULL;

	if (this->circular)
		finDelCiclo = this->cabeza;

	for (int i = 0; nodo != finDelCiclo || i == 0; nodo = nodo->getSig(), i++)
		printf("%2d | %-15s | %-15s\n", i + 1, nodo->getNombre().c_str(),
			nodo->getTlf().c_str());
}

void Lista::actualizar() {

	// Asegurarse de que la lista no este vacia
	if (this->cabeza != NULL) {

		// Asegurarse de que haya mas de un elemento
		if (this->cabeza->getSig() != NULL) {

			Nodo* ultimo = this->cabeza;

			// Recorrer cualquier tipo de lista, hasta llegar al ultimo
			while (ultimo->getSig() != NULL && ultimo->getSig() != this->cabeza)
				ultimo = ultimo->getSig();

			// Caso: Lista doble
			if (this->doble) {

				Nodo* aux = cabeza->getSig(), * auxPrev = cabeza;

				// Recorrer la lista doble
				while (aux != ultimo->getSig()) {

					aux->setPrev(auxPrev);
					auxPrev = aux;
					aux = aux->getSig();
				}
			}

			// Caso: Lista circular
			if (this->circular) {

				ultimo->setSig(cabeza);

				if (this->doble)
					cabeza->setPrev(ultimo);

				// Caso: Lista simple
			}
			else {

				ultimo->setSig(NULL);

				if (this->doble)
					cabeza->setPrev(NULL);
			}
		}
	}
}

string Lista::configuracion() {
	string cadena1, cadena2, cadena3;
	cadena1 = (this->pila) ? "PILA" : "COLA";
	cadena2 = (this->circular) ? "CIRCULAR" : "NO CIRCULAR";
	cadena3 = (this->doble) ? "DOBLE" : "SIMPLE";

	return cadena1 + " " + cadena2 + " " + cadena3;
}
