#include "StackLLNodo.h"

//Devuelve puntero al nodo nuevo (crea el nuevo nodo y le asigna informacion)
StackLLNodo* nuevoNodo(int informacion)
{
	StackLLNodo* nodoStack = new StackLLNodo();
	nodoStack->informacion = informacion;
	nodoStack->siguiente = NULL;
	return nodoStack;
};

//Nos dice si esta vacio o no el stack. 
int estaVacio(StackLLNodo* raiz)
{
	return !raiz;
};

//Añade nodos al stack
void push(StackLLNodo** raiz, int informacion)
{
	//Obtenemos puntero al nuevo nodo con el metodo nuevoNodo()
	StackLLNodo* nodoStack = nuevoNodo(informacion);

	//Hacemos que el siguiente del nuevo nodo apunte a la raiz y luego que la raiz se vuelva el nuevo nodo
	nodoStack->siguiente = *raiz;
	*raiz = nodoStack;
	cout << informacion << " se ha añadido al stack " << endl;
};

//Remueve el ultimo nodo del stack
int pop(StackLLNodo** raiz)
{
	if (estaVacio(*raiz))
		return INT_MIN;

	StackLLNodo* temporal = *raiz;
	*raiz = (*raiz)->siguiente;
	int popped = temporal->informacion;
	free(temporal);

	return popped;
};

//Nos da lo que contiene el ultimo nodo del stack
int peek(StackLLNodo* raiz)
{
	if (estaVacio(raiz))
		return INT_MIN;

	return raiz->informacion;
};
