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

	//Constructor con par�metros
	Nodo(int valor);

	//Constructor sin par�metros
	Nodo();
};

//Funci�n que crea un nuevo nodo y regresa un puntero a �l
Nodo* crearNodo(int informacion);

//Funci�n que inserta un nodo al �rbol binario, recibe un puntero al nodo raiz
Nodo* insertarNodo(Nodo* raiz, int valor);

//Funci�n que sirve para borrar un nodo del �rbol binario
//Hacemos esto asegur�ndonos de que se haga m�s peque�o desde abajo
//(Es decir, el nodo borrado es remplazado por el nodo que est� m�s abajo hasta la derecha)
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
//Como par�metros recibe el nodo ra�z y el nodo m�s profundo
//Esta funci�n es usada por la funci�n general para borrar
void borrarNodoMasProfundo_y_a_laDerecha(Nodo* raiz, Nodo* d_nodo);

//Funci�n para borrar una llave determinada del �rbol binario
Nodo* borrar(Nodo* raiz, int llave);

//Funci�n que sirve para imprimir los elementos del �rbol en inorder
void inorder(Nodo* temporal);