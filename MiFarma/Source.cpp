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
    ControllerProgram<int, double>* run = new ControllerProgram<int, double>(imprimir, imprimir);
    run->menu();
}

