#pragma once
#include"Libreria.h"

template<class T>
class NodoAB
{
public:
	T elemento;
	NodoAB* izq;
	NodoAB* der;

	void setElemento(T elemento) { this->elemento = elemento; }
	void setIzq(NodoAB* izq) { this->izq = izq; }
	void setDer(NodoAB* der) { this->der = der; }

	T getElemento() { return elemento; }
	NodoAB* getIzq() { return izq; }
	NodoAB* getDer() { return der; }
};