#pragma once
#include"Usuario.h"
#include"Producto.h"
#include"Pedido.h"
using namespace std;
//Recursivas
// 
//Contrase�a de 10 caracteres m�x
string generarContrasena(int caracterMax, string contrasena = "") {
	string caracteresDisponibles = "abcdefghijklmnopqrstuvwxyz123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ@#!�"; // -> 1 --> O(1)
	if (caracterMax == 0) return contrasena; // --> 1+1 --> 2 --> O(1)
	char caracter = caracteresDisponibles[rand() % caracteresDisponibles.length()]; // 4 --> O(1)
	contrasena += caracter; // -->concatenaci�n --> n --> O(n)
	return generarContrasena(caracterMax - 1, contrasena); // (n-1)*7n
}
//Tiempo detallado: 7n^2 - 7n
//Tiempo asint�tico: O(n^2)

//Usuario de 15 caracteres m�x
string generarNombreUsuario(int caracterMax, string nombreUsuario, string userNombre) {
	string caracteresDisponibles = "123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ@#!�"; // -> 1 --> O(1)
	if (caracterMax == 10) return nombreUsuario; // --> 2 --> O(1)
	else if (caracterMax == 0) nombreUsuario += userNombre; // --> 1 + n --> O(n)
	char caracter = caracteresDisponibles[rand() % caracteresDisponibles.length()]; // 4 --> O(1)
	nombreUsuario += caracter; // -->concatenaci�n --> n --> O(n)
	return generarNombreUsuario(caracterMax + 1, nombreUsuario, userNombre); // (n)*(n+7)
}
//Tiempo detallado: 7n^2 + 7n
//Tiempo asint�tico: O(n^2)


//Funci�n para retornar el Producto con mayor cantidad en el almac�n
Producto<string>* buscarProductoConMasCantidad(Lista<Producto<string>*>* l_productos, int index = 0, Producto<string>* maxCant = nullptr) {
	if (index >= l_productos->longitud()) return maxCant; 
	Producto<string>* productoActual = l_productos->obtenerPos(index); 
	if (maxCant == nullptr || productoActual->getCantidad() > maxCant->getCantidad()) {
		maxCant = productoActual;
	}
	return buscarProductoConMasCantidad(l_productos, index + 1, maxCant);
}

//Lambdas
//Funci�n lambda que retorna un string de la fecha y hora -> Se obtuvo cierto apoyo del ChatGPT
auto obtenerFechaYHora = [] {
	auto t = time(nullptr); // --> 2 --> O(1)
	auto tm = *localtime(&t); // --> 2 --> O(1)

	stringstream ss;
	ss << put_time(&tm, "%d-%m-%Y %H:%M"); // --> 2 --> O(1)

	return ss.str(); // --> 1 --> O(1)
};
//Tiempo detallado: 7
//Tiempo asint�tico: O(1)

//Ordenamiento:
//
//Ordenamiento Shell con Lista de productos de mayor a menor
void ordShellProductoMayorAMenor(Lista<Producto<string>*>* l_productosOrdenar) {
	int n = l_productosOrdenar->longitud();
	int i, j, k, intervalo = n / 2;
	Producto<string>* productoJ = NULL;
	Producto<string>* productoK = NULL;
	Producto<string>* temp = NULL;

	while (intervalo > 0) {
		for (i = intervalo; i < n; i++) {
			j = i - intervalo;
			while (j >= 0) {
				k = j + intervalo;
				productoJ = l_productosOrdenar->obtenerPos(j);
				productoK = l_productosOrdenar->obtenerPos(k);
				if (stod(productoJ->getPrecio()) >= stod(productoK->getPrecio())) {
					j = -1;
				}
				else {
					temp = productoJ;
					l_productosOrdenar->modificarPos(productoK, j);
					l_productosOrdenar->modificarPos(temp, k);
					j -= intervalo;
				}
			}
		}
		intervalo /= 2;
	}
}

//Ordenamiento Shell con Lista de productos de menor a mayor
void ordShellProductoMenorAMayor(Lista<Producto<string>*>* l_productosOrdenar) {
	int n = l_productosOrdenar->longitud();
	int i, j, k, intervalo = n / 2;
	Producto<string>* productoJ = NULL;
	Producto<string>* productoK = NULL;
	Producto<string>* temp = NULL;

	while (intervalo > 0) {
		for (i = intervalo; i < n; i++) {
			j = i - intervalo;
			while (j >= 0) {
				k = j + intervalo;
				productoJ = l_productosOrdenar->obtenerPos(j);
				productoK = l_productosOrdenar->obtenerPos(k);

				if (stod(productoJ->getPrecio()) <= stod(productoK->getPrecio())) {
					j = -1;
				}
				else {
					temp = productoJ;
					l_productosOrdenar->modificarPos(productoK, j);
					l_productosOrdenar->modificarPos(temp, k);
					j -= intervalo;
				}
			}
		}
		intervalo /= 2;
	}
}

string convertirStringMinuscula(string str) {
	transform(str.begin(), str.end(), str.begin(), ::tolower); // n --> O(n)
	return str; // 1 --> O(1)
}
// Tiempo detallado: n + 1
// Tiempo asint�tico: O(n)