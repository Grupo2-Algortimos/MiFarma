#pragma once
#include"Libreria.h"
#include"Lista.h"
#include"Producto.h"

class Pedido
{
private:
	string idPedido;
	string nombreUsuario;
	string nombreRepartidor;
	string direccion;
	Lista<Producto<string>*>* productosComprados;
	string estado; // "Pendiente", "En camino", "Entregado"
	string modoEntrega; // "Motocicleta", "Bicicleta"

public:
	Pedido(string p_idPedido, string p_nombreUsuario, string p_nombreRepartidor, string p_direccion, Lista<Producto<string>*>* p_productosComprados,
		string p_estado, string p_modoEntrega){
		idPedido = p_idPedido;
		nombreUsuario = p_nombreUsuario;
		nombreRepartidor = p_nombreRepartidor;
		direccion = p_direccion;
		productosComprados = p_productosComprados;
		estado = p_estado; // "Pendiente", "En camino", "Entregado"
		modoEntrega = p_modoEntrega; // "Motocicleta", "Bicicleta"
		calcularCostoTotal();
	}
	~Pedido(){}


	string getIdPedido() { return idPedido; }
	string getNombreUsuario() { return nombreUsuario; }
	string getNombreRepartidor() { return nombreRepartidor; }
	string getDireccion() { return direccion; }
	Lista<Producto<string>*>* getProductosComprados() { return productosComprados; }
	string getEstado() { return estado; }
	string getModoEntrega() { return modoEntrega; }

	void setIdPedido(string p_idPedido) { idPedido=p_idPedido; }
	void setNombreUsuario(string p_nombreUsuario) { nombreUsuario = p_nombreUsuario; }
	void setNombreRepartidor(string p_nombreRepartidor) { nombreRepartidor = p_nombreRepartidor; }
	void setDireccion(string p_direccion) { direccion = p_direccion; }
	void setProductosComprados(Lista<Producto<string>*>* p_productosComprados) { productosComprados = p_productosComprados; }
	void setEstado(string p_estado) { estado = p_estado; }
	void setModoEntrega(string p_modoEntrega) { modoEntrega = p_modoEntrega; }

	void mostarInformacion(int x, int y)
	{
		Console::SetCursorPosition(x, y + 0);
		cout << "Id Pedido: " << getIdPedido();
		Console::SetCursorPosition(x, y + 1);
		cout << "Nombre de Usuario: " << getNombreUsuario();
		Console::SetCursorPosition(x, y + 2);
		cout << "Nombre de Repartidor: " << getNombreRepartidor();
		Console::SetCursorPosition(x, y + 3);
		cout << "Direccion: " << getDireccion();
		Console::SetCursorPosition(x, y + 4);
		cout << "Productos:";
		mostrarProductosComprados(x, y + 5);

		Console::SetCursorPosition(x + 30, y + 0);
		cout << "Estado: " << getEstado();
		Console::SetCursorPosition(x + 30, y + 1);
		cout << "Modo Entrega: " << getModoEntrega();
		Console::SetCursorPosition(x + 30, y + 2);
		cout << "Costo Total: " << calcularCostoTotal();
	}

	void mostrarProductosComprados(int x, int y)
	{
		for (int i = 0; i < productosComprados->longitud(); i++)
		{
			Console::SetCursorPosition(x, y + i);
			productosComprados->obtenerPos(i)->getNombre();
		}
	}

	float calcularCostoTotal()
	{
		costoTotal = 0;
		for (int i = 0; i < productosComprados->longitud(); i++)
		{
			costoTotal += stof(productosComprados->obtenerPos(i)->getPrecio());
		}
		return costoTotal;
	}
};
