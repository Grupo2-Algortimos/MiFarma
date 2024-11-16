#pragma once
#include"Funciones.h"
#include"Boleta.h"
#include"ProductosInterfaz.h"
#include"Reclamos.h"
#include"ArbolBusqueda.h"
#include"ArbolBalanceado.h"
#include"Usuario.h"
#include"SedeAsignada.h"
#include"Cola.h"
#include"Pila.h"
class VistaUsuario
{
private:
	//Declaron Interfaces
	MainInterfaz* mainInterfaz;
	ProductosInterfaz* productosInterfaz;
	SedeAsignada<int, string> sedeUsuario;
	bool visto_carrito;
public:
	VistaUsuario()
	{
		mainInterfaz = new MainInterfaz();
		productosInterfaz = new ProductosInterfaz();
		visto_carrito = false;
	}

	~VistaUsuario()
	{
		delete mainInterfaz;
		delete productosInterfaz;
	}
	

	void vistaUsuarioPantalla(Lista<Producto<string>*>* l_productos, Lista<Producto<string>*>* l_productos_comprados, int& cont_productos_comprados,
		Lista<Usuario<double, int>*>* l_usuarios, Usuario<double, int>* usario_actual, Pedido<string>* &pedido_usuario, Cola<Pedido<string>*>* &c_pedidos, Pila<Reclamo<string>*>* &p_reclamos,
		Lista<Boleta<string>*>* &l_boletas, ArbolBusqueda<int>* ab_ids_productos, ArbolBalanceado<double>* abb_precios_productos)
	{
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
			if (op == 3) break;
			switch (op)
			{
			case 1:
				system("cls");
				mainInterfaz->encuadrar();
				loginUsuario(l_productos, l_productos_comprados, cont_productos_comprados, l_usuarios, usario_actual,
					pedido_usuario, c_pedidos, p_reclamos, l_boletas, ab_ids_productos, abb_precios_productos);
				break;
			case 2:
				system("cls");
				mainInterfaz->encuadrar();
				registerUsuario(i, l_usuarios);
				i++;
				break;
			default:
				cout << "Opcion no valida. Intente de nuevo.";
				break;
			}
			system("pause>>null");
		} while (op != 3);
	}

	void loginUsuario(Lista<Producto<string>*>* l_productos, Lista<Producto<string>*>* l_productos_comprados, int& cont_productos_comprados, 
		Lista<Usuario<double, int>*>* l_usuarios, Usuario<double, int>* usuario_actual, Pedido<string>* &pedido_usuario, Cola<Pedido<string>*>* &c_pedidos, Pila<Reclamo<string>*>* &p_reclamos,
		Lista<Boleta<string>*>* &l_boletas, ArbolBusqueda<int>* ab_ids_productos, ArbolBalanceado<double>* abb_precios_productos)
	{
		string user, password;
		bool salir = false;
		bool usuario_encontrado = false, contrasena_correcta = false;
		while (true)
		{
			l_productos_comprados = new Lista<Producto<string>*>();
			cont_productos_comprados = 0;
			if (salir)break;
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
			cout << "=============:: Login de Usuario ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 1);
			cin.ignore();
			cout << "Ingresar Usuario: "; getline(cin, user); 
			if (user == "1") break;
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 2);
			cout << "Ingresar contrasena: "; getline(cin, password);
			for (int i = 0; i < l_usuarios->longitud(); i++)
			{
				if (l_usuarios->obtenerPos(i)->getUser() == user)
				{
					usuario_encontrado = true;
					if (l_usuarios->obtenerPos(i)->getPassword() == password)
					{
						contrasena_correcta = true;
						system("cls");
						mainInterfaz->encuadrar();
						Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
						usuario_actual = l_usuarios->obtenerPos(i);
						cout << "Ingreso exitoso...";
						system("pause>>null");
						userOpciones(l_productos, l_productos_comprados, cont_productos_comprados, usuario_actual, pedido_usuario, c_pedidos,
							p_reclamos, l_boletas, ab_ids_productos, abb_precios_productos);
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
				cout << "El usuario o contrasena ingresado es incorrecto....";
				salir = true;
			}
		}
	}

	
	
	void registerUsuario(int i, Lista<Usuario<double, int>*>* l_usuarios) {
		string nombre, apellido, telefono, sexo, distrito;
		string user, password;
		Usuario<double, int>* auxUsuario;
		double dinero = 0;
		int op = 0, edad = 0;
		cin.ignore();
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Resgistro de Usuario ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "Ingresar nombre: "; getline(cin, nombre);
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cout << "Ingresar apellido: "; getline(cin, apellido);
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "Ingresar telefono: "; getline(cin, telefono);
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
		cout << "Ingresar sexo (M/F): "; getline(cin, sexo);
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 5);
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
				for (int i = 0; i < l_usuarios->longitud(); i++)
				{
					if (l_usuarios->obtenerPos(i)->getUser() == user)
					{
						op = -1;
						Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 5);
						cout << "El nombre de usuario ya existe!";
						system("pause>>null");
					}
				}
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
		auxUsuario = new Usuario<double, int>(user, password, nombre, apellido, telefono, sexo, distrito, dinero, edad);
		l_usuarios->agregaFinal(auxUsuario);
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "Usuario creado: " << auxUsuario->getUser();
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "Contrasena creada: " << auxUsuario->getPassword();
		system("pause>>null");
	}

	void userOpciones(Lista<Producto<string>*>* l_productos, Lista<Producto<string>*>* l_productos_comprados, int &cont_productos_comprados, Usuario<double, int>* usuario_actual,
		Pedido<string>* &pedido_usuario, Cola<Pedido<string>*>* &c_pedidos, Pila<Reclamo<string>*>* &p_reclamos, Lista<Boleta<string>*>* &l_boletas, ArbolBusqueda<int>* ab_ids_productos,
		ArbolBalanceado<double>* abb_precios_productos) {
		int opcionM;
		int i = 0;
		int p = 0;
		bool comprado = false;
		while (true)
		{
			if (comprado == true) break;
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(2, 2);
			cout << "Usuario: " << usuario_actual->getNombre();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
			cout << "=============:: User Menu ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
			cout << "[1] Ver todos los productos";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
			cout << "[2] Agregar Productos";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
			cout << "[3] Ver Carrito";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
			cout << "[4] Ingresar Reclamo";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 5);
			cout << "[5] Comprar Productos";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 6);
			cout << "[6] Salir";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 7);
			cout << "Seleccione una opcion : "; cin >> opcionM;
			if (opcionM == 6) break;
			system("cls");
			mainInterfaz->encuadrar();
			switch (opcionM)
			{
			case 1:
				verProductos(l_productos, ab_ids_productos, abb_precios_productos);
				break;
			case 2:
				agregarProducto(l_productos, l_productos_comprados, usuario_actual, cont_productos_comprados);
				break;
			case 3:
				verCarrito(l_productos_comprados, pedido_usuario, c_pedidos, usuario_actual, cont_productos_comprados);
				break;
			case 4:
				ingresarReclamo(p_reclamos, usuario_actual);
				break;
			case 5:
				comprado = comprarProductos(l_productos_comprados, usuario_actual, pedido_usuario, l_boletas, c_pedidos);
				break;
			}
			system("pause>>null");
		}
	}

	void verProductos(Lista<Producto<string>*>* l_productos, ArbolBusqueda<int>* ab_ids_productos, ArbolBalanceado<double>* abb_precios_productos)
	{
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
		cout << "[2] Buscar por categoria";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "[3] Buscar por nombre";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
		cout << "[4] Buscar por ID";
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
		case 4:
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
				ordShellProductoMenorAMayor(l_productos_ordenados);

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


	void agregarProducto(Lista<Producto<string>*>* l_productos, Lista<Producto<string>*>* l_productos_comprados, Usuario<double, int>*& usuario_actual,
		int &cont_productos_comprados)
	{
		int opcionesC;
		string nombre, categoria, cantidad;
		Producto<string>* auxProducto;
		bool producto_repetido = false;

		while (true)
		{
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(2, 2);
			cout << "Usuario: " << usuario_actual->getNombre();
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
			case 1:
				categoria = "Farmaco";
				productosInterfaz->dibujarFarmaco(ANCHO - 35, ALTO / 2 - 5);
				break;
			case 2:
				categoria = "Cosmeticos";
				productosInterfaz->dibujarCosmetico(ANCHO - 35, ALTO / 2 - 5);
				break;
			case 3:
				categoria = "Cuidado para bebes";
				productosInterfaz->dibujarBiberon(ANCHO - 35, ALTO / 2 - 5);
				break;
			case 4:
				categoria = "Cuidado personal";
				productosInterfaz->dibujarCuidadoPersonal(ANCHO - 35, ALTO / 2 - 5);
				break;
			case 5:
				categoria = "Personas mayores";
				productosInterfaz->dibujarPersonaMayor(ANCHO - 35, ALTO / 2 - 5);
				break;
			}
			Console::SetCursorPosition(2, 2);
			cout << "Usuario: " << usuario_actual->getNombre();
			Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 0);
			cout << "=============:: Productos ::=============";
			int contEspacios = 0;
			char tecla;
			for (int i = 0; i < l_productos->longitud(); i++)
			{
				if (contEspacios > 10)
				{
					Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 1 + i);
					cout << ".................";
					break;
				}

				if (l_productos->obtenerPos(i)->getCategoria() == categoria)
				{
					Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 1 + contEspacios);
					cout << l_productos->obtenerPos(i)->getNombre() << " : S/" << l_productos->obtenerPos(i)->getPrecio();
					contEspacios++;					
				}					
			}
			Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 3 + contEspacios);
			cin.ignore();
			cout << "Ingresar nombre del producto: "; getline(cin, nombre);
			Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 4 + contEspacios);			
			cout << "Ingresar cantidad del producto: "; cin >> cantidad;
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(2, 2);
			cout << "Usuario: " << usuario_actual->getNombre();
			auxProducto = NULL;
			for (int i = 0; i < l_productos->longitud(); i++)
			{
				if (convertirStringMinuscula(l_productos->obtenerPos(i)->getNombre()) == convertirStringMinuscula(nombre))
				{
					auxProducto = l_productos->obtenerPos(i);
					auxProducto->setCantidad(cantidad);
				}
			}
			if (auxProducto == NULL)
			{
				Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
				cout << "No se encontro un producto con ese nombre!";
			}
			else
			{
				//Determinar si el producto ya fue agregado
				for (int i = 0; i < l_productos_comprados->longitud(); i++)
				{
					if (convertirStringMinuscula(l_productos_comprados->obtenerPos(i)->getNombre()) == convertirStringMinuscula(nombre)) {

						l_productos_comprados->obtenerPos(i)->setCantidad(cantidad);
						producto_repetido = true;
					}
				}

				if (producto_repetido)
				{
					Console::SetCursorPosition(ANCHO / 4, ALTO / 3 + 0);
					cout << "Agregaste otra vez un producto";
					Console::SetCursorPosition(ANCHO / 4, ALTO / 3 + 1);
					cout << "Actualizado la cantidad que escogiste";
				}
				else
				{
					Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
					cout << "Producto Agregado!";
					l_productos_comprados->agregaPos(auxProducto, cont_productos_comprados);
					cont_productos_comprados++;
				}
			}
			system("pause>>null");
		}
	}

	void eliminarElementoCarrito(Lista<Producto<string>*>* l_productos_comprados) {
		int contEspacios = 0;
		string nombreProductoEliminar;
		bool producto_eliminado = false;

		if (l_productos_comprados->longitud() == 1)
		{
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 4, ALTO / 5 + 9);
			cout << "El producto " << l_productos_comprados->obtenerInicial()->getNombre() << " ha sido retirado correctamente";
			l_productos_comprados->eliminaInicial();
		}
		else
		{
			system("cls");
			mainInterfaz->encuadrar();
			Console::SetCursorPosition(ANCHO / 4, ALTO / 5 + 0);
			cout << "===========:: Carrito ::=============";
			for (int i = 0; i < l_productos_comprados->longitud(); i++)
			{
				if (contEspacios > 10)
				{
					Console::SetCursorPosition(ANCHO / 4, ALTO / 5 + 1 + i);
					cout << ".................";
					break;
				}
				Console::SetCursorPosition(ANCHO / 4, ALTO / 5 + 1 + i);
				cout << "- " << l_productos_comprados->obtenerPos(i)->getNombre() << " : S/." << l_productos_comprados->obtenerPos(i)->getPrecio()
					<< " x " << l_productos_comprados->obtenerPos(i)->getCantidad() << " = " << l_productos_comprados->obtenerPos(i)->getSubTotal();
				contEspacios++;
			}

			cin.ignore();
			Console::SetCursorPosition(ANCHO / 5, ALTO - 7);
			cout << "Ingrese el nombre del producto a eliminar: "; getline(cin, nombreProductoEliminar);
			for (int i = 0; i < l_productos_comprados->longitud(); i++)
			{
				if (convertirStringMinuscula(nombreProductoEliminar) == convertirStringMinuscula(l_productos_comprados->obtenerPos(i)->getNombre()))
				{
					l_productos_comprados->eliminaPos(i);
					producto_eliminado = true;
					break;
				}
			}

			system("cls");
			mainInterfaz->encuadrar();
			if (producto_eliminado)
			{
				nombreProductoEliminar.begin().operator*() = toupper(nombreProductoEliminar.begin().operator*());
				Console::SetCursorPosition(ANCHO / 4, ALTO / 5 + 9);
				cout << "El producto " << nombreProductoEliminar << " ha sido retirado correctamente";
			}
			else
			{
				Console::SetCursorPosition(ANCHO / 4, ALTO / 5 + 9);
				cout << "¡No se encontro el nombre del producto!";
			}
		}
	}

	void eliminarTodoCarrito(Lista<Producto<string>*>* l_productos_comprados, int& cont_productos_comprados)
	{
		l_productos_comprados->eliminaTodo();
		cont_productos_comprados = 0;
		system("cls");
		mainInterfaz->encuadrar();
		Console::SetCursorPosition(ANCHO / 4, ALTO / 5 + 9);
		cout << "Todo los productos del carrito han sido eliminados";
	}
	
	void verCarrito(Lista<Producto<string>*>* l_productos_comprados, Pedido<string>* &pedido_usuario, Cola<Pedido<string>*>* &c_pedidos, Usuario<double, int>* usuario_actual,
		int& cont_productos_comprados)
	{
		int opcCarrito;
		int contEspacios = 0;
		visto_carrito = true;
		Console::SetCursorPosition(2, 2);
		cout << "Usuario: " << usuario_actual->getNombre();
		if (l_productos_comprados->esVacia())
		{
			
			Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
			cout << "No hay productos agregados";
		}
		else
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 0);
			cout << "===========:: Carrito ::=============";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 1);
			cout << "[1] Ordenar por precio de menor a mayor";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 2);
			cout << "[2] Ordenar por precio de mayor a menor";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 3);
			cout << "[3] Eliminar un producto del carrito";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 4);
			cout << "[4] Eliminar todo el carrito";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 5);
			cout << "Escoger opcion: "; cin >> opcCarrito;

			switch (opcCarrito)
			{
			case 1:
				ordShellProductoMenorAMayor(l_productos_comprados);
				break;
			case 2:
				ordShellProductoMayorAMenor(l_productos_comprados);
				break;
			case 3 :
				eliminarElementoCarrito(l_productos_comprados);
				break;
			case 4:
				eliminarTodoCarrito(l_productos_comprados, cont_productos_comprados);
				break;
			}

			if (opcCarrito < 3)
			{
				system("cls");
				mainInterfaz->encuadrar();
				Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 0);
				cout << "===========:: Carrito ::=============";
				for (int i = 0; i < l_productos_comprados->longitud(); i++)
				{
					if (contEspacios > 10)
					{
						Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 1 + i);
						cout << ".................";
						break;
					}
					Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 1 + i);
					cout << "- " << l_productos_comprados->obtenerPos(i)->getNombre() << " : S/." << l_productos_comprados->obtenerPos(i)->getPrecio()
						<< " x " << l_productos_comprados->obtenerPos(i)->getCantidad() << " = " << l_productos_comprados->obtenerPos(i)->getSubTotal();
					contEspacios++;
				}


				int contPedido = 1;
				
				while (true)
				{
					Cola<Pedido<string>*>* c_pedidos_aux = c_pedidos->copiar();
					bool id_pedido_repetido = false;
					string id_pedido_nuevo = "P00" + to_string(contPedido);
					while (!c_pedidos_aux->esVacia())
					{
						Pedido<string>* pedido_aux = c_pedidos_aux->desencolar();
						if (pedido_aux->getIdPedido() == id_pedido_nuevo)
						{
							id_pedido_repetido = true;
						}
					}

					if (!id_pedido_repetido)
					{
						pedido_usuario = new Pedido<string>(id_pedido_nuevo, usuario_actual->getNombre(), repartidores.at(rand() % 4), usuario_actual->getDistrito(),
							l_productos_comprados, "Pendiente", "Motocicleta");
						break;
					}
					else
					{
						contPedido++;
					}

					delete c_pedidos_aux;
				}
				
				

				Console::SetCursorPosition(ANCHO - 25, ALTO / 2);
				cout << "Total: " << pedido_usuario->conseguirCostoTotal();
			}
		}
	}
	
	void ingresarReclamo(Pila<Reclamo<string>*>* &p_reclamos, Usuario<double, int>* &usuario_actual)
	{
		int contReclamos = 1;
		string fecha, nombreProducto, tipo, detalle, pedido;
		Pila<Reclamo<string>*>* p_reclamos_aux = p_reclamos->copiar();
		Reclamo<string>* nuevoReclamo = NULL;
		fecha = obtenerFechaYHora();
		
		cin.ignore();
		Console::SetCursorPosition(2, 2);
		cout << "Usuario: " << usuario_actual->getNombre();
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Ingresar Reclamo ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "Ingresar Nombre del Producto Inconforme: "; getline(cin, nombreProducto);
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cout << "Ingresar Tipo (R: reclamo || Q: queja): ";  getline(cin, tipo);
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "Ingresar Detalles: "; getline(cin, detalle);
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 4);
		cout << "Que solicita en el pedido?: "; getline(cin, pedido);
		while (true)
		{
			string idReclamo = "R00" + to_string(p_reclamos_aux->size() + contReclamos);
			
			bool id_reclamo_repetido = false;
			Reclamo<string>* auxReclamo;
			while (!p_reclamos_aux->esVacia())
			{
				auxReclamo = p_reclamos_aux->returnTope();
				if (auxReclamo->getIdReclamo() == idReclamo)
				{
					id_reclamo_repetido = true;
				}
				p_reclamos_aux->desapilar();
			}
			if (!id_reclamo_repetido)
			{
				nuevoReclamo = new Reclamo<string>(idReclamo, fecha, usuario_actual->getNombre(), usuario_actual->getTelefono(), usuario_actual->getDistrito(),
					nombreProducto, tipo, detalle, pedido);
				p_reclamos->apilar(nuevoReclamo);
				system("cls");
				mainInterfaz->encuadrar();
				Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
				cout << "Reclamo ingresado correctamente!";
				break;
			}
		}
	}

	bool comprarProductos(Lista<Producto<string>*>* l_productos_comprados, Usuario<double, int>* &usuario_actual, Pedido<string>* &pedido_usuario,
		Lista<Boleta<string>*>* &l_boletas, Cola<Pedido<string>*>* &c_pedidos)
	{
		string sedeAsignada;
		sedeAsignada = sedeUsuario.calcularSedeCercana(usuario_actual->getDistrito());
		string montoUsuario, fecha, idBoleta;
		Boleta<string>* auxBoleta;
		fecha = obtenerFechaYHora();
		if (l_productos_comprados->esVacia())
		{
			Console::SetCursorPosition(2, 2);
			cout << "Usuario: " << usuario_actual->getNombre();
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
			cout << "No has agregado ningun producto!";
		}
		else if (!visto_carrito)
		{
			Console::SetCursorPosition(2, 2);
			cout << "Usuario: " << usuario_actual->getNombre();
			Console::SetCursorPosition(ANCHO / 5, ALTO / 3 + 0);
			cout << "Tienes que ver tu carrito y confirmar tus productos para comprar!";
		}
		else
		{
			while (true)
			{
				system("cls");
				mainInterfaz->encuadrar();
				mainInterfaz->dibujarCarritoCompraz(ANCHO - 35, ALTO / 2 - 5);
				Console::SetCursorPosition(2, 2);
				cout << "Usuario: " << usuario_actual->getNombre();
				Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 0);
				cout << "=============:: Comprando Productos ::=============";
				Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 1);
				if (sedeUsuario.getDistancia() != -1)
					cout << "Sede Asignada: " << sedeAsignada << ", a " << sedeUsuario.getDistancia() << "km de distancia";
				else
					cout << "Sede Asignada por defecto: " << sedeAsignada;
				Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 2);
				if (sedeUsuario.getTiempo() != -1)
					cout << "Tiempor de llegada: " << sedeUsuario.getTiempo() << " minutos";
				else
					cout << "Tiempor de llegada: " << 25 << " minutos";
				Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 3);
				cout << "Monto total: " << pedido_usuario->conseguirCostoTotal();
				Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 4);
				cout << "Poner costo su monto: "; cin >> montoUsuario;
				system("cls");
				mainInterfaz->encuadrar();
				if (stod(montoUsuario) >= pedido_usuario->conseguirCostoTotal())
				{
					idBoleta = "B0" + to_string(l_boletas->longitud() + 1);
					c_pedidos->encolar(pedido_usuario);
					auxBoleta = new Boleta<string>(idBoleta, usuario_actual->getNombre(), fecha, montoUsuario, to_string(pedido_usuario->conseguirCostoTotal()));
					l_boletas->agregaFinal(auxBoleta);
					mainInterfaz->compra();
					system("pause>>null");
					system("cls");
					mainInterfaz->encuadrar();
					mainInterfaz->dibujarMoto(ANCHO - 35, ALTO / 2 - 5);
					mainInterfaz->dibujarCajaEntregada(ANCHO - 35, ALTO - 15);
					Console::SetCursorPosition(2, 2);
					cout << "Usuario: " << usuario_actual->getNombre();
					Console::SetCursorPosition(ANCHO / 6, ALTO / 5);
					cout << "=============:: Pronto llegara tu pedido ::=============";
					auxBoleta->mostrarInformacion(ANCHO / 6, ALTO / 5 + 1);
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
