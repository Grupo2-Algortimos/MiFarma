#pragma once
#include"Libreria.h"

template<class T>
class Producto
{
protected:
	T idProduct;
	T nombre;
	T precio;
	T categoria;
	T volumen;
	T cantidad;
	T fechaCad;

public:
	Producto() {
		this->idProduct = "";
		this->nombre = "";
		this->precio = "";
		this->categoria = "";
		this->volumen = "";
		this->cantidad = "1";
		this->fechaCad = "";
	}

	Producto(T _idProduct,T _nombre,T _precio,T _categoria, T _volumen,T _fechaCad) {
		this->idProduct = _idProduct;
		this->nombre = _nombre;
		this->precio = _precio;
		this->categoria = _categoria;
		this->volumen = _volumen;
		this->fechaCad = _fechaCad;
		this->cantidad = "1";
	}
	//metodos detter and setter
	T getIdProduct() { return idProduct; }
	T getNombre() { return nombre; }
	T getPrecio() { return precio; }
	T getCategoria() { return categoria; }
	T getVolumen() { return volumen; }
	T getCantidad() { return cantidad; }
	T getFechaCad() { return fechaCad; }
	double getSubTotal() { return (stod(precio) * stod(cantidad)); }

	
	void setIdProduct(T _idProduct) { idProduct = _idProduct; }
	void setNombre(T _nombre) { nombre = _nombre; }
	void setPrecio(T _precio) { precio = _precio; }
	void setCategoria(T _categoria) { categoria = _categoria; }
	void setVolumen(T _volumen) { volumen = _volumen; }
	void setCantidad(T _cantidad) { cantidad = _cantidad; }
	void setFechaCad(T _fechaCad) { fechaCad = _fechaCad; }
	
	//mostrar el Producto
	void mostrarProducto(int x, int y) {
		Console::SetCursorPosition(x, y + 0);
		cout << "ID Producto: " << getIdProduct();
		Console::SetCursorPosition(x, y + 1);
		cout << "Nombre: " << getNombre();
		Console::SetCursorPosition(x, y + 2);
		cout << "Precio: S/" << getPrecio();
		Console::SetCursorPosition(x, y + 3);
		cout << "Categoria: " << getCategoria();
		Console::SetCursorPosition(x, y + 4);
		cout << "Volumen: " << getVolumen();
		Console::SetCursorPosition(x, y + 5);
		cout << "Fecha de vencimiento: " << getFechaCad();		
	}

	void escribirArchivo(ofstream &archOUT)
	{
		archOUT << "ID Prdocuto: " << getIdProduct() << "\n";
		archOUT << "Nombre: " << getNombre() << "\n";
		archOUT << "Precio: S/." << getPrecio() << "\n";
		archOUT << "Categoria: " << getCategoria() << "\n";
		archOUT << "Volumen: " << getVolumen() << "\n";
		archOUT << "Fecha de vencimiento: " << getFechaCad() << "\n";
		archOUT << "------------------------------------------------" << "\n";
	}

};