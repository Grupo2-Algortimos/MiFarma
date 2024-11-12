#pragma once
#include"NodoAB.h"

template<typename T>
class ArbolBalanceado
{
	typedef function<int(T, T)> Comp; //Lambda
	NodoAB<T>* raiz;
	void(*procesar)(T);//Puntero a una función
	Comp comparar; //Lambda de criterio de comparación
private:
	bool _buscar(NodoAB<T>* nodo, T e)
	{
		if (nodo == nullptr) return false;
		else {
			int r = comparar(nodo->elemento, e);
			if (r == 0) return true;
			else if (r < 0)
				return _buscar(nodo->der, e);
			else
				return _buscar(nodo->izq, e);
		}
	}

	NodoAB<T>* _obtener(NodoAB<T>* nodo, T e)
	{
		if (nodo == nullptr) return nullptr;
		else {
			int r = comparar(nodo->elemento, e);
			if (r == 0) return nodo;
			else if (r < 0)
				return _obtener(nodo->der, e);
			else
				return _obtener(nodo->izq, e);
		}
	}

	bool _insertar(NodoAB<T>*& nodo, T e)
	{
		if (nodo == nullptr)
		{
			nodo = new NodoAB<T>();
			nodo->elemento = e;
			return true;
		}
		else {
			int r = comparar(nodo->elemento, e);
			if (r == 0) return false;
			else if (r < 0)
				return _insertar(nodo->der, e);
			else
				return _insertar(nodo->izq, e);
		}
	}

	void _enOrden(NodoAB<T>* nodo)
	{
		if (nodo == nullptr) return;
		_enOrden(nodo->izq);
		procesar(nodo->elemento);
		_enOrden(nodo->der);
	}

	void _preOrden(NodoAB<T>* nodo)

	{
		if (nodo == nullptr) return;
		procesar(nodo->elemento);
		_preOrden(nodo->izq);
		_preOrden(nodo->der);
	}

	void _postOrden(NodoAB<T>* nodo)

	{
		if (nodo == nullptr) return;
		_postOrden(nodo->izq);
		_postOrden(nodo->der);
		procesar(nodo->elemento);
	}

	bool _vacio()
	{
		return raiz == nullptr;
	}

	int _cantidad(NodoAB<T>* nodo)

	{
		//La cantidad de nodos en el arbol es:
		//	0 si esta vacio
		//	1 + cantidad nodos izq + cantidad nodos der
		if (nodo == nullptr)
			return 0;
		else
		{
			int ci, cd;
			ci = _cantidad(nodo->izq);
			cd = _cantidad(nodo->der);
			return 1 + ci + cd;
		}
	}

	int _altura(NodoAB<T>* nodo)
	{
		//La altura del arbol es:
		// 0 si es vacio
		// la mayor altura por izq o por der
		if (nodo == nullptr)
			return 0;
		else
		{
			int ai, ad;
			ai = _altura(nodo->izq);
			ad = _altura(nodo->der);
			return 1 + (ai > ad ? ai : ad);
		}
	}


	int _minimo(NodoAB<T>* nodo)
	{
		if (nodo->izq == nullptr)
			return nodo->elemento;
		else
			return _minimo(nodo->izq);
	}

	int _maximo(NodoAB<T>* nodo)
	{
		if (nodo->der == nullptr)
			return nodo->elemento;
		else
			return _maximo(nodo->der);
	}

	bool _eliminar(NodoAB<T>*& nodo, T e)
	{
		if (nodo == nullptr) return false;
		else {
			int r = comparar(nodo->elemento, e);
			if (r < 0)
				return _eliminar(nodo->der, e);
			else if (r > 0)
				return _eliminar(nodo->izq, e);
			else {
				//r==0 es porque se encontró el elemento "e" en el arbol
				//CASO 1:
				if (nodo->der == nullptr && nodo->izq == nullptr)
				{
					nodo = nullptr;
					delete nodo;
					return true;
				}
				//CASO 2:
				else if (nodo->izq == nullptr)
				{
					nodo = nodo->der;
					return true;
				}
				//CASO 3:
				else if (nodo->der == nullptr)
				{
					nodo = nodo->izq;
					return true;
				}
				//CASO 4:
				else {
					//Se establece buscar el menor elemento por la derecha
					Nodo<T>* aux = nodo->der;
					while (aux->izq != nullptr)
						aux = aux->izq;
					//Actualizamo el elemento en el nodo raiz
					nodo->elemento = aux->elemento;
					//Se envia a eliminar el elemento del arbol por la derecha
					return _eliminar(nodo->der, aux->elemento);
				}
			}
		}
	}

	NodoAB<T>* _nodoSucesor(NodoAB<T>* nodo, T e)
	{
		NodoAB<T>* actual = _obtener(nodo, e);
		if (actual == nullptr) return nullptr;
		if (actual->der != nullptr) {
			Nodo<T>* sucesor = actual->der;
			while (sucesor->izq != nullptr)
				sucesor = sucesor->izq;
			return sucesor;
		}
		NodoAB<T>* sucesor = nullptr;
		NodoAB<T>* predecesor = raiz;
		while (predecesor != actual) {
			if (comparar(actual->elemento, predecesor->elemento) < 0) {
				sucesor = predecesor;
				predecesor = predecesor->izq;
			}
			else {
				predecesor = predecesor->der;
			}
		}
		return sucesor;
	}

	NodoAB<T>* _nodoPredecesor(NodoAB<T>* nodo, T e)
	{
		Nodo<T>* actual = _obtener(nodo, e);
		if (actual == nullptr) return nullptr;
		if (actual->izq != nullptr) {
			Nodo<T>* predecesor = actual->izq;
			while (predecesor->der != nullptr)
				predecesor = predecesor->der;
			return predecesor;
		}
		NodoAB<T>* predecesor = nullptr;
		NodoAB<T>* sucesor = raiz;
		while (sucesor != actual) {
			if (comparar(actual->elemento, sucesor->elemento) > 0) {
				predecesor = sucesor;
				sucesor = sucesor->der;
			}
			else {
				sucesor = sucesor->izq;
			}
		}
		return predecesor;
	}

	int _numeroNodosPorNivel(NodoAB<T>* nodo, int nivel)
	{
		if (nodo == nullptr) return 0;
		if (nivel == 0) return 1;
		return _numeroNodosPorNivel(nodo->izq, nivel - 1) + _numeroNodosPorNivel(nodo->der, nivel - 1);
	}

public:
	ArbolBalanceado(void(*otroPunteroAFuncion)(T))
	{
		this->procesar = otroPunteroAFuncion;
		this->comparar = [](T a, T b)->int {return a - b; };
		raiz = nullptr;
	}

	~ArbolBalanceado() {}

	bool insertar(T e)
	{
		return _insertar(raiz, e);
	}

	bool buscar(T e)
	{
		return _buscar(raiz, e);
	}

	void enOrden()
	{
		_enOrden(raiz);
	}

	void preOrden()
	{
		_preOrden(raiz);
	}

	void postOrden()
	{
		_postOrden(raiz);
	}

	int cantidad()
	{
		return _cantidad(raiz);
	}

	int altura()
	{
		return _altura(raiz);
	}

	int minimo()
	{
		return _minimo(raiz);
	}

	int maximo()
	{
		return _maximo(raiz);
	}

	bool vacio()
	{
		return _vacio();
	}

	NodoAB<T>* obtener(T e)
	{
		return _obtener(raiz, e);
	}

	bool eliminar(T e)
	{
		return _eliminar(raiz, e);
	}

	NodoAB<T>* nodoSucesor(T e)
	{
		return _nodoSucesor(raiz, e);
	}

	NodoAB<T>* nodoPredecesor(T e)
	{
		return _nodoPredecesor(raiz, e);
	}

	int  numeroNodosPorNivel(int nivel)
	{
		return _numeroNodosPorNivel(raiz, nivel);
	}
};