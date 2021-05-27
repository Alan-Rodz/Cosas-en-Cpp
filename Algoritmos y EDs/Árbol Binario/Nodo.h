#pragma once
#include <queue>
#include <iostream>

using std::cout;
using std::endl;
using std::queue;

class Nodo
{
public:
	int informacion;
	Nodo* izquierda;
	Nodo* derecha;

	//Constructor con parámetros
	Nodo(int valor);

	//Constructor sin parámetros
	Nodo();
};

//Función que crea un nuevo nodo y regresa un puntero a él
Nodo* crearNodo(int informacion);

//Función que inserta un nodo al árbol binario, recibe un puntero al nodo raiz
Nodo* insertarNodo(Nodo* raiz, int valor);

//Función que sirve para borrar un nodo del árbol binario
//Hacemos esto asegurándonos de que se haga más pequeño desde abajo
//(Es decir, el nodo borrado es remplazado por el nodo que esté más abajo hasta la derecha)
//Ejemplos:
/*
Borrar 10 en el siguiente arbol
	10
	/ \
  20   30
Se vuelve:
  30
 /
20


Borrar 20 en el siguiente arbol
	10
   /  \
 20     30
          \
           40
Se vuelve:
	10
   /  \
 40    30
*/
//Como parámetros recibe el nodo raíz y el nodo más profundo
//Esta función es usada por la función general para borrar
void borrarNodoMasProfundo_y_a_laDerecha(Nodo* raiz, Nodo* d_nodo);

//Función para borrar una llave determinada del árbol binario
Nodo* borrar(Nodo* raiz, int llave);

//Función que sirve para imprimir los elementos del árbol en inorder
void inorder(Nodo* temporal);