#pragma once
#include"NodoAB.h"

template<class T>
class ArbolBinario
{
	NodoAB<T>* raiz;
	void(*procesar)(T); //Puntero a una función
private:
	bool _insertar(NodoAB<T>*& nodo, T e)
	{
		if (nodo == nullptr)
		{
			nodo = new NodoAB<T>();
			nodo->elemento = e;
		}
		else if (e < nodo->elemento)
		{
			return _insertar(nodo->izq, e);
		}
		else if (e >= nodo->elemento)
		{
			return _insertar(nodo->der, e);
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
		//La cantidad de nodos del árbol:
		// 0 si el árbol es vacio
		// 1 + cantidad de nodos por izquierda + cantidad de nodo por derecha
		if (nodo == nullptr)
			return 0;
		else
		{
			int ci = _cantidad(nodo->izq);
			int cd = _cantidad(nodo->der);
			return 1 + ci + cd;
		}
	}

	int _altura(NodoAB<T>* nodo)
	{
		//La altura del árbol:
		// 0 si el árbol es vacío
		// La mayor altura por izq y por derecha
		if (nodo == nullptr) return 0;
		else
		{
			int ai = 1 + _altura(nodo->izq);
			int ad = 1 + _altura(nodo->der);
			return (ai > ad) ? ai : ad;
		}
	}

	int _cantidadNodosIzquierda(NodoAB<T>* nodo)
	{
		if (nodo == nullptr) return 0;
		else
		{
			return _cantidad(nodo->izq);
		}
	}

	int _cantidadNodosDerecha(NodoAB<T>* nodo)
	{
		if (nodo == nullptr) return 0;
		else
		{
			return _cantidad(nodo->der);
		}
	}

	T _sumaNodos(NodoAB<T>* nodo)
	{
		if (nodo == nullptr) return 0;
		else
		{
			return nodo->elemento + _sumaNodos(nodo->izq) + _sumaNodos(nodo->der);
		}
	}


	void _convertirArbolEspejo(NodoAB<T>* nodo)
	{
		if (nodo == nullptr) return;

		NodoAB<T>* temp = nodo->izq;
		nodo->izq = nodo->der;
		nodo->der = temp;

		_convertirArbolEspejo(nodo->izq);
		_convertirArbolEspejo(nodo->der);
	}

	bool _buscar(NodoAB<T>* nodo, T e)
	{
		if (nodo == nullptr) {
			return false; // Elemento no encontrado
		}
		if (nodo->elemento == e) {
			return true; // Elemento encontrado
		}
		else if (e < nodo->elemento) {
			return _buscar(nodo->izq, e); // Buscar en el subárbol izquierdo
		}
		else {
			return _buscar(nodo->der, e); // Buscar en el subárbol derecho
		}
	}


public:
	ArbolBinario(void(*otroPunteroAFuncion)(T))
	{
		this->procesar = otroPunteroAFuncion;
		this->raiz = nullptr;
	}

	~ArbolBinario() {}

	bool insertar(T e)
	{
		return _insertar(raiz, e);
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

	bool vacio()
	{
		return _vacio();
	}

	int altura()
	{
		return _altura(raiz);
	}

	int cantidadNodosIzquierda()
	{
		return _cantidadNodosIzquierda(raiz);
	}

	int cantidadNodosDerecha()
	{
		return _cantidadNodosDerecha(raiz);
	}

	T sumaNodos()
	{
		return _sumaNodos(raiz);
	}

	void convertirArbolEspejo()
	{
		_convertirArbolEspejo(raiz);
	}

	bool buscar(T e) {
		return _buscar(raiz, e);
	}

};