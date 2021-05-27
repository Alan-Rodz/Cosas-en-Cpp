#include "HashTable.h"

int main()
{
	HashTable Tabla;
	if (Tabla.estaVacia())
		cout << "Respuesta correcta, la lista esta vacia" << endl;
	else
		cout << "Error a la hora de inicializar la tabla" << endl;

	cout << "Insertando elementos..." << endl;
	Tabla.insertarElemento(800, "Gonzalo");
	Tabla.insertarElemento(526, "Lisa");
	Tabla.insertarElemento(325, "Samuel");
	Tabla.insertarElemento(456, "Genaro");
	Tabla.insertarElemento(905, "Juan");
	Tabla.insertarElemento(322, "Pedro");
	cout << "Elementos insertados de manera exitosa." << endl; 

	cout << "Primera impresion" << endl;
	Tabla.imprimirTabla();

	cout << "Insertando elemento con la misma llave pero diferente nombre..." << endl;
	Tabla.insertarElemento(322, "Ricardo");

	cout << "Segunda impresion" << endl;
	Tabla.imprimirTabla();

	cout << "Removiendo algunos elementos..." << endl;
	Tabla.removerElemento(800);
	Tabla.removerElemento(526);

	cout << "Removiendo elemento que no esta presente en la tabla..." << endl;
	Tabla.removerElemento(10);
	cout << "Elementos removidos. Imprimiendo nuevamente:" << endl;
	Tabla.imprimirTabla();

	cout << "Comprobando que la lista no esta vacia:" << endl;
	if (Tabla.estaVacia())
		cout << "Hay un error, porque se supone que la lista no esta vacia." << endl;
	else
		cout << "El metodo para checar si la lista esta vacia funciona correctamente." << endl;

	Tabla.buscarElemento(322);
	Tabla.buscarElemento(325);
	Tabla.buscarElemento(10);
	return 0;
}