#include <iostream>
#include "QueueArreglo.h"

//Pros: Facil de Implementar
//Contras: Estático
int main()
{
	QueueArreglo* queue = crearQueue(1000);
	enqueue(queue, 10);
	enqueue(queue, 20);
	enqueue(queue, 30);
	enqueue(queue, 40);

	cout << dequeue(queue) << " removido del queue " << endl;
	cout << "El frente del queue es: " << frente(queue) << endl;
	cout << "El elemento de atras del queue es: " << atras(queue) << endl;

	return 0;
}