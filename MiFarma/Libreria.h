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
//definimos predeterminados
#define archivoEmpleados "ListaEmpleados.txt"
#define archivoProductos "ListaProductos.txt"
#define archivoReclamo "ListaReclamo.txt"
#define archivoProveedor "ListaProveedor.txt"
#define archivoBoletas "ListaBoletas.txt"
#define archivoUsuarios "ListaUsuarios.txt"

//definimos teclas de control
#define TECLA_IZQUIERDA 75
#define TECLA_DERECHA 77
#define TECLA_ESCAPE 27

using namespace System;
using namespace std;
int ANCHO = Console::WindowWidth;
int ALTO = Console::WindowHeight;

//Delivery
vector<string> repartidores = { "Roberto Bolaños", "Juan Carlos", "Miguel Osbaldo", "Maria de las Nieves"};
vector<string> estadosDelivery = { "Pendiente","En camino", "Entregado" };
vector<string> modosDelivery = { "Motocicleta","Bicicleta" };
//Nombres de clientes
vector<string> nombres_clientes = { "Juan","Maria","Carlos","Luisa","Pedro","Ana","Jose","Rosa","Jorge","Sofia" };
//Apellidos de clientes
vector<string> apellidos_clientes = { "Perez","Gomez","Torres","Garcia","Vasquez","Lopez","Gonzales","Rodriguez","Fernandez","Diaz" };