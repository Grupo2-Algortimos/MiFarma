#pragma once
#include <iostream>
using namespace std;

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
	void mostrar() {
		cout << "Nombre del Proveedor: " << getnombre() << endl;
		cout << "Telefono: " << gettelefono() << endl;
		cout << "Distrito: " << getdistrito() << endl;
		cout << "Producto: " << getproducto() << endl;
	}
};

