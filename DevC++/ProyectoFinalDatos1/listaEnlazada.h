#pragma once

#include <stdbool.h>

typedef struct _nodo {
	void *datos;
	struct _nodo *siguiente;
	struct _nodo *anterior;

} Nodo;

typedef struct {
	int contador;
	int tamano;
	Nodo *cabeza;
	Nodo *cola;
} Lista;	

/* Función para las iteraciones. */
typedef bool(*FuncionParaIterador)(int indice, Nodo *nodo);

/* Función para comparar. */
typedef bool(*FuncionComparador)(void *valor, Nodo *nodo);


Lista* lista_crear(int datosSize);
void lista_insertar(Lista *lista, void *datos);
Nodo* lista_borrar(Lista* lista, void* datos, FuncionComparador comparador);
bool lista_contiene(Lista *lista, void *datos, FuncionComparador comparador);
Nodo* lista_buscar(Lista *lista, void *datos, FuncionComparador comparador);
void lista_iterar(Lista *lista, FuncionParaIterador funcionParaIterador);

