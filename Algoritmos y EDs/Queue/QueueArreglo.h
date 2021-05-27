#pragma once
#include <iostream>
using std::cout;
using std::endl;

class QueueArreglo
{
public:
	int frente, atras, tamanio;
	unsigned capacidad;
	int* arreglo;
};


QueueArreglo* crearQueue(unsigned capacidad);

int estaLleno(QueueArreglo* queue);

int estaVacio(QueueArreglo* queue);

void enqueue(QueueArreglo* queue, int elemento);

int dequeue(QueueArreglo* queue);

int frente(QueueArreglo* queue);

int atras(QueueArreglo* queue);
