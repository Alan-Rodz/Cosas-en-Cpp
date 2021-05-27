#include <iostream>
#include "Grafo.h"
int main()
{
	//Creamos un nuevo grafo
	Grafo grafo(6);

	//Conexiones del vertice 0
	grafo.agregarConexion(0, 1);
	grafo.agregarConexion(0, 2);

	//Conexiones del vertice 1
	grafo.agregarConexion(1, 0);
	grafo.agregarConexion(1, 3);
	grafo.agregarConexion(1, 4);

	//Conexiones del vertice 2
	grafo.agregarConexion(2, 0);
	grafo.agregarConexion(2, 4);

	//Conexiones del vertice 3
	grafo.agregarConexion(3, 1);
	grafo.agregarConexion(3, 4);
	grafo.agregarConexion(3, 5);

	//Conexiones del vertice 4
	grafo.agregarConexion(4, 1);
	grafo.agregarConexion(4, 2);
	grafo.agregarConexion(4, 3);
	grafo.agregarConexion(4, 5);

	//Conexiones del vertice 5
	grafo.agregarConexion(5, 3);
	grafo.agregarConexion(5, 4);

	//Hacemos BFS e imprimimos resultado
	grafo.BFS(2);

	return 0;
}
