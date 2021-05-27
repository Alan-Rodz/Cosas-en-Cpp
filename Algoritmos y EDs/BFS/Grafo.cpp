#include "Grafo.h"

//Constructor con numero de vertices
Grafo::Grafo(int vertices)
{
	Vertices = vertices;

	//Creamos lista de adyacencia para cada vertice (asumimos que no hay vertices desconectados)
	lista_adyacencia = new list<int>[vertices];
}

//Método para añadir una conexion entre 2 vertices
//Vertice es el vertice que estamos considerando, quien es hacia quién (hacia qué otro vertice) está conectado
void Grafo::agregarConexion(int vertice, int quien)
{
	lista_adyacencia[vertice].push_back(quien);
};

//Método para hacer recorrido BFS dado un nodo inicial "s"
void Grafo::BFS(int s)
{
	//Comenzamos con todos los vertices como "no visitados"
	//Hacemos esto con un arreglo de booleanos de tamaño "Vertices" donde Vertices es el numero de vertices del grafo
	bool* visitado = new bool[Vertices];
	for (int i = 0; i < Vertices; i++)
		visitado[i] = false;

	//Creamos un queue para el BFS con una lista
	list<int> queue;

	//Hacemos que el nodo inicial "s" sea considerado como visitado
	visitado[s] = true;
	queue.push_back(s);

	//Continuamos hasta que el queue esté vacío (hasta que hayamos buscado cada nodo del grafo)
	while (!queue.empty())
	{
		//Hacemos que s sea lo que haya al frente del queue y lo removemos
		s = queue.front();
		queue.pop_front();

		//Obtenemos todos los vertices adyacentes a la iteracion correspondiente de "s"
		cout << "Checando los vertices adyacentes al vertice " << s << endl;
		for (auto i = lista_adyacencia[s].begin(); i != lista_adyacencia[s].end(); i++)
		{
			//Solo tomamos en cuenta los vertices que no hemos visitado todavia
			if (!visitado[*i])
			{
				//los marcamos como visitados
				cout << "Se ha visitado y agregado al queue: " << *i << endl;
				visitado[*i] = true;

				//Lo agregamos al queue para checar los vertices de este vertice
				queue.push_back(*i);	
			}
		}
	}
};