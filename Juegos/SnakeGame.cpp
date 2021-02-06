#include <iostream>
#include <conio.h>
#include <Windows.h>

using std::cout;
using std::endl;

bool gameOver = false;

//Variables constantes del mapa
const int anchura = 20;
const int altura = 20;

//Variables que controlan la posicion de la cabeza y de la siguiente fruta, asi como la puntuacion
int cabezaX, cabezaY, frutaX, frutaY, puntuacion;

//Arreglos que controlan el movimiento del resto del cuerpo de la serpiente, así como su longitud
int cuerpoX[100], cuerpoY[100]; 
int nCuerpo;

//Enum con las direcciones a las que se puede mover la serpiente y variable que tiene la direccion actual
enum eDireccion {ALTO = 0, IZQUIERDA, DERECHA, ARRIBA, ABAJO};
eDireccion direccion;

//Función para inicializar variables antes de que comience el juego
void Inicializar()
{
	gameOver = false;
	direccion = ALTO;
	cabezaX = anchura / 2;
	cabezaY = altura / 2;
	frutaX = rand() % anchura;
	frutaY = rand() % altura;
	puntuacion = 0;
}

//Función para dibujar nuestro mapa y la serpiente
void Dibujar()
{
	//Limpiamos la pantalla
	system("cls");
	
	//Pared de arriba
	for (int i = 0; i < anchura + 2; i++)
		cout << "#";
	cout << endl;

	//Dibujamos el mapa como si imprimieramos una matriz
	for (int i = 0; i < altura; i++)
	{
		for (int j = 0; j < anchura; j++)
		{
			//Si estamos en la primera posicion de la fila, imprimimos pared
			if (j == 0)
				cout << "#";

			//Si estamos en la posicion de la cabeza, imprimimos serpiente
			if (i == cabezaY && j == cabezaX)
				cout << "O";

			//Si estamos en una posicion de fruta, imprimimos F
			else if (i == frutaY && j == frutaX)
				cout << "F";

			//De otra manera imprimimos espacio blanco
			else
			{
				bool imprimir = false;
				for (int k = 0; k < nCuerpo; k++)
				{
					if (cuerpoX[k] == j && cuerpoY[k] == i)
					{
						cout << "o";
						imprimir = true;
					}
				}

				if (!imprimir)
					cout << " ";
			}

			//Si estamos en la ultima posicion de la fila, imprimimos pared
			if (j == anchura - 1)
				cout << "#";
		}
		cout << endl;
	}

	//Pared de abajo
	for (int i = 0; i < anchura + 2; i++)
		cout << "#";
	cout << endl;
	cout << endl;
	cout << "Puntuacion: " << puntuacion << endl;

}

//Función para manejar los controles, estamos usando WASD
void Controles()
{
	//Si se ha presionado una tecla
	if (_kbhit())
	{
		//_getch() Nos regresa el valor ASCII de la tecla presionada
		switch (_getch())
		{
		case 'a':
			direccion = IZQUIERDA;
			break;
			
		case 'd':
			direccion = DERECHA;
			break;

		case 'w':
			direccion = ARRIBA;
			break;

		case 's':
			direccion = ABAJO;
			break;

		case 'x':
			gameOver = true;
			break;
		}
	}
}

//La lógica de cómo se mueve la serpiente
void Logica()
{
	//Variables que nos sirven para la animación del cuerpo de la serpiente
	int anteriorX = cuerpoX[0];
	int anteriorY = cuerpoY[0];
	int anterior2X, anterior2Y;
	cuerpoX[0] = cabezaX;
	cuerpoY[0] = cabezaY;

	//Así es como imprimimos el cuerpo de la serpiente
	for (int i = 1; i < nCuerpo; i++)
	{
		anterior2X = cuerpoX[i];
		anterior2Y = cuerpoY[i];
		cuerpoX[i] = anteriorX;
		cuerpoY[i] = anteriorY;
		anteriorX = anterior2X;
		anteriorY = anterior2Y;
	}

	switch (direccion)
	{	
	case IZQUIERDA:
		cabezaX--;
		break;

	case DERECHA:
		cabezaX++;
		break;

	case ARRIBA:
		cabezaY--;
		break;

	case ABAJO:
		cabezaY++;
		break;

	default:
		break;
	}

	//Si nuestra cabeza sale toca las paredes, es GameOver
	//if (cabezaX > anchura || cabezaX < 0 || cabezaY > altura || cabezaY < 0)
		//gameOver = true;

	//Si queremos aparecer al otro lado del mapa cuando cruzamos las paredes
	if (cabezaX >= anchura)
		cabezaX = 0;
	else if (cabezaX < 0)
		cabezaX = anchura - 1;
	if (cabezaY >= altura)
		cabezaY = 0;
	else if (cabezaY < 0)
		cabezaY = altura - 1;


	//Si nos tocamos a nosotros mismos, es GameOver
	for (int i = 0; i < nCuerpo; i++)
		if (cuerpoX[i] == cabezaX && cuerpoY[i] == cabezaY)
			gameOver = true;
			
	//Si comemos una fruta
	if (cabezaX == frutaX && cabezaY == frutaY)
	{
		puntuacion += 10;
		frutaX = rand() % anchura;
		frutaY = rand() % altura;
		nCuerpo++;
	}

}

int main()
{
	Inicializar();
	while (!gameOver)
	{
		Dibujar();
		Controles();
		Logica();
		Sleep(10);
	}
	return 0;
}
