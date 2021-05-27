#pragma once

#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

class Grafo
{
public:
	//Constructor con numero de vertices
	Grafo(int vertices);

	//Método para añadir una conexion entre 2 vertices
	void agregarConexion(int vertice, int quien);

	//Método para hacer recorrido BFS dado un nodo inicial "s"
	void BFS(int s);

private:
	//numero de vertices
	int Vertices;
	
	//puntero a lista de adyacencia
	list<int> *lista_adyacencia;
};

