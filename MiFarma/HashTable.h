#pragma once
#include"Libreria.h"
#include "Usuario.h"

class HashTablaA {
private:
	vector<list<Usuario*>> theLists;   // Tabla: vector cuyo cada elemento es una Lista de Nodos Hash(key, value)
	int  currentSize;	//Tamaño del vector

public:
	explicit HashTablaA(int size = 101) : currentSize{ 0 }
	{
		theLists.resize(101);	//Resize al vector, para que tenga 101 elementos: 101 listas de Nodos Hash(key, value)
	}

	int getsize() {
		return theLists.size();
	}

	void makeEmpty()
	{
		for (auto& thisList : theLists)
			thisList.clear();
	}

	bool insert(Usuario*&& x)
	{
		auto& whichList = theLists[myhash(x->getNombre(),x->getApellido())]; //Del vector, obtenemos la lista de elementos según el hash(indice) obtenido

		whichList.push_back(x); //Agregamos el nuevo elemento(key, value) a la lista del hash(indice)

		return true;
	}

	void DispAll() {
		int pos = 0;
		int contEspacios = 0;
		for (auto& thisList : theLists) {		// Recorremos el vector<>
			if (contEspacios > 18) break;
			Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 1 + contEspacios);
			cout << "Key: " + to_string(pos) << " | ";
			for (auto& it : theLists[pos]) {	// Recorremos la Lista de cada indice del vector	
				cout << it->getNombre() << ",";		// Imprime key
				//cout << "(" << it.getKey() << ", " << it.getValue() << "); ";	// Imprime (key,value)
			}
			cout << endl;
			pos++;
			contEspacios++;
		}
	}

private:

	// ...:: FUNCION HASH ::...
	int conversor(string a, string b) {
		int sumaNombre = 0;
		int sumaApellido = 0;
		for (char c : a) {
			sumaNombre += static_cast<int>(c);  // Obtiene el código ASCII del carácter
		}
		for (char d : b) {
			sumaApellido += static_cast<int>(d);  // Obtiene el código ASCII del carácter
		}
		int operacion = (sumaNombre + sumaApellido) *50 / 2 ;
		return operacion;
	}


	size_t myhash(string key1, string key2)  {
		int hashVal = conversor(key1, key2);			//Funcion de Dispersion: k (the same key)
		hashVal %= theLists.size();		//Mapa de Compresion: Aritmetica Modular: F(k) = |k| mod N
		//hashVal = 10; //Prueba para verificar como se almacenan los elementos si obtienen el mismo hash
		return(hashVal);	//retornará el indice obtenido para la Tabla HASH
	}
};
