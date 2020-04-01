#include <iostream>
using namespace std;

//Un arbol binario tiene informacion y punteros a su hijo izquierdo y derecho en cada nodo
struct Nodo
{
	int informacion;
	struct Nodo* izquierda, *derecha;
	Nodo(int informacion)
	{
		this->informacion = informacion;
		izquierda = derecha = NULL;
	}
};

//Dado un arbol binario, imprimimos sus nodos de acuerdo al recorrido "desde abajo hacia arriba" (PostOrder)
//Esto quiere decir que vamos <Izquierda><Derecha><Raíz>
void imprimirPostOrder(struct Nodo* nodo){
    if(nodo == NULL){
        return;
    }

    //Primero visitamos el sub-arbol izquierdo
    imprimirPostOrder(nodo->izquierda);

    //Luego visitamos el sub-arbol derecho
    imprimirPostOrder(nodo->derecha);

    //Luego lidiamos con el nodo
    cout << nodo->informacion << " ";

}

//Dado un árbol binario, imprimanse sus nodos usando inorder
//Esto quiere decir que vamos <Izquierda><Raíz><Derecha>
void imprimirInorder(struct Nodo* nodo){
    if(nodo == NULL){
        return;
    }

    //Primero vamos al hijo izquierdo
    imprimirInorder(nodo->izquierda);

    //Luego imprimimos la información
    cout << nodo->informacion << " ";

    //Luego vamos al hijo derecho
    imprimirInorder(nodo->derecha);
}

//Dado un árbol binario, imprimanse sus nodos usando preorder
//Esto quiere decir que vamos
void imprimirPreOrder(struct Nodo* nodo){
    if(nodo == NULL){
        return;
    }

    //Primero imprimimos la información del nodo
    cout << nodo->informacion << " ";

    //Luego vamos al sub-árbol izquierdo
    imprimirPreOrder(nodo->izquierda);

    //Luego vamos al sub-árbol de la derecho
    imprimirPreOrder(nodo->derecha);
}

//Programa para probar las funciones de arriba
int main()
{
    struct Nodo *raiz = new Nodo(1);
    raiz->izquierda = new Nodo(2);
    raiz->derecha = new Nodo(3);
    raiz->izquierda->izquierda = new Nodo(4);
    raiz->izquierda->derecha = new Nodo(5);

    cout << "\nEl recorrido PreOrder del arbol binario es: \n";
    imprimirPreOrder(raiz);

    cout << "\nEl recorrido InOrder del arbol binario es: \n";
    imprimirInorder(raiz);

    cout << "\nEl recorrido PostOrder del arbol binario es: \n ";
    imprimirPostOrder(raiz);

    return 0;
}
