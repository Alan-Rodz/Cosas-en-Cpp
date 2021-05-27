#include "Nodo.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>

//Función para generar nuevos nodos
Nodo* obtenerNuevoNodo(int informacion)
{
	Nodo* temporal = new Nodo;
	temporal->informacion = informacion;
	temporal->anterior = temporal->siguiente = NULL;
	return temporal;
};

//Función para insertar al inicio de la DLL
void push(Nodo** referencia_cabeza, int nueva_informacion)
{
	Nodo* temporal = obtenerNuevoNodo(nueva_informacion);
	temporal->siguiente = *referencia_cabeza;
	(*referencia_cabeza)->anterior = temporal;
	(*referencia_cabeza) = temporal;
};

//Función para insertar despues de un determinado nodo
/*
	Pasos:
	1. Checamos si el nodo anterior es NULL
	2. Alocamos memoria para el nuevo nodo y asignamos información
	3. Hacemos que el siguiente del nuevo nodo sea el siguiente del nodo anterior
	4. Hacemos que el siguiente del nodo anterior sea el nuevo nodo
	5. Hacemos que el anterior del nuevo nodo sea el nodo anterior
	6. Hacemos que el nodo siguiente del nuevo nodo, en su campo "anterior", apunte al nuevo nodo
*/
void insertarDespuesDe(Nodo* nodo_anterior, int nueva_informacion)
{
	//1.
	if (nodo_anterior == NULL)
	{
		std::cout << "Se requiere un nodo anterior que no sea NULL" << std::endl;
		return;
	}
	//2.
	Nodo* nuevo_nodo = new Nodo;
	nuevo_nodo->informacion = nueva_informacion;
	//3. 
	nuevo_nodo->siguiente = nodo_anterior->siguiente;
	//4. 
	nodo_anterior->siguiente = nuevo_nodo;
	//5. 
	nuevo_nodo->anterior = nodo_anterior;
	//6. 
	if (nuevo_nodo->siguiente != NULL)
		nuevo_nodo->siguiente->anterior = nuevo_nodo;
};

//Función para insertar un nodo al final de la lista
/*
	Pasos:
	1. Alocamos memoria y asignamos informacion al nuevo nodo
	2. Hacemos, de manera temporal, que el ultimo nodo apunte a la cabeza
	3. Como el nuevo nodo será el ultimo, hacemos que su siguiente sea NULL
	4. Checamos si la lista esta vacia y si si lo esta, hacemos que el nuevo nodo sea la cabeza de la lista
	5. De otra forma recorremos toda la lista hasta llegar al ultimo nodo
	6. Hacemos que el siguiente del ultimo sea igual al nuevo nodo
	7. Hacemos que el anterior del nuevo nodo apunte a ultimo
*/
void insertarAlFinal(Nodo** referencia_cabeza, int nueva_informacion)
{
	//1.
	Nodo* nuevo_nodo = new Nodo;
	nuevo_nodo->informacion = nueva_informacion;

	//2. 
	Nodo* ultimo = *referencia_cabeza;

	//3.
	nuevo_nodo->siguiente = NULL;

	//4. 
	if (*referencia_cabeza == NULL)
	{
		nuevo_nodo->anterior = NULL;
		*referencia_cabeza = nuevo_nodo;
		return;
	}

	//5. 
	while (ultimo->siguiente != NULL)
		ultimo = ultimo->siguiente;

	//6.
	ultimo->siguiente = nuevo_nodo;

	//7. 
	nuevo_nodo->anterior = ultimo;
	return;
};

//Función para imprimir los contenidos de la lista a partir de un nodo determinado
void imprimirHaciaAdelante(Nodo* nodoInicial)
{
	Nodo* ultimo;

	//Recorremos a partir del nodo inicial
	while (nodoInicial != NULL)
	{
		std::cout << nodoInicial->informacion << std::endl;
		ultimo = nodoInicial;
		nodoInicial = nodoInicial->siguiente;
	}

	if (nodoInicial == NULL)
		std::cout << "NULL" << std::endl;
}

//Función para reversear la DLL
void reversearLista(Nodo** referencia_cabeza)
{
	Nodo* izquierda = *referencia_cabeza, * derecha = *referencia_cabeza;

	//Recorremos la lista entera y hacemos que el siguiente de "derecha" sea "derecha"
	while (derecha->siguiente != NULL)
		derecha = derecha->siguiente;

	//Intercambiamos la información entre izquierda y derecha moviendolos hasta que se junten o se crucen
	while (izquierda != derecha && izquierda->anterior != derecha)
	{
		//Intercambiamos la información entre izquierda y derecha
		//swap(izquierda->informacion, derecha->informacion);

		//Hacemos que el puntero de izquierda avance
		izquierda = izquierda->siguiente;

		//Hacemos que el puntero de derecha avance en el orden contrario
		derecha = derecha->anterior;
	}
};
