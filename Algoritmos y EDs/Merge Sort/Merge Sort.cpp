#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

//Une dos sub-arreglos a partir del arreglo principal
//El primer sub-arreglo es arreglo[izquierda...mitad]
//El segundo sub-arreglo es arreglo[mitad+1...derecha]
void merge(int arreglo[], int izquierda, int mitad, int derecha)
{
	int n1 = mitad - izquierda + 1;
	int n2 = derecha - mitad;

	//Arreglos temporales
	int* IZQ = new int[n1];
	int* DER = new int[n2];

	//Copiamos la informacion necesaria hacia los vectores
	for (int i = 0; i < n1; i++)
		IZQ[i] = arreglo[izquierda + i];

	for (int j = 0; j < n2; j++)
		DER[j] = arreglo[mitad + 1 + j];

	//Unimos los arreglos temporales hacia arreglo[izquierda...derecha]
	//Indices iniciales del primero, segundo y tercer arreglo (el tercero es en el que se unen);
	int i = 0, j = 0, k = izquierda;
	while (i < n1 && j < n2)
	{
		if (IZQ[i] < DER[j])
		{
			arreglo[k] = IZQ[i];
			i++;
		}
		else
		{
			arreglo[k] = DER[j];
			j++;
		}
		k++;
	}

	//Copiamos los elementos restantes de IZQ[], si es que faltan
	while (i < n1)
	{
		arreglo[k] = IZQ[i];
		i++;
		k++;
	}

	//Copiamos los elementos restantes de DER[], si es que faltan
	while (j < n2)
	{
		arreglo[k] = DER[j];
		j++;
		k++;
	}
}

void mergeSort(int arreglo[], int izquierda, int derecha)
{
	//Recursividad
	if (izquierda >= derecha)
		return; 

	int mitad = (izquierda + derecha - 1) / 2;
	mergeSort(arreglo, izquierda, mitad);
	mergeSort(arreglo, mitad + 1, derecha);
	merge(arreglo, izquierda, mitad, derecha);
}

void imprimirArreglo(int arreglo[], int tamaño)
{
	for (int i = 0; i < tamaño; i++)
		cout << arreglo[i] << " ";

	cout << endl;
}

int main()
{
	int arreglo[] = { 12, 11, 13, 5, 6, 7 };
	int tamaño_arreglo = sizeof(arreglo) / sizeof(arreglo[0]);

	cout << "Arreglo desordenado: " << endl;
	imprimirArreglo(arreglo, tamaño_arreglo);

	mergeSort(arreglo, 0, tamaño_arreglo - 1);
	
	cout << "Arreglo ordenado: " << endl;
	imprimirArreglo(arreglo, tamaño_arreglo);
	
	
	return 0;
}