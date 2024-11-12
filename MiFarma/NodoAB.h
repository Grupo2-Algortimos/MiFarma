#pragma once
#include"Libreria.h"

template<class T>
class NodoAB
{
public:
	T elemento;
	NodoAB* izq;
	NodoAB* der;
};