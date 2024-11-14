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
    /*
    void DispAll() {
        bool salir = false, tecla_presionada = true;
        int contVentanas = 1;
        int contEspacios = 0;
        for (size_t i = 0; i < table.size(); i++) {
            if (table[i] != nullptr && table[i] != DELETED) {
                if (contEspacios > 18) break;
                Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 1 + contEspacios);
                cout << "key " << i << " | Nombre: " << table[i]->getNombre() << ", Apellido: " << table[i]->getApellido() << endl;
                contEspacios++;
            }
            Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 1);
            cout << "[->] Mover siguiente producto";
            Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 2);
            cout << "[<-] Retroceder anterior producto";
            Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 3);
            cout << "[B] Buscar";
            Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 4);
            cout << "[ESC] Salir";
            Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 10);
            cout << "<" << contVentanas << " : " << getsize() / 3 + 1 << ">";
            tecla_presionada = false;
            if (kbhit())
            {
                char tecla = getch();
                switch (tecla)
                {
                case TECLA_DERECHA:                    
                    if (contProductos < l_productos->longitud() - 3)
                    {
                        contProductos += 3;
                        contVentanas++;
                    }
                    break;
                case TECLA_IZQUIERDA:
                    if (contProductos > 2)
                    {
                        contProductos -= 3;
                        contVentanas--;
                    }
                    break;
                case TECLA_ESCAPE:
                    salir = true;
                    break;
                }
                tecla_presionada = true;
            }
        }
    }
    */

    void DispAll() {
        bool salir = false;
        int contVentanas = 1;                 // Contador de páginas (ventanas)
        int paginaActual = 0;                 // Índice de la página actual
        const int elementosPorPagina = 10;    // Número de elementos por página

        while (!salir) {
            // Limpiar la pantalla o posición inicial (esto dependerá de cómo implementes el entorno gráfico o consola)
            //system("cls");  // Solo si estás en Windows; en Linux/Mac puedes usar `clear`
            //mainInterfaz->encuadrar();

            int inicio = paginaActual * elementosPorPagina;
            int fin = std::min(static_cast<int>(table.size()), inicio + elementosPorPagina);
            int contEspacios = 0;

            for (int i = inicio; i < fin; ++i) {
                if (table[i] != nullptr && table[i] != DELETED) {
                    // Posicionar y mostrar cada elemento
                    Console::SetCursorPosition(ANCHO / 6, ALTO / 5 + 1 + contEspacios);
                    cout << "key " << i << " | Nombre: " << table[i]->getNombre()
                        << ", Apellido: " << table[i]->getApellido() << endl;
                    contEspacios++;
                }
            }

            // Mostrar las instrucciones de navegación
            Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 1);
            cout << "[->] Mover a la siguiente página";
            Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 2);
            cout << "[<-] Mover a la página anterior";
            Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 3);
            cout << "[ESC] Salir";
            Console::SetCursorPosition(ANCHO - 40, ALTO / 5 + 10);
            cout << "<" << paginaActual + 1 << " de " << (table.size() + elementosPorPagina - 1) / elementosPorPagina << ">";

            // Detectar entrada de teclas
            if (kbhit()) {
                char tecla = getch();
                switch (tecla) {
                case TECLA_DERECHA:
                    if ((paginaActual + 1) * elementosPorPagina < table.size()) {
                        paginaActual++;  // Avanzar a la siguiente página
                        contVentanas++;
                    }
                    break;
                case TECLA_IZQUIERDA:
                    if (paginaActual > 0) {
                        paginaActual--;  // Retroceder a la página anterior
                        contVentanas--;
                    }
                    break;
                case TECLA_ESCAPE:
                    salir = true;  // Salir del bucle y de la función
                    break;
                }
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
