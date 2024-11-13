#pragma once
#include"Libreria.h"
template<class T>
class Entidad
{
protected:
	T user;
	T password;
	T nombre;
	T apellido;
	T telefono;
	T sexo;
	T distrito;
public:
	Entidad() {
		this->user = "";
		this->password = "";
		this->nombre = "";
		this->apellido = "";
		this->telefono = "";
		this->sexo = "";
		this->distrito = "";
	}
	Entidad(T puser,T ppassword,T pnombre,T papellido,
	T ptelefono,T psexo,T pdistrito) {
		this->user = puser;
		this->password = ppassword;
		this->nombre = pnombre;
		this->apellido = papellido;
		this->telefono = ptelefono;
		this->sexo = psexo;
		this->distrito = pdistrito;
	}
	Entidad(T pnombre, T papellido,
		T ptelefono, T pdistrito) {
		this->nombre = pnombre;
		this->apellido = papellido;
		this->telefono = ptelefono;	
		this->distrito = pdistrito;
	}
	
	//metodos getter y setter
	T getUser() { return user; }
	T getPassword(){ return password; }
	T getNombre(){ return nombre; }
	T getApellido(){ return apellido; }
	T getTelefono(){ return telefono; }
	T getSexo(){ return sexo; }
	T getDistrito(){ return distrito; }

	void setUser(T puser) { user = puser; }
	void setPassword(T ppassword) { password = ppassword; }
	void setNombre(T pnombre) { nombre = pnombre; }
	void setApellido(T papellido) { apellido = papellido; }
	void setTelefono(T ptelefono) { telefono = ptelefono; }
	void setSexo(T psexo) { sexo = psexo; }
	void setDistrito(T pdistrito) { distrito = pdistrito; }

};
