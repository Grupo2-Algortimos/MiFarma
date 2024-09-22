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
	}
};

