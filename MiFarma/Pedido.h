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
	string distrito;
	Lista<Producto<string>*>* productosComprados;
	string estado; // "Pendiente", "En camino", "Entregado"
	string modoEntrega; // "Motocicleta", "Bicicleta"

public:
	Pedido(string p_idPedido, string p_nombreUsuario, string p_nombreRepartidor, string p_distrito, Lista<Producto<string>*>* p_productosComprados,
		string p_estado, string p_modoEntrega){
		this->idPedido = p_idPedido;
		this->nombreUsuario = p_nombreUsuario;
		this->nombreRepartidor = p_nombreRepartidor;
		this->distrito = p_distrito;
		this->productosComprados = p_productosComprados;
		this->estado = p_estado; // "Pendiente", "En camino", "Entregado"
		this->modoEntrega = p_modoEntrega; // "Motocicleta", "Bicicleta"
	}
	~Pedido(){}


	string getIdPedido() { return this->idPedido; }
	string getNombreUsuario() { return this->nombreUsuario; }
	string getNombreRepartidor() { return this->nombreRepartidor; }
	string getDistrito() { return distrito; }
	Lista<Producto<string>*>* getProductosComprados() { return this->productosComprados; }
	string getEstado() { return this->estado; }
	string getModoEntrega() { return this->modoEntrega; }

	void setIdPedido(string p_idPedido) { this->idPedido = p_idPedido; }
	void setNombreUsuario(string p_nombreUsuario) { this->nombreUsuario = p_nombreUsuario; }
	void setNombreRepartidor(string p_nombreRepartidor) { this->nombreRepartidor = p_nombreRepartidor; }
	void setDistrito(string p_distrito) { this->distrito = p_distrito; }
	void setProductosComprados(Lista<Producto<string>*>* p_productosComprados) { this->productosComprados = p_productosComprados; }
	void setEstado(string p_estado) { this->estado = p_estado; }
	void setModoEntrega(string p_modoEntrega) { this->modoEntrega = p_modoEntrega; }

	void mostarInformacion(int x, int y)
	{
		Console::SetCursorPosition(x, y + 0);
		cout << "Id Pedido: " << getIdPedido();
		Console::SetCursorPosition(x, y + 1);
		cout << "Nombre de Usuario: " << getNombreUsuario();
		Console::SetCursorPosition(x, y + 2);
		cout << "Nombre de Repartidor: " << getNombreRepartidor();
		Console::SetCursorPosition(x, y + 3);
		cout << "Direccion: " << getDistrito();
		Console::SetCursorPosition(x, y + 4);
		cout << "Productos:";
		mostrarProductosComprados(x, y + 5);

		Console::SetCursorPosition(x + 30, y + 0);
		cout << "Estado: " << getEstado();
		Console::SetCursorPosition(x + 30, y + 1);
		cout << "Modo Entrega: " << getModoEntrega();
		Console::SetCursorPosition(x + 30, y + 2);
		cout << "Costo Total: " << conseguirCostoTotal();
	}

	void mostrarProductosComprados(int x, int y)
	{
		for (int i = 0; i < productosComprados->longitud(); i++)
		{
			Console::SetCursorPosition(x, y + i);
			cout << productosComprados->obtenerPos(i)->getNombre();
		}
	}
	double conseguirCostoTotal()
	{
		//Función lambda que retorna la suma de los precios del carrito para calcular el total
		auto obtenerSumaTotal = [](Lista<Producto<string>*>* productosComprados) {

			double suma = 0;
			for (int i = 0; i < productosComprados->longitud(); i++)
			{
				suma += stod(productosComprados->obtenerPos(i)->getPrecio()) * stod(productosComprados->obtenerPos(i)->getCantidad());
			}
			return suma;
		};
		return obtenerSumaTotal(getProductosComprados());
	}
};
