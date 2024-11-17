#pragma once
#include"Usuario.h"
#include"Producto.h"
#include"Pedido.h"

// Función para truncar cadenas largas y rellenar con espacios si son cortas
string ajustarTexto(const string& texto, int ancho) {
	if (texto.length() > ancho) {
		return texto.substr(0, ancho); // Trunca el texto si es muy largo
	}
	return texto + string(ancho - texto.length(), ' '); // Rellena con espacios si es corto
}

//Recursivas
// 
//Contraseña de 10 caracteres máx
string generarContrasena(int caracterMax, string contrasena = "") {
	string caracteresDisponibles = "abcdefghijklmnopqrstuvwxyz123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ@#!¡"; // -> 1 --> O(1)
	if (caracterMax == 0) return contrasena; // --> 1+1 --> 2 --> O(1)
	char caracter = caracteresDisponibles[rand() % caracteresDisponibles.length()]; // 4 --> O(1)
	contrasena += caracter; // -->concatenación --> n --> O(n)
	return generarContrasena(caracterMax - 1, contrasena); // (n-1)*7n
}
//Tiempo detallado: 7n^2 - 7n
//Tiempo asintótico: O(n^2)

//Usuario de 15 caracteres máx
string generarNombreUsuario(int caracterMax, string nombreUsuario, string userNombre) {
	string caracteresDisponibles = "123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ@#!¡"; // -> 1 --> O(1)
	if (caracterMax == 10) return nombreUsuario; // --> 2 --> O(1)
	else if (caracterMax == 0) nombreUsuario += userNombre; // --> 1 + n --> O(n)
	char caracter = caracteresDisponibles[rand() % caracteresDisponibles.length()]; // 4 --> O(1)
	nombreUsuario += caracter; // -->concatenación --> n --> O(n)
	return generarNombreUsuario(caracterMax + 1, nombreUsuario, userNombre); // (n)*(n+7)
}
//Tiempo detallado: 7n^2 + 7n
//Tiempo asintótico: O(n^2)


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
	auto t = time(nullptr); // --> 2 --> O(1)
	auto tm = *localtime(&t); // --> 2 --> O(1)

	stringstream ss;
	ss << put_time(&tm, "%d-%m-%Y %H:%M"); // --> 2 --> O(1)

	return ss.str(); // --> 1 --> O(1)
};
//Tiempo detallado: 7
//Tiempo asintótico: O(1)

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
// Tiempo asintótico: O(n)

string removerPrimerCaracter(string str)
{
	return str.substr(1, str.length() - 1);
}

char obtenerPrimerCaracter(string str)
{
	return str[0];
}

//Funcion para calcular cuantos productos hay por categoria
int contarProductosPorCategoria(Lista<Producto<string>*>* l_productos, string categoria) {
	int cantidad = 0;
	for (int i = 0; i < l_productos->longitud(); i++)
	{
		if (l_productos->obtenerPos(i)->getCategoria() == categoria) {
			cantidad++;
		}
	}
	return cantidad;
}

int obtenerPrimerProductoPorCategoria(Lista<Producto<string>*>* l_productos, string categoria) {
	for (int i = 0; i < l_productos->longitud(); i++)
	{
		if (l_productos->obtenerPos(i)->getCategoria() == categoria) {
			return i;
		}
	}
	return -1;
}

// Ordenamiento avanzado con Mergesort
void merge(Lista<Usuario<double, int>*>* l_usuarios, int inicio, int medio, int fin) {
	int n1 = medio - inicio + 1;
	int n2 = fin - medio;

	// Crear sublistas temporales
	vector<Usuario<double, int>*> izquierda(n1);
	vector<Usuario<double, int>*> derecha(n2);

	// Copiar datos a las sublistas
	for (int i = 0; i < n1; i++) {
		izquierda[i] = l_usuarios->obtenerPos(inicio + i);
	}
	for (int j = 0; j < n2; j++) {
		derecha[j] = l_usuarios->obtenerPos(medio + 1 + j);
	}

	// Fusionar las sublistas en orden
	int i = 0, j = 0, k = inicio;
	while (i < n1 && j < n2) {
		if (izquierda[i]->getEdad() <= derecha[j]->getEdad()) {
			l_usuarios->modificarPos(izquierda[i], k);
			i++;
		}
		else {
			l_usuarios->modificarPos(derecha[j], k);
			j++;
		}
		k++;
	}

	// Copiar elementos restantes de izquierda, si los hay
	while (i < n1) {
		l_usuarios->modificarPos(izquierda[i], k);
		i++;
		k++;
	}

	// Copiar elementos restantes de derecha, si los hay
	while (j < n2) {
		l_usuarios->modificarPos(derecha[j], k);
		j++;
		k++;
	}
}

void mergeSort(Lista<Usuario<double, int>*>* l_usuarios, int inicio, int fin) {
	if (inicio < fin) {
		int medio = inicio + (fin - inicio) / 2;

		// Ordenar cada mitad recursivamente
		mergeSort(l_usuarios, inicio, medio);
		mergeSort(l_usuarios, medio + 1, fin);

		// Fusionar las mitades ordenadas
		merge(l_usuarios, inicio, medio, fin);
	}
}

// ordenamiento Quick sort

int partition(Lista<Producto<string>*>* l_productos, int inicio, int fin) {

	Producto<string>* pivote = l_productos->obtenerPos(fin); // Último elemento como pivote
	double precioPivote = stod(pivote->getPrecio());
	int i = inicio - 1;

	for (int j = inicio; j < fin; j++) {
		Producto<string>* productoJ = l_productos->obtenerPos(j);
		if (stod(productoJ->getPrecio()) <= precioPivote) {
			i++;
			// Intercambiar productos
			Producto<string>* temp = l_productos->obtenerPos(i);
			l_productos->modificarPos(productoJ, i);
			l_productos->modificarPos(temp, j);
		}
	}

	// Colocar el pivote en la posición correcta
	Producto<string>* temp = l_productos->obtenerPos(i + 1);
	l_productos->modificarPos(pivote, i + 1);
	l_productos->modificarPos(temp, fin);

	return i + 1;
}

void quickSort(Lista<Producto<string>*>* l_productos, int inicio, int fin) {
	if (inicio < fin) {
		int pi = partition(l_productos, inicio, fin); // Partición

		// Ordenar sublistas recursivamente
		quickSort(l_productos, inicio, pi - 1);
		quickSort(l_productos, pi + 1, fin);
	}
}

void ordenarXPrecio(Lista<Producto<string>*>* l_productos) {
	if (l_productos->longitud() > 1) {
		quickSort(l_productos, 0, l_productos->longitud() - 1);
	}
}