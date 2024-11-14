#pragma once
#include"NodoAVL.h"
template<class T>
class ArbolBalanceado
{
private:
	NodoAVL<T>* raiz;
	void(*procesar)(T); //puntero a funci�n

	//Operaciones privadas
	int _altura(NodoAVL<T>* nodo)
	{
		if (nodo == nullptr)return 0;
		return nodo->altura;
	}

	void _rotarDerecha(NodoAVL<T>*& nodo)
	{
		NodoAVL<T>* p = nodo->izq;
		nodo->izq = p->der;
		p->der = nodo;
		nodo = p;
	}

	void _rotarIzquierda(NodoAVL<T>*& nodo)
	{
		NodoAVL<T>* p = nodo->der;
		nodo->der = p->izq;
		p->izq = nodo;
		nodo = p;
	}

	void _balanceo(NodoAVL<T>*& nodo)
	{
		int hizq = _altura(nodo->izq);
		int hder = _altura(nodo->der);
		int fb = hder - hizq;

		if (fb > 1) //Rotar a la izq
		{
			int hhizq = _altura(nodo->der->izq);
			int hhder = _altura(nodo->der->der);
			if (hhizq > hhder) //Verificar si aplica doble rotaci�n
			{
				_rotarDerecha(nodo->der);
			}
			_rotarIzquierda(nodo);
		}
		if (fb < -1)
		{
			int hhizq = _altura(nodo->izq->izq);
			int hhder = _altura(nodo->izq->der);
			if (hhizq < hhder) //Verificar si aplica doble rotaci�n
			{
				_rotarIzquierda(nodo->izq);
			}
			_rotarDerecha(nodo);
		}
		//Actualizar la altura del nodo raiz
		hizq = _altura(nodo->izq);
		hder = _altura(nodo->der);
		nodo->altura = 1 + ((hizq > hder) ? hizq : hder);
	}

	bool _insertar(NodoAVL<T>*& nodo, T e)
	{
		if (nodo == nullptr)
		{
			//Nuevo elemento
			nodo = new NodoAVL<T>();
			nodo->elemento = e;
			return true;
		}
		else if (e == nodo->elemento)
			return false;
		else if (e < nodo->elemento)
			_insertar(nodo->izq, e);
		else if (e > nodo->elemento)
			_insertar(nodo->der, e);
		_balanceo(nodo);
		return true;
	}

	void _inOrden(NodoAVL<T>* nodo)
	{
		if (nodo == nullptr) return;
		_inOrden(nodo->izq);
		procesar(nodo->elemento);
		_inOrden(nodo->der);
	}

	void _inOrdenH(NodoAVL<T>* nodo)
	{
		if (nodo == nullptr) return;
		_inOrdenH(nodo->izq);
		procesar(nodo->altura);
		_inOrdenH(nodo->der);
	}

	int _cantidad(NodoAVL<T>* nodo)
	{
		if (nodo == nullptr) return 0;
		return 1 + _cantidad(nodo->izq) + _cantidad(nodo->der);
	}

	bool _buscar(NodoAVL<T>* nodo, T e)
	{
		if (nodo == nullptr) {
			return false; // Elemento no encontrado
		}
		if (nodo->elemento == e) {
			return true; // Elemento encontrado
		}
		else if (e < nodo->elemento) {
			return _buscar(nodo->izq, e); // Buscar en el sub�rbol izquierdo
		}
		else {
			return _buscar(nodo->der, e); // Buscar en el sub�rbol derecho
		}
	}


public:
	ArbolBalanceado(void(*nuevaFuncion)(T))
	{
		this->procesar = nuevaFuncion;
		this->raiz = nullptr;
	}

	bool insertar(T e)
	{
		return _insertar(raiz, e);
	}

	void inOrden()
	{
		_inOrden(raiz);
	}

	void inOrdenH()
	{
		_inOrdenH(raiz);
	}

	int cantidad()
	{
		return _cantidad(raiz);
	}

	bool buscar(T e)
	{
		return _buscar(raiz, e);
	}

	~ArbolBalanceado() {}
};