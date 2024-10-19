#pragma once
#include"Nodo.h"
using namespace std;
template<class T>
class Cola
{
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
public:
	Cola()
	{
		this->inicio = NULL;
		this->fin = NULL;
	}

	~Cola()
	{
		delete inicio;
		delete fin;
	}

	bool esVacia() {
		return (inicio == NULL);
	}

	void encolar(T v)
	{
		Nodo<T>* nodo = new Nodo<T>(v);
		if (esVacia())
		{
			inicio = nodo;
			fin = inicio;
		}
		else
		{
			fin->sigte = nodo;
			fin = nodo;
		}

		nodo = NULL;
	}

	T desencolar()
	{
		T dato = inicio->elem;
		if (inicio == fin)
		{
			inicio = NULL;
			fin = NULL;
		}
		else
		{
			inicio = inicio->sigte;
		}
		return dato;
	}

	int size()
	{
		if (esVacia()) return 0;
		int cont = 0;
		Nodo<T>* aux = inicio;
		while (aux != NULL)
		{
			cont++;
			aux = aux->sigte;
		}
		return cont;
	}

	T back()
	{
		return fin->elem;
	}

	T front()
	{
		return inicio->elem;
	}

};
