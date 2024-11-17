#include "Nodo.h"

typedef unsigned int uint;
template <class T>
class Lista {
private:
    Nodo<T>* nodo;
    function<bool(string, string)> Comp;
    Nodo<T>* ini;
    uint lon; // número de elementos en la lista

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
    
    ~Lista()
    {
        eliminaTodo();
    }

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
    void eliminaTodo();
    T obtenerInicial();
    T obtenerPos(uint pos);
    T obtenerFinal();
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
		ini = ini->sigte;
		delete aux;
		lon--; // Decrement the member variable 'lon' instead of calling 'size'
	}
}

template <class T>
void Lista<T>::eliminaPos(uint pos) {
    if (pos >= lon) return;
    if (pos == 0) {
        eliminaInicial();
    }
    else if (pos >= 1 && pos < lon) {
        Nodo<T>* aux = ini;
        Nodo<T>* nodo_remove;
        for (int i = 1; i < pos; i++) {
            aux = aux->sigte;
        }
        nodo_remove = aux->sigte;
        aux->sigte = nodo_remove->sigte;
        if (nodo_remove->sigte != nullptr)
            nodo_remove->sigte = aux;

        delete nodo_remove;
        lon--; // Decrement the member variable 'lon' instead of calling 'size'
    }
}

template <class T>
void Lista<T>::eliminaFinal() {
	eliminaPos(lon - 1);
}

template <class T>
void Lista<T>::eliminaTodo() {
	if (lon == 0) return;
	while (lon > 0) {
		eliminaInicial();
	}
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
