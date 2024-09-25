#pragma once
#include"Libreria.h"

template<class T>
class Boleta
{
private:
	T idBoleta;
	T nombre;
	T fecha;
	T montoUsuario;
	T costoPedido;
public:
	Boleta(T _idBoleta, T _nombre, T _fecha, T _montoUsuario, T _costoPedido) {
		this->idBoleta = _idBoleta;
		this->nombre = _nombre;
		this->fecha = _fecha;
		this->montoUsuario = _montoUsuario;
		this->costoPedido = _costoPedido;
	}
	//metodos getter and setter
	T getIdBoleta() { return idBoleta; }
	T getNombre() { return nombre; }
	T getFecha() { return fecha; }
	T getMontoUsuario() { return montoUsuario; }
	T getCostoPedido() { return costoPedido; }

	void setIdBoleta(T _idBoleta) { idBoleta = _idBoleta; }
	void setNombre(T _nombre) { nombre = _nombre; }
	void setFecha(T _fecha) { fecha = _fecha; }
	void setMontoUsuario(T _montoUsuario) { montoUsuario = _montoUsuario; }
	void setCostoPedido(T _costoPedido) { costoPedido = _costoPedido; }

	void mostrarInformacion(int x, int y)
	{
		Console::SetCursorPosition(x, y + 0);
		cout << "ID de Boleta: " << getIdBoleta();
		Console::SetCursorPosition(x, y + 1);
		cout << "Nombre del comprador: " << getNombre();
		Console::SetCursorPosition(x, y + 2);
		cout << "Fecha de la Boleta: " << getFecha();
		Console::SetCursorPosition(x, y + 3);
		cout << "Monto de la compra: " << getMontoUsuario();
		Console::SetCursorPosition(x, y + 4);
		cout << "Vuelto para el usuario: " << getVuelto();
	}

	double getVuelto()
	{
		auto obtenerVuelto = [](T montoUsuario, T costoPedido)
		{
				return (stod(montoUsuario) - stod(costoPedido));
		};
		return obtenerVuelto(getMontoUsuario(), getCostoPedido());
	}
};

