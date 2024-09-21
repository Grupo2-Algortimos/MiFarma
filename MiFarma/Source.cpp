#include "ControllerProgram.h"

int main()
{
    Programa* run = new Programa();
    run->lecturaArchivoEmpleados();
    run->lecturaArchivoProductos();
    run->lecturaArchivoReclamo();
    run->lecturaArchivoProveedor();
    run->menu();
}

