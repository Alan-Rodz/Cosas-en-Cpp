#include "StackArreglo.h"
#include "StackLLNodo.h"

/*
//Stack con arreglos
Pros: Facil de Implementar. Se guarda memoria porque no usamos punteros.
Contras: No es dinámico. No crece / decrece a la hora de ejecución. 
int main()
{
    class StackArreglo stackArreglo;
    stackArreglo.push(10);
    stackArreglo.push(20);
    stackArreglo.push(30);
    stackArreglo.push(40);
    cout << stackArreglo.pop() << " Removido del stack " << endl;
    cout << stackArreglo.pop() << " Removido del stack " << endl;
    cout << stackArreglo.pop() << " Removido del stack " << endl;

    return 0;
}
*/

//Stack con singly linked list
//Pros: Puede crecer o disminuir su tamaño como sea necesario
//Cons: Requiere + memoria por el uso de punteros
int main()
{
    StackLLNodo* raiz = NULL;

    push(&raiz, 10);
    push(&raiz, 20);
    push(&raiz, 30);

    cout << pop(&raiz) << " removido del stack "<< endl;

    cout << "El ultimo elemento del stack es " << peek(raiz) << endl;

    return 0;
}