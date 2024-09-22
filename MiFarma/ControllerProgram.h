#pragma once
#include"Empleado.h"
#include"Reclamos.h"
#include"Proveedor.h"
#include"Funciones.h"
#include"Repartidor.h"
#include"DeliveryInterfaz.h"
#include"CompraInterfaz.h"
#include"ProductosInterfaz.h"

class Programa {
private:
	//declarando lista
	Lista<Empleado*>* l_empleados;
	Lista<Producto<string>*>* l_productos;
	Lista<Usuario*>* l_usuario;
	Lista<Reclamo<string>*>* l_reclamo;
	Lista<Proveedor*>* l_proveedor;
	//Declaron Interfaces
	MainInterfaz* mainInterfaz;
	ProductosInterfaz* productosInterfaz;
	DeliveryInterfaz* deliveryInterfaz;
	CompraInterfaz* compraInterfaz;
	//Declarando colas
	queue<Pedido> c_Pedidos;
public:
	Programa() {
		//Listas
		l_empleados = new Lista<Empleado*>();
		l_productos = new Lista<Producto<string>*>();
		l_usuario = new Lista<Usuario*>();
		l_reclamo = new Lista<Reclamo<string>*>();
		l_proveedor = new Lista<Proveedor*>();
		//Interfaces o decoracion
		mainInterfaz = new MainInterfaz();
		productosInterfaz = new ProductosInterfaz();
		deliveryInterfaz = new DeliveryInterfaz();
		compraInterfaz = new CompraInterfaz();
	}
	//importacion de archivos
	void lecturaArchivoEmpleados() {
		ifstream archIN;
		archIN.open(archivoEmpleados, ios::in); //Apertura
		if (!archIN.is_open())
		{
			cout << "Error: No se pudo abrir el archivo !!!";
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
			cout << "Error: No se pudo abrir el archivo !!!";
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
			string idProduct, nombre, precio, categoria, cantidad, fechaCaducidad;
			// Extraer todos los valores de esa fila [considerando 3 columans]
			getline(stream, idProduct, delimitador);
			getline(stream, nombre, delimitador);
			getline(stream, precio, delimitador);
			getline(stream, categoria, delimitador);
			getline(stream, cantidad, delimitador);
			getline(stream, fechaCaducidad, delimitador);
			aux = new Producto<string>(idProduct, nombre, precio, categoria, cantidad, fechaCaducidad);
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
			cout << "Error: No se pudo abrir el archivo !!!";
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
			string iDReclamo, fecha, nombre, telefono, distrito, nombreProducto, tipo, detalle, pedido;
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
			cout << "Error: No se pudo abrir el archivo !!!";
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
			string nombre, telefono, distrito, producto;
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
		//mainInterfaz->inicio();
		system("cls");
		//Leer los archivos preestablecidos
		lecturaArchivoEmpleados();
		lecturaArchivoProductos();
		lecturaArchivoReclamo();
		lecturaArchivoProveedor();
		//Menu
		int opcion;
		mainInterfaz->encuadrar();
		Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 0);
		cout << "=============:: Menu ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 1);
		cout << "[1] Vista Empleado";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 2);
		cout << "[2] Vista Usuario";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 3);
		cout << "Seleccione una opcion: "; cin >> opcion;
		switch (opcion)
		{
		case 1: 
			vistaEmpleado();
			break;
		case 2:
			vistaUsuario();
			break;
		}
	}

	void vistaEmpleado() {
		int op = 0;
		int coni = 0;
		do
		{
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 0);
			cout << "=============:: Menu ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 1);
			cout << "[1] Ingresar";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 2);
			cout << "[2] Registrar";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 3);
			cout << "Seleccione una opcion... ";  cin >> op;
			switch (op)
			{
			case 1:
				loginEmpleado();
				break;
			case 2:
				registroEmpleado(coni);
				coni++;
				break;
			}
		} while (op != 3);
	}

	void vistaUsuario(){
		int op = 0;
		int i = 0;
		do
		{
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 0);
			cout << "=============:: Menu ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 1);
			cout << "[1] Ingresar";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 2);
			cout << "[2] Registrar";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 3);
			cout << "Seleccione una opcion: ";  cin >> op;
			switch (op)
			{
			case 1:
				system("cls");
				mainInterfaz->encuadrar();
				loginUsuario();
				break;
			case 2:
				system("cls");
				mainInterfaz->encuadrar();
				registerUsuario(i);
				i++;
				break;
			}
		} while (op != 3);
	}

	void loginEmpleado() {
		string user, password;
		do
		{
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
			cout << "=============:: Login ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 1);
			cout << "Ingresar Usuario: "; cin >> user;
			if (user == "1") break;
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 2);
			cout << "Ingresar contrasena: "; cin >> password;
			for (int i = 0; i < l_empleados->longitud(); i++)
			{
				if (l_empleados->obtenerPos(i)->getUser() == user)
				{
					if (l_empleados->obtenerPos(i)->getPassword() == password)
					{
						system("cls");
						mainInterfaz->encuadrar();
						Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
						cout << "Ingreso exitoso...";
						system("pause>>null");
						adminOpciones();
						break;
					}
					else {
						system("cls");
						mainInterfaz->encuadrar();
						Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
						cout << "La contrasena ingresada es incorrecta....";
						system("pause>>null");
						break;
					}
				}
				else
				{
					system("cls");
					mainInterfaz->encuadrar();
					Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
					cout << "El usuario ingresado es incorrecto....";
					system("pause>>null");
					break;
				}
			}

		} while (true);
	}

	void loginUsuario() {
		string user, password;
		do
		{
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
			cout << "=============:: Login ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 1);
			cout << "Ingresar Usuario: "; cin >> user;
			if (user == "1") break;
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 2);
			cout << "Ingresar contrasena: "; cin >> password;
			for (int i = 0; i < l_usuario->longitud(); i++)
			{
				if (l_usuario->obtenerPos(i)->getUser() == user)
				{
					if (l_usuario->obtenerPos(i)->getPassword() == password)
					{
						system("cls");
						mainInterfaz->encuadrar();
						Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
						cout << "Ingreso exitoso...";
						system("pause>>null");
						userOpciones();
						break;
					}
					else {
						system("cls");
						mainInterfaz->encuadrar();
						Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
						cout << "La contrasena ingresada es incorrecta....";
						system("pause>>null");
						break;
					}
				}
				else
				{
					system("cls");
					mainInterfaz->encuadrar();
					Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
					cout << "El usuario ingresado es incorrecto....";
					system("pause>>null");
					break;
				}
			}

		} while (true);
	}

	void registroEmpleado(int coni) {
		system("cls");
		mainInterfaz->encuadrar();
		string user, password, nombre, apellido, telefono, sexo, distrito, idTrabajador, puesto;
		Empleado* aux;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Resgistro ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "Ingresar un Usuario: "; cin >> user;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cout << "Ingresar una contrasena: "; cin >> password;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "Ingresar un nombre: "; cin >> nombre;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
		cout << "Ingresar un apellido: "; cin >> apellido;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 5);
		cout << "Ingresar un telefono: "; cin >> telefono;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 6);
		cout << "Ingrese su genero: "; cin >> sexo;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 7);
		cout << "Ingrese su distrito: "; cin >> distrito;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 8);
		cout << "Ingrese su idTrabajador: "; cin >> idTrabajador;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 9);
		cout << "Ingrese su puesto: "; cin >> puesto;
		aux = new Empleado(user, password, nombre, apellido, telefono, sexo, distrito, idTrabajador, puesto);
		l_empleados->agregaPos(aux, coni);
	}

	void registerUsuario(int i) {
		string nombre, apellido, telefono, sexo, distrito;
		string user, password;
		Usuario* auxUsuario;
		int dinero = 0;
		int pos = 0;
		int op = 0;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Resgistro ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "Ingresar nombre: "; cin >> nombre;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cout << "Ingresar apellido: "; cin >> apellido;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "Ingresar telefono: "; cin >> telefono;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
		cout << "Ingresar sexo (M/F): "; cin >> sexo;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 5);
		cin.ignore();
		cout << "Ingresar distrito: "; getline(cin, distrito);
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 6);
		//Luego se implementaran los métodos recursivos para generar contraseña y nombre de usuario
		do {
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cout << "Desea crear su nombre de usuario o desea generarlo aleatoriamente?: ";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
			cout << "[1] Crearlo";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
			cout << "[2] Generarlo aleatoriamente";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
			cout << "Seleccione una opcion: ";  cin >> op;

			if (op == 1) {
				Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
				cout << "Ingresar nombre de usuario: "; cin >> user;
			}
			else if (op == 2) {
				user = generarNombreUsuario(0, "", nombre);
			}
			else
			{
				Console::SetCursorPosition(ANCHO / 3, ALTO / 4 - 1);
				cout << "Opcion Incorrecta!";
			}
		} while (op != 1 && op != 2);

		op = 0;

		do {
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cout << "Desea crear su contrasena o desea generarla aleatoriamente?: ";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
			cout << "[1] Crearla";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
			cout << "[2] Generarla aleatoriamente";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
			cout << "Seleccione una opcion: ";  cin >> op;
			if (op == 1) {
				do {
					Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
					cout << "Ingresar constrasena (8 caracteres max): "; cin >> password;
				} while (password.length() > 8);
			}
			else if (op == 2) {
				password = generarContrasena(8);
			}
		} while (op != 1 && op != 2);

		system("cls");
		mainInterfaz->encuadrar();
		auxUsuario = new Usuario(user, password, nombre, apellido, telefono, sexo, distrito, dinero);
		//Lista Usuarios -> Agregar
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "Usuario creado: " <<auxUsuario->getUser();
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "Contrasena creada: "<< auxUsuario->getPassword();
		l_usuario->agregaPos(auxUsuario,i);
		system("pause>>null");
	}


	void userOpciones() {
		int opcionM;
		int i = 0;
		int p = 0;
		while (true)
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cout << "=============:: User Menu ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
			cout << "[1] Elegir Categoria";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
			cout << "[2] Ver Carrito";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
			cout << "[3] Ingresar Reclamo";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
			cout << "[4] Salir";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 5);
			cout << "Seleccione una opcion : "; cin >> opcionM;
			if (opcionM == 10) break;
			switch (opcionM)
			{
			case 1:

				break;
			case 2:

				break;
			case 3:

				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			case 9:
				break;
			}
			system("pause>>null");
		}
	}

	void adminOpciones() {
		int opcionM;
		int i = 0;
		int p = 0;
		while (true)
		{
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cout << "=============:: Admin Menu ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
			cout << "[1] Ingresar Producto";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
			cout << "[2] Buscar Productos";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
			cout << "[3] Modificar Producto";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
			cout << "[4] Buscar Pedidos";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 5);
			cout << "[5] Buscar Reclamos";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 6);
			cout << "[6] Ingresar Proveedor";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 7);
			cout << "[7] Buscar Proveedores";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 8);
			cout << "[8] Buscar Boletas";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 9);
			cout << "[9] Salir";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 10);
			cout << "Seleccione una opcion : "; cin >> opcionM;
			if (opcionM == 9)break;
			switch (opcionM)
			{
			case 1: 
				system("cls");
				mainInterfaz->encuadrar();
				ingresarProducto(i);
				i++;
				break;
			case 2:
				system("cls");
				mainInterfaz->encuadrar();
				buscarProducto();
				break;
			case 3:
				system("cls");
				mainInterfaz->encuadrar();
				modificarProducto();
				break;
			case 4:
				break;
			case 5:
				system("cls");
				mainInterfaz->encuadrar();
				buscarReclamos();
				break;
			case 6:
				system("cls");
				mainInterfaz->encuadrar();
				ingresarProveedor(p);
				p++;
				break;
			case 7:
				system("cls");
				mainInterfaz->encuadrar();
				buscarProveedor();
				break;
			case 8:
				break;
			}
			system("pause>>null");
		}		
	}

	void ingresarProducto(int i) {
		string idProduct,nombre,precio, categoria,cantidad,fechaCad;
		Producto<string>* auxProduct;		
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Ingresar Producto ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "Ingresar IDProducto: "; cin >> idProduct;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cout << "Ingresar Nombre del Producto: "; cin >> nombre;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "Ingresar Precio del Producto: "; cin >> precio;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
		cout << "Ingresar Categoria del Producto: "; cin >> categoria;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 5);
		cout << "Ingresar cantidad del Producto: "; cin >> cantidad;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 6);
		cout << "Ingresar Fecha de caducidad del Producto: "; cin >> fechaCad;;
		auxProduct = new Producto<string>(idProduct,nombre,precio,categoria,cantidad,fechaCad);
		l_productos->agregaPos(auxProduct, i);		
	}

	void buscarProducto() {
		string nombre, categoria;
		int opcionesP, opcionesC, contEspacios = 0;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Buscar Producto ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "[1] Buscar por categoria";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cout << "[2] Buscar por Nombre";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "Seleccionar una opcion: "; cin >> opcionesP;
		switch (opcionesP)
		{
		case 1:
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cout << "=============:: Buscar por categoria ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
			cout << "[1] Farmaco";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
			cout << "[2] Cosmeticos";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
			cout << "[3] Cuidado para bebes";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
			cout << "[4] Cuidado personal";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 5);
			cout << "[5] Personas mayores";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 6);
			cout << "Ingresar opcion: "; cin >> opcionesC;
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 0);
			cout << "=============:: Productos ::=============";
			switch (opcionesC)
			{
			case 1: categoria = "Farmaco"; break;
			case 2: categoria = "Cosmeticos"; break;
			case 3: categoria = "Cuidado para bebes"; break;
			case 4: categoria = "Cuidado personal"; break;
			case 5: categoria = "Personas mayores"; break;
			}
			contEspacios = 0;
			for (int i = 0; i < l_productos->longitud(); i++)
			{
				if (contEspacios > 20) break;
				if (l_productos->obtenerPos(i)->getCategoria() == categoria)
				{
					Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 1 + contEspacios);
					cout << l_productos->obtenerPos(i)->getNombre();
					contEspacios++;
				}
			}
			break;
		case 2:
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cout << "=============:: Buscar por Nombre ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
			cout << "Ingresar Nombre del producto: ";
			cin.ignore(); getline(cin, nombre);
			for (int i = 0; i < l_productos->longitud(); i++)
			{
				if (l_productos->obtenerPos(i)->getNombre() == nombre)
				{
					l_productos->obtenerPos(i)->mostrarProducto(ANCHO / 3, ALTO / 4 + 2);
				}				
			}

			break;
		}
	}

	void modificarProducto() {
		string nombreB;
		string idProduct, nombre, precio, categoria, cantidad, fechaCad;
		Producto<string>* auxProduct;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Buscar Producto a Modificar ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "Ingrese el nombre : "; cin >> nombreB;
		for (int i = 0; i < l_productos->longitud(); i++)
		{
			if (l_productos->obtenerPos(i)->getNombre() == nombreB)
			{
				system("cls");
				mainInterfaz->encuadrar();
				l_productos->obtenerPos(i)->mostrarProducto(ANCHO / 3, ALTO / 5 + 0);
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 6);
				cout << "=============:: Modificar Producto ::=============";
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 7);
				cout << "Ingresar IDProducto: "; cin >> idProduct;
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 8);
				cout << "Ingresar Nombre del Producto: "; cin >> nombre;
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 9);
				cout << "Ingresar Precio del Producto: "; cin >> precio;
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 10);
				cout << "Ingresar Categoria del Producto: "; cin >> categoria;
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 11);
				cout << "Ingresar cantidad del Producto: "; cin >> cantidad;
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 12);
				cout << "Ingresar Fecha de caducidad del Producto: "; cin >> fechaCad;
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 13);
				auxProduct = new Producto<string>(idProduct, nombre, precio, categoria, cantidad, fechaCad);
				l_productos->modificarPos(auxProduct, i);
				break;
			}
		}
	}

	void buscarReclamos() {
		string idReclamo;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cin.ignore();
		cout << "Ingresar Id del Reclamo: "; getline(cin,idReclamo);
		system("cls");
		mainInterfaz->encuadrar();
		for (int i = 0; i < l_reclamo->longitud(); i++)
		{
			if (l_reclamo->obtenerPos(i)->getIdReclamo() == idReclamo)
			{
				l_reclamo->obtenerPos(i)->mostrarReclamo(ANCHO / 3, ALTO / 5 + 0);
			}
		}
		cin.ignore();
	}

	void ingresarProveedor(int p) {
		string nombre,telefono,distrito,producto;
		Proveedor* auxProve;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Ingresar Producto ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "Ingresar Nombre del Proveedor: "; cin >> nombre;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cout << "Ingresar Telefono: "; cin >> telefono;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "Ingresar Distrito: "; cin >> distrito;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
		cout << "Ingresar Producto: "; cin >> producto;
		auxProve = new Proveedor(nombre, telefono, distrito, producto);
		l_proveedor->agregaPos(auxProve, p);
	}

	void buscarProveedor() {
		string nombre;
		int contNombreIncorrecto = 0;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Buscar Proveedor ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cin.ignore();
		cout << "Ingresar Nombre del Proveedor: "; getline(cin, nombre);
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		system("cls");
		mainInterfaz->encuadrar();
		for (int i = 0; i < l_proveedor->longitud(); i++)
		{
			if (l_proveedor->obtenerPos(i)->getnombre()==nombre)
			{
				l_proveedor->obtenerPos(i)->mostrar(ANCHO / 3, ALTO / 5);
			}
			else
			{
				contNombreIncorrecto++;
			}
		}

		if (contNombreIncorrecto == l_proveedor->longitud())
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 0);
			cout << "No hay proveedores con ese nombre!";
		}
	}


};
