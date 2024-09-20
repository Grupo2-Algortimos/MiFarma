#pragma once
#include <iostream>
using namespace std;

template<class T>
class Producto
{
protected:
	T idProduct;
	T nombre;
	T precio;
	T cantidad;
	T fechaCad;

public:
	Producto(T _idProduct,T _nombre,T _precio,T _cantidad,T _fechaCad) {
		this->idProduct = _idProduct;
		this->nombre = _nombre;
		this->precio = _precio;
		this->cantidad = _cantidad;
		this->fechaCad = _fechaCad;
	}
	//metodos detter and setter
	T getIdProduct() { return idProduct; }
	T getNombre() { return nombre; }
	T getPrecio() { return precio; }
	T getCantidad() { return cantidad; }
	T getFechaCad() { return fechaCad; }

	void setIdProduct(T _idProduct) { idProduct = _idProduct; }
	void setNombre(T _nombre)    { nombre = _nombre; }
	void setPrecio(T _precio)    { precio = _precio; }
	void setCantidad(T _cantidad)  { cantidad = _cantidad; }
	void setFechaCad(T _fechaCad)  { fechaCad = _fechaCad; }
	
	//mostrar el Producto
	void mostrarProducto() {
		cout << "ID Producto: " << getIdProduct() << endl;
		cout << "Nombre: " << getNombre() << endl;
		cout << "Precio: S/" << getPrecio() << endl;
		cout << "Cantidad: " << getCantidad() << endl;
		cout << "Fecha de vencimiento: " << getFechaCad() << endl;		
	}
};





