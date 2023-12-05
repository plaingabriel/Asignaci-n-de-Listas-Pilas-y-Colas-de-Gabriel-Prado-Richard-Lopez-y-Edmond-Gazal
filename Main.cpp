#include "Lista.h"
#include <iostream>

using namespace std;

void static menuConvertirLista(Lista* lista) {
	int opc;

	do {
		cout << "Elija una de las opciones: \n";
		cout << "1 - Convertir a Lista Simple\n";
		cout << "2 - Convertir a Lista Doble\n";
		cout << "3 - Convertir a Lista Circular Simple\n";
		cout << "4 - Convertir a Lista Circular Doble\n";
		cout << "5 - Volver\n";

		cin >> opc;

		switch (opc) {
		case 1:
			lista->convertir(opc);
			return;
			break;

		case 2:
			lista->convertir(opc);
			return;
			break;

		case 3:
			lista->convertir(opc);
			return;
			break;

		case 4:
			lista->convertir(opc);
			return;
			break;

		case 5:
			cout << "Saliendo del menu...\n";
			break;

		default:
			cout << "Opcion invalida\n";
			break;
		}
	} while (opc != 5);
}

void static menuCambiarModo(Lista* lista) {
	int opc;

	do {
		cout << "Elija una de las opciones: \n";
		cout << "1 - Cambiar de Cola a Pila\n";
		cout << "2 - Cambiar de Pila a Cola\n";
		cout << "3 - Volver\n";

		cin >> opc;

		switch (opc) {
		case 1:
			lista->convertir(5);
			return;
			break;

		case 2:
			lista->convertir(6);
			return;
			break;

		case 3:
			cout << "Saliendo del menu...\n";
			break;

		default:
			cout << "Opcion invalida\n";
			break;
		}
	} while (opc != 3);
}

void menuConvertir(Lista* lista) {
	int opc;

	do {

		cout << "Elija que quiere hacer: \n";
		cout << "1 - Convertir Tipo de Lista \n";
		cout << "2 - Convertir a pila/cola\n";
		cout << "3 - Volver\n";
		cin >> opc;

		switch (opc) {

		case 1:

			menuConvertirLista(lista);
			break;

		case 2:

			menuCambiarModo(lista);
			break;

		case 3:

			cout << "Saliendo del menu...\n";
			break;

		default:

			cout << "Opcion invalida. Por favor, intente de nuevo\n";
			break;
		}

	} while (opc != 3);
}

void static subMenu(Lista* lista) {
	int opc;

	do {
		cout << "\nTipo de lista: " + lista->configuracion() + "\n" << endl;
		cout << "Escoja una de las siguientes opciones:\n";
		cout << "1 - Convertir:\n";
		cout << "2 - Agregar:\n";
		cout << "3 - Eliminar:\n";
		cout << "4 - Mostrar: \n";
		cout << "5 - Salir:\n";

		cin >> opc;

		switch (opc) {
		case 1:

			menuConvertir(lista);
			break;

		case 2:

			lista->PUSH();
			break;

		case 3:

			lista->POP();
			break;

		case 4:
			lista->mostrarLista();
			break;

		case 5:

			cout << "Saliendo del menu...\n";
			break;

		default:

			cout << "Opcion incorrecta. Por favor, intente de nuevo\n";
			break;
		}

	} while (opc != 5);
}

void static menu() {
	int opc;

	do {

		cout << "Escriba el numero de la opcion que desee ingresar:\n";
		cout << "1 - Crear Lista\n";
		cout << "2 - Salir del Programa\n";

		cin >> opc;

		switch (opc) {
		case 1: {

			Lista* lista = new Lista();
			subMenu(lista);
			break;
		}

		case 2:

			cout << "Cerrando el programa...\n";
			break;

		default:

			cout << "Opcion incorrecta. Por favor, intente de nuevo\n";
			break;
		}

	} while (opc != 2);
}

int main(int argc, char const* argv[]) {
	menu();

	return 0;
}