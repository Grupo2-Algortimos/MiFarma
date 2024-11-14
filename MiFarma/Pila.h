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
	int size();
	Pila<T>* copiar();
	T returnTope();
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


template <class T>
int Pila<T>::size()
{
	NodoP<T>* aux = tope;
	int cont = 0;
	while (aux != NULL)
	{
		cont++;
		aux = aux->siguiente;
	}
	return cont;
}

template <class T>
Pila<T>* Pila<T>::copiar()
{
	Pila<T> temporal;
	NodoP<T>* aux = tope;

	while (aux != NULL)
	{
		temporal.apilar(aux->dato);
		aux = aux->siguiente;
	}

	Pila<T>* pila_copia = new Pila<T>();
	aux = temporal.tope;
	while (aux != NULL)
	{
		pila_copia->apilar(aux->dato);
		aux = aux->siguiente;
	}

	return pila_copia;
}

template <class T>
T Pila<T>::returnTope()
{
	if (esVacia())
	{
		return NULL;
	}
	else
	{
		return tope->dato;
	}
}