#pragma once
#include"Empleado.h"
#include"Reclamos.h"
#include"Proveedor.h"
#include"Funciones.h"
#include"ProductosInterfaz.h"
#include"HashTable.h"
#include"Pila.h"
#include"ArbolBusqueda.h"
#include"ArbolBalanceado.h"
#include"Cola.h"

template<class T1, class T2>
class VistaEmpleado
{
private:
	//Declaron Interfaces
	T1* mainInterfaz;
	T2* productosInterfaz;
public:
	VistaEmpleado()
	{
		//Interfaces o decoracion
		mainInterfaz = new MainInterfaz();
		productosInterfaz = new ProductosInterfaz();
	}

	~VistaEmpleado()
	{
		delete mainInterfaz;
		delete productosInterfaz;
	}

	void vistaEmpleadoPantalla(Lista<Empleado<string>*>* l_empleados, Lista<Producto<string>*>* l_productos, Lista<Proveedor<string>*>* l_proveedores,
		Lista<Boleta<string>*>* l_boletas, Pila<Reclamo<string>*>* p_reclamos, Cola<Pedido<string>*>* c_pedidos, ArbolBusqueda<int>* ab_ids_productos,
		ArbolBusqueda<int>* ab_ids_pedidos, ArbolBusqueda<int>* ab_ids_reclamos, ArbolBusqueda<int>* ab_ids_boletas, ArbolBusqueda<int>* ab_ids_proveedores,
		ArbolBalanceado<double>* abb_precios_productos, ArbolBalanceado<int>* abb_edades_usuarios, HashTable<Usuario<double, int>>& ht_usuarios) {
		int op = 0;
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
				loginEmpleado(l_empleados, l_productos, l_proveedores, l_boletas, p_reclamos, c_pedidos, ab_ids_productos, ab_ids_pedidos,
					ab_ids_reclamos, ab_ids_boletas, ab_ids_proveedores, abb_precios_productos, abb_edades_usuarios, ht_usuarios);
				break;
			case 2:
				system("cls");
				mainInterfaz->encuadrar();
				Console::SetCursorPosition(ANCHO / 3, ALTO / 2.5 + 0);
				cin.ignore();
				cout << "Ingresar la master key: "; getline(cin, master_key);
				if (master_key == "mifarma")
				{
					registroEmpleado(l_empleados);
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


	void loginEmpleado(Lista<Empleado<string>*>* l_empleados, Lista<Producto<string>*>* l_productos, Lista<Proveedor<string>*>* l_proveedores,
		Lista<Boleta<string>*>* l_boletas, Pila<Reclamo<string>*>* p_reclamos, Cola<Pedido<string>*>* c_pedidos, ArbolBusqueda<int>* ab_ids_productos,
		ArbolBusqueda<int>* ab_ids_pedidos, ArbolBusqueda<int>* ab_ids_reclamos, ArbolBusqueda<int>* ab_ids_boletas, ArbolBusqueda<int>* ab_ids_proveedores,
		ArbolBalanceado<double>* abb_precios_productos, ArbolBalanceado<int>* abb_edades_usuarios, HashTable<Usuario<double, int>>& ht_usuarios) {
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
						adminOpciones(l_empleados, l_productos, l_proveedores, l_boletas, p_reclamos, c_pedidos, ab_ids_productos, ab_ids_pedidos,
							ab_ids_reclamos, ab_ids_boletas, ab_ids_proveedores, abb_precios_productos, abb_edades_usuarios, ht_usuarios);
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

	void registroEmpleado(Lista<Empleado<string>*>* l_empleados) {
		system("cls");
		mainInterfaz->encuadrar();
		string user, password, nombre, apellido, telefono, sexo, distrito, idTrabajador, puesto;
		Empleado<string>* aux;
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
		aux = new Empleado<string>(user, password, nombre, apellido, telefono, sexo, distrito, idTrabajador, puesto);
		l_empleados->agregaFinal(aux);
	}

	void adminOpciones(Lista<Empleado<string>*>* l_empleados, Lista<Producto<string>*>* l_productos,Lista<Proveedor<string>*>* l_proveedores, 
		Lista<Boleta<string>*>* l_boletas, Pila<Reclamo<string>*>* p_reclamos, Cola<Pedido<string>*>* c_pedidos, ArbolBusqueda<int>* ab_ids_productos, 
		ArbolBusqueda<int>* ab_ids_pedidos, ArbolBusqueda<int>* ab_ids_reclamos, ArbolBusqueda<int>* ab_ids_boletas, ArbolBusqueda<int>* ab_ids_proveedores, 
		ArbolBalanceado<double>* abb_precios_productos, ArbolBalanceado<int>* abb_edades_usuarios, HashTable<Usuario<double, int>>& ht_usuarios)
	{
		int opcionM;
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
			cout << "[9] Generar Usuarios";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 10);
			cout << "[10] Buscar Usuario";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 11);
			cout << "[11] Salir";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 12);
			cout << "Seleccione una opcion : "; cin >> opcionM;
			if (opcionM == 11)break;
			system("cls");
			mainInterfaz->encuadrar();
			switch (opcionM)
			{
			case 1:
				ingresarProducto(l_productos);
				break;
			case 2:
				buscarProducto(l_productos, ab_ids_productos, abb_precios_productos);
				break;
			case 3:
				modificarProducto(l_productos);
				break;
			case 4:
				buscarPedidos(c_pedidos, ab_ids_pedidos);
				break;
			case 5:
				buscarReclamos(p_reclamos, ab_ids_reclamos);
				break;
			case 6:
				ingresarProveedor(l_proveedores);
				break;
			case 7:
				buscarProveedor(l_proveedores, ab_ids_proveedores);
				break;
			case 8:
				buscarBoletas(l_boletas, ab_ids_boletas);
				break;
			case 9:
				crearDataSet(ht_usuarios, abb_edades_usuarios);
				break;
			case 10:
				buscarUsuario(ht_usuarios, abb_edades_usuarios);
				break;
			}
			system("pause>>null");
		}
	}

	

	void ingresarProducto(Lista<Producto<string>*>* l_productos) {
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
		l_productos->agregaFinal(auxProduct);
	}

	void buscarProducto(Lista<Producto<string>*>* l_productos, ArbolBusqueda<int>* ab_ids_productos, ArbolBalanceado<double>* abb_precios_productos) {
		//Variables para buscar producto por id, categoria, nombre y todos
		string nombre, categoria, auxCategoria, id_producto;
		bool productoEncontrado = false, salir = false, tecla_presionada = true;
		int opcionesProducto, opcionesCategoria, contProductos = 0, contVentanas = 1, contadorCategoria = 0;
		int primerProductoCategoria = 0;

		//Variables para precios
		Producto<string>* productoMin = NULL;
		Producto<string>* productoMax = NULL;
		Lista<Producto<string>*>* l_productos_ordenados = new Lista<Producto<string>*>();
		double minimoPrecio = abb_precios_productos->minimo();
		double maximoPrecio = abb_precios_productos->maximo();
		int opcionesPrecio;

		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Buscar Producto ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "[1] Mostrar todos";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cout << "[2] Buscar por ID";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "[3] Buscar por categoria";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
		cout << "[4] Buscar por nombre";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 5);
		cout << "[5] Buscar por precio";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 6);
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
					Console::SetCursorPosition(ANCHO / 6, ALTO / 6 + 7);
					cout << "------------------------------------------";
					if (contProductos < l_productos->longitud() - 3)
					{
						Console::SetCursorPosition(ANCHO / 6, ALTO / 6 + 21);
						cout << "=========================================";
						Console::SetCursorPosition(ANCHO / 6, ALTO / 6 + 14);
						cout << "------------------------------------------";
						for (int i = 0; i < 22; i++)
						{
							Console::SetCursorPosition(ANCHO / 6 - 1, ALTO / 6 + i); cout << "|";
							Console::SetCursorPosition(ANCHO / 6 + 41, ALTO / 6 + i); cout << "|";
						}
						l_productos->obtenerPos(contProductos)->mostrarProducto(ANCHO / 6, ALTO / 6 + 1);
						l_productos->obtenerPos(contProductos + 1)->mostrarProducto(ANCHO / 6, ALTO / 6 + 8);
						l_productos->obtenerPos(contProductos + 2)->mostrarProducto(ANCHO / 6, ALTO / 6 + 15);
					}
					else
					{
						for (int i = 0; i < 8; i++)
						{
							Console::SetCursorPosition(ANCHO / 6 - 1, ALTO / 6 + i); cout << "|";
							Console::SetCursorPosition(ANCHO / 6 + 41, ALTO / 6 + i); cout << "|";
						}
						l_productos->obtenerPos(contProductos)->mostrarProducto(ANCHO / 6, ALTO / 6 + 1);
						if (contProductos + 1 < l_productos->longitud())
						{
							for (int i = 8; i < 16; i++)
							{
								Console::SetCursorPosition(ANCHO / 6 - 1, ALTO / 6 + i); cout << "|";
								Console::SetCursorPosition(ANCHO / 6 + 41, ALTO / 6 + i); cout << "|";
							}
							Console::SetCursorPosition(ANCHO / 6, ALTO / 6 + 9);
							cout << "=========================================";
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
			cin.ignore();
			Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 4 + 0);
			cout << "===========:: Buscar por ID del producto ::===========";
			Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 4 + 1);
			cout << "Ingresar ID del producto: "; getline(cin, id_producto);

			if (obtenerPrimerCaracter(id_producto) >= 48 && obtenerPrimerCaracter(id_producto) <= 57)
			{
				int id_producto_entero = stoi(id_producto);
				if (ab_ids_productos->buscar(id_producto_entero))
				{
					Producto<string>* producto_aux = l_productos->obtenerPos(id_producto_entero - 1);
					auxCategoria = producto_aux->getCategoria();
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
					producto_aux->mostrarProducto(ANCHO / 5 - 10, ALTO / 4 + 2);
				}
				else
				{
					Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 4 + 2);
					cout << "No hay productos con ese ID!";
				}
			}
			else
			{
				for (int i = 0; i < l_productos->longitud(); i++)
				{
					if (convertirStringMinuscula(l_productos->obtenerPos(i)->getIdProduct()) == convertirStringMinuscula(id_producto))
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
					cout << "No hay productos con ese ID!";
				}

			}

			break;

		case 3:
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

		case 4:
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

		case 5:
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cout << "=============:: Buscar por precio ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
			cout << "[1] Ver productos por precios de menor a mayor";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
			cout << "[2] Ver solo los productos de minimo y mayor precio ";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
			cout << "Escoger opcion: "; cin >> opcionesPrecio;

			if (opcionesPrecio == 1)
			{
				for (int i = 0; i < l_productos->longitud(); i++)
				{
					l_productos_ordenados->agregaFinal(l_productos->obtenerPos(i));
				}
				ordenarXPrecio(l_productos_ordenados);
				while (!salir)
				{
					if (tecla_presionada)
					{
						system("cls");
						mainInterfaz->encuadrar();
						Console::SetCursorPosition(ANCHO / 6, ALTO / 6 + 0);
						cout << "=============:: Productos ::=============";
						if (contProductos < l_productos_ordenados->longitud() - 3)
						{
							l_productos_ordenados->obtenerPos(contProductos)->mostrarProducto(ANCHO / 6, ALTO / 6 + 1);
							l_productos_ordenados->obtenerPos(contProductos + 1)->mostrarProducto(ANCHO / 6, ALTO / 6 + 8);
							l_productos_ordenados->obtenerPos(contProductos + 2)->mostrarProducto(ANCHO / 6, ALTO / 6 + 15);
						}
						else
						{
							l_productos_ordenados->obtenerPos(contProductos)->mostrarProducto(ANCHO / 6, ALTO / 6 + 1);
							if (contProductos + 1 < l_productos_ordenados->longitud())
							{
								l_productos_ordenados->obtenerPos(contProductos + 1)->mostrarProducto(ANCHO / 6, ALTO / 6 + 8);
							}
						}

						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 1);
						cout << "[->] Mover siguiente producto";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 2);
						cout << "[<-] Retroceder anterior producto";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 3);
						cout << "[ESC] Salir";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 10);
						cout << "<" << contVentanas << " : " << l_productos_ordenados->longitud() / 3 + 1 << ">";
						tecla_presionada = false;
					}

					if (kbhit())
					{
						char tecla = getch();
						switch (tecla)
						{
						case TECLA_DERECHA:
							if (contProductos < l_productos_ordenados->longitud() - 3)
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
			}
			else
			{
				for (int i = 0; i < l_productos->longitud(); i++)
				{
					double precioProducto = stod(l_productos->obtenerPos(i)->getPrecio());
					if (precioProducto == minimoPrecio)
					{
						productoMin = l_productos->obtenerPos(i);
					}
					if (precioProducto == maximoPrecio)
					{
						productoMax = l_productos->obtenerPos(i);
					}
				}

				contProductos = 1;
				while (!salir)
				{
					if (tecla_presionada)
					{
						system("cls");
						mainInterfaz->encuadrar();

						if (contProductos == 1) auxCategoria = productoMin->getCategoria();
						else auxCategoria = productoMax->getCategoria();

						if (auxCategoria == "Farmaco")
						{
							productosInterfaz->dibujarFarmaco(ANCHO - 35, ALTO / 2 - 10);
						}
						if (auxCategoria == "Cosmeticos")
						{
							productosInterfaz->dibujarCosmetico(ANCHO - 35, ALTO / 2 - 10);
						}
						if (auxCategoria == "Cuidado para bebes")
						{
							productosInterfaz->dibujarBiberon(ANCHO - 35, ALTO / 2 - 10);
						}
						if (auxCategoria == "Cuidado personal")
						{
							productosInterfaz->dibujarCuidadoPersonal(ANCHO - 35, ALTO / 2 - 10);
						}
						if (auxCategoria == "Personas mayores")
						{
							productosInterfaz->dibujarPersonaMayor(ANCHO - 35, ALTO / 2 - 10);
						}

						if (contProductos == 1)
						{
							Console::SetCursorPosition(ANCHO / 6, ALTO / 6 + 0);
							cout << "=============:: Precio minimo ::=============";
							productoMin->mostrarProducto(ANCHO / 6, ALTO / 6 + 1);
						}
						else
						{
							Console::SetCursorPosition(ANCHO / 6, ALTO / 6 + 0);
							cout << "=============:: Precio maximo ::=============";
							productoMax->mostrarProducto(ANCHO / 6, ALTO / 6 + 1);
						}
						Console::SetCursorPosition(ANCHO - 40, ALTO / 2 + 1);
						cout << "[->] Mover siguientes productos";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 2 + 2);
						cout << "[<-] Retroceder anteriores productos";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 2 + 3);
						cout << "[ESC] Salir";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 2 + 8);
						cout << "<" << contVentanas << " : " << 2 << ">";
						tecla_presionada = false;
					}
					if (kbhit())
					{
						char tecla = getch();
						switch (tecla)
						{
						case TECLA_DERECHA:
							if (contProductos < 2)
							{
								contProductos++;
								contVentanas++;
							}
							break;
						case TECLA_IZQUIERDA:
							if (contProductos > 1)
							{
								contProductos--;
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
				//sobrescribirArchivoProducto(l_productos);
				break;
			}
		}
		if (!productoEncontrado)
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
			cout << "No hay productos con ese nombre!";
		}
	}

	void buscarPedidos(Cola<Pedido<string>*>* c_pedidos, ArbolBusqueda<int>* ab_ids_pedidos)
	{
		//Cola auxiliar para mostrar los pedidos
		Cola<Pedido<string>*>* c_pedidos_aux = c_pedidos->copiar();
		int size_cola = c_pedidos->size();
		Pedido<string>* pedidoAux = NULL;
		int opcModo, contPedidos = 0;
		string idPedido;
		bool salir = false, tecla_presionada = true, pedidoEncontrado = false;
		if (c_pedidos_aux->esVacia())
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
				while (!c_pedidos_aux->esVacia() && salir == false)
				{
					if (tecla_presionada)
					{
						system("cls");
						mainInterfaz->encuadrar();
						c_pedidos_aux->front()->mostarInformacion(ANCHO / 5 - 10, ALTO / 5);
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
								c_pedidos_aux->desencolar();
							}
							break;
						case TECLA_ESCAPE:
							salir = true;
							break;
						}
						tecla_presionada = true;
					}
				}
				if (c_pedidos_aux->esVacia())
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

				if (obtenerPrimerCaracter(idPedido) >= 48 && obtenerPrimerCaracter(idPedido) <= 57)
				{
					int id_pedido_entero = stoi(idPedido);
					if (ab_ids_pedidos->buscar(id_pedido_entero))
					{
						while (!c_pedidos_aux->esVacia())
						{
							pedidoAux = c_pedidos_aux->front();
							if (stoi(removerPrimerCaracter(pedidoAux->getIdPedido())) == id_pedido_entero)
							{
								pedidoEncontrado = true;
								pedidoAux->mostarInformacion(ANCHO / 4, ALTO / 5);
								break;
							}
							c_pedidos_aux->desencolar();
						}
					}
					else
					{
						Console::SetCursorPosition(ANCHO / 3, ALTO / 5);
						cout << "No hay Pedidos con ese ID!";
					}
				}
				else
				{
					for (int i = 0; i < c_pedidos_aux->size(); i++)
					{
						if (convertirStringMinuscula(c_pedidos_aux->back()->getIdPedido()) == convertirStringMinuscula(idPedido) && i == c_pedidos_aux->size() - 1)
						{
							pedidoAux = c_pedidos_aux->back();
							c_pedidos_aux->back()->mostarInformacion(ANCHO / 4, ALTO / 5);
						}
						if (convertirStringMinuscula(c_pedidos_aux->front()->getIdPedido()) == convertirStringMinuscula(idPedido))
						{
							pedidoAux = c_pedidos_aux->front();
							c_pedidos_aux->front()->mostarInformacion(ANCHO / 4, ALTO / 5);
						}
						c_pedidos_aux->desencolar();
					}
					if (pedidoAux == NULL)
					{
						Console::SetCursorPosition(ANCHO / 3, ALTO / 5);
						cout << "No hay Pedidos con ese ID!";
					}
				}

				
				break;
			}
		}

	}

	void buscarReclamos(Pila<Reclamo<string>*>* p_reclamos, ArbolBusqueda<int>* ab_ids_reclamos) {
		bool escape = false;
		string idReclamo;
		int opcModo, contReclamos = 0, opcionMover;
		bool  salir = false, tecla_presionada = true, reclamoEncontrado = false;
		Pila<Reclamo<string>*>* p_reclamos_aux = p_reclamos->copiar();
		Reclamo<string>* auxReclamo = p_reclamos_aux->returnTope();
		int size_pila = p_reclamos->size();
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
			while (!p_reclamos_aux->esVacia() && salir == false)
			{
				if (tecla_presionada)
				{
					system("cls");
					mainInterfaz->encuadrar();
					auxReclamo->mostrarReclamo(ANCHO / 4 - 10, ALTO / 5);
					Console::SetCursorPosition(ANCHO - 35, ALTO / 2 + 1);
					cout << "[->] Siguente Reclamo";
					Console::SetCursorPosition(ANCHO - 35, ALTO / 2 + 2);
					cout << "[ESC] Salir";
					Console::SetCursorPosition(ANCHO - 35, ALTO / 2 + 8);
					cout << "<" << contReclamos + 1 << " : " << size_pila << ">";
					tecla_presionada = false;
				}
				if (kbhit())
				{
					char tecla = getch();
					switch (tecla)
					{
					case TECLA_DERECHA:
						if (contReclamos < size_pila)
						{
							contReclamos++;
							p_reclamos_aux->desapilar();
							auxReclamo = p_reclamos_aux->returnTope();
						}
						break;
					case TECLA_ESCAPE:
						salir = true;
						break;
					}
					tecla_presionada = true;
				}
			}
			if (p_reclamos_aux->esVacia())
			{
				system("cls");
				mainInterfaz->encuadrar();
				Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
				cout << "Se han mostrado todos los reclamos!";
			}

			break;
		case 2:
			cin.ignore();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 - 2);
			cout << "=============:: Reclamos ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 - 1);
			cout << "Ingresar Id del Reclamo: "; getline(cin, idReclamo);
			system("cls");
			mainInterfaz->encuadrar();

			if (obtenerPrimerCaracter(idReclamo) >= 48 && obtenerPrimerCaracter(idReclamo) <= 57)
			{
				int id_reclamo_entero = stoi(idReclamo);
				if (ab_ids_reclamos->buscar(id_reclamo_entero))
				{
					while (!p_reclamos_aux->esVacia())
					{
						auxReclamo = p_reclamos_aux->desapilar();
						if (stoi(removerPrimerCaracter(auxReclamo->getIdReclamo())) == id_reclamo_entero)
						{
							auxReclamo->mostrarReclamo(ANCHO / 4, ALTO / 5);
							break;
						}
					}
				}
				else
				{
					Console::SetCursorPosition(ANCHO / 3, ALTO / 5);
					cout << "No hay Reclamos con ese ID!";
				}
			}
			else
			{
			int contador_reclamos_aux = 0;
				while (!p_reclamos_aux->esVacia())
				{
					auxReclamo = p_reclamos_aux->desapilar();
					if (convertirStringMinuscula(auxReclamo->getIdReclamo()) == convertirStringMinuscula(idReclamo))
					{
						reclamoEncontrado = true;
						auxReclamo->mostrarReclamo(ANCHO / 4, ALTO / 5);
						break;
					}
					contador_reclamos_aux++;
				}

				if (!reclamoEncontrado)
				{
					Console::SetCursorPosition(ANCHO / 3, ALTO / 5);
					cout << "No hay Reclamos con ese ID!";
				}
			}

			break;
		}
		
		delete p_reclamos_aux;
	}

	void ingresarProveedor(Lista<Proveedor<string>*>* l_proveedores) {
		string id, nombre, telefono, distrito, producto;
		Proveedor<string>* auxProve;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Ingresar Proveedor ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "Ingresar ID del Proveedor: "; cin >> id;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cout << "Ingresar Nombre del Proveedor: "; cin >> nombre;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "Ingresar Telefono: "; cin >> telefono;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
		cout << "Ingresar Distrito: "; cin >> distrito;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 5);
		cout << "Ingresar Producto: "; cin >> producto;
		auxProve = new Proveedor<string>(id, nombre, telefono, distrito, producto);
		l_proveedores->agregaFinal(auxProve);
	}

	void buscarProveedor(Lista<Proveedor<string>*>* l_proveedores, ArbolBusqueda<int>* ab_ids_proveedores) {
		string nombre, id_proveedor;
		bool proveedorEncontrado = false;
		int opcModo, contProveedores = 0;
		bool salir = false, tecla_presionada = true;

		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Buscar Proveedores ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "[1] Mostrar todos";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cout << "[2] Buscar por nombre";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "[3] Buscar por ID";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
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

		case 3:
			cin.ignore();
			Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 4 + 0);
			cout << "===========:: Buscar por ID del proveedor ::===========";
			Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 4 + 1);
			cout << "Ingresar ID del proveedor: "; getline(cin, id_proveedor);
			system("cls");
			mainInterfaz->encuadrar();
			if (obtenerPrimerCaracter(id_proveedor) >= 48 && obtenerPrimerCaracter(id_proveedor) <= 57)
			{
				int id_proveedor_entero = stoi(id_proveedor);
				if (ab_ids_proveedores->buscar(id_proveedor_entero))
				{
					Proveedor<string>* proveedor_aux = l_proveedores->obtenerPos(id_proveedor_entero - 1);
					proveedor_aux->mostrar(ANCHO / 5 - 10, ALTO / 4 + 2);
				}
				else
				{
					Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 4 + 2);
					cout << "No hay proveedores con ese ID!";
				}
			}
			else
			{
				for (int i = 0; i < l_proveedores->longitud(); i++)
				{
					if (convertirStringMinuscula(l_proveedores->obtenerPos(i)->getidProveedor()) == convertirStringMinuscula(id_proveedor))
					{
						proveedorEncontrado = true;
						l_proveedores->obtenerPos(i)->mostrar(ANCHO / 5 - 10, ALTO / 4 + 2);
					}
				}
				if (!proveedorEncontrado)
				{
					Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 4 + 2);
					cout << "No hay proveedores con ese ID!";
				}

			}
			break;
		}
	}

	void buscarBoletas(Lista<Boleta<string>*>* l_boletas, ArbolBusqueda<int>* ab_ids_boletas)
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
						l_boletas->obtenerPos(contBoletas)->mostrarInformacion(ANCHO / 6, ALTO / 5 + 1);
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 1);
						cout << "[->] Mover siguiente boleta";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 2);
						cout << "[<-] Retroceder anterior boleta";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 3);
						cout << "[ESC] Salir";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 10);
						cout << "<" << contBoletas + 1 << " : " << l_boletas->longitud() << ">";
						tecla_presionada = false;
					}
					if (kbhit())
					{
						char tecla = getch();
						switch (tecla)
						{
						case TECLA_DERECHA:
							if (contBoletas < l_boletas->longitud() - 1)
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
				cin.ignore();
				Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 4 + 0);
				cout << "===========:: Buscar por ID de la boleta ::===========";
				Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 4 + 1);
				cout << "Ingresar ID de la boleta: "; getline(cin, idBoleta);
				system("cls");
				mainInterfaz->encuadrar();
				if (obtenerPrimerCaracter(idBoleta) >= 48 && obtenerPrimerCaracter(idBoleta) <= 57)
				{
					int id_boleta_entero = stoi(idBoleta);
					if (ab_ids_boletas->buscar(id_boleta_entero))
					{
						Boleta<string>* boleta_aux = l_boletas->obtenerPos(id_boleta_entero - 1);
						boleta_aux->mostrarInformacion(ANCHO / 3, ALTO / 5 + 1);
					}
					else
					{
						Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 4 + 2);
						cout << "No hay boletas con ese ID!";
					}
				}
				else
				{
					for (int i = 0; i < l_boletas->longitud(); i++)
					{
						if (convertirStringMinuscula(l_boletas->obtenerPos(i)->getIdBoleta()) == convertirStringMinuscula(idBoleta))
						{
							boletaEncontrada = true;
							l_boletas->obtenerPos(i)->mostrarInformacion(ANCHO / 3, ALTO / 5 + 1);
						}
					}
					if (!boletaEncontrada)
					{
						Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 4 + 2);
						cout << "No hay boletas con ese ID!";
					}

				}
				break;
			}
			
		}

	}

	void crearDataSet(HashTable<Usuario<double, int>> &ht_usuarios, ArbolBalanceado<int>* abb_edades_usuarios) {
		system("cls");
		mainInterfaz->encuadrar();
		int N, edad;
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
			"Brenia", "Jesus Maria", "Pueblo Libre", "San Miguel", "Magdalena del Mar",
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
			cout << "Error al crear el archivo.";
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

			double dinero = rand() % 1001;
			edad = rand() % 71 + 20;

			ht_usuarios.insert(new Usuario<double, int>(nomUsuario, password, nombre, apellido, telefono, sexoElegido, distrito, dinero, edad));
			abb_edades_usuarios->insertar(edad);

			archivo << nomUsuario << "|" << password << "|" << nombre << "|" << apellido << "|" << telefono << "|" << sexoElegido << "|" << distrito << "|" << dinero << "|" << edad << "\n";
		}

		archivo.close();
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "Usuarios generados con exito.";
		
		
	}
	
	void buscarUsuario(HashTable<Usuario<double, int>> &ht_usuarios, ArbolBalanceado<int>* abb_edades_usuarios) {
		bool salir = false, tecla_presionada = true;
		int contVentanas = 1;                 // Contador de páginas (ventanas)
		int paginaActual = 0;                 // Índice de la página actual
		const int elementosPorPagina = 10;    // Número de elementos por página

		int opcModo, contUsuarios;

		system("cls");
		mainInterfaz->encuadrar();
		if (ht_usuarios.is_empty())
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 0);
			cout << "No hay usuario con generados aleatoriamente!";
		}
		else
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cout << "=============:: Buscar Usuarios ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
			cout << "[1] Mostrar todos";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
			cout << "[2] Mostrar todos ordenados por edad";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
			cout << "Seleccionar una opcion: "; cin >> opcModo;
			system("cls");
			mainInterfaz->encuadrar();
			switch (opcModo)
			{
			case 1:
				Console::SetCursorPosition(ANCHO / 3, ALTO / 7 + 0);
				cout << "===========:: HashTable de Usuarios::===========";
				while (!salir) {
					// Limpiar la pantalla o posición inicial (esto dependerá de cómo implementes el entorno gráfico o consola)
					if (tecla_presionada)
					{
						system("cls");  // Solo si estás en Windows; en Linux/Mac puedes usar `clear`
						mainInterfaz->encuadrar();

						int inicio = paginaActual * elementosPorPagina;
						int fin = min(static_cast<int>(ht_usuarios.getsize()), inicio + elementosPorPagina);
						int contEspacios = 0;

						int nH = 48;

						for (int i = inicio; i < fin; ++i) {
							if (ht_usuarios.getTable()[i] != nullptr && ht_usuarios.getTable()[i] != ht_usuarios.getDELETED()) {
								// Posicionar y mostrar cada elemento
								Console::SetCursorPosition(ANCHO / 6 - 1, ALTO / 5);
								cout << "+------------------------------------------------+";
								Console::SetCursorPosition(ANCHO / 6 - 1, ALTO / 5 + 11);
								cout << "+------------------------------------------------+";
								for (int i = 1; i < 11; i++) {
									Console::SetCursorPosition(ANCHO / 6 - 1, ALTO / 5 + i);
									cout << "|";
									Console::SetCursorPosition(ANCHO / 6 + nH, ALTO / 5 + i);
									cout << "|";
								}
								Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 1 + contEspacios);
								cout << "key " << i << " | Nombre: " << ht_usuarios.getTable()[i]->getNombre()
									<< ", Apellido: " << ht_usuarios.getTable()[i]->getApellido();
								
								contEspacios++;
							}
						}

						// Mostrar las instrucciones de navegación
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 1);
						cout << "[->] Mover a la siguiente pagina";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 2);
						cout << "[<-] Mover a la pagina anterior";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 3);
						cout << "[ESC] Salir";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 10);
						cout << "<" << paginaActual + 1 << " de " << (ht_usuarios.getsize() + elementosPorPagina - 1) / elementosPorPagina << ">";
						tecla_presionada = false;
					}


					// Detectar entrada de teclas
					if (kbhit()) {
						char tecla = getch();
						switch (tecla) {
						case TECLA_DERECHA:
							if ((paginaActual + 1) * elementosPorPagina < ht_usuarios.getsize()) {
								paginaActual++;  // Avanzar a la siguiente página
								contVentanas++;
							}
							break;
						case TECLA_IZQUIERDA:
							if (paginaActual > 0) {
								paginaActual--;  // Retroceder a la página anterior
								contVentanas--;
							}
							break;
						case TECLA_ESCAPE:
							salir = true;  // Salir del bucle y de la función
							break;
						}
						tecla_presionada = true;
					}

				}
				break;
			case 2:
				Lista<Usuario<double, int>*>* l_usuarios_aux = new Lista<Usuario<double, int>*>();
				
				for (int i = 0; i < ht_usuarios.getsize(); ++i) {
					if (ht_usuarios.getTable()[i] != nullptr && ht_usuarios.getTable()[i] != ht_usuarios.getDELETED()) {
						l_usuarios_aux->agregaFinal(ht_usuarios.getTable()[i]);
					}
				}

				if (l_usuarios_aux->longitud() > 1) {
					mergeSort(l_usuarios_aux, 0, l_usuarios_aux->longitud() - 1);
				}

				contUsuarios = 0;
				while (!salir)
				{
					if (tecla_presionada)
					{
						system("cls");
						mainInterfaz->encuadrar();
						Console::SetCursorPosition(ANCHO / 6, ALTO / 6 + 0);
						cout << "=============:: Usuario ::=============";
						l_usuarios_aux->obtenerPos(contUsuarios)->mostrar(ANCHO / 6, ALTO / 6 + 1);
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 1);
						cout << "[->] Mover siguiente usuario";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 2);
						cout << "[<-] Retroceder anterior usuario";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 3);
						cout << "[ESC] Salir";
						Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 10);
						cout << "<" << contUsuarios + 1 << " : " << l_usuarios_aux->longitud() << ">";
						tecla_presionada = false;
					}
					if (kbhit())
					{
						char tecla = getch();
						switch (tecla)
						{
						case TECLA_DERECHA:
							if (contUsuarios < l_usuarios_aux->longitud() - 1)
							{
								contUsuarios++;
							}
							break;
						case TECLA_IZQUIERDA:
							if (contUsuarios > 0)
							{
								contUsuarios--;
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
			}
			
		}
		
	}
};
