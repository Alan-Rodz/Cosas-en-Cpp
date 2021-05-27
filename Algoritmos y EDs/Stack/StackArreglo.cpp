#include "StackArreglo.h"

bool StackArreglo::push(int x)
{
	if (elementoHastaArriba >= (MAX - 1)) 
	{
		cout << "Overflow del Stack" << endl;
		return false;
	}
	else 
	{
		arreglo[++elementoHastaArriba] = x;
		cout << x << " Se ha agregado al stack" << endl;
		return true;
	}
}

int StackArreglo::pop()
{
	if (elementoHastaArriba < 0) 
	{
		cout << "Underflow del stack";
		return 0;
	}
	else 
	{
		int x = arreglo[elementoHastaArriba--];
		return x;
	}
}
int StackArreglo::peek()
{
	if (elementoHastaArriba < 0) 
	{
		cout << "El stack esta vacio";
		return 0;
	}
	else 
	{
		int x = arreglo[elementoHastaArriba];
		return x;
	}
}

bool StackArreglo::estaVacio()
{
	return (elementoHastaArriba < 0);
}