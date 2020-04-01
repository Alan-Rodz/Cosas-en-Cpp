#include <iostream>
using namespace std;

int main(){

    //Valores de las filas y las columnas
    const int FILAS = 3;
    const int COLUMNAS = 3;

    //Matriz de 3 filas y 3 columnas
    int Matriz[FILAS][COLUMNAS];

    //Ingresar los valores
    //Filas
    for (int i = 0; i < FILAS; i++){

        //Columnas
        for (int j = 0; j < COLUMNAS; j++){

            std::cout << "Enter Element (" << i << "," << j << "): ";
            std::cin >> Matriz[i][j];

        }
    }

    // Imprimir los valores

    //For int i = Filas
    for (int i = 0; i < FILAS; i++)
    {
        //For int j = columnas
        for (int j = 0; j < COLUMNAS; j++)
        {
            cout << "Elemento en [" << i << "][" << j << "]: ";
            cout << Matriz[i][j] << endl;
        }
    }
}