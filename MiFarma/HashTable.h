#pragma once
#include"Libreria.h"
#include "Usuario.h"

using namespace std;

template <class T>
class HashTablaA {
private:
    std::vector<T*> table;    // Vector que contiene punteros a T o nullptr si la posición está vacía
    int currentSize;          // Cantidad de elementos en la tabla
    const T* DELETED;         // Marcador especial para posiciones borradas

public:
    explicit HashTablaA(int size = 101) : table(size, nullptr), currentSize(0)
    {
        // `DELETED` es una dirección especial para marcar eliminaciones sin usar memoria real
        DELETED = reinterpret_cast<T*>(0xFFFFFFFF);
    }

    int getsize() const {
        return table.size();
    }

    void makeEmpty() {
        for (auto& item : table) {
            if (item != nullptr && item != DELETED) {
                delete item;  // Liberar la memoria de elementos en la tabla
            }
            item = nullptr;
        }
        currentSize = 0;
    }

    bool insert(T* x) {
        int index = myhash(x->getNombre(), x->getApellido());
        int initialIndex = index;

        while (table[index] != nullptr && table[index] != DELETED) {
            if (*table[index] == *x) {
                // Si ya existe el elemento, no lo volvemos a insertar
                return false;
            }
            index = (index + 1) % table.size();  // Sondeo lineal
            if (index == initialIndex) return false;  // Tabla llena
        }

        table[index] = x;
        currentSize++;
        return true;
    }

    bool remove(const std::string& nombre, const std::string& apellido) {
        int index = myhash(nombre, apellido);
        int initialIndex = index;

        while (table[index] != nullptr) {
            if (table[index] != DELETED && table[index]->getNombre() == nombre && table[index]->getApellido() == apellido) {
                delete table[index];   // Liberar memoria del elemento eliminado
                table[index] = const_cast<T*>(DELETED);  // Marca como eliminada
                currentSize--;
                return true;
            }
            index = (index + 1) % table.size();  // Sondeo lineal
            if (index == initialIndex) break;    // Se recorrió la tabla completa
        }
        return false;
    }

    void DispAll() {
        int contEspacios = 0;
        for (size_t i = 0; i < table.size(); i++) {
            if (table[i] != nullptr && table[i] != DELETED) {
                if (contEspacios > 18) break;
                Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 1 + contEspacios);
                std::cout << "key " << i << " | Nombre: " << table[i]->getNombre() << ", Apellido: " << table[i]->getApellido() << endl;
                contEspacios++;
            }
        }
    }

private:
    int conversor(const std::string& a, const std::string& b) const {
        int sumaNombre = 0;
        int sumaApellido = 0;
        for (char c : a) {
            sumaNombre += static_cast<int>(c);
        }
        for (char d : b) {
            sumaApellido += static_cast<int>(d);
        }
        int operacion = (sumaNombre + sumaApellido) * 50 / 2;
        return operacion;
    }

    size_t myhash(const std::string& key1, const std::string& key2) const {
        int hashVal = conversor(key1, key2);
        hashVal %= table.size();  // Aritmética modular para obtener el índice
        return hashVal;
    }
};
