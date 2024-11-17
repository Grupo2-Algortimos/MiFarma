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
		const int anchoContenido = 36;
		Console::SetCursorPosition(x, y + 0);
		cout << "+" << string(anchoContenido, '-') << "+";
		Console::SetCursorPosition(x, y + 1);
		cout << "| " << ajustarTexto("***           BOLETA           ***", anchoContenido - 2) << " |";
		Console::SetCursorPosition(x, y + 2);
		cout << "+" << string(anchoContenido, '-') << "+";
		Console::SetCursorPosition(x, y + 3);
		cout << "| " << ajustarTexto("ID de Boleta: " + getIdBoleta(), anchoContenido - 2) << " |";
		Console::SetCursorPosition(x, y + 4);
		cout << "| " << ajustarTexto("Nombre del comprador: " + getNombre(), anchoContenido - 2) << " |";
		Console::SetCursorPosition(x, y + 5);
		cout << "| " << ajustarTexto("Fecha de la Boleta: " + getFecha(), anchoContenido - 2) << " |";
		Console::SetCursorPosition(x, y + 6);
		cout << "| " << ajustarTexto("Costo de la compra: S/. " + getCostoPedido(), anchoContenido - 2) << " |";
		Console::SetCursorPosition(x, y + 7);
		cout << "| " << ajustarTexto("Vuelto para el usuario: S/. " + to_string(getVuelto()), anchoContenido - 2) << " |";
		Console::SetCursorPosition(x, y + 8);
		cout << "+" << string(anchoContenido, '-') << "+";
	}

	double getVuelto()
	{
		auto obtenerVuelto = [](T montoUsuario, T costoPedido)
		{
				return (stod(montoUsuario) - stod(costoPedido)); // 4 --> O(1)
		};
		return obtenerVuelto(getMontoUsuario(), getCostoPedido()); // 3 --> O(1)

		// Tiempo detallado: 7
		// Tiempo asintótico: O(1)
	}
};

