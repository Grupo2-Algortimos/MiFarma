#pragma once
#include"Empleado.h"
#include"Reclamos.h"
#include"Proveedor.h"
#include"Funciones.h"
#include"ProductosInterfaz.h"
#include "HashTable.h"
class VistaEmpleado
{
private:
	//Declaron Interfaces
	MainInterfaz* mainInterfaz;
	ProductosInterfaz* productosInterfaz;
	HashTablaA hashTable;
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
			if (!usuario_encontrado)
			{
				system("cls");
				mainInterfaz->encuadrar();
				Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
				cout << "El usuario ingresado es incorrecto....";
				salir = true;
			}
			if (!contrasena_correcta)
			{
				system("cls");
				mainInterfaz->encuadrar();
				Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
				cout << "La contrasena ingresada es incorrecta....";
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
		l_empleados->agregaPos(aux, coni);
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
			}
			system("pause>>null");
		}
	}

	void ingresarProducto(int i, Lista<Producto<string>*>* l_productos) {
		string idProduct, nombre, precio, categoria, cantidad, fechaCad;
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
		auxProduct = new Producto<string>(idProduct, nombre, precio, categoria, cantidad, fechaCad);
		l_productos->agregaPos(auxProduct, i);
	}

	void buscarProducto(Lista<Producto<string>*>* l_productos) {
		string nombre, categoria, auxCategoria;
		int opcionesP, opcionesC, contEspacios = 0;
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 0);
		cout << "=============:: Buscar Producto ::=============";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 1);
		cout << "[1] Buscar por categoria";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 2);
		cout << "[2] Buscar por Nombre";
		Console::SetCursorPosition(ANCHO / 3, ALTO / 4 + 3);
		cout << "Seleccionar una opcion: "; cin >> opcionesP;
		system("cls");
		mainInterfaz->encuadrar();
		switch (opcionesP)
		{
		case 1:
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
			Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 5 + 0);
			cout << "=============:: Productos ::=============";
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
			contEspacios = 0;
			for (int i = 0; i < l_productos->longitud(); i++)
			{
				if (contEspacios > 20) break;
				if (l_productos->obtenerPos(i)->getCategoria() == categoria)
				{
					Console::SetCursorPosition(ANCHO / 5, ALTO / 5 + 1 + contEspacios);
					cout << l_productos->obtenerPos(i)->getNombre() << " : S/" << l_productos->obtenerPos(i)->getPrecio();
					contEspacios++;
				}
			}
			break;
		case 2:
			Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 4 + 0);
			cout << "===========:: Buscar por Nombre ::===========";
			Console::SetCursorPosition(ANCHO / 5 - 10, ALTO / 4 + 1);
			cout << "Ingresar Nombre del producto: ";
			cin.ignore(); getline(cin, nombre);
			for (int i = 0; i < l_productos->longitud(); i++)
			{

				if (l_productos->obtenerPos(i)->getNombre() == nombre)
				{
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
			break;
		}
	}

	void modificarProducto(Lista<Producto<string>*>* l_productos) {
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

	void buscarPedidos(queue<Pedido*> c_pedidos)
	{
		//Cola auxiliar para mostrar los pedidos
		queue<Pedido*> c_pedidos_aux = c_pedidos;

		int contIdIncorrecto = 0;
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
			if (contIdIncorrecto == c_pedidos_aux.size() + 1)
			{
				Console::SetCursorPosition(ANCHO / 3, ALTO / 3 + 0);
				cout << "No hay Pedidos con ese ID!";
			}
		}

	}

	void buscarReclamos(Lista<Reclamo<string>*>* l_reclamos) {
		string idReclamo;
		bool encontrado = false;
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
	}

	void ingresarProveedor(int p, Lista<Proveedor*>* l_proveedores) {
		string nombre, telefono, distrito, producto;
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
		l_proveedores->agregaPos(auxProve, p);
	}

	void buscarProveedor(Lista<Proveedor*>* l_proveedores) {
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
		for (int i = 0; i < l_proveedores->longitud(); i++)
		{
			if (l_proveedores->obtenerPos(i)->getnombre() == nombre)
			{
				l_proveedores->obtenerPos(i)->mostrar(ANCHO / 3, ALTO / 5);
			}
			else
			{
				contNombreIncorrecto++;
			}
		}

		if (contNombreIncorrecto == l_proveedores->longitud())
		{
			Console::SetCursorPosition(ANCHO / 3, ALTO / 5 + 0);
			cout << "No hay proveedores con ese nombre!";
		}
	}

	void buscarBoletas(Lista<Boleta<string>*>* l_boletas)
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

};
