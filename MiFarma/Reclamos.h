#pragma once
#include"Libreria.h"

template<class T>
class Reclamo
{
private:
	T iDReclamo;
	T fecha;
	T nombre;
	T telefono;
	T distrito;
	T nombreProducto;
	T tipo;
	T detalle;
	T pedido;
public:
	Reclamo()
	{
		this->iDReclamo = " ";
		this->fecha = " ";
		this->nombre = " ";
		this->telefono = " ";
		this->distrito = " ";
		this->nombreProducto = " ";
		this->tipo = " ";
		this->detalle = " ";
		this->pedido = " ";
	}
	Reclamo(T _idReclamo, T _fecha, T _nombre, T _telefono, T _distrito, T _nombreProducto, T _tipo, T _detalle, T _pedido)
	{
		this->iDReclamo = _idReclamo;
		this->fecha = _fecha;
		this->nombre = _nombre;
		this->telefono = _telefono;
		this->distrito = _distrito;
		this->nombreProducto = _nombreProducto;
		this->tipo = _tipo;
		this->detalle = _detalle;
		this->pedido = _pedido;
	}
	// metodos getter and setter
	T getIdReclamo() { return iDReclamo; }
	T getFecha() { return fecha; }
	T getNombre() { return nombre; }
	T getTelefono() { return telefono; }
	T getDistrito() { return distrito; }
	T getNombreProducto() { return nombreProducto; }
	T getTipo() { return tipo; }
	T getDetalle() { return detalle; }
	T getPedido() { return pedido; }

	T setIdReclamo(T _iDReclamo) { iDReclamo = _iDReclamo; }
	T setFecha(T _fecha) { fecha = _fecha; }
	T setNombre(T _nombre) { fecha = _nombre; }
	T setTelefono(T _tele) { fecha = _tele; }
	T setDistrito(T _dis) { fecha = _dis; }
	T setNombreProducto(T _nombreProducto) { nombreProducto = _nombreProducto; }
	T setTipo(T _tipo) { tipo = _tipo; }
	T setDetalle(T _detalle) { detalle = _detalle; }
	T setPedido(T _pedido) { pedido = _pedido; }
	//mostrar reclamo

	void mostrarReclamo(int x, int y) {
		Console::SetCursorPosition(x, y + 0);
		cout << "ID Reclamo: " << getIdReclamo();
		Console::SetCursorPosition(x, y + 1);
		cout << "Fecha: " << getFecha();
		Console::SetCursorPosition(x, y + 2);
		cout << "Informacion del usuario";
		Console::SetCursorPosition(x, y + 3);
		cout << "-------------------------------------" << endl;
		Console::SetCursorPosition(x, y + 4);
		cout << "Nombre: " << getNombre();
		Console::SetCursorPosition(x, y + 5);
		cout << "Telefono: " << getTelefono();
		Console::SetCursorPosition(x, y + 6);
		cout << "Distrito: " << getDistrito();
		Console::SetCursorPosition(x, y + 7);
		cout << "-------------------------------------";
		Console::SetCursorPosition(x, y + 8);
		cout << "informacion del Reclamo";
		Console::SetCursorPosition(x, y + 9);
		cout << "-------------------------------------";
		Console::SetCursorPosition(x, y + 10);
		cout << "Nombre del Producto: " << getNombreProducto();
		Console::SetCursorPosition(x, y + 11);
		cout << "Tipo de reclamo (R: reclamo || Q: queja): " << getTipo();
		Console::SetCursorPosition(x, y + 12);
		cout << "Detalle: " << getDetalle();
		Console::SetCursorPosition(x, y + 13);
		cout << "Pedido: " << getPedido();
	}

};


