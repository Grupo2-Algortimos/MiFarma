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
		for (int i = 1; i < 6; i++)
		{
			Console::SetCursorPosition(x - 1, y + i); cout << "|";
			Console::SetCursorPosition(x + 57, y + i); cout << "|";
		}
		const int anchoContenido = 57;
		Console::SetCursorPosition(x - 1, y + 0);
		cout << "+" << string(anchoContenido, '-') << "+";
		Console::SetCursorPosition(x, y + 1);
		cout << "Id Pedido: " << getIdPedido();
		Console::SetCursorPosition(x, y + 2);
		cout << "Nombre de Usuario: " << getNombreUsuario();
		Console::SetCursorPosition(x, y + 3);
		cout << "Nombre de Repartidor: " << getNombreRepartidor();
		Console::SetCursorPosition(x, y + 4);
		cout << "Direccion: " << getDistrito();
		Console::SetCursorPosition(x - 1, y + 5);
		cout << "+" << string(anchoContenido, '-') << "+";
		Console::SetCursorPosition(x, y + 6);
		cout << "Productos:";
		mostrarProductosComprados(x, y + 7);
		Console::SetCursorPosition(x + 32, y + 1);
		cout << "Estado: " << getEstado();
		Console::SetCursorPosition(x + 32, y + 2);
		cout << "Modo Entrega: " << getModoEntrega();
		Console::SetCursorPosition(x + 32, y + 3);
		cout << "Costo Total: " << conseguirCostoTotal();
	}

	void mostrarProductosComprados(int x, int y)
	{
		Console::SetCursorPosition(x - 1, y - 1); cout << "|";
		Console::SetCursorPosition(x + 28, y - 1); cout << "|";
		for (int i = 0; i < productosComprados->longitud(); i++)
		{
			if (i > 10)
			{
				Console::SetCursorPosition(x, y + i);
				cout << "................";
				break;
			}
			Console::SetCursorPosition(x - 1, y + i ); cout << "|";
			Console::SetCursorPosition(x + 28, y + i); cout << "|";

			Console::SetCursorPosition(x, y + i);
			cout << productosComprados->obtenerPos(i)->getNombre() << " : x" << productosComprados->obtenerPos(i)->getCantidad();
		}
		if (productosComprados->longitud() > 10)
		{
			Console::SetCursorPosition(x - 1, y + 12); cout << "|";
			Console::SetCursorPosition(x + 28, y + 12); cout << "|";
			Console::SetCursorPosition(x - 1, y + 12);
			cout << "+" << string(28, '-') << "+";
		}
		else
		{
			Console::SetCursorPosition(x - 1, y + productosComprados->longitud());
			cout << "+" << string(28, '-') << "+";
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

	void escribirArchivo(ofstream &archOUT)
	{
		archOUT << "ID Pedido: " << getIdPedido() << "\n";
		archOUT << "Nombre de Usuario: " << getNombreUsuario() << "\n";
		archOUT << "Nombre de Repartidor: " << getNombreRepartidor() << "\n";
		archOUT << "Distrito: " << getDistrito() << "\n";
		archOUT << "Productos: " << "\n";
		for (int i = 0; i < getProductosComprados()->longitud(); i++)
		{
			archOUT << getProductosComprados()->obtenerPos(i)->getNombre() << " : x" << getProductosComprados()->obtenerPos(i)->getCantidad() << "\n";
		}
		archOUT << "Estado: " << getEstado() << "\n";
		archOUT << "Modo de Entrega: " << getModoEntrega() << "\n";
		archOUT << "Costo Total: " << conseguirCostoTotal() << "\n";
		archOUT << "---------------------------------------------------------" << "\n";
	}
};
