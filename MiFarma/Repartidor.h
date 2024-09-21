#pragma once
#include"Entidad.h"
//#include"Pedido.h"
#include"Usuario.h"
class Repartidor:public Entidad
{
private:
	string idRepartidor;
	Usuario* usuario;
	//Pedido* pedido;

public:
	Repartidor():Entidad()
	{
		this->idRepartidor = " ";
		this->usuario = NULL;
		//this->pedido = NULL;
	}

	Repartidor(string p_user, string p_password, string p_nombre, string p_apellido, string p_telefono,
		string p_sexo, string p_distrito, string p_idRepartidor, Usuario* p_usuario)
		: Entidad(p_user, p_password, p_nombre, p_apellido, p_telefono, p_sexo, p_distrito)
	{
		this->idRepartidor = p_idRepartidor;
		this->usuario = p_usuario;
		//this->pedido = NULL;
	}
	~Repartidor(){}

	string getIdRepartidor() { return this->idRepartidor; }
	Usuario* getUsuario() { return this->usuario; }
	//Pedido* getPedido() { return this->pedido; }

	void setIdRepartidor(string p_idRepartidor) { this->idRepartidor = p_idRepartidor; }
	void setUsuario(Usuario* p_usuario) { this->usuario = p_usuario; }
	//void setPedido(Pedido* p_pedido) { this->pedido = p_pedido; }

	//mostrar Repartidor
	void mostrarEmpleado() {
		cout << "ID Trabajador: " << getIdRepartidor() << endl;
		cout << "Usuario a entregar pedido: " << getUsuario()->getNombre() << endl;
		//cout << "Pedido a entregar: " << getPedido()->getNumero() << endl;
		cout << "Nombre: " << getNombre() << endl;
		cout << "Apellido: " << getApellido() << endl;
		cout << "Teléfono: " << getTelefono() << endl;
		cout << "Sexo: " << getSexo() << endl;
		cout << "Distrito: " << getDistrito() << endl;
	}
};
