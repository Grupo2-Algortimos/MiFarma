#pragma once
#include"Libreria.h"

template<class T>
class Proveedor
{
private:
	T idProveedor;
	T nombre;
	T telefono;
	T distrito;
	T producto;
public:
	Proveedor(T idProveedor, T _nombre,T _telefono,T _distrito,T _producto) {
		this->idProveedor = idProveedor;
		this->nombre = _nombre;
		this->telefono = _telefono;
		this->distrito = _distrito;
		this->producto = _producto;
	}
	//metodos getter and setter
	T getidProveedor() { return idProveedor; }
	T getnombre() { return nombre; }
	T gettelefono() { return telefono; }
	T getdistrito() { return distrito; }
	T getproducto() { return producto; }
	
	void setidProveedor(T id) { idProveedor = id; }
	void setnombre(T _nombre) { nombre = _nombre; }
	void settelefono(T tele) { telefono = tele; }
	void setdistrito(T distri) { distrito = distri; }
	void setproducto(T product) { producto = product; }
	//mostrar proveedor
	void mostrar(int x, int y) {
		Console::SetCursorPosition(x, y + 0);
		cout << "ID: " << getidProveedor();
		Console::SetCursorPosition(x, y + 1);
		cout << "Nombre: " << getnombre();
		Console::SetCursorPosition(x, y + 2);
		cout << "Telefono: " << gettelefono();
		Console::SetCursorPosition(x, y + 3);
		cout << "Distrito: " << getdistrito();
		Console::SetCursorPosition(x, y + 4);
		cout << "Producto: " << getproducto();
	}
};

