#include "Nodo.h"
#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include <cassert>

//Esta funcion imprime los contenidos de la singly linked list a partir del nodo que recibe
void imprimirLista(Nodo* nodoInicial)
{
	while (nodoInicial != NULL)
	{
		std::cout << nodoInicial->informacion << " ";
		nodoInicial = nodoInicial->siguienteNodo;
	}
};

//Método para añadir nodo al frente de la lista (nueva cabeza)
//Recibe un puntero hacia otro puntero (**) y la nueva información (int)
//La complejidad es O(1)
void nodoAlFrenteDeLaLista(Nodo** referencia_cabeza, int nueva_informacion)
{
	//1. Alocamos un nuevo nodo, que se volverá la nueva cabeza.
	Nodo* nuevo_nodo = new Nodo();

	//2. Le ponemos la información. 
	nuevo_nodo->informacion = nueva_informacion;

	//3. Lo hacemos la nueva cabeza.
	nuevo_nodo->siguienteNodo = (*referencia_cabeza);

	//4. Hacemos que la cabeza antigua a la cabeza nueva
	(*referencia_cabeza) = nuevo_nodo;

};

//Método para añadir nodo después de un nodo dado 
//La función recibe un puntero hacia un nodo, y el nuevo nodo es insertado después del que esta función recibe
//La complejidad es O(1)
void insertarDespuesDe(Nodo* nodo_anterior, int nueva_informacion)
{
	//1. Checamos si el nodo anterior es NULL
	if (nodo_anterior == NULL)
	{
		std::cout << "El nodo anterior no puede ser NULL";
		return;
	}

	//2. Alocamos el nuevo nodo
	Nodo* nuevo_nodo = new Nodo();

	//3. Le ponemos la información
	nuevo_nodo->informacion = nueva_informacion;

	//4. Hacemos que el siguiente nodo del nuevo nodo sea el siguiente del nodo anterior
	nuevo_nodo->siguienteNodo = nodo_anterior->siguienteNodo;

	//5. Hacemos que el siguiente nodo del nodo anterior sea el nuevo nodo
	nodo_anterior->siguienteNodo = nuevo_nodo;
};

//Método para añadir un nodo al final de la lista
//Recibe un puntero al puntero de la cabeza y un int para la informacion del nuevo nodo
//Complejidad O(n) donde n es el número de elementos en la singly linked list
void insertarAlFinal(Nodo** referencia_cabeza, int nueva_informacion)
{
	//1. Alocamos el nuevo nodo
	Nodo* nuevo_nodo = new Nodo();

	//Usaremos esto en el paso 5
	Nodo* ultimo = *referencia_cabeza;

	//2. Ponemos la informacion en el nuevo nodo
	nuevo_nodo->informacion = nueva_informacion;

	//3. Como este nuevo nodo será insertado al último, su siguienteNodo será NULL
	nuevo_nodo->siguienteNodo = NULL;

	//4. En caso de que la singly linked list esté vacía, hacemos que el nuevo nodo sea la cabeza
	if (*referencia_cabeza == NULL)
	{
		*referencia_cabeza = nuevo_nodo;
		return;
	}

	//5. De otra forma recorremos la singly linked list hasta el último nodo
	while (ultimo->siguienteNodo != NULL)
		ultimo = ultimo->siguienteNodo;

	//6. Cambiamos el siguienteNodo del ultimo nodo a que sea el nuevo nodo
	ultimo->siguienteNodo = nuevo_nodo;
	return;

};


//Dado un puntero hacia el puntero de la cabeza y la llave a eliminar, borra la primera ocurrencia de la llave en la lista
/*  Pasos:
	1. Encontramos el nodo anterior al que queremos borrar
	2. Cambiamos el siguienteNodo del nodo anterior
	3. Liberamos la memoria del nodo que contiene la llave que queremos borrar
*/
void borrarPrimeraOcurrencia(Nodo** referencia_cabeza, int llave)
{
	//Guardamos temporalmente el nodo cabeza
	Nodo* temporal = *referencia_cabeza;
	Nodo* anterior = NULL;

	//Si el nodo de la cabeza tiene la llave que queremos borrar:
	if (temporal != NULL && temporal->informacion == llave)
	{
		//Cambiamos la cabeza
		*referencia_cabeza = temporal->siguienteNodo;

		//Borramos la cabeza antigua
		delete temporal;
		return;
	}

	//De otra manera buscamos la llave que queremos borrar, siendo conscientes del nodo anterior al que contiene la llave, 
	//ya que tenemos que cambiar su siguienteNodo
	while (temporal != NULL && temporal->informacion != llave)
	{
		anterior = temporal;
		temporal = temporal->siguienteNodo;
	}

	//Si la llave no está presente en la singly linked list
	if (temporal == NULL)
		return;

	//Desligamos el nodo anterior de la singly linked list
	anterior->siguienteNodo = temporal->siguienteNodo;

	//Liberamos memoria
	delete temporal;
};

//Para borrar nodos dada su posición
//Si el nodo es la cabeza / raiz simplemente lo borramos. 
//Si está en medio de la lista necesitamos un puntero al nodo anterior al que queremos borrar.
void borrarNodo(Nodo** referencia_cabeza, int posicion)
{
	//Si la lista está vacía
	if (referencia_cabeza == NULL)
		return;

	//Guardamos el nodo
	Nodo* temporal = *referencia_cabeza;

	//Si tenemos que borrar la cabeza;
	if (posicion == 0)
	{
		//Cambiamos la cabeza y liberamos memoria
		*referencia_cabeza = temporal->siguienteNodo;
		delete(temporal);
		return;
	}

	//Buscamos el nodo anterior al que hemos borrado
	for (int i = 0; temporal != NULL && i < posicion - 1; i++)
		temporal = temporal->siguienteNodo;

	//Si la posición es mayor al número de nodos
	if (temporal == NULL || temporal->siguienteNodo == NULL)
		return;

	//Guardamos puntero al siguiente nodo del que vamos a borrar
	Nodo* siguiente = temporal->siguienteNodo->siguienteNodo;

	//Borramos el nodo de la singly linked list
	free (temporal->siguienteNodo);

	//Desligamos el nodo borrado de la singly linked list
	temporal->siguienteNodo = siguiente;
};

//Para borrar toda la singly linked list
void borrarLista(Nodo** referencia_cabeza)
{
	//Derreferenciamos la referencia para obtener la verdadera cabeza
	Nodo* actual = *referencia_cabeza;
	Nodo* siguiente;

	//Recorremos la lista borrando
	while (actual != NULL)
	{
		siguiente = actual->siguienteNodo;
		free(actual);
		actual = siguiente;
	}

	//Derreferenciamos la referencia de la cabeza para afectar a la cabeza real en el caller
	*referencia_cabeza = NULL;
};

//Cuenta el número de nodos en la singly linked list
int cuentaIterativa(Nodo* cabeza)
{
	int cuenta = 0;
	Nodo* actual = cabeza;

	//Recorremos la lista añadiendo a la cuenta
	while (actual != NULL)
	{
		cuenta++;
		actual = actual->siguienteNodo;
	}

	return cuenta;
};

//Cuenta el número de nodos en la singly linked list de manera recursiva
int cuentaRecursiva(Nodo* cabeza)
{
	//Caso base
	if (cabeza == NULL)
		return 0;

	//La cuenta es 1 + lo que quede en la lista
	return 1 + cuentaRecursiva(cabeza->siguienteNodo);
};

//Checa si una llave está presente en la singly linked list
bool buscarIterativo(Nodo* cabeza, int llave)
{
	Nodo* actual = cabeza;
	while (actual != NULL)
	{
		if (actual->informacion == llave)
			return true;

		actual = actual->siguienteNodo;
	}

	return false;
};

//Checa si una llave está presente en la singly linked list
bool buscarRecursivo(Nodo* cabeza, int llave)
{
	//Caso base
	if (cabeza == NULL)
		return false;

	//Si la llave está en el nodo actual
	if (cabeza->informacion == llave)
		return true;

	//Caso recursivo
	return buscarRecursivo(cabeza->siguienteNodo, llave);
};

//Regresa lo que esté en el nodo dado como indice
int buscarIndiceRecursivo(Nodo* cabeza, int indice)
{
	if (cabeza == NULL)
		return -1;
	
	int cuenta = 0;

	//Caso base
	if (cuenta == indice)
		return cabeza->informacion;

	//Si no, seguimos de manera recursiva
	return buscarIndiceRecursivo(cabeza->siguienteNodo, indice - 1);
};

//Cuenta el numero de veces que ocurre el indice en la singly linked list
int contarNumeroVeces(Nodo* cabeza, int indice)
{
	Nodo* actual = cabeza;
	int cuenta = 0;
	while (actual != NULL)
	{
		if (actual->informacion == indice)
			cuenta++;
		actual = actual->siguienteNodo;
	}
	return cuenta;
};

//Regresa el ultimo elemento de la lista a partir del nodo actual recibido
Nodo* obtenerUltimoPuntero(Nodo* actual)
{
	while (actual != NULL && actual->siguienteNodo != NULL)
		actual = actual->siguienteNodo;

	return actual;
};

//Regresa el contenido del ultimo nodo de la lista
int obtenerUltimoContenido(Nodo* actual)
{
	while (actual != NULL && actual->siguienteNodo != NULL)
		actual = actual->siguienteNodo;
	return actual->informacion;
};

//Bubble sort para singly linked list
void bubbleSort(Nodo* cabeza)
{
	Nodo* actual1 = cabeza;
	Nodo* actual2 = cabeza;

	for (int i = 0; i < cuentaIterativa(cabeza); i++)
	{
		for (int j = 0; j < cuentaIterativa(cabeza); j++)
		{
			if (actual1->informacion < actual2->informacion)
			{
				int temporal = actual1->informacion;
				actual1->informacion = actual2->informacion;
				actual2->informacion = temporal;
			}
			actual2 = actual2->siguienteNodo;
		}
		actual2 = cabeza;
		actual1 = cabeza->siguienteNodo;
		for (int k = 0; k < i; k++)
			actual1 = actual1->siguienteNodo;
	}
};