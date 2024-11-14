#pragma once
#include "Entidad.h"

template<class T1, class T2>
class Usuario : public Entidad<string>
{
private:
	T1 dinero;
	T2 edad;
public:
	//constructor
	Usuario() :Entidad()
	{
		this->dinero = 0;
	}
	Usuario(string p_user, string p_password, string p_nombre, string p_apellido, string p_telefono,
		string p_sexo, string p_distrito, T1 p_dinero, T2 p_edad):	Entidad(p_user, p_password, p_nombre, p_apellido, p_telefono, p_sexo, p_distrito){
		
		this->dinero = p_dinero;
		this->edad = p_edad;
	}
	//metodo getter y setter
	T1 getDinero() { return dinero; }
	T2 getEdad() { return edad; }

	void setDinero(T1 p_dinero) { dinero = p_dinero; }
	void setEdad(T2 p_edad) { edad = p_edad; }
	//Mostrar en consola
	void mostrar(int x, int y) {		
		Console::SetCursorPosition(x, y + 0);
		cout << "Nombre: " << getNombre();
		Console::SetCursorPosition(x, y + 1);
		cout << "Apellido: " << getApellido();
		Console::SetCursorPosition(x, y + 2);
		cout << "Teléfono: " << getTelefono();
		Console::SetCursorPosition(x, y + 3);
		cout << "Sexo: " << getSexo();
		Console::SetCursorPosition(x, y + 4);
		cout << "Distrito: " << getDistrito();
		Console::SetCursorPosition(x, y + 5);
		cout << "Dinero: " << getDinero();
		Console::SetCursorPosition(x, y + 6);
		cout << "Edad: " << getDinero();
	}

	bool operator==( Usuario& other)  {
		return (getNombre() == other.getNombre() && getApellido() == other.getApellido());
	}
};

