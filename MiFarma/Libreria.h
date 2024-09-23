#pragma once
#include <iostream>
#include<fstream>//Gestion de Archivo
#include<string>//getline
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<sstream>//stream
#include"stack"
#include"queue"
//definimos predeterminados
#define archivoEmpleados "ListaEmpleados.txt"
#define archivoProductos "ListaProductos.txt"
#define archivoReclamo "ListaReclamo.txt"
#define archivoProveedor "ListaProveedor.txt"
#define archivoBoletas "ListaBoletas.txt"
#define archivoUsuarios "ListaUsuarios.txt"
using namespace System;
using namespace std;
int ANCHO = Console::WindowWidth;
int ALTO = Console::WindowHeight;
//Delivery
vector<string> repartidores = { "Roberto Bolaños", "Juan Carlos", "Miguel Osbaldo", "Maria de las Nieves"};
vector<string> estadosDelivery = { "Pendiente","En camino", "Entregado" };
vector<string> modosDelivery = { "Motocicleta","Bicicleta" };