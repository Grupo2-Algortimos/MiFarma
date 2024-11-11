#pragma once

using namespace std;

template<class T>
class NodoP
{
public:
	T dato;
	NodoP<T>* siguiente;

	NodoP(T v, NodoP<T>* sig = NULL)
	{
		dato = v;
		siguiente = sig;
	}
};

template <class T>
class Pila
{
private:
	NodoP<T>* tope;
public:
	Pila()
	{
		tope = NULL;
	}
	void apilar(T v);
	T desapilar();
	bool esVacia();
};
//IMPLEMENTACIÓN
template <class T>
void Pila<T>::apilar(T v)
{
	if (esVacia())
	{
		tope = new NodoP<T>(v);
	}
	else
	{
		tope = new NodoP<T>(v, tope);
	}
}
template <class T>
T Pila<T>::desapilar()
{
	if (esVacia())
	{
		//Pila vacia
		return NULL;
	}
	else
	{
		T elemento = (T)(tope->dato);
		tope = (NodoP<T>*)tope->siguiente;
		return elemento;
	}
}

template <class T>
bool Pila<T>::esVacia()
{
	return (tope == NULL);
}


