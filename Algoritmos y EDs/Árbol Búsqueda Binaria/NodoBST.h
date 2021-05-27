#pragma once
#include <iostream>
using std::cout;
using std::endl;

class NodoBST
{
public:
	int informacion;
	NodoBST* izquierda, * derecha;

	//Constructor default
	NodoBST();

	//Constructor con parámetros
	NodoBST(int);

	//Función para insertar
	NodoBST* insertar(NodoBST* raiz, int valor);

	//Recorrido inorder
	void inorder(NodoBST* raiz);

	//Dado un arbol BST y una llave, esta funcion borra la llave y regresa la nueva raiz
	NodoBST* borrarNodo(NodoBST* raiz, int llave);

};



