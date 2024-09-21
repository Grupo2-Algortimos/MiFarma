#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
#include"Usuario.h"
#include"Producto.h"
#include"Lista.h"
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
//Ordenamiento Shell con Lista de productos de mayor a menor
void ordShellProdcutoMayorAMenor(Lista<Producto<string>*>* l_productosOrdenar) {
	int n = l_productosOrdenar->longitud();
	int i, j, k, intervalo = n / 2;
	Producto<string>* productoJ;
	Producto<string>* productoK;
	Producto<string>* temp;
	while (intervalo > 0) {
		for (i = intervalo; i < n; i++) {
			j = i - intervalo;
			while (j >= 0) {
				k = j + intervalo;
				productoJ = l_productosOrdenar->obtenerPos(j);
				productoK = l_productosOrdenar->obtenerPos(k);
			}
			if (stod(productoJ->getPrecio()) >= stod(productoK->getPrecio())) {
				break;
			}
			else {
				temp = productoJ;
				l_productosOrdenar->modificarPos(productoJ, k);
				l_productosOrdenar->modificarPos(productoK, j);
			}
		}
	}
}
//Ordenamiento Shell con Lista de productos de menor a mayor
void ordShellProdcutoMenorAMayor(Lista<Producto<string>*>* l_productosOrdenar) {
	int n = l_productosOrdenar->longitud();
	int i, j, k, intervalo = n / 2;
	Producto<string>* productoJ;
	Producto<string>* productoK;
	Producto<string>* temp;
	while (intervalo > 0) {
		for (i = intervalo; i < n; i++) {
			j = i - intervalo;
			while (j >= 0) {
				k = j + intervalo;
				productoJ = l_productosOrdenar->obtenerPos(j);
				productoK = l_productosOrdenar->obtenerPos(k);
			}
			if (stod(productoJ->getPrecio()) <= stod(productoK->getPrecio())) {
				break;
			}
			else {
				temp = productoJ;
				l_productosOrdenar->modificarPos(productoJ, k);
				l_productosOrdenar->modificarPos(productoK, j);
			}
		}
	}
}