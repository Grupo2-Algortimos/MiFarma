#pragma once
#include <iostream>
#include "Empleado.h"
#include "Producto.h"
#include "Usuario.h"
#include "Reclamos.h"
#include "Proveedor.h"
#include "Funciones.h"
#include "ListaEmpleados.h"
#include <fstream>	//Gestion de Archivo
#include <string>	//getline
#include <sstream>	//stream
//definimos predeterminados
#define archivoEmpleados "ListaEmpleados.txt"
#define archivoProductos "ListaProductos.txt"
#define archivoReclamo "ListaReclamo.txt"
#define archivoProveedor "ListaProveedor.txt"


using namespace std;
class Programa {
private:
	//declarando lista
	Lista<Empleado*>* l_empleados;
	Lista<Producto<string>*>* l_productos;
	Lista<Usuario*>* l_usuario;
	Lista<Reclamo<string>*>* l_reclamo;
	Lista<Proveedor*>* l_proveedor;

public:
	Programa() {
		l_empleados = new Lista<Empleado*>();
		l_productos = new Lista<Producto<string>*>();
		l_usuario = new Lista<Usuario*>();
		l_reclamo = new Lista<Reclamo<string>*>();
		l_proveedor = new Lista<Proveedor*>();
	}
	//importacion de archivos
	void lecturaArchivoEmpleados() {
		ifstream archIN;
		archIN.open(archivoEmpleados, ios::in); //Apertura
		if (!archIN.is_open())
		{
			cout << "Error: No se pudo abrir el archivo !!!" << endl;
			exit(1);
		}
		string linea;
		char delimitador = '|'; //Separador de cada columna de la línea
		int i = 0;
		Empleado* auxE;
		// Encabezado: Leemos la primera línea para descartarla, pues es el encabezado
		getline(archIN, linea);
		// Contenido: Leemos todas las líneas
		while (getline(archIN, linea))
		{
			stringstream stream(linea); // Convertir la cadena a un stream			
			string user, password, nombre, apellido, telefono, sexo, distrito, idTrabajador, puesto;
			// Extraer todos los valores de esa fila [considerando 3 columans]
			getline(stream, user, delimitador);
			getline(stream, password, delimitador);
			getline(stream, nombre, delimitador);
			getline(stream, apellido, delimitador);
			getline(stream, telefono, delimitador);
			getline(stream, sexo, delimitador);
			getline(stream, distrito, delimitador);
			getline(stream, idTrabajador, delimitador);
			getline(stream, puesto, delimitador);
			
			auxE = new Empleado(user, password, nombre, apellido, telefono, sexo, distrito, idTrabajador, puesto);
			l_empleados->agregaPos(auxE, i);
			i++;
		}
		// Cerramos Archivo
		archIN.close();

	}
	
	void lecturaArchivoProductos() {
		ifstream archIN;
		archIN.open(archivoProductos, ios::in); //Apertura
		if (!archIN.is_open())
		{
			cout << "Error: No se pudo abrir el archivo !!!" << endl;
			exit(1);
		}
		string linea;
		char delimitador = '|'; //Separador de cada columna de la línea
		int i = 0;
		Producto<string>* aux;
		// Encabezado: Leemos la primera línea para descartarla, pues es el encabezado
		getline(archIN, linea);
		// Contenido: Leemos todas las líneas
		while (getline(archIN, linea))
		{
			stringstream stream(linea); // Convertir la cadena a un stream			
			string idProduct, nombre, precio, cantidad, fechaCaducidad;
			// Extraer todos los valores de esa fila [considerando 3 columans]
			getline(stream, idProduct, delimitador);
			getline(stream, nombre, delimitador);
			getline(stream, precio, delimitador);
			getline(stream, cantidad, delimitador);
			getline(stream, fechaCaducidad, delimitador);
			aux = new Producto<string>(idProduct, nombre, precio, cantidad, fechaCaducidad);
			l_productos->agregaPos(aux, i);
			i++;
		}
		// Cerramos Archivo
		archIN.close();
	}

	void lecturaArchivoReclamo() {
		ifstream archIN;
		archIN.open(archivoReclamo, ios::in); //Apertura
		if (!archIN.is_open())
		{
			cout << "Error: No se pudo abrir el archivo !!!" << endl;
			exit(1);
		}
		string linea;
		char delimitador = '|'; //Separador de cada columna de la línea
		int i = 0;
		Reclamo<string>* auxR;
		// Encabezado: Leemos la primera línea para descartarla, pues es el encabezado
		getline(archIN, linea);
		// Contenido: Leemos todas las líneas
		while (getline(archIN, linea))
		{
			stringstream stream(linea); // Convertir la cadena a un stream			
			string iDReclamo,fecha,nombre,telefono,distrito,nombreProducto,tipo,detalle,pedido;
			// Extraer todos los valores de esa fila [considerando 3 columans]
			getline(stream, iDReclamo, delimitador);
			getline(stream, fecha, delimitador);
			getline(stream, nombre, delimitador);
			getline(stream, telefono, delimitador);
			getline(stream, distrito, delimitador);
			getline(stream, nombreProducto, delimitador);
			getline(stream, tipo, delimitador);
			getline(stream, detalle, delimitador);
			getline(stream, pedido, delimitador);
			auxR = new Reclamo<string>(iDReclamo, fecha, nombre, telefono, distrito, nombreProducto, tipo, detalle, pedido);
			l_reclamo->agregaPos(auxR, i);
			i++;
		}
		// Cerramos Archivo
		archIN.close();
	}

	void lecturaArchivoProveedor() {
		ifstream archIN;
		archIN.open(archivoProveedor, ios::in); //Apertura
		if (!archIN.is_open())
		{
			cout << "Error: No se pudo abrir el archivo !!!" << endl;
			exit(1);
		}
		string linea;
		char delimitador = '|'; //Separador de cada columna de la línea
		int i = 0;
		Proveedor* auxP;
		// Encabezado: Leemos la primera línea para descartarla, pues es el encabezado
		getline(archIN, linea);
		// Contenido: Leemos todas las líneas
		while (getline(archIN, linea))
		{
			stringstream stream(linea); // Convertir la cadena a un stream			
			string nombre,telefono,distrito,producto;
			// Extraer todos los valores de esa fila [considerando 3 columans]
			getline(stream, nombre, delimitador);
			getline(stream, telefono, delimitador);
			getline(stream, distrito, delimitador);
			getline(stream, producto, delimitador);
			
			auxP = new Proveedor(nombre, telefono, distrito, producto);
			l_proveedor->agregaPos(auxP, i);
			i++;
		}
		// Cerramos Archivo
		archIN.close();
	}

	//Menu del programa
	void menu(){
		int opcion;
		cout << "=============:: Menu ::=============" << endl;
		cout << "[1] Vista Empleado" << endl;
		cout << "[2] Vista Usuario" << endl;
		cout << "Seleccione una opcion... "; cin >> opcion;
		switch (opcion)
		{
		case 1: 
			system("cls");
			vistaEmpleado();
			break;
		case 2:
			system("cls");
			vistaUsuario();
			break;
		}
	}

	void vistaUsuario(){
		int op = 0;
		int i = 0;
		do
		{
			cout << "=============:: Menu ::=============" << endl;
			cout << "[1] Ingresar" << endl;
			cout << "[2] Registrar" << endl;
			cout << "Seleccione una opcion... ";  cin >> op;
			switch (op)
			{
			case 1:
				system("cls");
				loginUsuario();
				break;
			case 2:
				system("cls");
				registerUsuario(i);
				i++;
				break;
			}
		} while (op != 3);
	}

	void loginUsuario() {
		string user, password;		
		do
		{
			cout << "=============:: Login ::=============" << endl;
			cout << "Ingresar Usuario: "; cin >> user; cout << endl;
			for (int i = 0; i < l_usuario->longitud(); i++)
			{
				if (l_usuario->obtenerPos(i)->getUser() == user)
				{
					cout << "Ingresar contraseña: "; cin >> password; cout << endl;
					if (l_usuario->obtenerPos(i)->getPassword() == password)
					{
						cout << "Registro exitoso..." << endl;
					}
				}
				else
				{
					cout << "El usuario ingresado es incorrecto...." << endl;
				}
			}
			
		} while (true);
	}

	void registerUsuario(int i) {
		string nombre, apellido, telefono, sexo, distrito;
		string user, password;
		Usuario* auxUsuario;
		int dinero = 0;
		int pos = 0;
		int op = 0;
		cout << "=============:: Resgistro ::=============" << endl;
		cout << "Ingresar nombre: "; cin >> nombre; cout << endl;
		cout << "Ingresar apellido: "; cin >> apellido; cout << endl;
		cout << "Ingresar telefono: "; cin >> telefono; cout << endl;
		cout << "Ingresar sexo (M/F): "; cin >> sexo; cout << endl;
		cout << "Ingresar distrito: "; cin >> distrito; cout << endl;
		//Luego se implementaran los métodos recursivos para generar contraseña y nombre de usuario
		cout << "¿Desea crear su nombre de usuario o desea generarlo aleatoriamente?: " << endl;
		cout << "[1] Crearlo" << endl;
		cout << "[2] Generarlo aleatoriamente" << endl;
		do {
			cout << "Seleccione una opcion... ";  cin >> op;

			if (op == 1) {
				cout << "Ingresar nombre de usuario: "; cin >> user; cout << endl;
			}
			else if (op == 2) {
				user = generarNombreUsuario(0, "", nombre);
			}
		} while (op != 1 && op != 2);

		op = 0;

		do {
			cout << "¿Desea crear su contrasena o desea generarla aleatoriamente?: " << endl;
			cout << "[1] Crearla" << endl;
			cout << "[2] Generarla aleatoriamente" << endl;
			cout << "Seleccione una opcion... ";  cin >> op;
			if (op == 1) {
				do {
					cout << "Ingresar constrasena (8 caracteres max): "; cin >> password; cout << endl;
				} while (password.length() > 8);
			}
			else if (op == 2) {
				password = generarContrasena(8);
			}
		} while (op != 1 && op != 2);

		auxUsuario = new Usuario(user, password, nombre, apellido, telefono, sexo, distrito, dinero);
		//Lista Usuarios -> Agregar
		cout << auxUsuario->getUser() << endl;
		cout << auxUsuario->getPassword() << endl;
		l_usuario->agregaPos(auxUsuario,i);
	}

	void vistaEmpleado() {
		int op = 0;
		int coni = 0;
		do
		{
			cout << "=============:: Menu ::=============" << endl;
			cout << "[1] Ingresar" << endl;
			cout << "[2] Registrar" << endl;
			cout << "Seleccione una opcion... ";  cin >> op;
			switch (op)
			{
			case 1:
				system("cls");
				login();
				break;
			case 2:
				system("cls");
				registro(coni);
				coni++;
				break;
			}
		} while (op != 3);				
	}

	void login() {
		string user, password;
		string C_user, C_password;
		Empleado* aux;
		Empleado* aux2;
		do
		{
			cout << "=============:: Login ::=============" << endl;
			cout << "Ingresar Usuario: "; cin >> user; cout << endl;
			aux = new Empleado(user, "", "", "", "", "", "", "", "");
			C_user = l_empleados->buscarUsuario(aux);
			if (C_user == user)
			{
				cout << "Ingresar contraseña: "; cin >> password; cout << endl;
				aux2 = new Empleado("", password, "", "", "", "", "", "", "");
				C_password = l_empleados->buscarPassword(aux2);
				if (C_password == password)
				{
					adminOpciones();
					break;					
				}
				else
				{
					cout << "La contraseña ingresada no es correcta..." << endl;
				}
			}
			else
			{
				cout << "EL usuario ingresado no es correcto..." << endl;
			}
		} while (true);		
	}

	void registro(int coni) {
		string user,password,nombre,apellido,telefono,sexo,distrito,idTrabajador,puesto;
		Empleado* aux;				
		cout << "=============:: Resgistro ::=============" << endl;
		cout << "Ingresar un Usuario: "; cin >> user; cout << endl;
		cout << "Ingresar una contraseña: "; cin >> password; cout << endl;
		cout << "Ingresar un nombre: "; cin >> nombre; cout << endl;
		cout << "Ingresar un apellido: "; cin >> apellido; cout << endl;
		cout << "Ingresar un telefono: "; cin >> telefono; cout << endl;
		cout << "Ingrese su genero: "; cin >> sexo; cout << endl;
		cout << "Ingrese su distrito: "; cin >> distrito; cout << endl;
		cout << "Ingrese su idTrabajador: "; cin >> idTrabajador; cout << endl;
		cout << "Ingrese su puesto: "; cin >> puesto; cout << endl;	
		aux = new Empleado(user, password, nombre, apellido, telefono, sexo, distrito, idTrabajador, puesto);
		l_empleados->agregaPos(aux, coni);		
	}


	void adminOpciones() {
		int opcionM;
		int i = 0;
		int p = 0;
		while (true)
		{
			cout << "=============:: Admin Menu ::=============" << endl;
			cout << "[1] Ingresar Productos" << endl;
			cout << "[2] Ver Productos" << endl;
			cout << "[3] Buscar Productos" << endl;
			cout << "[4] Modificar Producto" << endl;
			cout << "[5] Ver Pedidos" << endl;
			cout << "[6] Ver Reclamos" << endl;
			cout << "[7] Ingresar Proveedor" << endl;
			cout << "[8] Ver Proveedor" << endl;
			cout << "[9] Buscar Proveedor" << endl;
			cout << "[10] Ver Boletas" << endl;
			cout << "[11] Salir" << endl;
			cout << "Seleccione una opcion : "; cin >> opcionM;
			switch (opcionM)
			{
			case 1: 
				system("cls");
				ingresarProducto(i);
				i++;
				break;
			case 2:
				system("cls");
				cout << "==============:: Lista de Productos ::==============" << endl;
				for (int i = 0; i < l_productos->longitud(); i++)
				{
					l_productos->obtenerPos(i)->mostrarProducto();
					cout << "--------------------------------------" << endl;
				}
				break;
			case 3:
				system("cls");
				buscarProducto();
				break;
			case 4:
				system("cls");
				modificarProducto();
				break;
			case 5:

				break;
			case 6:
				system("cls");
				verReclamos();
				break;
			case 7:
				system("cls");
				ingresarProveedor(p);
				p++;
				break;
			case 8:
				system("cls");
				cout << "==============:: Lista de Proveedores ::==============" << endl;
				for (int i = 0; i < l_proveedor->longitud(); i++)
				{
					l_proveedor->obtenerPos(i)->mostrar();
					cout << "--------------------------------------" << endl;
				}
				break;
			case 9:
				system("cls");
				buscarProveedor();
				break;
			case 10:

				break;
			case 11:
				break;
				break;
			}
		}		
	}

	void ingresarProducto(int i) {
		string idProduct,nombre,precio,cantidad,fechaCad;
		Producto<string>* auxProduct;		
		cout << "=============:: Ingresar Producto ::=============" << endl;
		cout << "Ingresar IDProducto: "; cin >> idProduct; cout << endl;
		cout << "Ingresar Nombre del Producto: "; cin >> nombre; cout << endl;
		cout << "Ingresar Precio del Producto: "; cin >> precio; cout << endl;
		cout << "Ingresar cantidad del Producto: "; cin >> cantidad; cout << endl;
		cout << "Ingresar Fecha de caducidad del Producto: "; cin >> fechaCad; cout << endl;
		auxProduct = new Producto<string>(idProduct,nombre,precio,cantidad,fechaCad);
		l_productos->agregaPos(auxProduct, i);		
	}

	void buscarProducto() {
		string nombre, precio;
		int opciones;
		Producto<string>* auxProduct;
		cout << "=============:: Buscar Producto ::=============" << endl;
		cout << "[1] Buscar por Nombre" << endl;
		cout << "[2] Buscar por Precio" << endl;
		cout << "Seleccionar una opcion: "; cin >> opciones;
		switch (opciones)
		{
		case 1:
			cout << "=============:: Buscar Producto ::=============" << endl;
			cout << "Ingresar Nombre del producto: "; cin >> nombre; cout << endl;			
						for (int i = 0; i < l_productos->longitud(); i++)
			{
				if (l_productos->obtenerPos(i)->getNombre() == nombre)
				{
					l_productos->obtenerPos(i)->mostrarProducto();
					cout << "------------------------------------" << endl;
				}				
			}
			break;
		case 2:
			cout << "=============:: Buscar Producto ::=============" << endl;
			cout << "Ingresar Precio del producto: "; cin >> precio; cout << endl;
			for (int i = 0; i < l_productos->longitud(); i++)
			{
				if (l_productos->obtenerPos(i)->getPrecio() == precio)
				{
					l_productos->obtenerPos(i)->mostrarProducto();
					cout << "------------------------------------" << endl;
				}
			}
			break;
		}
		

	}

	void modificarProducto() {
		string nombreB;
		string idProduct, nombre, precio, cantidad, fechaCad;
		Producto<string>* auxProduct;
		cout << "=============:: Buscar Producto a Modificar ::=============" << endl;
		cout << "ingre el nombre: "; cin >> nombreB; cout << endl;
		for (int i = 0; i < l_productos->longitud(); i++)
		{
			if (l_productos->obtenerPos(i)->getNombre() == nombreB)
			{
				l_productos->obtenerPos(i)->mostrarProducto();
				cout << "=============:: Modificar Producto ::=============" << endl;
				cout << "Ingresar IDProducto: "; cin >> idProduct; cout << endl;
				cout << "Ingresar Nombre del Producto: "; cin >> nombre; cout << endl;
				cout << "Ingresar Precio del Producto: "; cin >> precio; cout << endl;
				cout << "Ingresar cantidad del Producto: "; cin >> cantidad; cout << endl;
				cout << "Ingresar Fecha de caducidad del Producto: "; cin >> fechaCad; cout << endl;
				auxProduct = new Producto<string>(idProduct, nombre, precio, cantidad, fechaCad);
				l_productos->modificarPos(auxProduct, i);
				break;
			}
		}
	}

	void verReclamos() {
		int num = 1;
		for (int i = 0; i < l_reclamo->longitud(); i++)
		{
			cout << "--------------------------------" << endl;
			cout << "Reclamo Numero: " << num << endl;
			cout << "--------------------------------" << endl;
			l_reclamo->obtenerPos(i)->mostrarReclamo();
			cout << "--------------------------------" << endl;
			num++;
		}
	}

	void ingresarProveedor(int p) {
		string nombre,telefono,distrito,producto;
		Proveedor* auxProve;
		cout << "=============:: Ingresar Producto ::=============" << endl;
		cout << "Ingresar Nombre del Proveedor: "; cin >> nombre; cout << endl;
		cout << "Ingresar Telefono: "; cin >> telefono; cout << endl;
		cout << "Ingresar Distrito: "; cin >> distrito; cout << endl;
		cout << "Ingresar Producto: "; cin >> producto; cout << endl;
		auxProve = new Proveedor(nombre, telefono, distrito, producto);
		l_proveedor->agregaPos(auxProve, p);
	}

	void buscarProveedor() {
		string nombre;
		cout << "=============:: Buscar Proveedor ::=============" << endl;
		cout << "Ingresar Nombre del Proveedor: "; cin >> nombre; cout << endl;
		for (int i = 0; i < l_proveedor->longitud(); i++)
		{
			if (l_proveedor->obtenerPos(i)->getnombre()==nombre)
			{
				l_proveedor->obtenerPos(i)->mostrar();
				cout << "----------------------------" << endl;
			}
		}
	}






};
