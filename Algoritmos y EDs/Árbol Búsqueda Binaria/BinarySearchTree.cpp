#include <iostream>
#include "NodoBST.h"

int main()
{
	NodoBST b, * raiz = nullptr;
	raiz = b.insertar(raiz, 50);
	b.insertar(raiz, 30);
	b.insertar(raiz, 20);
	b.insertar(raiz, 40);
	b.insertar(raiz, 70);
	b.insertar(raiz, 60);
	b.insertar(raiz, 80);

	cout << "-----------------------------" << endl;
	cout << "Nodos originales " << endl;
	b.inorder(raiz);
	cout << "-----------------------------" << endl;
	cout << "Borramos 20 " << endl;
	raiz = b.borrarNodo(raiz, 20);	
	b.inorder(raiz);
	cout << "-----------------------------" << endl;
	cout << "Borramos 30 " << endl;
	raiz = b.borrarNodo(raiz, 30);
	b.inorder(raiz);
	cout << "-----------------------------" << endl;
	cout << "Borramos 50 " << endl;
	raiz = b.borrarNodo(raiz, 50);
	b.inorder(raiz);
	cout << "-----------------------------" << endl;
	return 0;
}