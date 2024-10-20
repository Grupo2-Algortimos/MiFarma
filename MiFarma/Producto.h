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
	T cantidad;
	T fechaCad;
	T cantPrecio;

public:
	Producto() {
		this->idProduct = "";
		this->nombre = "";
		this->precio = "";
		this->categoria = "";
		this->cantidad = "";
		this->fechaCad = "";
	}

	Producto(T _idProduct,T _nombre,T _precio,T _categoria, T _cantidad,T _fechaCad) {
		this->idProduct = _idProduct;
		this->nombre = _nombre;
		this->precio = _precio;
		this->categoria = _categoria;
		this->cantidad = _cantidad;
		this->fechaCad = _fechaCad;
	}
	//metodos detter and setter
	T getIdProduct() { return idProduct; }
	T getNombre() { return nombre; }
	T getPrecio() { return precio; }
	T getCategoria() { return categoria; }
	T getCantidad() { return cantidad; }
	T getFechaCad() { return fechaCad; }
	T getcantProducto() { return cantPrecio; }

	
	void setIdProduct(T _idProduct) { idProduct = _idProduct; }
	void setNombre(T _nombre) { nombre = _nombre; }
	void setPrecio(T _precio) { precio = _precio; }
	void setCategoria(T _categoria) { categoria = _categoria; }
	void setCantidad(T _cantidad) { cantidad = _cantidad; }
	void setFechaCad(T _fechaCad) { fechaCad = _fechaCad; }
	void setcantProducto(T _cantPrecio) { cantPrecio = _cantPrecio; }
	
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
		cout << "Cantidad: " << getCantidad();
		Console::SetCursorPosition(x, y + 5);
		cout << "Fecha de vencimiento: " << getFechaCad();		
	}
};