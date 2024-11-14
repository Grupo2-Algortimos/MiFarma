#pragma once
#include"Nodo.h"

template<class T>
class Cola
{
private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
public:
	Cola()
	{
		this->inicio = nullptr;
		this->fin = nullptr;
	}

	~Cola(){}

	bool esVacia()
	{
		return inicio == nullptr;
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
		nodo = nullptr;
	}

	T desencolar()
	{
		T dato = inicio->elem;
		if (inicio == fin)
		{
			inicio = nullptr;
			fin = nullptr;
		}
		else
		{
			inicio = inicio->sigte;
		}
		return dato;
	}

	T front()
	{
		return inicio->elem;
	}

	T back()
	{
		return fin->elem;
	}

	int size()
	{
		int cont = 0;
		Nodo<T>* aux = inicio;
		while (aux != nullptr)
		{
			cont++;
			aux = aux->sigte;
		}
		return cont;
	}

	Cola<T>* copiar()
	{
		Cola<T>* copia = new Cola<T>();
		if (esVacia()) {
			return copia;
		}

		Nodo<T>* aux = this->inicio;
		copia->inicio = new Nodo<T>(aux->elem);
		Nodo<T>* nodoCopia = copia->inicio;

		aux = aux->sigte;
		while (aux != nullptr) {
			nodoCopia->sigte = new Nodo<T>(aux->elem);
			nodoCopia = nodoCopia->sigte;
			aux = aux->sigte;
		}
		copia->fin = nodoCopia;

		return copia;
	}
};
