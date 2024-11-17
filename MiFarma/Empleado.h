#pragma once
#include"Entidad.h"

template<class T>
class Empleado : public Entidad<T>
{
private:
    T idTrabajador;
    T puesto;

public:
    // Constructor
    Empleado():Entidad()
    {
        this->idTrabajador = "";
        this->puesto = "";
    }
    Empleado(T p_user, T p_password, T p_nombre, T p_apellido, T p_telefono,
        T p_sexo, T p_distrito, T p_idTrabajador, T p_puesto)
        : Entidad(p_user, p_password, p_nombre, p_apellido, p_telefono, p_sexo, p_distrito)
    {
        this->idTrabajador = p_idTrabajador;
        this->puesto = p_puesto;
    }

    // Métodos getter y setter para `Empleado`
    T getIdTrabajador() { return idTrabajador; }
    T getPuesto() { return puesto; }

    void setIdTrabajador(T p_idTrabajador) { idTrabajador = p_idTrabajador; }
    void setPuesto(T p_puesto) { puesto = p_puesto; }

    //Mostrar en consola
    void mostrarEmpleado() {
        cout << "ID Trabajador: " << getIdTrabajador() << endl; // 2 -> O(1)
        cout << "Puesto: " << getPuesto() << endl; // 2 -> O(1)
        cout << "Nombre: " << getNombre() << endl; // 2 -> O(1)
        cout << "Apellido: " << getApellido() << endl; // 2 -> O(1)
        cout << "Teléfono: " << getTelefono() << endl; // 2 -> O(1)
        cout << "Sexo: " << getSexo() << endl; // 2 -> O(1)
        cout << "Distrito: " << getDistrito() << endl; // 2 -> O(1)
    }
    // Tiempo detallado: 14
    // Tiempo asintótico: O(1)


    void escribirArchivo(ofstream &archOUT)
    {
        archOUT << "ID Trabajador: " << getIdTrabajador() << "\n";
		archOUT << "Puesto: " << getPuesto() << "\n";
		archOUT << "Nombre: " << getNombre() << "\n";
		archOUT << "Apellido: " << getApellido() << "\n";
		archOUT << "Teléfono: " << getTelefono() << "\n";
		archOUT << "Sexo: " << getSexo() << "\n";
		archOUT << "Distrito: " << getDistrito() << "\n";
		archOUT << "Nombre de usuario: " << getUser() << "\n";
		archOUT << "Contraseña: " << getPassword() << "\n";
		archOUT << "-------------------------------------------\n";
    }
};

