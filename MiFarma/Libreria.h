#pragma once
#include<iostream>
#include<fstream>//Gestion de Archivo
#include<string>//getline
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<cctype>
#include<sstream>//stream
#include<algorithm>
#include<stack>
#include<queue>
#include<conio.h>
#include<list>
#include<vector>
#include<functional>
//Definimos Archivos de Lectura
#define archivoEmpleadosLectura "LecturaListaEmpleados.txt"
#define archivoProductosLectura "LecturaListaProductos.txt"
#define archivoReclamoLectura "LecturaPilaReclamo.txt"
#define archivoProveedorLectura "LecturaListaProveedor.txt"
#define archivoBoletasLectura "LecturaListaBoletas.txt"
#define archivoUsuariosLectura "LecturaListaUsuarios.txt"
//Definimos Archivos de Escritura
#define archivoEmpleadosEscritura "EscrituraListaEmpleados.txt"
#define archivoProductosEscritura "EscrituraListaProductos.txt"
#define archivoReclamoEscritura "EscrituraPilaReclamo.txt"
#define archivoProveedorEscritura "EscrituraListaProveedor.txt"
#define archivoBoletasEscritura "EscrituraListaBoletas.txt"
#define archivoUsuariosEscritura "EscrituraListaUsuarios.txt"
#define archivoPedidosEscritura "EscrituraColaPedidos.txt"

//Definimos Teclas de Control
#define TECLA_IZQUIERDA 75
#define TECLA_DERECHA 77
#define TECLA_ESCAPE 27

using namespace System;
using namespace std;
int ANCHO = Console::WindowWidth;
int ALTO = Console::WindowHeight;

//Delivery
vector<string> repartidores = { "Roberto", "Carlos", "Miguel", "Maria"};
vector<string> estadosDelivery = { "Pendiente","En camino", "Entregado" };
vector<string> modosDelivery = { "Motocicleta","Bicicleta" };
//Nombres de clientes
vector<string> nombres_clientes = { "Juan","Maria","Carlos","Luisa","Pedro","Ana","Jose","Rosa","Jorge","Sofia" };
//Apellidos de clientes
vector<string> apellidos_clientes = { "Perez","Gomez","Torres","Garcia","Vasquez","Lopez","Gonzales","Rodriguez","Fernandez","Diaz" };