#pragma once
#include"Libreria.h"

template<class T>
class Boleta
{
private:
	T nombre;
	T fecha;
	T monto;
public:
	Boleta(T _nombre, T _fecha, T _monto) {
		this->nombre = _nombre;
		this->fecha = _fecha;
		this->monto = _monto;
	}
	//metodos getter and setter
	T getnombre() { return nombre; }
	T getfecha() { return fecha; }
	T getmonto() { return monto; }

	void setnombre(T _nombre) { nombre = _nombre; }
	void setfecha(T _fecha) { fecha = _fecha; }
	void setmonto(T _monto) { monto = _monto; }


};

