#pragma once
#include <iostream>
using namespace std;

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
	T getiDReclamo() { return iDReclamo; }
	T getfecha() { return fecha; }
	T getnombre() { return nombre; }
	T gettelefono() { return telefono; }
	T getdistrito() { return distrito; }
	T getnombreProducto() { return nombreProducto; }
	T gettipo() { return tipo; }
	T getdetalle() { return detalle; }
	T getpedido() { return pedido; }

	T setiDReclamo(T _iDReclamo) { iDReclamo = _iDReclamo; }
	T setfecha(T _fecha) { fecha = _fecha; }
	T setnombre(T _nombre) { fecha = _nombre; }
	T settelefono(T _tele) { fecha = _tele; }
	T setdistrito(T _dis) { fecha = _dis; }
	T setnombreProducto(T _nombreProducto) { nombreProducto = _nombreProducto; }
	T settipo(T _tipo) { tipo = _tipo; }
	T setdetalle(T _detalle) { detalle = _detalle; }
	T setpedido(T _pedido) { pedido = _pedido; }
	//mostrar reclamo

	void mostrarReclamo() {
		cout << "ID Reclamo: " << getiDReclamo() << endl;
		cout << "Fecha: " << getfecha() << endl;
		cout << "-------------------------------------" << endl;
		cout << "informacion del usuario" << endl;
		cout << "-------------------------------------" << endl;
		cout << "Nombre: " << getnombre() << endl;
		cout << "Telefono: " << gettelefono() << endl;
		cout << "Distrito: " << getdistrito() << endl;
		cout << "-------------------------------------" << endl;
		cout << "informacion del Reclamo" << endl;
		cout << "-------------------------------------" << endl;
		cout << "Nombre del Producto: " << getnombreProducto() << endl;		
		cout << "Tipo de reclamo (R: reclamo || Q: queja): " << gettipo() << endl;
		cout << "Detalle: " << getdetalle() << endl;
		cout << "Pedido: " << getpedido() << endl;
	}

};


