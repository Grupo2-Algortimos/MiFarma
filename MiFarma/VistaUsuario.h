#pragma once
#include"Funciones.h"
#include"Boleta.h"
#include"ProductosInterfaz.h"
#include"Reclamos.h"
class VistaUsuario
{
private:
	//Declaron Interfaces
	MainInterfaz* mainInterfaz;
	ProductosInterfaz* productosInterfaz;
public:
	VistaUsuario()
	{
		mainInterfaz = new MainInterfaz();
		productosInterfaz = new ProductosInterfaz();
	}

	~VistaUsuario()
	{
		delete mainInterfaz;
		delete productosInterfaz;
	}

	void vistaUsuarioPantalla(Lista<Producto<string>*>* l_productos, Lista<Producto<string>*>* l_productos_comprados, int& cont_productos_comprados,
		Lista<Usuario*>* l_usuarios, Usuario* usario_actual, Pedido* &pedido_usuario, queue<Pedido*> &c_pedidos, Lista<Reclamo<string>*>* l_reclamos,
		Lista<Boleta<string>*>* l_boletas)
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
					pedido_usuario, c_pedidos, l_reclamos, l_boletas);
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
		} while (op != 3);
	}

	void loginUsuario(Lista<Producto<string>*>* l_productos, Lista<Producto<string>*>* l_productos_comprados, int& cont_productos_comprados, 
		Lista<Usuario*>* l_usuarios, Usuario* usario_actual, Pedido* &pedido_usuario, queue<Pedido*> &c_pedidos, Lista<Reclamo<string>*>* l_reclamos,
		Lista<Boleta<string>*>* l_boletas) 
	{
		string user, password;
		bool salir = false;
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
			cout << "Ingresar Usuario: "; cin >> user;
			if (user == "1") break;
			Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 2);
			cout << "Ingresar contrasena: "; cin >> password;
			for (int i = 0; i < l_usuarios->longitud(); i++)
			{
				if (l_usuarios->obtenerPos(i)->getUser() == user)
				{
					if (l_usuarios->obtenerPos(i)->getPassword() == password)
					{
						system("cls");
						mainInterfaz->encuadrar();
						Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
						usario_actual = l_usuarios->obtenerPos(i);
						cout << "Ingreso exitoso...";
						system("pause>>null");
						userOpciones(l_productos, l_productos_comprados, cont_productos_comprados, usario_actual, pedido_usuario, c_pedidos,
							l_reclamos, l_boletas);
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

	void registerUsuario(int i, Lista<Usuario*>* l_usuarios) {
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
		cout << "Usuario creado: " << auxUsuario->getUser();
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "Contrasena creada: " << auxUsuario->getPassword();
		l_usuarios->agregaPos(auxUsuario, i);
		system("pause>>null");
	}

	void userOpciones(Lista<Producto<string>*>* l_productos, Lista<Producto<string>*>* l_productos_comprados, int &cont_productos_comprados,
		Usuario* usario_actual, Pedido* &pedido_usuario, queue<Pedido*> &c_pedidos, Lista<Reclamo<string>*>* l_reclamos, Lista<Boleta<string>*>* l_boletas) {
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
				listarProducto(l_productos, l_productos_comprados, cont_productos_comprados);
				break;
			case 2:
				verCarrito(l_productos_comprados, pedido_usuario, c_pedidos, usario_actual);
				break;
			case 3:
				ingresarReclamo(l_reclamos, usario_actual);
				break;
			case 4:
				comprado = comprarProductos(l_productos_comprados, usario_actual, pedido_usuario, l_boletas, c_pedidos);
				break;
			}
			system("pause>>null");
		}
	}

	void listarProducto(Lista<Producto<string>*>* l_productos, Lista<Producto<string>*>* l_productos_comprados,
		int &cont_productos_comprados)
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
			Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 0);
			cout << "=============:: Productos ::=============";
			int contEspacios = 0;
			for (int i = 0; i < l_productos->longitud(); i++)
			{
				if (contEspacios > 10) break;
				if (l_productos->obtenerPos(i)->getCategoria() == categoria)
				{
					Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 1 + contEspacios);
					cout << l_productos->obtenerPos(i)->getNombre() << " : S/" << l_productos->obtenerPos(i)->getPrecio();
					contEspacios++;
				}
			}
			Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 2 + contEspacios);
			cin.ignore();
			cout << "Ingresar nombre del producto: "; getline(cin, nombre);
			system("cls");
			mainInterfaz->encuadrar();
			for (int i = 0; i < l_productos->longitud(); i++)
			{
				if (l_productos->obtenerPos(i)->getNombre() == nombre)
				{
					auxProducto = l_productos->obtenerPos(i);
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

	void verCarrito(Lista<Producto<string>*>* l_productos_comprados, Pedido* &pedido_usuario, queue<Pedido*> &c_pedidos, Usuario* usuario_actual)
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
			cout << "[1] Ordenar por precio de menor a mayor";
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 2);
			cout << "[2] Ordenar por precio de mayor a menor";
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
				cout << "- " << l_productos_comprados->obtenerPos(i)->getNombre() << " : " << l_productos_comprados->obtenerPos(i)->getPrecio();
				contEspacios++;
			}
			pedido_usuario = new Pedido("P0" + to_string(c_pedidos.size()), usuario_actual->getNombre(), "Javier", usuario_actual->getDistrito(), 
				l_productos_comprados, "Pendiente", "Motocicleta");
			Console::SetCursorPosition(ANCHO - 25, ALTO / 2);
			cout << "Total: " << pedido_usuario->conseguirCostoTotal();
		}
	}
	void ingresarReclamo(Lista<Reclamo<string>*>* l_reclamos, Usuario* usario_actual)
	{
		string idReclamo, fecha, nombreProducto, tipo, detalle, pedido;
		Reclamo<string>* auxReclamo;
		idReclamo = "R0" + to_string(l_reclamos->longitud());
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
		l_reclamos->agregaPos(auxReclamo, l_reclamos->longitud());
	}

	bool comprarProductos(Lista<Producto<string>*>* l_productos_comprados, Usuario* usario_actual, Pedido* &pedido_usuario,
		Lista<Boleta<string>*>* l_boletas, queue<Pedido*> &c_pedidos)
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
				mainInterfaz->dibujarCarritoCompraz(ANCHO - 35, ALTO / 2 - 5);
				Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 0);
				cout << "=============:: Comprando Productos ::=============";
				Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 1);
				cout << "Monto total: " << pedido_usuario->conseguirCostoTotal();
				Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 2);
				cout << "Poner costo su monto: "; cin >> montoUsuario;
				system("cls");
				mainInterfaz->encuadrar();
				if (stod(montoUsuario) >= pedido_usuario->conseguirCostoTotal())
				{
					idBoleta = "B03" + to_string(l_boletas->longitud());
					c_pedidos.push(pedido_usuario);
					auxBoleta = new Boleta<string>(idBoleta, usario_actual->getNombre(), fecha, montoUsuario, to_string(pedido_usuario->conseguirCostoTotal()));
					l_boletas->agregaPos(auxBoleta, l_boletas->longitud());
					mainInterfaz->compra();
					system("pause>>null");
					system("cls");
					mainInterfaz->encuadrar();
					mainInterfaz->dibujarMoto(ANCHO - 35, ALTO / 2 - 5);
					mainInterfaz->dibujarCajaEntregada(ANCHO / 2.5, ALTO - 15);
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
