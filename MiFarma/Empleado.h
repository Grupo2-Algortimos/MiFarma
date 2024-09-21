#pragma once
#include "Entidad.h"

class Empleado : public Entidad 
{
private:
    string idTrabajador;
    string puesto;

public:
    // Constructor
    Empleado():Entidad()
    {
        this->idTrabajador = "";
        this->puesto = "";
    }
    Empleado(string p_user, string p_password, string p_nombre, string p_apellido, string p_telefono,
        string p_sexo, string p_distrito, string p_idTrabajador, string p_puesto)
        : Entidad(p_user, p_password, p_nombre, p_apellido, p_telefono, p_sexo, p_distrito)
    {
        this->idTrabajador = p_idTrabajador;
        this->puesto = p_puesto;
    }

    // Métodos getter y setter para `Empleado`
    string getIdTrabajador() { return idTrabajador; }
    string getPuesto() { return puesto; }

    void setIdTrabajador(string p_idTrabajador) { idTrabajador = p_idTrabajador; }
    void setPuesto(string p_puesto) { puesto = p_puesto; }

    //mostrar el empleado
    void mostrarEmpleado() {
        cout << "ID Trabajador: " << getIdTrabajador() << endl;
        cout << "Puesto: " << getPuesto() << endl;
        cout << "Nombre: " << getNombre() << endl;
        cout << "Apellido: " << getApellido() << endl;
        cout << "Teléfono: " << getTelefono() << endl;
        cout << "Sexo: " << getSexo() << endl;
        cout << "Distrito: " << getDistrito() << endl;
    }
};

