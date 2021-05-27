#include <iostream>
#include "Nodo.h"

/*
  
    Doubly Linked List

    Ventajas sobre la singly linked list:
    La DLL puede ser recorrida en ambas direcciones
    La operación de borrar en una DLL es más eficiente
    Podemos insertar un nuevo nodo de manera rápida si su posición es anterior a un nodo determinado

    Desventajas sobre la singly linked list:
    Cada nodo de una DLL requiere espacio de memoria extra para el segundo puntero
    Todas las operaciones requieren dicho segundo puntero (más espacio de memoria)

*/

/*
    Aplicaciones de la DLL:
    -Representar un juego de cartas (ya que cada carta tendrá una anterior y una posterior a ella)
    -Representar un historial de búsqueda
    -Puede ser usada para programar otras estructuras de datos como el stack, hash table, o arbol binario
*/

Nodo* cabeza;

int main()
{
    cabeza = obtenerNuevoNodo(5);
    push(&cabeza, 3);
    push(&cabeza, 2);
    insertarDespuesDe(cabeza->siguiente, 1);
    insertarAlFinal(&cabeza, 0);
    imprimirHaciaAdelante(cabeza);
}