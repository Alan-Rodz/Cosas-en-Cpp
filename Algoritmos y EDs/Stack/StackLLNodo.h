#pragma once
#include <iostream>

using std::cout;
using std::endl;

class StackLLNodo
{
public:
	int informacion;
	StackLLNodo* siguiente;
};

StackLLNodo* nuevoNodo(int informacion);

int estaVacio(StackLLNodo* raiz);

void push(StackLLNodo** raiz, int informacion);

int pop(StackLLNodo** raiz);

int peek(StackLLNodo* raiz);

