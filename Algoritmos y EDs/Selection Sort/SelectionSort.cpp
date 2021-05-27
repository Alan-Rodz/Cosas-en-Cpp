#include <iostream>

using std::cout;
using std::endl;

void intercambiar(int* x, int* y)
{
	int temporal = *x;
	*x = *y;
	*y = temporal;
}

//n es el tamaño del arreglo que queremos ordenar
//Complejidad O(n^2)
void selectionSort(int arreglo[], int n)
{

	//Movemos de uno en uno el limite del arreglo desordenado
	for (int i = 0; i < n - 1; i++)
	{
		//Encontramos el elemento mas pequeño del arreglo desordenado
		int indice_minimo = i;
		for (int j = i + 1; j < n; j++)
			if (arreglo[j] < arreglo[indice_minimo])
				indice_minimo = j;
		
		//Intercambiamos el indice minimo con el primer elemento del arreglo
		intercambiar(&arreglo[indice_minimo], &arreglo[i]);
	}
}

//Función para imprimir el arreglo
void imprimirArreglo(int arreglo[], int tamaño)
{
	for (int i = 0; i < tamaño; i++)
		cout << arreglo[i] << " ";

	cout << endl;
}

int main()
{
	int arreglo[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arreglo) / sizeof(arreglo[0]);
	selectionSort(arreglo, n);
	cout << "Arreglo ordenado:" << endl; 
	imprimirArreglo(arreglo, n);
	return 0;
}