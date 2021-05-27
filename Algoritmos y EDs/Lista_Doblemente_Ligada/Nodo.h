#pragma once
class Nodo
{
public:
	int informacion;
	Nodo* siguiente;
	Nodo* anterior;
};

//Funci�n para generar nuevos nodos
Nodo* obtenerNuevoNodo(int informacion);

//Funci�n para insertar al inicio de la DLL
void push(Nodo** referencia_cabeza, int nueva_informacion);

//Funci�n para insertar despues de un determinado nodo
void insertarDespuesDe(Nodo* nodo_anterior, int nueva_informacion);

//Funci�n para insertar un nodo al final de la lista
void insertarAlFinal(Nodo** referencia_cabeza, int nueva_informacion);

//Funci�n para imprimir los contenidos de la lista a partir de un nodo determinado
void imprimirHaciaAdelante(Nodo* nodoInicial);

//Funci�n para reversear la DLL
void reversearLista(Nodo** referencia_cabeza);