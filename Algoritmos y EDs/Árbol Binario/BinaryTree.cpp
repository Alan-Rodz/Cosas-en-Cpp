#include <iostream>
#include "Nodo.h"

using std::cout;
using std::endl;

// Versión 1 que muestra cómo funcionan los árboles binarios 
//int main()
//{
//	Nodo* raiz = new Nodo(1);
//
//	/*       1 
//            / \ 
//          NULL NULL 
//    */
//
//    raiz->izquierda = new Nodo(2);
//    raiz->derecha = new Nodo(3);
//
//    /*
//          1 
//         / \ 
//       2     3 
//      / \   /  \ 
//   NULL NULL NULL NULL 
//    */
//
//    raiz->izquierda->izquierda = new Nodo(4);
//
//    /*
//               1 
//            /     \ 
//           2       3 
//          / \     / \ 
//         4 NULL NULL NULL 
//        / \ 
//     NULL NULL 
//    */
//
//    return 0;
//}


//Versión 2 que usa árboles binarios
int main()
{
	Nodo* raiz = crearNodo(10);
	raiz->izquierda = crearNodo(11);
	raiz->izquierda->izquierda = crearNodo(7);
	raiz->derecha = crearNodo(9);
	raiz->derecha->izquierda = crearNodo(15);
	raiz->derecha->derecha = crearNodo(8);

	/*
			10
	       /  \
	      11   9
		 /    / \
		7    15  8
	*/

	cout << "Recorrido inorder antes de insertar en la raiz" << endl;
	inorder(raiz);
	cout << endl;

	int llave = 12;
	raiz = insertarNodo(raiz, llave);

	/*
			10
		   /	\
		  11	  9
		 /  \    / \
		7   12  15  8
	*/

	cout << "Recorrido inorder despues de insertar en la raiz" << endl;
	inorder(raiz);
	cout << endl;

	cout << "Recorrido inorder despues de borrar 11 del arbol" << endl;
	raiz = borrar(raiz, 11);

	/*
			10
		   /	\
		  8	      9
		 /  \    /
		7   12  15
	*/

	inorder(raiz);
	cout << endl;


}