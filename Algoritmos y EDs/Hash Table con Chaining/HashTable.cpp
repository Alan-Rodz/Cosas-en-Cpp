#include "HashTable.h"

bool HashTable::estaVacia() const
{
	int suma = 0;
	for (int i = 0; i < gruposHash; i++)
		suma += tabla[i].size();

	if (!suma)
		return true;

	else
		return false;
}

int HashTable::funcionHash(int llave)
{
	//Estamos usando modulos, por ejemplo si llave = 905, nos regresa 5 porque 905%10 = 5 
	return llave % gruposHash; 
}

void HashTable::insertarElemento(int llave, string valor)
{
	//Este es el valor que determina a qué lista del arreglo de listas va el par de (llave, valor)
	int valorHash = funcionHash(llave);
	auto& indice = tabla[valorHash];
	//Iterador al inicio de esta lista que usaremos para checar si la llave ya está en esta lista
	auto iterador = begin(indice);
	//Checamos si la llave que queremos insertar ya existe o no (de inicio asumimos que no existe)
	bool llaveExiste = false;
	for (; iterador != end(indice); iterador++)
		if (iterador->first == llave)
		{
			llaveExiste = true;
			iterador->second = valor;
			cout << "La llave existia. Se ha reemplazado su valor. " << endl;
			break;
		}

	//En cambio si la llave no existe
	if (!llaveExiste)
		indice.emplace_back(llave, valor);

	return;
	

}

void HashTable::removerElemento(int llave)
{
	//Este es el valor que determina a qué lista del arreglo de listas va el par de (llave, valor)
	int valorHash = funcionHash(llave);
	auto& indice = tabla[valorHash];
	//Iterador al inicio de esta lista que usaremos para checar si la llave ya está en esta lista
	auto iterador = begin(indice);
	//Checamos si la llave que queremos insertar ya existe o no (de inicio asumimos que no existe)
	bool llaveExiste = false;

	//Si si existe, la removemos
	for (; iterador != end(indice); iterador++)
		if (iterador->first == llave)
		{
			llaveExiste = true;
			iterador = indice.erase(iterador);
			cout << "Se ha removido el par asociado al elemento. " << endl;
			break;
		}

	//Si el elemento no fue removido
	if (!llaveExiste)
		cout << "No se encontro el elemento. El par no fue removido. " << endl;

	return; 
}

void HashTable::buscarElemento(int llave)
{
	bool llaveExiste = false;

	for (int i = 0; i < gruposHash; i++)
	{
		if (tabla[i].size() == 0)
			continue;

		auto iterador = tabla[i].begin();
		for (; iterador != tabla[i].end(); iterador++)
			if (iterador->first == llave)
			{
				llaveExiste = true;
				cout << "La llave si esta presente y corresponde al valor: " << iterador->second << endl;
				break;
			}
	}

	if (!llaveExiste)
		cout << "No se encontro ningun valor asociado a la llave introducida. " << endl;

	return;
}

void HashTable::imprimirTabla()
{
	for(int i = 0; i < gruposHash; i++)
	{
		//Checamos cada lista de nuestra tabla y si esta vacia continuamos
		if (tabla[i].size() == 0)
			continue;
		
		//Iterador que apunta a la lista en la que nos encontramos y que la recorre
		auto iterador = tabla[i].begin();
		for (; iterador != tabla[i].end(); iterador++)
			cout << "Llave: " << iterador->first << " Valor: " << iterador->second << endl;
	}

	return;
}