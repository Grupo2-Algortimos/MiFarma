#pragma once
#include "Entidad.h"

class Usuario : public Entidad
{
private:
	int dinero;
public:
	//constructor
	Usuario() :Entidad()
	{
		this->dinero = 0;
	}
	Usuario(string p_user, string p_password, string p_nombre, string p_apellido, string p_telefono,
		string p_sexo, string p_distrito,int p_dinero):	Entidad(p_user, p_password, p_nombre, p_apellido, p_telefono, p_sexo, p_distrito){
		
		this->dinero = p_dinero;
	}
	//metodo getter y setter
	int getDinero() { return dinero; }
	void setDinero(int p_dinero) { dinero = p_dinero; }
	//mostrar
	void mostrar() {		
		cout << "Nombre: " << getNombre() << endl;
		cout << "Apellido: " << getApellido() << endl;
		cout << "Teléfono: " << getTelefono() << endl;
		cout << "Sexo: " << getSexo() << endl;
		cout << "Distrito: " << getDistrito() << endl;
		cout << "Dinero: " << getDinero() << endl;
	}
};

