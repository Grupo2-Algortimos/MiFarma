#pragma once
template<class T>
class Nodo {
public:
	T elem;
	Nodo* sigte;
	Nodo() {
		sigte = nullptr;
	}
	Nodo(T pelem)
	{
		elem = pelem;
		sigte = nullptr;
	}

	//Métodos Setter / Getter
	void set_Elem(T pelem)
	{
		elem = pelem;
	}
	T get_Elem()
	{
		return elem;
	}
	void set_Sgte(Nodo* pSgte)
	{
		sigte = pSgte;
	}
	Nodo* get_Sgte()
	{
		return sigte;
	}

	//Métodos de Servicio
	bool es_vacio()
	{
		return sigte == NULL;
	}
};