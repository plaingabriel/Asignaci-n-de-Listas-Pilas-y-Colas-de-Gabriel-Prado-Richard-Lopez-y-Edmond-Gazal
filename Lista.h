#pragma once
#include "Nodo.h"

class Lista {

	static const int LONGITUDNUMERO = 11;
	bool doble, pila, circular;

	Nodo* cabeza;

public:
	Lista();

	Lista(bool, bool, bool);

	Nodo* crearNodo();

	void PUSH();

	void POP();

	void convertir(int opc);

	void eliminarUltimo();

	void eliminarPrimero();

	void mostrarLista();

	void actualizar();

	string configuracion();
};
