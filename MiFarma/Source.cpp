#include "ControllerProgram.h"

//Funci�n Imprimir gen�rico para los arboles Binarios
template<typename T>
void imprimir(T e)
{
	cout << e << " ";
}

int main()
{
    Console::CursorVisible = false;
    ControllerProgram* run = new ControllerProgram(imprimir, imprimir);
    run->menu();
}

