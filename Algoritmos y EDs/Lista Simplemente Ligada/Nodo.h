#pragma once
class Nodo
{
	//Atributos generales de nuestros nodos
public:
	int informacion;
	Nodo* siguienteNodo;
};

//Método para imprimir toda la lista a partir de un nodo inicial
void imprimirLista(Nodo* nodoInicial);

//Método para añadir nodo al frente de la lista (nueva cabeza)
void nodoAlFrenteDeLaLista(Nodo** referencia_cabeza, int nueva_informacion);

//Método para añadir nodo después de un nodo dado 
//La función recibe un puntero hacia un nodo, y el nuevo nodo es insertado después del que esta función recibe
void insertarDespuesDe(Nodo* nodo_anterior, int nueva_informacion);

//Método para añadir un nodo al final de la lista
void insertarAlFinal(Nodo** referencia_cabeza, int nueva_informacion);

//Dada una llave (informacion), borrar la primera ocurrencia de dicha llave en la lista
void borrarPrimeraOcurrencia(Nodo** referencia_cabeza, int llave);

//Para borrar nodos dada su posición
//Si el nodo es la cabeza / raiz simplemente lo borramos. 
//Si está en medio de la lista necesitamos un puntero al nodo anterior al que queremos borrar.
void borrarNodo(Nodo** referencia_cabeza, int posicion);

//Para borrar toda la singly linked list
void borrarLista(Nodo** referencia_cabeza);

//Cuenta el número de nodos en la singly linked list de manera iterativa
int cuentaIterativa(Nodo* cabeza);

//Cuenta el número de nodos en la singly linked list de manera recursiva
int cuentaRecursiva(Nodo* cabeza);

//Checa si una llave está presente en la singly linked list
bool buscarIterativo(Nodo* cabeza, int llave);

//Checa si una llave está presente en la singly linked list
bool buscarRecursivo(Nodo* cabeza, int llave);

//Regresa lo que esté en el nodo dado como indice
int buscarIndiceRecursivo(Nodo* cabeza, int indice);

//Cuenta el numero de veces que ocurre el indice en la singly linked list
int contarNumeroVeces(Nodo* cabeza, int indice);

//Regresa un puntero hacia el ultimo elemento de la lista a partir del nodo actual recibido
Nodo* obtenerUltimoPuntero(Nodo* actual);

//Regresa el contenido del ultimo nodo de la lista
int obtenerUltimoContenido(Nodo* actual);

//Bubble sort para singly linked list
void bubbleSort(Nodo* cabeza);