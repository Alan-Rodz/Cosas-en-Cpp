#include <iostream>

using std::cout;
using std::endl; 

//Función recursiva de busqueda binaria
//Regresa la posicion de x en el arreglo que recibe, o -1 si no lo encuentra
//Estamos buscando el elemento x
int busquedaBinaria(int arreglo[], int izquierda, int derecha, int x)
{
	if (derecha >= izquierda)
	{
		int mitad = izquierda + (derecha - 1) / 2;

		//Si el elemento que buscamos esta en la mitad
		if (arreglo[mitad] == x)
			return mitad;

		//Si el elemento que buscamos es menor que la mitad, buscamos en sub-arreglo izquierdo
		if (arreglo[mitad] > x)
			return busquedaBinaria(arreglo, izquierda, mitad - 1, x);

		//Si el elemento que buscamos es mayor que la mtiad, buscamos en sub-arreglo derecho
		return busquedaBinaria(arreglo, mitad + 1, derecha, x);
	}

	//Si el elemento no esta presente en el arreglo
	return -1;
}

int main()
{
	int arreglo[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arreglo) / sizeof(arreglo[0]);
	int resultado = busquedaBinaria(arreglo, 0, n - 1, x);
	(resultado == -1) ? cout << "El elemento no esta presente en el arreglo " << endl 
		: cout << "El elemento esta presente en el indice " << resultado;

}