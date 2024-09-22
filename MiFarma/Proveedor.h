#pragma once
#include"Libreria.h"

class Proveedor
{
private:
	string nombre;
	string telefono;
	string distrito;
	string producto;
public:
	Proveedor(string _nombre,string _telefono,string _distrito,string _producto) {
		this->nombre = _nombre;
		this->telefono = _telefono;
		this->distrito = _distrito;
		this->producto = _producto;
	}
	//metodos getter and setter
	string getnombre() { return nombre; }
	string gettelefono() { return telefono; }
	string getdistrito() { return distrito; }
	string getproducto() { return producto; }
	
	void setnombre(string _nombre) { nombre = _nombre; }
	void settelefono(string tele) { telefono = tele; }
	void setdistrito(string distri) { distrito = distri; }
	void setproducto(string product) { producto = product; }
	//mostrar proveedor
	void mostrar(int x, int y) {
		Console::SetCursorPosition(x, y + 0);
		cout << "Nombre del Proveedor: " << getnombre();
		Console::SetCursorPosition(x, y + 1);
		cout << "Telefono: " << gettelefono();
		Console::SetCursorPosition(x, y + 2);
		cout << "Distrito: " << getdistrito();
		Console::SetCursorPosition(x, y + 3);
		cout << "Producto: " << getproducto();
	}
};

