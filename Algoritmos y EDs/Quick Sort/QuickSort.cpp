#include <iostream>

using std::cout;
using std::endl;

void intercambiar(int* x, int* y)
{
	int temporal = *x;
	*x = *y;
	*y = temporal;
}

/*Esta función toma el ultimo elemento como el pivote,
  lo pone en la posición correcta en el arreglo ordenado, 
  y pone todos los elementos menores que el a su izquierda, 
  mientras que pone todos los elementos mayores que el a su derecha
*/
int particion(int arreglo[], int inferior, int superior)
{
	int pivote = arreglo[superior];
	int i = (inferior - 1);

	for (int j = inferior; j <= superior; j++)
	{
		//Si el elemento superior es menor que el pivote
		if (arreglo[j] < pivote)
		{
			i++;
			intercambiar(&arreglo[i], &arreglo[j]);
		}
	}
	intercambiar(&arreglo[i + 1], &arreglo[superior]);
	return (i + 1);
}


//Función principal de quicksort
//recibe el arreglo a ordenar, indice inicial (inferior) y final (superior)
void quickSort(int arreglo[], int inferior, int superior)
{
	if (inferior < superior)
	{
		//ip es el indice de la particion, arreglo[p] ahora esta en su lugar correcto
		int ip = particion(arreglo, inferior, superior);

		//Ordenamos los elementos que están antes y después de la particion
		quickSort(arreglo, inferior, ip - 1);
		quickSort(arreglo, ip + 1, superior);
	}
}

void imprimirArreglo(int arreglo[], int tamaño)
{
	for (int i = 0; i < tamaño; i++)
		cout << arreglo[i] << " ";
	cout << endl;
}

int main()
{
	int arreglo[] = { 10, 7, 8, 9, 1, 5 };
	int tamaño = sizeof(arreglo) / sizeof(arreglo[0]);
	
	cout << "Arreglo sin ordenar: " << endl;
	imprimirArreglo(arreglo, tamaño);
	
	cout << "Arreglo ordenado: " << endl;
	quickSort(arreglo, 0, tamaño - 1);
	imprimirArreglo(arreglo, tamaño);

	return 0;

}