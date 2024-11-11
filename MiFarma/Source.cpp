#include "ControllerProgram.h"

int main()
{
    Console::CursorVisible = false;
    ControllerProgram* run = new ControllerProgram();
    run->menu();
}

