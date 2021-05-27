#include "NodoBST.h"

//Constructor default
NodoBST::NodoBST() :informacion(0), izquierda(nullptr), derecha(nullptr) {};

//Constructor con parámetros
NodoBST::NodoBST(int valor)
{
	informacion = valor;
	izquierda = derecha = nullptr;
}

//Función para insertar
NodoBST* NodoBST::insertar(NodoBST* raiz, int valor)
{
	//Si la raiz es null insertamos el primer nodo
	if (!raiz)
		return new NodoBST(valor);

	//Insertamos la informacion
	//Insertamos en el nodo derecho si el valor a insertar es mayor que el valor en la raiz
	if (valor > raiz->informacion)
		raiz->derecha = insertar(raiz->derecha, valor);

	//De otra manera insertamos a la izquierda
	else
		raiz->izquierda = insertar(raiz->izquierda, valor);

	//Regresamos la raiz despues de la insercion
	return raiz;

};


//Recorrido inorder
void NodoBST::inorder(NodoBST* raiz)
{
	if (!raiz)
		return;

	inorder(raiz->izquierda);
	cout << raiz->informacion << endl;
	inorder(raiz->derecha);
};

//Dado un arbol BST y una llave, esta funcion borra la llave y regresa la nueva raiz
NodoBST* NodoBST::borrarNodo(NodoBST* raiz, int llave)
{
	//Caso base
	if (raiz == nullptr)
		return raiz;

	//Llamadas recursivas para los nodos anteriores al que tenemos que borrar
	if (raiz->informacion > llave) 
	{
		raiz->izquierda = borrarNodo(raiz->izquierda, llave);
		return raiz;
	}
	else if (raiz->informacion < llave) {
		raiz->derecha = borrarNodo(raiz->derecha, llave);
		return raiz;
	}


	//Llegamos a este punto cuando la raiz es el nodo a borrar
	//Si alguno de sus hijos está vacío:
	if (raiz->izquierda == nullptr) 
	{
		NodoBST* temporal = raiz->derecha;
		delete raiz;
		return temporal;
	}
	else if (raiz->derecha == nullptr) 
	{
		NodoBST* temporal = raiz->izquierda;
		delete raiz;
		return temporal;
	}

	//Si ambos hijos existen
	else 
	{

		NodoBST* padre = raiz;

		//Buscamos al sucesor
		NodoBST* sucesor = raiz->derecha;
		while (sucesor->izquierda != nullptr) 
		{
			padre = sucesor;
			sucesor = sucesor->izquierda;
		}

		//Borramos al sucesor. Como siempre siempre es el hijo izquierdo de su padre, 
		//Podemos hacer su hijo derecho el izquierdo de su padre
		//Si no hay sucesor entonces hacemos que sucesor->derecha sea padre->derecha
		if (padre != raiz)
			padre->izquierda= sucesor->derecha;
		else
			padre->derecha= sucesor->derecha;

		//Copiamos la informacion del sucesor a la raiz
		raiz->informacion = sucesor->informacion;

		// Delete Successor and return root
		delete sucesor;
		return raiz;
	}
};