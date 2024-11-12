#include "ControllerProgram.h"

//Función Imprimir para los arboles Binarios
void imprimir(int e)
{
	cout << e << " ";
}

int main()
{
    Console::CursorVisible = false;
    ControllerProgram* run = new ControllerProgram(imprimir);
    run->menu();
}

