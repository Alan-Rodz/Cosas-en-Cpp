#include "Nodo.h"
#include "stdio.h"
#include "stdlib.h"
#include "iostream"

//Diferencias entre arreglos y singly linked lists:
/*
	1. En el arreglo los datos tienen que tener tipo similar.
	2. En el arreglo se puede acceder por �ndice mientras que en la singly linked list se tiene que iniciar desde la cabeza.
	3. En el arreglo el tiempo de acceso es r�pido, en la singly linked list es linear.
	4. En arreglos, insertar y borrar es lento. En singly linked list, insertar y borrar es r�pido.
	5. Los arreglos son de tama�o definido. Las singly linked list reciben alocaci�n de memoria durante la ejecuci�n. 
	6. En arreglos los elementos est�n contiguos en memoria. En la singly linked list la locaci�n es aleatoria en memoria.
	7. Los arreglos requieren menos memoria que una singly linked list.
	8. Sin embargo, el arreglo usa memoria de manera no eficiente, mientras que la singly linked list la usa de manera eficiente.

	Por tanto las ventajas principales de la singly linked list frente a un arreglo son:
	1. Tama�o din�mico.
	2. Facilidad para a�adir y borrar elementos.

	Las desventajas principales de la singly linked list frente a un arreglo son:
	1. No se permite el acceso aleatorio a los elementos, pues debe ser un acceso secuencial. No podemos hacer b�squeda binaria.
	2. Se requiere espacio de memoria adicional para los punteros de cada nodo de la singly linked list. 
	3. Los arreglos tienen mejor localidad-cach� y esto puede tener un gran efecto en el desempe�o.
*/

//Primer uso de singly linked list muy b�sica
/*
int main()
{
	Nodo* cabeza = NULL;
	Nodo* segundo = NULL;
	Nodo* tercero = NULL;

	//Ponemos los 3 nodos en el heap
	cabeza = new Nodo();
	segundo = new Nodo();
	tercero = new Nodo();

	//Ahora el primer nodo contiene informaci�n y est� ligado al segundo
	cabeza->informacion = 1;
	cabeza->siguienteNodo = segundo;

	//El segundo nodo contiene informaci�n y est� ligado al tercero
	segundo->informacion = 2;
	segundo->siguienteNodo = tercero;

	//El tercer nodo contiene informaci�n y est� ligado a NULL
	tercero->informacion = 3;
	tercero->siguienteNodo = NULL;

	//Imprimimos los contenidos de nuestra singly linked list
	imprimirLista(cabeza);
}
*/

//Segundo uso de singly linked list con m�todos m�s elaborados
/*
int main()
{
	//Creamos la cabeza de la singly linked list
	Nodo* cabeza = NULL;

	//6->NULL
	insertarAlFinal(&cabeza, 6);

	//7->6->NULL
	nodoAlFrenteDeLaLista(&cabeza, 7);

	//1->7->6->NULL
	nodoAlFrenteDeLaLista(&cabeza, 1);

	//1->7->6->4->NULL
	insertarAlFinal(&cabeza, 4);

	//1->8->7->6->4->NULL
	insertarDespuesDe(cabeza->siguienteNodo, 8);

	//Imprimimos la lista
	std::cout << "La lista creada es: " << std::endl;
	imprimirLista(cabeza);

	return 0;
}
*/

//Tercer uso de singly linked list con m�todo para borrar primera ocurrencia de una llave y borrar nodo espec�fico
/*
int main()
{
	Nodo* cabeza = NULL;

	insertarAlFinal(&cabeza, 7);
	insertarAlFinal(&cabeza, 1);
	insertarAlFinal(&cabeza, 3);
	insertarAlFinal(&cabeza, 2);

	std::cout << "Singly linked list creada: " << std::endl;
	imprimirLista(cabeza);

	std::cout << "\n";

	borrarPrimeraOcurrencia(&cabeza, 1);
	std::cout << "Singly linked list despues de borrar 1: " << std::endl;
	imprimirLista(cabeza);

	borrarNodo(&cabeza, 0);
	std::cout << "Singly linked list despues de borrar 7: " << std::endl;
	imprimirLista(cabeza);

	return 0;
}
*/

//Cuarto uso de singly linked list con m�todo para borrar toda la lista y para obtener el # de nodos, buscar nodos, bubble sort
int main()
{
	Nodo* cabeza = NULL;
	insertarAlFinal(&cabeza, 1);
	insertarAlFinal(&cabeza, 4);
	insertarAlFinal(&cabeza, 1);
	insertarAlFinal(&cabeza, 12);
	insertarAlFinal(&cabeza, 1);
	insertarAlFinal(&cabeza, 100);

	imprimirLista(cabeza);
	std::cout << "\n";
	std::cout << cuentaIterativa(cabeza);
	std::cout << "\n";
	std::cout << cuentaRecursiva(cabeza);
	std::cout << "\n";
	std::cout << buscarIterativo(cabeza, 12) << std::endl;
	std::cout << buscarRecursivo(cabeza, 12) << std::endl;
	std::cout << buscarIndiceRecursivo(cabeza, 1) << std::endl;
	std::cout << contarNumeroVeces(cabeza, 1) << std::endl;
	std::cout << obtenerUltimoPuntero(cabeza) << std::endl;
	std::cout << obtenerUltimoContenido(cabeza) << std::endl;
	bubbleSort(cabeza);
	imprimirLista(cabeza);

	borrarLista(&cabeza);
}