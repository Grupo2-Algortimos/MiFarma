#pragma once
#include"Empleado.h"
#include"Reclamos.h"
#include"Proveedor.h"
#include"Funciones.h"
#include"DeliveryInterfaz.h"
#include"CompraInterfaz.h"
#include"ProductosInterfaz.h"
#include"Boleta.h"

class Programa {
private:
	//declarando lista
	Lista<Empleado*>* l_empleados;
	Lista<Producto<string>*>* l_productos;
	Lista<Producto<string>*>* l_productos_comprados;
	Lista<Usuario*>* l_usuario;
	Lista<Reclamo<string>*>* l_reclamo;
	Lista<Proveedor*>* l_proveedor;
	Lista<Boleta<string>*>* l_boletas;
	//Declaron Interfaces
	MainInterfaz* mainInterfaz;
	ProductosInterfaz* productosInterfaz;
	DeliveryInterfaz* deliveryInterfaz;
	CompraInterfaz* compraInterfaz;
	//Declarando colas
	queue<Pedido*> c_pedidos;
	//Declarando usuario
	Usuario* usario_actual;
	Pedido* pedido_usuario;

	// Otras variables
	int cont_productos_comprados;
public:
	Programa() {
		//Listas
		l_empleados = new Lista<Empleado*>();
		l_productos = new Lista<Producto<string>*>();
		l_productos_comprados = new Lista<Producto<string>*>();
		l_usuario = new Lista<Usuario*>();
		l_reclamo = new Lista<Reclamo<string>*>();
		l_proveedor = new Lista<Proveedor*>();
		l_boletas = new Lista<Boleta<string>*>();
		//Interfaces o decoracion
		mainInterfaz = new MainInterfaz();
		productosInterfaz = new ProductosInterfaz();
		deliveryInterfaz = new DeliveryInterfaz();
		compraInterfaz = new CompraInterfaz();
		usario_actual = NULL;
		pedido_usuario = NULL;
		//Leer los archivos preestablecidos
		lecturaArchivoEmpleados();
		lecturaArchivoProductos();
		lecturaArchivoReclamo();
		lecturaArchivoProveedor();
		lecturaArchivoBoletas();
		lecturaArchivoUsuario();
		agregandoPedidos();


		//Otras variables
		cont_productos_comprados = 0;
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
			// Extraer todos los valores de esa fila [considerando 4 columnas]
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

	void lecturaArchivoBoletas() {
		ifstream archIN;
		archIN.open(archivoBoletas, ios::in); //Apertura
		if (!archIN.is_open())
		{
			cout << "Error: No se pudo abrir el archivo !!!";
			exit(1);
		}
		string linea;
		char delimitador = '|'; //Separador de cada columna de la línea
		int i = 0;
		Boleta<string>* auxB;
		// Encabezado: Leemos la primera línea para descartarla, pues es el encabezado
		getline(archIN, linea);
		// Contenido: Leemos todas las líneas
		while (getline(archIN, linea))
		{
			stringstream stream(linea); // Convertir la cadena a un stream			
			string idBoleta, nombre, fecha, montoUsuario, costoPedido;
			// Extraer todos los valores de esa fila [considerando 4 columans]
			getline(stream, idBoleta, delimitador);
			getline(stream, nombre, delimitador);
			getline(stream, fecha, delimitador);
			getline(stream, montoUsuario, delimitador);
			getline(stream, costoPedido, delimitador);

			auxB = new Boleta<string>(idBoleta, nombre, fecha, montoUsuario, costoPedido);
			l_boletas->agregaPos(auxB, i);
			i++;
		}
		// Cerramos Archivo
		archIN.close();
	}

	void lecturaArchivoUsuario() {
		ifstream archIN;
		archIN.open(archivoUsuarios, ios::in); //Apertura
		if (!archIN.is_open())
		{
			cout << "Error: No se pudo abrir el archivo !!!";
			exit(1);
		}
		string linea;
		char delimitador = '|'; //Separador de cada columna de la línea
		int i = 0;
		Usuario* auxU;
		// Encabezado: Leemos la primera línea para descartarla, pues es el encabezado
		getline(archIN, linea);
		// Contenido: Leemos todas las líneas
		while (getline(archIN, linea))
		{
			stringstream stream(linea); // Convertir la cadena a un stream			
			string user, password, nombre, apellido, telefono, sexo, distrito, dinero;
			// Extraer todos los valores de esa fila [considerando 3 columans]
			getline(stream, user, delimitador);
			getline(stream, password, delimitador);
			getline(stream, nombre, delimitador);
			getline(stream, apellido, delimitador);
			getline(stream, telefono, delimitador);
			getline(stream, sexo, delimitador);
			getline(stream, distrito, delimitador);
			getline(stream, dinero, delimitador);

			auxU = new Usuario(user, password, nombre, apellido, telefono, sexo, distrito, stod(dinero));
			l_usuario->agregaPos(auxU, i);
			i++;
		}
		// Cerramos Archivo
		archIN.close();
	}

	void agregandoPedidos()
	{
		Random r;
		Lista<Producto<string>*>* l_productosAleatorios = new Lista<Producto<string>*>();
		int catidad_productos = r.Next(1, 5); // [1-4]
		int num_alea;
		for (int j = 0; j < catidad_productos; j++)
		{
			num_alea = r.Next(0, l_productos->longitud() + 1);
			l_productosAleatorios->agregaPos(l_productos->obtenerPos(num_alea), j);
		}
		Pedido* pedido1 = new Pedido("P01", "Jose", "Kevin", "Puente Piedra", l_productosAleatorios, "En Camino", "Bicicleta");
		c_pedidos.push(pedido1);

		l_productosAleatorios = new Lista<Producto<string>*>();
		catidad_productos = r.Next(1, 5); // [1-4]
		for (int j = 0; j < catidad_productos; j++)
		{
			num_alea = r.Next(0, l_productos->longitud() + 1);
			l_productosAleatorios->agregaPos(l_productos->obtenerPos(num_alea), j);
		}
		Pedido* pedido2 = new Pedido("P02", "Maria", "Luz", "San miguel", l_productosAleatorios, "Pendiente", "Motocicleta");
		c_pedidos.push(pedido2);

		l_productosAleatorios = new Lista<Producto<string>*>();
		catidad_productos = r.Next(1, 5); // [1-4]
		for (int j = 0; j < catidad_productos; j++)
		{
			num_alea = r.Next(0, l_productos->longitud() + 1);
			l_productosAleatorios->agregaPos(l_productos->obtenerPos(num_alea), j);
		}
		Pedido* pedido3 = new Pedido("P03", "Pepe", "Manuel", "San miguel", l_productosAleatorios, "Pendiente", "Bicicleta");
		c_pedidos.push(pedido3);
	}

	//Menu del programa
	void menu(){
		srand(time(NULL));
		//mainInterfaz->inicio();
		//Menu
		int opcion;
		while (true)
		{
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 0);
			cout << "=============:: Menu ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 1);
			cout << "[1] Vista Empleado";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 2);
			cout << "[2] Vista Usuario";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 3);
			cout << "[3] Salir del Programa";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 4);
			cout << "Seleccione una opcion: "; cin >> opcion;
			if (opcion == 3)break;
			switch (opcion)
			{
			case 1:
				vistaEmpleado();
				break;
			case 2:
				vistaUsuario();
				break;
			}
			system("pause>>null");
		}

	}

	void vistaEmpleado() {
		int op = 0;
		int coni = 0;
		string master_key = "";
		do
		{
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 0);
			cout << "=============:: Vista de Empleado ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 1);
			cout << "[1] Ingresar";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 2);
			cout << "[2] Registrar";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 3);
			cout << "[3] Salir";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 4);
			cout << "Seleccione una opcion... ";  cin >> op;
			if (op == 3)break;
			switch (op)
			{
			case 1:
				loginEmpleado();
				break;
			case 2:
				system("cls");
				mainInterfaz->encuadrar();
				Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 0);
				cin.ignore();
				cout << "Ingresar la master key: "; getline(cin, master_key);
				if (master_key == "mifarma")
				{
					registroEmpleado(coni);
					coni++;
				}
				else
				{
					Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 1);
					cout << "Master key incorrecta!";
				}
				break;
			}
			system("pause>>null");

		} while (true);
	}

	void vistaUsuario(){
		int op = 0;
		int i = 0;
		do
		{
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 0);
			cout << "=============:: Vista de Usuario ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 1);
			cout << "[1] Ingresar";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 2);
			cout << "[2] Registrar";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 3);
			cout << "[3] Salir";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 4);
			cout << "Seleccione una opcion: ";  cin >> op;
			if (op == 3)break;
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
		bool salir = false;
		while (true)
		{
			if (salir)break;
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
			cout << "=============:: Login de Empleado ::=============";
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
						salir = true;
						break;
					}
					else {
						system("cls");
						mainInterfaz->encuadrar();
						Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
						cout << "La contrasena ingresada es incorrecta....";
						system("pause>>null");
						salir = true;
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
					salir = true;
					break;
				}
			}
		}
	}

	void loginUsuario() {
		string user, password;
		bool salir = false;
		while(true)
		{
			l_productos_comprados = new Lista<Producto<string>*>();
			cont_productos_comprados = 0;
			if (salir)break;
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
			cout << "=============:: Login de Usuario ::=============";
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
						usario_actual = l_usuario->obtenerPos(i);
						cout << "Ingreso exitoso...";
						system("pause>>null");
						userOpciones();
						salir = true;
						break;
					}
					else {
						system("cls");
						mainInterfaz->encuadrar();
						Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
						cout << "La contrasena ingresada es incorrecta....";
						system("pause>>null");
						salir = true;
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
					salir = true;
					break;
				}
			}

		}
	}

	void registroEmpleado(int coni) {
		system("cls");
		mainInterfaz->encuadrar();
		string user, password, nombre, apellido, telefono, sexo, distrito, idTrabajador, puesto;
		Empleado* aux;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Resgistro de Empleado ::=============";
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
		cout << "=============:: Resgistro de Usuario ::=============";
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
		bool comprado = false;
		while (true)
		{
			if (comprado == true) break;
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cout << "=============:: User Menu ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
			cout << "[1] Listar Productos";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
			cout << "[2] Ver Carrito";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
			cout << "[3] Ingresar Reclamo";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
			cout << "[4] Comprar Productos";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 5);
			cout << "[5] Salir";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 6);
			cout << "Seleccione una opcion : "; cin >> opcionM;
			if (opcionM == 5) break;
			system("cls");
			mainInterfaz->encuadrar();
			switch (opcionM)
			{
			case 1:
				listarProducto();
				break;
			case 2:
				verCarrito();
				break;
			case 3:
				ingresarReclamo();
				break;
			case 4:
				comprado = comprarProductos();
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
			system("cls");
			mainInterfaz->encuadrar();
			switch (opcionM)
			{
			case 1: 
				ingresarProducto(i);
				i++;
				break;
			case 2:
				buscarProducto();
				break;
			case 3:
				modificarProducto();
				break;
			case 4:
				buscarPedidos();
				break;
			case 5:
				buscarReclamos();
				break;
			case 6:
				ingresarProveedor(p);
				p++;
				break;
			case 7:
				buscarProveedor();
				break;
			case 8:
				buscarBoletas();
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

	void buscarPedidos()
	{
		queue<Pedido*> c_pedidos_aux;
		int contIdIncorrecto = 0;
		c_pedidos_aux = this->c_pedidos;
		string idPedido;
		if (c_pedidos_aux.empty())
		{
			Console::SetCursorPosition(ANCHO / 2.5, ALTO / 2 + 0);
			cout << "No hay pedidos a mostrar!";
		}
		else
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cout << "=============:: Pedids ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
			cin.ignore();
			cout << "Ingresar Id del Pedido: "; getline(cin, idPedido);
			system("cls");
			mainInterfaz->encuadrar();
			for (int i = 0; i < c_pedidos_aux.size(); i++)
			{
				if (c_pedidos_aux.back()->getIdPedido() == idPedido && i == c_pedidos_aux.size() - 1)
				{
					c_pedidos_aux.back()->mostarInformacion(ANCHO / 4, ALTO / 5);
				}
				if (c_pedidos_aux.front()->getIdPedido() == idPedido)
				{
					c_pedidos_aux.front()->mostarInformacion(ANCHO / 4, ALTO / 5);
				}
				else
				{
					contIdIncorrecto++;
				}
				c_pedidos_aux.pop();
			}
		}
		if (contIdIncorrecto == c_pedidos_aux.size() + 1)
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
			cout << "No hay Pedidos con ese ID!";
		}
	}

	void buscarReclamos() {
		string idReclamo;
		int contIdIncorrecto = 0;
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
			else
			{
				contIdIncorrecto++;
			}
		}
		if (contIdIncorrecto == l_reclamo->longitud())
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 0);
			cout << "No hay reclamos con ese ID!";
		}	
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

	void buscarBoletas()
	{
		string idBoleta;
		int contIdIncorrecto = 0;
		if (l_boletas->esVacia())
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
			cout << "No hay boletas a mostrar!";
		}
		else
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cin.ignore();
			cout << "Ingresar Id del Boleta: "; getline(cin, idBoleta);
			system("cls");
			mainInterfaz->encuadrar();
			for (int i = 0; i < l_boletas->longitud(); i++)
			{
				if (l_boletas->obtenerPos(i)->getIdBoleta() == idBoleta)
				{
					l_boletas->obtenerPos(i)->mostrarInformacion(ANCHO / 3, ALTO / 5 + 0);
				}
				else
				{
					contIdIncorrecto++;
				}
			}
			if (contIdIncorrecto == l_boletas->longitud())
			{
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 0);
				cout << "No hay boletas con ese ID!";
			}
		}

	}

	void listarProducto()
	{
		int opcionesC, contNombreIncorrecto = 0;
		string nombre, categoria;
		Producto<string>* auxProducto;
		while (true)
		{
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cout << "===========:: Categorias ::=============";
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
			cout << "[6] Salir";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 7);
			cout << "Ingresar opcion: "; cin >> opcionesC;
			if (opcionesC == 6)break;
			system("cls");
			mainInterfaz->encuadrar();
			switch (opcionesC)
			{
			case 1: categoria = "Farmaco"; break;
			case 2: categoria = "Cosmeticos"; break;
			case 3: categoria = "Cuidado para bebes"; break;
			case 4: categoria = "Cuidado personal"; break;
			case 5: categoria = "Personas mayores"; break;
			}
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 0);
			cout << "=============:: Productos ::=============";
			int contEspacios = 0;
			for (int i = 0; i < l_productos->longitud(); i++)
			{
				if (contEspacios > 10) break;
				if (l_productos->obtenerPos(i)->getCategoria() == categoria)
				{
					Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 1 + contEspacios);
					cout << l_productos->obtenerPos(i)->getNombre();
					contEspacios++;
				}
			}
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 2 + contEspacios);
			cin.ignore();
			cout << "Ingresar nombre del producto: "; getline(cin, nombre);
			system("cls");
			mainInterfaz->encuadrar();
			for (int i = 0; i < l_productos->longitud(); i++)
			{
				if (l_productos->obtenerPos(i)->getNombre() == nombre)
				{
					auxProducto = this->l_productos->obtenerPos(i);
				}
				else
				{
					contNombreIncorrecto++;
				}
			}
			if (contNombreIncorrecto == l_productos->longitud())
			{
				Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
				cout << "No se encontro un producto con ese nombre!";
			}
			else
			{
				Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
				cout << "Producto Listado!";
				l_productos_comprados->agregaPos(auxProducto, cont_productos_comprados);
				cont_productos_comprados++;
			}
			system("pause>>null");
		}
	}

	void verCarrito()
	{
		int opcCarrito;
		int contEspacios = 0;
		if (l_productos_comprados->esVacia())
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
			cout << "No has listado ningun producto!";
		}
		else
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 0);
			cout << "===========:: Carrito ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 1);
			cout << "[1] Ordenar de menor a mayor";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 2);
			cout << "[2] Ordenar de mayor a menor";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 3);
			cout << "Escoger opcion: "; cin >> opcCarrito;
			if (l_productos_comprados->longitud() > 1)
			{
				switch (opcCarrito)
				{
				case 1:
					ordShellProductoMenorAMayor(l_productos_comprados);
					break;
				case 2:
					ordShellProductoMayorAMenor(l_productos_comprados);
					break;
				}
			}

			for (int i = 0; i < l_productos_comprados->longitud(); i++)
			{
				if (contEspacios > 10)
				{
					Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 4 + i);
					cout << "............" << endl;
					break;
				}
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 4 + i);
				cout << "- " <<l_productos_comprados->obtenerPos(i)->getNombre() << " : " << l_productos_comprados->obtenerPos(i)->getPrecio();
				contEspacios++;
			}
			pedido_usuario = new Pedido("P0" + to_string(c_pedidos.size()), usario_actual->getNombre(), "Javier", usario_actual->getDistrito(), l_productos_comprados, "Pendiente", "Motocicleta");
			Console::SetCursorPosition(ANCHO - 25, ALTO / 2);
			cout << "Total: " << pedido_usuario->conseguirCostoTotal();
		}
	}
	const void ingresarReclamo()
	{
		string idReclamo, fecha, nombreProducto, tipo, detalle, pedido;
		Reclamo<string>* auxReclamo;
		idReclamo = "R0" + to_string(l_reclamo->longitud());
		fecha = obtenerFechaYHora();
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Ingresar Reclamo ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "Ingresar Nombre del Producto Inconforme: "; cin >> nombreProducto;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cout << "Ingresar Tipo (R: reclamo || Q: queja): "; cin >> tipo;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "Ingresar Detalles: "; cin >> detalle;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
		cout << "Que solicita en el pedido?: "; cin >> pedido;
		auxReclamo = new Reclamo<string>(idReclamo, fecha, usario_actual->getNombre(), usario_actual->getTelefono(), usario_actual->getDistrito(),
			nombreProducto, tipo, detalle, pedido);
		l_reclamo->agregaPos(auxReclamo, l_reclamo->longitud());
	}
	bool comprarProductos()
	{
		string montoUsuario, fecha, idBoleta;
		Boleta<string>* auxBoleta;
		fecha = obtenerFechaYHora();
		if (l_productos_comprados->esVacia())
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
			cout << "No has listado ningun producto!";
		}
		else
		{
			while (true)
			{
				system("cls");
				mainInterfaz->encuadrar();
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 0);
				cout << "=============:: Comprando Productos ::=============";
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 1);
				cout << "Monto total: " << pedido_usuario->conseguirCostoTotal();
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 2);
				cout << "Poner costo su monto: "; cin >> montoUsuario;
				system("cls");
				mainInterfaz->encuadrar();
				if (stod(montoUsuario) >= pedido_usuario->conseguirCostoTotal())
				{
					idBoleta = "B03" + to_string(l_boletas->longitud());
					c_pedidos.push(pedido_usuario);
					auxBoleta = new Boleta<string>(idBoleta, usario_actual->getNombre(), fecha, montoUsuario, to_string(pedido_usuario->conseguirCostoTotal()));
					l_boletas->agregaPos(auxBoleta, l_boletas->longitud());
					compraInterfaz->compra();
					system("pause>>null");
					system("cls");
					mainInterfaz->encuadrar();
					Console::SetCursorPosition(ANCHO / 3, ALTO / 5);
					cout << "=============:: Pronto llegara tu pedido ::=============";
					auxBoleta->mostrarInformacion(ANCHO / 3, ALTO / 5 + 1);
					return true;
				}
				else
				{
					Console::SetCursorPosition(ANCHO / 3, ALTO / 3);
					cout << "El monto no alcanza! ";
				}
				system("pause>>null");
			}
		}
	}
};
