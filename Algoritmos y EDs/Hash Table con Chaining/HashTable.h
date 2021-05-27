#pragma once
#include <iostream>
#include <list>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::string;
using std::list;
using std::pair;

//Nuestros pares valores llave seran (llave, nombre) donde la llave es un numero de telefono
class HashTable
{
private:
	//Grupos hash es la cantidad de "espacios" que tiene nuestra tabla, cada espacio con su propia lista
	static const int gruposHash = 10;

	//La lista 1 estará en el indice 0 del arreglo, la lista 2 en el indice 1, la lista 3 en el indice 2, etc
	list<pair<int, string>> tabla[gruposHash];

public:
	bool estaVacia() const;
	int funcionHash(int llave);
	void insertarElemento(int llave, string valor);
	void removerElemento(int llave);
	void buscarElemento(int llave);
	void imprimirTabla();
};

