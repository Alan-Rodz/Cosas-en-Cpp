#include <iostream>
using std::cout;
using std::endl;
#define MAX 1000

class StackArreglo 
{
    int elementoHastaArriba;

public:
    int arreglo[MAX]; // Tamaño maximo del stack

    //Constructor
    StackArreglo() { elementoHastaArriba = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool estaVacio();
};