#pragma once
#include"VistaUsuario.h"
#include"VistaEmpleado.h"

template<class T1, class T2>
class ControllerProgram {
private:
	//declarando lista
	Lista<Empleado<string>*>* l_empleados;
	Lista<Producto<string>*>* l_productos;
	Lista<Producto<string>*>* l_productos_comprados;
	Lista<Usuario<double, int>*>* l_usuarios;
	Lista<Reclamo<string>*>* l_reclamos;
	Lista<Proveedor*>* l_proveedores;
	Lista<Boleta<string>*>* l_boletas;

	//Declaron Interfaces
	MainInterfaz* mainInterfaz;
	ProductosInterfaz* productosInterfaz;

	//Declarando colas
	Cola<Pedido<string>*>* c_pedidos;

	//Declarando usuario
	Usuario<double, int>* usuario_actual;
	Pedido<string>* pedido_usuario;

	//Declarando vistas
	VistaUsuario* vistaUsuario;
	VistaEmpleado* vistaEmpleado;

	// hashtable
	HashTablaA<Usuario<double, int>> hashTable;

	//Arboles Binarios de Busqueda
	ArbolBusqueda<int>* ab_ids_productos;
	ArbolBusqueda<int>* ab_ids_boletas;
	ArbolBusqueda<int>* ab_ids_reclamos;

	//Arboles Binarios Balanceados
	ArbolBalanceado<double>* abb_precios_productos;

	// Otras variables
	int cont_productos_comprados;

public:
	ControllerProgram(void(*imprimirInt)(T1), void(*imprimirDouble)(T2)) {
		//Listas
		l_empleados = new Lista<Empleado<string>*>();
		l_productos = new Lista<Producto<string>*>();
		l_productos_comprados = new Lista<Producto<string>*>();
		l_usuarios = new Lista<Usuario<double, int>*>();
		l_reclamos = new Lista<Reclamo<string>*>();
		l_proveedores = new Lista<Proveedor*>();
		l_boletas = new Lista<Boleta<string>*>();
		//Interfaces o decoracion
		mainInterfaz = new MainInterfaz();
		productosInterfaz = new ProductosInterfaz();

		//Colas
		c_pedidos = new Cola<Pedido<string>*>();
		pedido_usuario = NULL;

		//Arbol Binario de Busqueda
		ab_ids_productos = new ArbolBusqueda<int>(imprimirInt);
		ab_ids_boletas = new ArbolBusqueda<int>(imprimirInt);
		ab_ids_reclamos = new ArbolBusqueda<int>(imprimirInt);

		//Arboles Binarios Balanceados
		abb_precios_productos = new ArbolBalanceado<double>(imprimirDouble);

		//Usuario Actual y pedido de usuario
		usuario_actual = NULL;
		pedido_usuario = NULL;
		//Leer los archivos preestablecidos
		lecturaArchivoEmpleados();
		lecturaArchivoProductos();
		lecturaArchivoReclamo();
		lecturaArchivoProveedor();
		lecturaArchivoBoletas();
		lecturaArchivoUsuario();
		agregandoPedidos();
		registrarDatosArbolesBinarios();

		//Vistas
		vistaUsuario = new VistaUsuario();
		vistaEmpleado = new VistaEmpleado();

		//Otras variables
		cont_productos_comprados = 0;
	}

	~ControllerProgram()
	{
		delete l_empleados;
		delete l_productos;
		delete l_productos_comprados;
		delete l_usuarios;
		delete l_proveedores;
		delete l_boletas;
		delete l_reclamos;
		delete c_pedidos;
		delete usuario_actual;
		delete pedido_usuario;
		delete ab_ids_productos;
		delete ab_ids_boletas;
		delete ab_ids_reclamos;
		delete abb_precios_productos;
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
		Empleado<string>* auxE;
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

			auxE = new Empleado<string>(user, password, nombre, apellido, telefono, sexo, distrito, idTrabajador, puesto);
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
			string idProduct, nombre, precio, categoria, volumen, fechaCaducidad;
			// Extraer todos los valores de esa fila [considerando 3 columans]
			getline(stream, idProduct, delimitador);
			getline(stream, nombre, delimitador);
			getline(stream, precio, delimitador);
			getline(stream, categoria, delimitador);
			getline(stream, volumen, delimitador);
			getline(stream, fechaCaducidad, delimitador);
			aux = new Producto<string>(idProduct, nombre, precio, categoria, volumen, fechaCaducidad);
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
			l_reclamos->agregaPos(auxR, i);
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
			l_proveedores->agregaPos(auxP, i);
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
		Usuario<double, int>* auxU;
		// Encabezado: Leemos la primera línea para descartarla, pues es el encabezado
		getline(archIN, linea);
		// Contenido: Leemos todas las líneas
		while (getline(archIN, linea))
		{
			stringstream stream(linea); // Convertir la cadena a un stream			
			string user, password, nombre, apellido, telefono, sexo, distrito, dinero, edad;
			// Extraer todos los valores de esa fila [considerando 3 columans]
			getline(stream, user, delimitador);
			getline(stream, password, delimitador);
			getline(stream, nombre, delimitador);
			getline(stream, apellido, delimitador);
			getline(stream, telefono, delimitador);
			getline(stream, sexo, delimitador);
			getline(stream, distrito, delimitador);
			getline(stream, dinero, delimitador);
			getline(stream, edad, delimitador);

			auxU = new Usuario<double, int>(user, password, nombre, apellido, telefono, sexo, distrito, stod(dinero), stoi(edad));
			l_usuarios->agregaPos(auxU, i);
			hashTable.insert(auxU);
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
		Pedido<string>* pedido1 = new Pedido<string>("P001", "Jose", "Kevin", "Puente Piedra", l_productosAleatorios, "En Camino", "Bicicleta");
		c_pedidos->encolar(pedido1);

		l_productosAleatorios = new Lista<Producto<string>*>();
		catidad_productos = r.Next(1, 5); // [1-4]
		for (int j = 0; j < catidad_productos; j++)
		{
			num_alea = r.Next(0, l_productos->longitud() + 1);
			l_productosAleatorios->agregaPos(l_productos->obtenerPos(num_alea), j);
		}
		Pedido<string>* pedido2 = new Pedido<string>("P002", "Maria", "Luz", "San miguel", l_productosAleatorios, "Pendiente", "Motocicleta");
		c_pedidos->encolar(pedido2);

		l_productosAleatorios = new Lista<Producto<string>*>();
		catidad_productos = r.Next(1, 5); // [1-4]
		for (int j = 0; j < catidad_productos; j++)
		{
			num_alea = r.Next(0, l_productos->longitud() + 1);
			l_productosAleatorios->agregaPos(l_productos->obtenerPos(num_alea), j);
		}
		Pedido<string>* pedido3 = new Pedido<string>("P003", "Pepe", "Manuel", "San miguel", l_productosAleatorios, "Pendiente", "Bicicleta");
		c_pedidos->encolar(pedido3);
	}

	void registrarDatosArbolesBinarios()
	{
		//Registrar Ids y Precios de los productos
		for (int i = 0; i < l_productos->longitud(); i++)
		{
			string id = removerPrimerCaracter(l_productos->obtenerPos(i)->getIdProduct());
			string precio = l_productos->obtenerPos(i)->getPrecio();
			ab_ids_productos->insertar(stoi(id));
			abb_precios_productos->insertar(stod(precio));
		}

		//Registrar Ids de las boletas
		Cola<Pedido<string>*>* c_pedidos_aux = c_pedidos->copiar();
		while (!c_pedidos_aux->esVacia())
		{
			Pedido<string>* pedido_aux = c_pedidos_aux->front();
			string id = removerPrimerCaracter(pedido_aux->getIdPedido());
			ab_ids_boletas->insertar(stoi(id));
			c_pedidos_aux->desencolar();
		}

		//Registrar Ids de los reclamos
		for (int i = 0; i < l_reclamos->longitud(); i++)
		{
			Reclamo<string>* reclamo_aux = l_reclamos->obtenerPos(i);
			string id = removerPrimerCaracter(reclamo_aux->getIdReclamo());
			ab_ids_reclamos->insertar(stoi(id));
		}
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
				vistaEmpleado->vistaEmpleadoPantalla(l_empleados, l_productos, c_pedidos, l_reclamos, l_proveedores, l_boletas, ab_ids_productos, ab_ids_boletas, ab_ids_reclamos);
				break;
			case 2:
				vistaUsuario->vistaUsuarioPantalla(l_productos, l_productos_comprados, cont_productos_comprados, l_usuarios, usuario_actual,pedido_usuario, 
					c_pedidos, l_reclamos, l_boletas, ab_ids_productos);
				break;
			}
			system("pause>>null");
		}
	}
};
