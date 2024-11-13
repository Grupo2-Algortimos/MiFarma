#pragma once
#include"Libreria.h"

template<class T>
class NodoAVL
{
public:
	T elemento;
	NodoAVL* izq;
	NodoAVL* der;
	int altura;
	NodoAVL()
	{
		izq = nullptr;
		der = nullptr;
		altura = 0;
	}
};