#include <iostream>
#include <list>

using namespace std;

class Grafo{
private:
    //Número de vertices del grafo
    int V;

    //Apuntador a la lista de Adyacencia
    list<int> *ady;

    //Funciones recursivas que ayudan a DFS
    //El primer argumento es el nodo en el que iniciamos
    //El segundo argumento es el arreglo de nodos visitados
    void DFS_helper(int NodoInicial, bool *visitado);

public:
    //Constructor Prototipo
    Grafo(int v);

    //Método para añadir una arista
    void anadirArista(int v, int w);

    //Método para recorrido BFS dado un nodo inicial "NodoInicial"
    void DFS(int NodoInicial);
};

//Constructor con numero de vertices
Grafo::Grafo(int v){
    //Numero de Vertices
    V = v;

    //Crear nueva lista de adyacencia
    ady = new list<int>[v];
}

//Implementacion de metodo para añadir aristas
void Grafo::anadirArista(int v, int w){
    ady[v].push_back(w);
}

void Grafo::DFS_helper(int NodoInicial, bool *visitado){
    //Marcamos el nodo en el que nos encontramos como visitado
    cout << "Visitando nodo " << NodoInicial << endl;
    visitado[NodoInicial] = true;

    //Recorrer la lista de adyacencia
    for (auto i = ady[NodoInicial].begin(); i != ady[NodoInicial].end(); i++){
        //Si no se ha visitado, entoces vamos a ese vertice
        if(!visitado[*i]){
            cout << "Yendo al vertice " << *i << " desde el vertice " << NodoInicial << endl;
            DFS_helper(*i, visitado);
        }
    }
}

//Realiza BFS dado un vertice inicial
void Grafo::DFS(int NodoInicial){
    //Comienza con todos los vertices como no visitados
    bool *visitado = new bool[V];
    for(int i = 0; i < V; i++){
        visited[i] = false;
    }

    //Oomienzo de la llamada recursiva
    DFS_helper(NodoInicial, visitado);
}




int main()
{
    //Creamos un nuevo grafo
    Grafo g(6);

    //Creamos algunos aristas a los vertices

    //Conexiones para el vertice 0
    g.anadirArista(0,1);
    g.anadirArista(0,2);

    //Conexiones para el vertice 1
    g.anadirArista(1,0);
    g.anadirArista(1,3);
    g.anadirArista(1,4);

    //Conexiones para el vertice 2
    g.anadirArista(2,0);
    g.anadirArista(2,4);

    //Conexiones para el vertice 3
    g.anadirArista(3,1);
    g.anadirArista(3,4);
    g.anadirArista(3,5);

    //Conexiones para el vertice 4
    g.anadirArista(4,1);
    g.anadirArista(4,2);
    g.anadirArista(4,3);
    g.anadirArista(4,5);

    //Conexiones para el vertice 5
    g.anadirArista(5,3);
    g.anadirArista(5,4);

    //Realiza DFS e imprime el resultado
    g.DFS();
    return 0;
}
