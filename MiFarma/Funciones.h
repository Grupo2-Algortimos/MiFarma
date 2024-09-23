#pragma once
#include"Usuario.h"
#include"Producto.h"
#include"Pedido.h"
using namespace std;
//Recursivas
// 
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

//Función para retornar el Producto con mayor cantidad en el almacén
Producto<string>* buscarProductoConMasCantidad(Lista<Producto<string>*>* l_productos, int index = 0, Producto<string>* maxCant = nullptr) {
	if (index >= l_productos->longitud()) return maxCant;
	Producto<string>* productoActual = l_productos->obtenerPos(index);
	if (maxCant == nullptr || productoActual->getCantidad() > maxCant->getCantidad()) {
		maxCant = productoActual;
	}
	return buscarProductoConMasCantidad(l_productos, index + 1, maxCant);
}

//Lambdas
//Función lambda que retorna un string de la fecha y hora -> Se obtuvo cierto apoyo del ChatGPT
auto obtenerFechaYHora = [] {
	auto t = time(nullptr);
	auto tm = *localtime(&t);

	stringstream ss;
	ss << put_time(&tm, "%d-%m-%Y %H:%M");

	return ss.str();
};

//Ordenamiento:
//
//Ordenamiento Shell con Lista de productos de mayor a menor
void ordShellProdcutoMayorAMenor(Lista<Producto<string>*>*l_productosOrdenar) {
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