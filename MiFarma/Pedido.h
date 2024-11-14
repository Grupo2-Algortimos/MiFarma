#pragma once
#include"Libreria.h"
#include"Lista.h"
#include"Producto.h"

template<class T>
class Pedido
{
private:
	T idPedido;
	T nombreUsuario;
	T nombreRepartidor;
	T distrito;
	Lista<Producto<T>*>* productosComprados;
	T estado; // "Pendiente", "En camino", "Entregado"
	T modoEntrega; // "Motocicleta", "Bicicleta"

public:
	Pedido(T p_idPedido, T p_nombreUsuario, T p_nombreRepartidor, T p_distrito, Lista<Producto<T>*>* p_productosComprados,
		T p_estado, T p_modoEntrega){
		this->idPedido = p_idPedido;
		this->nombreUsuario = p_nombreUsuario;
		this->nombreRepartidor = p_nombreRepartidor;
		this->distrito = p_distrito;
		this->productosComprados = p_productosComprados;
		this->estado = p_estado; // "Pendiente", "En camino", "Entregado"
		this->modoEntrega = p_modoEntrega; // "Motocicleta", "Bicicleta"
	}
	~Pedido(){}


	T getIdPedido() { return this->idPedido; }
	T getNombreUsuario() { return this->nombreUsuario; }
	T getNombreRepartidor() { return this->nombreRepartidor; }
	T getDistrito() { return distrito; }
	Lista<Producto<T>*>* getProductosComprados() { return this->productosComprados; }
	T getEstado() { return this->estado; }
	T getModoEntrega() { return this->modoEntrega; }

	void setIdPedido(T p_idPedido) { this->idPedido = p_idPedido; }
	void setNombreUsuario(T p_nombreUsuario) { this->nombreUsuario = p_nombreUsuario; }
	void setNombreRepartidor(T p_nombreRepartidor) { this->nombreRepartidor = p_nombreRepartidor; }
	void setDistrito(T p_distrito) { this->distrito = p_distrito; }
	void setProductosComprados(Lista<Producto<T>*>* p_productosComprados) { this->productosComprados = p_productosComprados; }
	void setEstado(T p_estado) { this->estado = p_estado; }
	void setModoEntrega(T p_modoEntrega) { this->modoEntrega = p_modoEntrega; }

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
		auto obtenerSumaTotal = [](Lista<Producto<T>*>* productosComprados) {

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
