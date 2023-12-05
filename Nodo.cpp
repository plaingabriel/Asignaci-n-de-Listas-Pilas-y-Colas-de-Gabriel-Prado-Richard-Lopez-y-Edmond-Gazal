#include "Nodo.h"

Nodo::Nodo(string nombre, string tlf) {
	this->nombre = nombre;
	this->tlf = tlf;
	this->sig = NULL;
	this->prev = NULL;
}

void Nodo::setSig(Nodo* nodo) { this->sig = nodo; }

void Nodo::setPrev(Nodo* nodo) { this->prev = nodo; }

string Nodo::getNombre() { return this->nombre; }

string Nodo::getTlf() { return this->tlf; }

Nodo* Nodo::getSig() { return this->sig; }

Nodo* Nodo::getPrev() { return this->prev; }
