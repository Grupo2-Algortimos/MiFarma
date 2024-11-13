#pragma once
#include"Empleado.h"
#include"Reclamos.h"
#include"Proveedor.h"
#include"Funciones.h"
#include"ProductosInterfaz.h"
#include "HashTable.h"
#include "Pila.h"

class VistaEmpleado
{
private:
	//Declaron Interfaces
	MainInterfaz* mainInterfaz;
	ProductosInterfaz* productosInterfaz;
	HashTablaA<Usuario> hashTable;
	Pila<Reclamo<string>*>* p_reclamo;
public:
	VistaEmpleado()
	{
		//Interfaces o decoracion
		mainInterfaz = new MainInterfaz();
		productosInterfaz = new ProductosInterfaz();
		p_reclamo = new Pila<Reclamo<string>*>();
	}

	~VistaEmpleado()
	{
		delete mainInterfaz;
		delete productosInterfaz;
	}

	void vistaEmpleadoPantalla(Lista<Empleado*>* l_empleados, Lista<Producto<string>*>* l_productos, queue<Pedido*> c_pedidos, Lista<Reclamo<string>*>* l_reclamos,
		Lista<Proveedor*>* l_proveedores, Lista<Boleta<string>*>* l_boletas) {
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
			cout << "Seleccione una opcion: ";  cin >> op;
			if (op == 3)break;
			switch (op)
			{
			case 1:
				loginEmpleado(l_empleados, l_productos, c_pedidos, l_reclamos, l_proveedores, l_boletas);
				break;
			case 2:
				system("cls");
				mainInterfaz->encuadrar();
				Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 0);
				cin.ignore();
				cout << "Ingresar la master key: "; getline(cin, master_key);
				if (master_key == "mifarma")
				{
					registroEmpleado(coni, l_empleados);
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


	void loginEmpleado(Lista<Empleado*>* l_empleados, Lista<Producto<string>*>* l_productos, queue<Pedido*> c_pedidos, Lista<Reclamo<string>*>* l_reclamos,
		Lista<Proveedor*>* l_proveedores, Lista<Boleta<string>*>* l_boletas) {
		string user, password;
		bool salir = false;
		bool usuario_encontrado = false, contrasena_correcta = false;
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
					usuario_encontrado = true;
					if (l_empleados->obtenerPos(i)->getPassword() == password)
					{
						contrasena_correcta = true;
						system("cls");
						mainInterfaz->encuadrar();
						Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
						cout << "Ingreso exitoso...";
						system("pause>>null");
						adminOpciones(l_productos, c_pedidos, l_reclamos, l_proveedores, l_boletas);
						salir = true;
						break;
					}
				}
			}
			if (!usuario_encontrado || !contrasena_correcta)
			{
				system("cls");
				mainInterfaz->encuadrar();
				Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
				cout << "El usuario o contrasena es incorrecto....";
				salir = true;
			}
		}
	}


	

	void registroEmpleado(int coni, Lista<Empleado*>* l_empleados) {
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
		l_empleados->agregaFinal(aux);
		
	}

	void adminOpciones(Lista<Producto<string>*>* l_productos, queue<Pedido*> c_pedidos, Lista<Reclamo<string>*>* l_reclamos,
		Lista<Proveedor*>* l_proveedores, Lista<Boleta<string>*>* l_boletas)
	{
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
			cout << "[1] Ingresar nuevo Producto";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
			cout << "[2] Buscar Productos";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
			cout << "[3] Modificar Producto";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
			cout << "[4] Buscar Pedidos";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 5);
			cout << "[5] Buscar Reclamos";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 6);
			cout << "[6] Ingresar nuevo Proveedor";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 7);
			cout << "[7] Buscar Proveedores";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 8);
			cout << "[8] Buscar Boletas";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 9);
			cout << "[9] Actualizar Logistica";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 10);
			cout << "[10] Generar Usuarios";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 11);
			cout << "[11] Buscar Usuario";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 12);
			cout << "[12] Salir";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 13);
			cout << "Seleccione una opcion : "; cin >> opcionM;
			if (opcionM == 12)break;
			system("cls");
			mainInterfaz->encuadrar();
			switch (opcionM)
			{
			case 1:
				ingresarProducto(i, l_productos);
				i++;
				break;
			case 2:
				buscarProducto(l_productos);
				break;
			case 3:
				modificarProducto(l_productos);
				break;
			case 4:
				buscarPedidos(c_pedidos);
				break;
			case 5:
				buscarReclamos(l_reclamos);
				break;
			case 6:
				ingresarProveedor(p, l_proveedores);
				p++;
				break;
			case 7:
				buscarProveedor(l_proveedores);
				break;
			case 8:
				buscarBoletas(l_boletas);
				break;
			case 9:
				actualizarLogistica();
				break;
			case 10:
				crearDataSet();
				break;
			case 11:
				buscarUsuario();
				break;
			}
			system("pause>>null");
		}
	}

	

	void ingresarProducto(int i, Lista<Producto<string>*>* l_productos) {
		string idProduct, nombre, precio, categoria, cantidad, fechaCad;
		Producto<string>* auxProduct;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Ingresar nuevo Producto ::=============";
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
		auxProduct = new Producto<string>(idProduct, nombre, precio, categoria, cantidad, fechaCad);
		l_productos->agregaPos(auxProduct, i);		
	}

	void buscarProducto(Lista<Producto<string>*>* l_productos) {
		string nombre, categoria, auxCategoria;
		bool productoEncontrado = false, salir = false, tecla_presionada = true;
		int opcionesProducto, opcionesCategoria, contProductos = 0, contVentanas = 1, contadorCategoria = 0;
		int primerProductoCategoria = 0;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Buscar Producto ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "[1] Mostrar todos";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cout << "[2] Buscar por categoria";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "[3] Buscar por nombre";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
		cout << "Seleccionar una opcion: "; cin >> opcionesProducto;
		system("cls");
		mainInterfaz->encuadrar();
		switch (opcionesProducto)
		{
		case 1:
			while (!salir)
			{
				if (tecla_presionada)
				{
					system("cls");
					mainInterfaz->encuadrar();
					Console::SetCursorPosition(ANCHO / 6, ALTO / 6 + 0);
					cout << "=============:: Productos ::=============";
					if (contProductos < l_productos->longitud() - 3)
					{
						l_productos->obtenerPos(contProductos)->mostrarProducto(ANCHO / 6, ALTO / 6 + 1);
						l_productos->obtenerPos(contProductos + 1)->mostrarProducto(ANCHO / 6, ALTO / 6 + 8);
						l_productos->obtenerPos(contProductos + 2)->mostrarProducto(ANCHO / 6, ALTO / 6 + 15);
					}
					else
					{
						l_productos->obtenerPos(contProductos)->mostrarProducto(ANCHO / 6, ALTO / 6 + 1);
						if (contProductos + 1 < l_productos->longitud())
						{
							l_productos->obtenerPos(contProductos + 1)->mostrarProducto(ANCHO / 6, ALTO / 6 + 8);
						}
					}

					Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 1);
					cout << "[->] Mover siguiente producto";
					Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 2);
					cout << "[<-] Retroceder anterior producto";
					Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 3);
					cout << "[ESC] Salir";
					Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 10);
					cout << "<" << contVentanas << " : " << l_productos->longitud() / 3 + 1 << ">";
					tecla_presionada = false;
				}

				if (kbhit())
				{
					char tecla = getch();
					switch (tecla)
					{
					case TECLA_DERECHA:
						if (contProductos < l_productos->longitud() - 3)
						{
							contProductos += 3;
							contVentanas++;
						}
						break;
					case TECLA_IZQUIERDA:
						if (contProductos > 2)
						{
							contProductos -= 3;
							contVentanas--;
						}
						break;
					case TECLA_ESCAPE:
						salir = true;
						break;
					}
					tecla_presionada = true;
				}
			}	
			break;

		case 2:
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
			cout << "Ingresar opcion: "; cin >> opcionesCategoria;
			while (!salir)
			{
				if (tecla_presionada)
				{
					system("cls");
					mainInterfaz->encuadrar();
					switch (opcionesCategoria)
					{
					case 1:
						categoria = "Farmaco";
						productosInterfaz->dibujarFarmaco(ANCHO - 35, ALTO / 3 - 5);
						break;
					case 2:
						categoria = "Cosmeticos";
						productosInterfaz->dibujarCosmetico(ANCHO - 35, ALTO / 3 - 5);
						break;
					case 3:
						categoria = "Cuidado para bebes";
						productosInterfaz->dibujarBiberon(ANCHO - 35, ALTO / 3 - 5);
						break;
					case 4:
						categoria = "Cuidado personal";
						productosInterfaz->dibujarCuidadoPersonal(ANCHO - 35, ALTO / 3 - 5);
						break;
					case 5:
						categoria = "Personas mayores";
						productosInterfaz->dibujarPersonaMayor(ANCHO - 35, ALTO / 3 - 5);
						break;
					}
					contadorCategoria = contarProductosPorCategoria(l_productos, categoria);
					primerProductoCategoria = obtenerPrimerProductoPorCategoria(l_productos, categoria);
					Console::SetCursorPosition(ANCHO / 6, ALTO / 6 + 0);
					cout << "=============:: Productos ::=============";
					if (contProductos < l_productos->longitud() - 3)
					{
						int indice = primerProductoCategoria + contProductos;
						if (l_productos->obtenerPos(indice)->getCategoria() == categoria)l_productos->obtenerPos(indice)->mostrarProducto(ANCHO / 6, ALTO / 6 + 1);
						if (l_productos->obtenerPos(indice + 1)->getCategoria() == categoria)l_productos->obtenerPos(indice + 1)->mostrarProducto(ANCHO / 6, ALTO / 6 + 8);
						if (l_productos->obtenerPos(indice + 2)->getCategoria() == categoria)l_productos->obtenerPos(indice + 2)->mostrarProducto(ANCHO / 6, ALTO / 6 + 15);
					}
					Console::SetCursorPosition(ANCHO - 40, ALTO / 2 + 1);
					cout << "[->] Mover siguientes productos";
					Console::SetCursorPosition(ANCHO - 40, ALTO / 2 + 2);
					cout << "[<-] Retroceder anteriores productos";
					Console::SetCursorPosition(ANCHO - 40, ALTO / 2 + 3);
					cout << "[ESC] Salir";
					Console::SetCursorPosition(ANCHO - 40, ALTO / 2 + 8);
					cout << "<" << contVentanas << " : " << (contadorCategoria / 3) + 1 << ">";
					tecla_presionada = false;
				}
				if (kbhit())
				{
					char tecla = getch();
					switch (tecla)
					{
					case TECLA_DERECHA:
						if (contProductos < contadorCategoria - 3)
						{
							contProductos += 3;
							contVentanas++;
						}
						break;
					case TECLA_IZQUIERDA:
						if (contProductos > 2)
						{
							contProductos -= 3;
							contVentanas--;
						}
						break;
					case TECLA_ESCAPE:
						salir = true;
						break;
					}
					tecla_presionada = true;
				}
			}
			break;

		case 3:
			Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 4 + 0);
			cout << "===========:: Buscar por Nombre ::===========";
			Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 4 + 1);
			cout << "Ingresar Nombre del producto: ";
			cin.ignore(); getline(cin, nombre);
			for (int i = 0; i < l_productos->longitud(); i++)
			{

				if (convertirStringMinuscula(l_productos->obtenerPos(i)->getNombre()) == convertirStringMinuscula(nombre))
				{
					productoEncontrado = true;
					auxCategoria = l_productos->obtenerPos(i)->getCategoria();
					if (auxCategoria == "Farmaco")
					{
						productosInterfaz->dibujarFarmaco(ANCHO - 35, ALTO / 2 - 5);
					}
					if (auxCategoria == "Cosmeticos")
					{
						productosInterfaz->dibujarCosmetico(ANCHO - 35, ALTO / 2 - 5);
					}
					if (auxCategoria == "Cuidado para bebes")
					{
						productosInterfaz->dibujarBiberon(ANCHO - 35, ALTO / 2 - 5);
					}
					if (auxCategoria == "Cuidado personal")
					{
						productosInterfaz->dibujarCuidadoPersonal(ANCHO - 35, ALTO / 2 - 5);
					}
					if (auxCategoria == "Personas mayores")
					{
						productosInterfaz->dibujarPersonaMayor(ANCHO - 35, ALTO / 2 - 5);
					}
					l_productos->obtenerPos(i)->mostrarProducto(ANCHO / 5 - 10, ALTO / 4 + 2);
				}
			}

			if (!productoEncontrado)
			{
				Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 4 + 2);
				cout << "No hay productos con ese nombre!";
			}

			break;
		}
	}

	void modificarProducto(Lista<Producto<string>*>* l_productos) {
		string nombreB;
		string idProduct, nombre, precio, categoria, cantidad, fechaCad;
		bool productoEncontrado = false;
		Producto<string>* auxProduct;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Buscar Producto a Modificar ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "Ingrese el nombre : "; cin >> nombreB;
		for (int i = 0; i < l_productos->longitud(); i++)
		{
			if (convertirStringMinuscula(l_productos->obtenerPos(i)->getNombre()) == convertirStringMinuscula(nombreB))
			{
				productoEncontrado = true;
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
		if (!productoEncontrado)
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
			cout << "No hay productos con ese nombre!";
		}
	}

	void buscarPedidos(queue<Pedido*> c_pedidos)
	{
		//Cola auxiliar para mostrar los pedidos
		queue<Pedido*> c_pedidos_aux = c_pedidos;
		int size_cola = c_pedidos.size();
		Pedido* pedidoAux = NULL;
		int opcModo, contPedidos = 0;
		string idPedido;
		bool salir = false, tecla_presionada = true;
		if (c_pedidos_aux.empty())
		{
			Console::SetCursorPosition(ANCHO / 2.5, ALTO / 2 + 0);
			cout << "No hay pedidos a mostrar!";
		}
		else
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cout << "=============:: Buscar Pedido ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
			cout << "[1] Mostrar todos";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
			cout << "[2] Buscar por ID";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
			cout << "Seleccionar una opcion: "; cin >> opcModo;
			system("cls");
			mainInterfaz->encuadrar();
			switch (opcModo)
			{
			case 1:
				while (!c_pedidos_aux.empty() && salir == false)
				{
					if (tecla_presionada)
					{
						system("cls");
						mainInterfaz->encuadrar();
						c_pedidos_aux.front()->mostarInformacion(ANCHO / 4, ALTO / 5);
						Console::SetCursorPosition(ANCHO - 40, ALTO / 2 + 1);
						cout << "[->] Siguente Pedido";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 2 + 2);
						cout << "[ESC] Salir";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 2 + 8);
						cout << "<" << contPedidos + 1 << " : " << size_cola << ">";
						tecla_presionada = false;
					}	
					if (kbhit())
					{
						char tecla = getch();
						switch (tecla)
						{
						case TECLA_DERECHA:
							if (contPedidos < size_cola)
							{
								contPedidos++;
								c_pedidos_aux.pop();
							}
							break;
						case TECLA_ESCAPE:
							salir = true;
							break;
						}
						tecla_presionada = true;
					}
				}
				if (c_pedidos_aux.empty())
				{
					system("cls");
					mainInterfaz->encuadrar();
					Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
					cout << "Se han mostrado todos los pedidos!";
				}
				break;
			case 2:
				cin.ignore();
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 - 2);
				cout << "=============:: Pedidos ::=============";
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 - 1);
				cout << "Ingresar Id del Pedido: "; getline(cin, idPedido);
				system("cls");
				mainInterfaz->encuadrar();
				for (int i = 0; i < c_pedidos_aux.size(); i++)
				{
					if (c_pedidos_aux.back()->getIdPedido() == idPedido && i == c_pedidos_aux.size() - 1)
					{
						pedidoAux = c_pedidos_aux.back();
						c_pedidos_aux.back()->mostarInformacion(ANCHO / 4, ALTO / 5);
					}
					if (c_pedidos_aux.front()->getIdPedido() == idPedido)
					{
						pedidoAux = c_pedidos_aux.front();
						c_pedidos_aux.front()->mostarInformacion(ANCHO / 4, ALTO / 5);
					}
					c_pedidos_aux.pop();
				}
				if (pedidoAux == NULL)
				{
					Console::SetCursorPosition(ANCHO / 3, ALTO / 5);
					cout << "No hay Pedidos con ese ID!";
				}
				break;
			}
		}

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
			p_reclamo->apilar(auxR);
			i++;
		}
		// Cerramos Archivo
		archIN.close();
	}

	void buscarReclamos(Lista<Reclamo<string>*>* l_reclamos) {
		lecturaArchivoReclamo();
		bool escape = false;
		string idReclamo;
		int opcModo, contReclamos = 0, opcionMover;
		bool encontrado = false;
		Reclamo<string>* auxReclamo = new Reclamo<string>();
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Buscar Reclamo ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "[1] Mostrar todos";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cout << "[2] Buscar por ID";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "Seleccionar una opcion: "; cin >> opcModo;
		system("cls");
		mainInterfaz->encuadrar();
		switch (opcModo)
		{
		case 1:
			do
			{
				auxReclamo = p_reclamo->desapilar();
				l_reclamos->agregaFinal(auxReclamo);
			} while (!p_reclamo->esVacia());						
			while (escape == false)
			{
				system("cls");				
				mainInterfaz->encuadrar();
				Console::SetCursorPosition(ANCHO / 6, ALTO / 6 + 0);
				cout << "=============:: Reclamos ::=============";				
				l_reclamos->obtenerPos(contReclamos)->mostrarReclamo(ANCHO / 6, ALTO / 6 + 1);
				Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 1);
				cout << "[1] Mover siguiente reclamo";
				Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 2);
				cout << "[2] Retroceder anterior reclamo";
				Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 3);
				cout << "[3] Salir";
				Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 10);
				cout << "<" << contReclamos + 1 << " : " << l_reclamos->longitud() << ">";
				Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 4);
				cout << "Escoger Opcion: "; cin >> opcionMover;
				if (opcionMover == 3) break;
				switch (opcionMover)
				{
				case 1:
					if (contReclamos < l_reclamos->longitud() - 1)
					{
						contReclamos++;						
					}
					break;
				case 2:
					if (contReclamos > 0)
					{
						contReclamos--;
					}
					break;
				}					
			}			
			break;
		case 2:
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cin.ignore();
			cout << "Ingresar Id del Reclamo: "; getline(cin, idReclamo);
			system("cls");
			mainInterfaz->encuadrar();
			for (int i = 0; i < l_reclamos->longitud(); i++)
			{
				if (l_reclamos->obtenerPos(i)->getIdReclamo() == idReclamo)
				{
					l_reclamos->obtenerPos(i)->mostrarReclamo(ANCHO / 3, ALTO / 5 + 0);
					encontrado = true;
					break;
				}
			}
			if (!encontrado)
			{
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 0);
				cout << "No hay reclamos con ese ID!";
			}
			break;
		}
		
	}

	void ingresarProveedor(int p, Lista<Proveedor*>* l_proveedores) {
		string nombre, telefono, distrito, producto;
		Proveedor* auxProve;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Ingresar Proveedor ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "Ingresar Nombre del Proveedor: "; cin >> nombre;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cout << "Ingresar Telefono: "; cin >> telefono;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "Ingresar Distrito: "; cin >> distrito;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
		cout << "Ingresar Producto: "; cin >> producto;
		auxProve = new Proveedor(nombre, telefono, distrito, producto);
		l_proveedores->agregaPos(auxProve, p);
	}

	void buscarProveedor(Lista<Proveedor*>* l_proveedores) {
		string nombre;
		bool proveedorEncontrado = false;
		int opcModo, contProveedores = 0;
		bool salir = false, tecla_presionada = true;

		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Buscar Proveedores ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "[1] Mostrar todos";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cout << "[2] Buscar por ID";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "Seleccionar una opcion: "; cin >> opcModo;
		system("cls");
		mainInterfaz->encuadrar();
		switch (opcModo)
		{
		case 1:
			while (!salir)
			{
				if (tecla_presionada)
				{
					system("cls");
					mainInterfaz->encuadrar();
					Console::SetCursorPosition(ANCHO / 6, ALTO / 6 + 0);
					cout << "=============:: Proveedores ::=============";
					l_proveedores->obtenerPos(contProveedores)->mostrar(ANCHO / 6, ALTO / 6 + 1);
					Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 1);
					cout << "[->] Mover siguiente reclamo";
					Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 2);
					cout << "[<-] Retroceder anterior reclamo";
					Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 3);
					cout << "[ESC] Salir";
					Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 10);
					cout << "<" << contProveedores + 1 << " : " << l_proveedores->longitud() << ">";
					Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 4);
					tecla_presionada = false;
				}
				if (kbhit())
				{
					char tecla = getch();
					switch (tecla)
					{
					case TECLA_DERECHA:
						if (contProveedores < l_proveedores->longitud() - 1)
						{
							contProveedores++;
						}
						break;
					case TECLA_IZQUIERDA:
						if (contProveedores > 0)
						{
							contProveedores--;
						}
						break;
					case TECLA_ESCAPE:
						salir = true;
						break;
					}
					tecla_presionada = true;
				}
			}
			break;
		case 2:
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cout << "=============:: Buscar Proveedores ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
			cin.ignore();
			cout << "Ingresar Nombre del Proveedor: "; getline(cin, nombre);
			system("cls");
			mainInterfaz->encuadrar();
			for (int i = 0; i < l_proveedores->longitud(); i++) {
				if (convertirStringMinuscula(l_proveedores->obtenerPos(i)->getnombre()) == convertirStringMinuscula(nombre)) {
					l_proveedores->obtenerPos(i)->mostrar(ANCHO / 3, ALTO / 5);
					proveedorEncontrado = true;
					break;
				}
			}
			if (!proveedorEncontrado) {
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 1);
				cout << "No hay proveedores con ese nombre!";
			}
			break;
		}
	}

	void buscarBoletas(Lista<Boleta<string>*>* l_boletas)
	{
		string idBoleta;
		int opcModo, opcionMover, contBoletas = 0;
		bool boletaEncontrada = false;
		bool salir = false, tecla_presionada = true;

		if (l_boletas->esVacia())
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
			cout << "No hay boletas a mostrar!";
		}
		else
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cout << "=============:: Buscar Boletas ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
			cout << "[1] Mostrar todos";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
			cout << "[2] Buscar por ID";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
			cout << "Seleccionar una opcion: "; cin >> opcModo;
			system("cls");
			mainInterfaz->encuadrar();
			switch (opcModo)
			{
			case 1:
				while (!salir)
				{
					if (tecla_presionada)
					{
						system("cls");
						mainInterfaz->encuadrar();
						Console::SetCursorPosition(ANCHO / 6, ALTO / 6 + 0);
						cout << "=============:: Boleta ::=============";
						l_boletas->obtenerPos(contBoletas)->mostrarInformacion(ANCHO / 6, ALTO / 6 + 1);
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 1);
						cout << "[->] Mover siguiente boleta";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 2);
						cout << "[<-] Retroceder anterior boleta";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 3);
						cout << "[ESC] Salir";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 10);
						cout << "<" << contBoletas + 1 << " : " << l_boletas->longitud() - 1 << ">";
						tecla_presionada = false;
					}
					if (kbhit())
					{
						char tecla = getch();
						switch (tecla)
						{
						case TECLA_DERECHA:
							if (contBoletas < l_boletas->longitud() - 2)
							{
								contBoletas++;
							}
							break;
						case TECLA_IZQUIERDA:
							if (contBoletas > 0)
							{
								contBoletas--;
							}
							break;
						case TECLA_ESCAPE:
							salir = true;
							break;
						}
						tecla_presionada = true;
					}
				}
				break;
			case 2:
				Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
				cin.ignore();
				cout << "Ingresar Id del Boleta: "; getline(cin, idBoleta);
				system("cls");
				mainInterfaz->encuadrar();
				for (int i = 0; i < l_boletas->longitud(); i++)
				{
					if (l_boletas->obtenerPos(i)->getIdBoleta() == idBoleta)
					{
						boletaEncontrada = true;
						l_boletas->obtenerPos(i)->mostrarInformacion(ANCHO / 3, ALTO / 5 + 0);
					}
				}
				if (!boletaEncontrada)
				{
					Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 0);
					cout << "No hay boletas con ese ID!";
				}
			}
		}

	}

	void actualizarLogistica()
	{

	}

	void crearDataSet() {
		system("cls");
		int N;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Crear Usuarios ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "Elegir el numero de usuarios a generar: "; cin >> N;

		string arrNombresH[25] = {
			"Carlos", "Juan", "Luis", "Pedro", "Jorge",
			"Miguel", "Andres", "Jose", "Ricardo", "Eduardo",
			"Francisco", "Antonio", "Manuel", "Alejandro", "Raul",
			"Javier", "Fernando", "Sergio", "Pablo", "Hector",
			"David", "Roberto", "Cristian", "Diego", "Ramiro"
		};
		string arrNombresM[25] = {
			"Maria", "Ana", "Luisa", "Carmen", "Laura",
			"Isabel", "Sofia", "Paula", "Gabriela", "Patricia",
			"Sandra", "Veronica", "Claudia", "Andrea", "Natalia",
			"Monica", "Rosa", "Silvia", "Yolanda", "Luz",
			"Lorena", "Daniela", "Adriana", "Lucia", "Florencia"
		};
		string arrApellidos[50] = {
			"Garcia", "Rodriguez", "Martinez", "Lopez", "Hernandez",
			"Perez", "Gonzalez", "Sanchez", "Ramirez", "Torres",
			"Flores", "Rivera", "Gomez", "Diaz", "Cruz",
			"Morales", "Ortiz", "Gutierrez", "Chavez", "Ramos",
			"Vargas", "Castillo", "Jimenez", "Moreno", "Mendoza",
			"Romero", "Paredes", "Navarro", "Molina", "Silva",
			"Rojas", "Suarez", "Herrera", "Medina", "Vega",
			"Mejia", "Campos", "Escobar", "Reyes", "Caballero",
			"Rios", "Ponce", "Maldonado", "Fuentes", "Carrasco",
			"Bravo", "Aguilar", "Castro", "Soto", "Reynoso"
		};
		string celular = "9";
		string distritoLimaMetro[] = {
			"Ancon","Brena", "Santa Rosa", "Carabayllo", "Puente Piedra", "San Martin de Porres",
			"Los Olivos", "Comas", "Independencia", "Rimac", "Cercado de Lima",
			"Breña", "Jesus Maria", "Pueblo Libre", "San Miguel", "Magdalena del Mar",
			"Lince", "La Victoria", "San Isidro", "Miraflores", "Barranco",
			"Chorrillos", "San Juan de Lurigancho", "El Agustino", "Ate",
			"Santa Anita", "La Molina", "San Borja", "Surquillo", "Santiago de Surco",
			"Villa Maria del Triunfo", "Villa El Salvador", "San Juan de Miraflores",
			"Pachacamac", "Cieneguilla", "Lurigancho", "Lurin", "Punta Hermosa",
			"Punta Negra", "San Bartolo", "Santa Maria del Mar", "Pucusana", "Chaclacayo", "Callao"
		};

		srand(time(NULL));

		ofstream archivo("usuariosGenerados.txt");
		if (!archivo) {
			cout << "Error al crear el archivo." << endl;
			return;
		}
		for (int i = 0; i < N; ++i) {
			bool esHombre = (rand() % 2 == 0);
			string nombre = esHombre ? arrNombresH[rand() % 25] : arrNombresM[rand() % 25];
			string apellido = arrApellidos[rand() % 50];
			string sexoElegido = esHombre ? "M" : "F";
			string nomUsuario = generarNombreUsuario(0, "", nombre);
			string password = generarContrasena(8);

			string telefono = "9";
			for (int j = 0; j < 8; ++j) {
				telefono += to_string(rand() % 10);
			}

			for (int j = 0; j < 8; ++j) {
				password += 'A' + rand() % 26;
			}

			string distrito = distritoLimaMetro[rand() % 43];

			int dinero = rand() % 1001;

			hashTable.insert(new Usuario(nomUsuario, password, nombre, apellido, telefono, sexoElegido, distrito, dinero));

			archivo << nomUsuario << "|" << password << "|" << nombre << "|" << apellido << "|" << telefono << "|" << sexoElegido << "|" << distrito << "|" << dinero << "|\n";
		}

		archivo.close();
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "Usuarios generados con exito.";
		
		
	}
	
	void buscarUsuario() {			
		mainInterfaz->encuadrar();
		Console::SetCursorPosition(ANCHO / 3, ALTO / 7 + 0);
		cout << "===========:: lista de usuarios::===========" << endl;
		hashTable.DispAll();
	}
};
