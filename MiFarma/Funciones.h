#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "Usuario.h"
#include "Producto.h"


using namespace std;

//Contraseña de 10 caracteres máx
string generarContrasena(int caracterMax, string contrasena = "") {
	string caracteresDisponibles = "abcdefghijklmnopqrstuvwxyz123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ@#!¡";
	if (caracterMax == 0) return contrasena;
	char caracter = caracteresDisponibles[rand() % caracteresDisponibles.length()];
	contrasena += caracter;
	return generarContrasena(caracterMax - 1, contrasena);
}

//Usuario de 15 caracteres máx
string generarNombreUsuario(int caracterMax, string nombreUsuario, string userNombre) {
	string caracteresDisponibles = "123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ@#!¡";
	if (caracterMax == 10) return nombreUsuario;
	else if (caracterMax == 0) nombreUsuario += userNombre;
	char caracter = caracteresDisponibles[rand() % caracteresDisponibles.length()];
	nombreUsuario += caracter;
	return generarNombreUsuario(caracterMax + 1, nombreUsuario, userNombre);
}

//Funcion para retornar el Producto más caro



