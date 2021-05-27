#include "QueueArreglo.h"

//Creamos objeto de tipo queue y regresamos un puntero a todo su contenido (después de inicializarlo)
QueueArreglo* crearQueue(unsigned capacidad)
{
	QueueArreglo* queue = new QueueArreglo();
	queue->capacidad = capacidad;
	queue->frente = queue->tamanio = 0;

	queue->atras = capacidad - 1;
	queue->arreglo = new int[(queue->capacidad * sizeof(int))];

	return queue;
}

//El queue esta lleno cuando el tamaño es igual a la capacidad
int estaLleno(QueueArreglo* queue)
{
	return (queue->tamanio == queue->capacidad);
}

//El queue esta vacio si su tamaño es 0
int estaVacio(QueueArreglo* queue)
{
	return (queue->tamanio == 0);
}

//Función para añadir un elemento al queue, cambia atras y tamaño
void enqueue(QueueArreglo* queue, int elemento)
{
	if (estaLleno(queue))
		return;

	queue->atras = (queue->atras + 1) % queue->capacidad;
	queue->arreglo[queue->atras] = elemento;
	queue->tamanio = queue->tamanio + 1;
	cout << "Se ha agregado el elemento " << elemento << " al queue " << endl; 
}

//Funcion para remover un elemento del queue, cambia frente y tamaño
int dequeue(QueueArreglo* queue)
{
	if (estaVacio(queue))
		return INT_MIN;

	int elemento = queue->arreglo[queue->frente];
	queue->frente = (queue->frente + 1) % queue->capacidad;
	queue->tamanio = queue->tamanio - 1;
	return elemento;
}

//Funcion para obtener el frente del queue
int frente(QueueArreglo* queue)
{
	if (estaVacio(queue))
		return INT_MIN;

	return queue->arreglo[queue->frente];
}

//Funcion para obtener atras del queue
int atras(QueueArreglo* queue)
{
	if (estaVacio(queue))
		return INT_MIN;

	return queue->arreglo[queue->atras];
}