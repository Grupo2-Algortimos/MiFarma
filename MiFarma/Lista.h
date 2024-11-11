#include "Nodo.h"
#include <functional>
#include "Producto.h"

typedef unsigned int uint;
template <class T>
class Lista {
private:
    Nodo<T>* nodo;
    function<bool(string, string)> Comp;
    Nodo<T>* ini;
    uint lon; // n�mero de elementos en la lista

public:
    Lista() : ini(nullptr), lon(0) { 
        nodo = new Nodo<T>(); 
        Comp = [](string x, string _x) //Compara las coordenadas de los Puntos
            {
                if (x == _x)
                    return true;
                else
                    return false;
            }; //definimos la funcion LAMBDA
    }
    
    ~Lista();
    /*Lista() {
        nodo = new Nodo<T>();
    };*/
    Lista(Nodo<T>* pNodo) {
        nodo = pNodo;
    };
    uint longitud();
    bool esVacia();
    void agregaInicial(T elem);
    void agregaPos(T elem, uint pos);
    void agregaFinal(T elem);
    void modificarInicial(T elem);
    void modificarPos(T elem, uint pos);
    void modificarFinal(T elem);
    void eliminaInicial();
    void eliminaPos(uint pos);
    void eliminaFinal();
    T obtenerInicial();
    T obtenerPos(uint pos);
    T obtenerFinal();
    string buscarUsuario(T elem);
    string buscarPassword(T elem);
    string buscarProducto(T elem);
    void eliminarProducto(string producto);


    //~Lista(void);
    void agregar(T pNodo); //sumar nodos a la lista
    bool esvacia(void);
    T cabeza(void); //retorna el dato del primer nodo
    Lista* resto(void); //retorna el puntero al "resto" de la lista
    //resto= lo que queda de la lista sin la cabeza
    string toPrint(string p);
    T suma(T i);
    int size();
    void borrar(void); //borra la cabeza
    void borrar_last();//borra el ultimo
    void concat(Lista<T>* l1);// le transfiere los datos de l1 a this
    Lista<T>* copy(void);// hace una copia de la lista
    void tomar(int n);//deja "vivos" los n primeros nodos y borra el resto
    void addOrdenado(T d);// suma nodos ordenados de menor a mayor
    bool esta(T d); //retorna true cuando d est  en la lista
    void borrarDato(T d);// borra el nodo que contiene a d

};
template <class T>
uint Lista<T>::longitud() {
    return lon;
}
template <class T>
bool Lista<T>::esVacia() {
    return lon == 0;
}
template <class T>
void Lista<T>::agregaInicial(T elem) {
    Nodo<T>* nuevo = new Nodo<T>(elem);
    if (nuevo != nullptr) {
        ini = nuevo;
        lon++;
    }
}
template <class T>
string Lista<T>::buscarUsuario(T elem) {
    Nodo<T>* aux = ini;
    string user;
    while (aux != nullptr) {
        Empleado* oNodo = (Empleado*)(aux->elem);
        Empleado* oDato = (Empleado*)(elem);
        if (Comp(oNodo->getUser(), oDato->getUser())) {
            user = oNodo->getUser();
            return user;
        }
        aux = aux->sigte;
    }
    return "";
}

template <class T>
string Lista<T>::buscarPassword(T elem) {
    Nodo<T>* aux = ini;
    string pass;
    while (aux != nullptr) {
        Empleado* oNodo = (Empleado*)(aux->elem);
        Empleado* oDato = (Empleado*)(elem);
        if (Comp(oNodo->getPassword(), oDato->getPassword())) {
            pass = oNodo->getPassword();
            return pass;
        }
        aux = aux->sigte;
    }
    return "";
}

template <class T>
string Lista<T>::buscarProducto(T elem) {
    Nodo<T>* aux = ini;
    string pass;
    while (aux != nullptr) {
        Empleado* oNodo = (Empleado*)(aux->elem);
        Empleado* oDato = (Empleado*)(elem);
        if (Comp(oNodo->getNombre(), oDato->getNombre())) {
            pass = oNodo->getNombre();
            return pass;
        }
        aux = aux->sigte;
    }
    return "";
}

template<class T>
void Lista<T>::eliminarProducto(string producto) {
    Nodo<T>* actual = ini;
    Nodo<T>* anterior = nullptr;

    while (actual != nullptr) {
        Producto<string>* producto_actual = dynamic_cast<Producto<string>*>(actual->elem);

        // Comparar el nombre del producto
        if (producto_actual != nullptr && Comp(producto_actual->getNombre(), producto)) {
            if (anterior == nullptr) {
                // Si el producto a eliminar est� en el primer nodo
                ini = actual->sigte;
            }
            else {
                // Saltar el nodo actual ajustando el puntero del anterior
                anterior->sigte = actual->sigte;
            }

            // Liberar el nodo y su elemento
            delete actual->elem;
            delete actual;

            // Disminuir el contador de longitud de la lista
            lon--;          

            break;
        }

        // Avanzar al siguiente nodo
        anterior = actual;
        actual = actual->sigte;
    }
   
}



template <class T>
void Lista<T>::agregaPos(T elem, uint pos) {
    if (pos > lon) return;
    if (pos == 0) {
        agregaInicial(elem);
    }
    else {
        Nodo<T>* aux = ini;
        for (int i = 1; i < pos; i++) {
            aux = aux->get_Sgte();
        }
        Nodo<T>* nuevo = new Nodo<T>(elem);
        nuevo->set_Sgte(aux->get_Sgte());
        if (nuevo != nullptr) {

            aux->set_Sgte(nuevo);
            lon++;
        }
    }
}
template <class T>
void Lista<T>::agregaFinal(T elem) {
    agregaPos(elem, lon); // ;)s
}

template <class T>
void Lista<T>::eliminaInicial() {
    if (lon > 0) {
        Nodo<T>* aux = ini;
        ini = ini->sgte;
        delete aux;
        lon--;
    }
}

template <class T>
void Lista<T>::eliminaPos(uint pos) {
    if (pos >= size)return;
    if (pos == 0) {
        eliminaInicial();
    }
    else if (pos >= 1 && pos < size) {
        Nodo<T>* aux = ini;
        Nodo<T>* nodo_remove;
        for (int i = 1; i < pos; i++)
        {
            aux = aux->sgte;
        }
        nodo_remove = aux->sgte;
        aux->sgte = nodo_remove->sgte;
        if (nodo_remove->sgte != nullptr)
            nodo_remove->sgte = aux;

        delete nodo_remove;
        size--;
    }

}
template <class T>
void Lista<T>::eliminaFinal() {
}

template <class T>
void Lista<T>::modificarInicial(T elem) {
    if (lon > 0) {
        ini->elem = elem;
    }
}

template <class T>
void Lista<T>::modificarPos(T elem, uint pos) {
    if (pos >= 0 && pos < lon) {
        Nodo<T>* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->sigte;
        }
        aux->elem = elem;
    }
}
template <class T>
void Lista<T>::modificarFinal(T elem) {
    modificar(elem, lon - 1);
}

template <class T>
T Lista<T>::obtenerInicial() {
    return obtenerPos(0);
}


template <class T>
T Lista<T>::obtenerPos(uint pos) {
    if (pos >= 0 && pos < lon) {
        Nodo<T>* aux = ini;
        for (int i = 0; i < pos; i++) {
            aux = aux->get_Sgte();
        }
        return aux->get_Elem();
    }
    else {
        return NULL;
    }
}
template <class T>
T Lista<T>::obtenerFinal() {
    return obtenerPos(lon - 1);
}

template <class T>
void Lista<T>::agregar(T d) //100
{
    Nodo<T>* nuevo = new Nodo<T>(d);
    nuevo->set_Sgte(nodo);
    nodo = nuevo;
}




