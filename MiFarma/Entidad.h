#pragma once
#include <iostream>
using namespace std;

class Entidad
{
protected:
	string user;
	string password;
	string nombre;
	string apellido;
	string telefono;
	string sexo;
	string distrito;
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
	Entidad(string puser,string ppassword,string pnombre,string papellido,
	string ptelefono,string psexo,string pdistrito) {
		this->user = puser;
		this->password = ppassword;
		this->nombre = pnombre;
		this->apellido = papellido;
		this->telefono = ptelefono;
		this->sexo = psexo;
		this->distrito = pdistrito;
	}
	Entidad(string pnombre, string papellido,
		string ptelefono, string pdistrito) {
		this->nombre = pnombre;
		this->apellido = papellido;
		this->telefono = ptelefono;	
		this->distrito = pdistrito;
	}
	
	//metodos getter y setter
	string    getUser() { return user; }
	string getPassword(){ return password; }
	string getNombre(){ return nombre; }
	string getApellido(){ return apellido; }
	string getTelefono(){ return telefono; }
	string getSexo(){ return sexo; }
	string getDistrito(){ return distrito; }

	void setUser(string puser) { user = puser; }
	void setPassword(string ppassword) { password = ppassword; }
	void setNombre(string pnombre) { nombre = pnombre; }
	void setApellido(string papellido) { apellido = papellido; }
	void setTelefono(string ptelefono) { telefono = ptelefono; }
	void setSexo(string psexo) { sexo = psexo; }
	void setDistrito(string pdistrito) { distrito = pdistrito; }

};
