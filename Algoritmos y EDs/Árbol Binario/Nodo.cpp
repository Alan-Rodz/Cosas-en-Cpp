#include "Nodo.h"
//Constructor con parámetros
Nodo::Nodo(int valor)
{
	informacion = valor;
	izquierda = nullptr;
	derecha = nullptr;
};

//Constructor sin parámetros
Nodo::Nodo()
{
	informacion = 0;
	izquierda = nullptr;
	derecha = nullptr;
};

//Función que crea un nuevo nodo y regresa un puntero a él
Nodo* crearNodo(int valor)
{
	Nodo* nuevoNodo = new Nodo();
	if (!nuevoNodo)
	{
		cout << "Error de memoria" << endl;
		return NULL;
	}

	nuevoNodo->informacion = valor;
	nuevoNodo->izquierda = nuevoNodo->derecha = nullptr;
	return nuevoNodo;
};

//Función que inserta un nodo al árbol binario, recibe un puntero al nodo raiz
Nodo* insertarNodo(Nodo* raiz, int valor)
{
	//si el árbol está vacío hacemos que el nuevo nodo sea la raiz
	if (raiz == nullptr)
	{
		raiz = crearNodo(valor);
		return raiz;
	}

	//De otra manera hacemos BFS con un queue hasta que encontremos un lugar vacio
	//(un izquierda/derecha) de algún nodo que esté apuntando a NULL
	queue<Nodo*> queue;
	queue.push(raiz);

	while (!queue.empty())
	{
		Nodo* temporal = queue.front();
		queue.pop();
		if (temporal->izquierda != nullptr)
			queue.push(temporal->izquierda);
		else
		{
			temporal->izquierda = crearNodo(valor);
			return raiz;
		}

		if (temporal->derecha != nullptr)
			queue.push(temporal->derecha);
		else
		{
			temporal->derecha = crearNodo(valor);
			return raiz;
		}
	}

	return nullptr;
};

/*
Función que sirve para borrar un nodo del árbol binario
Hacemos esto asegurándonos de que se haga más pequeño desde abajo
(Es decir, el nodo borrado es remplazado por el nodo que esté más abajo hasta la derecha)
Ejemplos:
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
void borrarNodoMasProfundo_y_a_laDerecha(Nodo* raiz, Nodo* d_nodo)
{
	queue<Nodo*> queue;
	queue.push(raiz);

	//Hacemos BFS hasta llegar al ultimo nodo
	Nodo* temporal;
	while (!queue.empty()) 
	{
		temporal = queue.front();
		queue.pop();
		if (temporal == d_nodo) 
		{
			temporal = nullptr;
			delete (d_nodo);
			return;
		}
		if (temporal->derecha) 
		{
			if (temporal->derecha == d_nodo) 
			{
				temporal->derecha = nullptr;
				delete (d_nodo);
				return;
			}
			else
				queue.push(temporal->derecha);
		}

		if (temporal->izquierda) 
		{
			if (temporal->izquierda == d_nodo) 
			{
				temporal->izquierda = nullptr;
				delete (d_nodo);
				return;
			}
			else
				queue.push(temporal->izquierda);
		}
	}
};

//Función para borrar una llave determinada del árbol binario
Nodo* borrar(Nodo* raiz, int llave)
{
	if (raiz == nullptr)
		return nullptr;

	if (raiz->izquierda == nullptr && raiz->derecha == nullptr)
	{
		if (raiz->informacion == llave)
			return nullptr;
		else
			return raiz;
	}
		
	queue<Nodo*> queue;
	queue.push(raiz);
	Nodo* temporal = new Nodo();
	Nodo* nodo_llave = nullptr;

	//Hacemos BFS para encontrar el nodo mas profundo y a la derecha 
	//Así como el nodo que tiene la llave que queremos eliminar
	while (!queue.empty())
	{
		temporal = queue.front();
		queue.pop();
		
		if (temporal->informacion == llave)
			nodo_llave = temporal;

		if (temporal->izquierda)
			queue.push(temporal->izquierda);

		if (temporal->derecha)
			queue.push(temporal->derecha);
	}

	if (nodo_llave != nullptr)
	{
		int x = temporal->informacion;
		borrarNodoMasProfundo_y_a_laDerecha(raiz, temporal);
		nodo_llave->informacion = x;
	}

	return raiz;
};

//Función que sirve para imprimir los elementos del árbol en inorder
void inorder(Nodo* temporal)
{
	if (temporal == nullptr)
		return;

	//Recursividad: Sub-arbol izquierdo, nodo, sub-arbol derecho
	inorder(temporal->izquierda);
	cout << temporal->informacion << " ";
	inorder(temporal->derecha);
};

