#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "listaEnlazada.h"

Lista* lista_crear(int datosSize) {

	Lista* lista = new Lista();
	lista->contador = 0;
	lista->tamano = datosSize;
	lista->cabeza = NULL;
	lista->cola = NULL;
	return lista;
}

void lista_insertar(Lista* lista, void* datos) {	
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->datos = datos;

	if (lista->cabeza == NULL) {
		lista->cabeza = nuevoNodo;
		lista->cola = nuevoNodo;		
	}
	else {
		nuevoNodo->anterior = lista->cola;
		lista->cola->siguiente = nuevoNodo;
		lista->cola = nuevoNodo;
	}

	lista->contador++;
}


Nodo* lista_borrar(Lista* lista, void* datos, FuncionComparador comparador) {

	Nodo* nodo_actual = lista->cabeza;

	while (nodo_actual != NULL) {
		if (comparador(datos, nodo_actual) == true) {
			
			// If único nodo
			if (nodo_actual->anterior == NULL && nodo_actual->siguiente == NULL)
			{
				lista->cabeza = NULL;
				lista->cola = NULL;
			}
			// If cabeza
			else if (nodo_actual->anterior == NULL) {
				lista->cabeza = lista->cabeza->siguiente;				
				lista->cabeza->anterior = NULL;				
			}
			// If cola
			else if (nodo_actual->siguiente == NULL) {
				lista->cola = lista->cola->anterior;
				lista->cola->siguiente = NULL;				
			}
			else {
				nodo_actual->anterior->siguiente = nodo_actual->siguiente;
				nodo_actual->siguiente->anterior = nodo_actual->anterior;
			}
			lista->contador--;
			nodo_actual->siguiente = NULL;
			nodo_actual->anterior = NULL;
			return nodo_actual;
		}
		nodo_actual = nodo_actual->siguiente;
	}
	return NULL;
}


bool lista_contiene(Lista* lista, void* datos, FuncionComparador comparador) {

	Nodo* nodo = lista->cabeza;
	while (nodo != NULL) {
		if (comparador(datos, nodo) == true)
			return true;
		nodo = nodo->siguiente;
	}
	return false;
}

Nodo* lista_buscar(Lista* lista, void* datos, FuncionComparador comparador) {

	Nodo* nodo = lista->cabeza;
	while (nodo != NULL) {
		if (comparador(datos, nodo) == true) {
			return nodo;
		}
		nodo = nodo->siguiente;
	}
	return NULL;
}

void lista_iterar(Lista* lista, FuncionParaIterador funcionParaIterador) {
	int i = 0;
	Nodo* nodo = lista->cabeza;
	while (nodo != NULL) {
		if (!funcionParaIterador(i, nodo))
			return;
		nodo = nodo->siguiente;
		i++;
	}
}
