// Programa en C++ que usa Dijkstra para encontrar el camino mas corto desde el nodo inicial a cada otro nodo de un grafo
// Usa una matriz de adyacencia para representar el grafo
#include <limits.h>
#include <stdio.h>

// Numero de vertices en el grafo
#define V 9

// Funcion para encontrar el vertice con el valor de distancia minimo del conjunto de vertices todavia no incluidos en el arbol de caminos mas cortos
int distanciaMinima(int distancia[], bool conjuntoArbolCaminosMasCortos[])
{
    // Inicializamos valor minimo
    int minimo = INT_MAX, indice_minimo;

    for (int v = 0; v < V; v++)
        if (conjuntoArbolCaminosMasCortos[v] == false && distancia[v] <= minimo)
            minimo = distancia[v], indice_minimo = v;

    return indice_minimo;
}

// Funcion para imprimir el arreglo construido de distancias
void imprimirSolucion(int arregloDistancias[])
{
    printf("Vertice \t Distancia desde el nodo inicial\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, arregloDistancias[i]);
}

// Funcion para implementar Dijkstra para un grafo representado a través de una matriz de adyacencia
void dijkstra(int grafo[V][V], int nodoInicial)
{
    // Arreglo que vamos a regresar. distancia[i] tendra la distancia mas corta desde el nodoInicial hasta i
    int distancias[V]; 
    

    // Arreglo de booleanos. conjuntoArbolCaminosMasCortos[i] sera verdadero si el vertice i esta incluido en el arbol de caminos mas cortos
    // o la distancia mas corta desde el nodoInicial hasta i esta finalizada
    bool conjuntoArbolCaminosMasCortos[V];

    // Inicializamos todas las distancias como infinitas y el arreglo de booleanos en falso
    for (int i = 0; i < V; i++)
        distancias[i] = INT_MAX, conjuntoArbolCaminosMasCortos[i] = false;

    // La distancia del nodoIncial hacia si mismo siempre es 0
    distancias[nodoInicial] = 0;

    // Encontramos el camino mas corto para todos los vertices
    for (int count = 0; count < V - 1; count++) 
    {
        // Escogemos el vertice con la distancia minima del conjunto de vertices que no han sido procesados todavia
        // u siempre es igual al nodoInicial en la primera iteracion
        int u = distanciaMinima(distancias, conjuntoArbolCaminosMasCortos);

        // Marcamos el vertice elegido como procesado
        conjuntoArbolCaminosMasCortos[u] = true;

        // Actualizamos el valor de los vertices adyacentes al vertice elegido
        for (int v = 0; v < V; v++)

            // Actualizamos distancias[v] si no se encuentra en el arreglo de booleanos, existe una conexion de u a v y el valor total del
            // camino desde el nodoInicial hacia v a través de u es menor que el valor actual de distancias[v]
            if (!conjuntoArbolCaminosMasCortos[v] && grafo[u][v] && distancias[u] != INT_MAX && distancias[u] + grafo[u][v] < distancias[v])
                distancias[v] = distancias[u] + grafo[u][v];
    }

    // Imprimimos el arreglo construido de distancias
    imprimirSolucion(distancias);
}


int main()
{
    // Matriz de adyacencia de un grafo
    int grafo[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(grafo, 0);

    return 0;
}
