#pragma once
#include <iostream>
#include <conio.h>
#include "Grafo.h"

using namespace std;

class SedeAsignada {
private:
    CGrafo<int>* G;
    vector<string> distritosLima;
    vector<string> sedesMiFarma;
    int distancia;
    int tiempo;

    // Función que asigna una distancia fija entre distritos colindantes para evitar aleatoriedad
    int distanciaFija() {
        return 3;
    }

    // Método para agregar arcos bidireccionales entre distritos colindantes
    void agregarArcoBidireccional(string desde, string hasta, int distancia) {
        G->adicionarArco(desde, hasta, distancia);   // Arco de desde -> hasta
        G->adicionarArco(hasta, desde, distancia);   // Arco de hasta -> desde (bidireccional)
    }

public:
    SedeAsignada() {
        G = new CGrafo<int>();
        tiempo = -1;
        distancia = -1;
        // Inicializar los distritos y sedes
        distritosLima = {
            "Ancon","Brena", "Santa Rosa", "Carabayllo", "Puente Piedra", "San Martin de Porres",
            "Los Olivos", "Comas", "Independencia", "Rimac", "Cercado de Lima",
            "Breña", "Jesus Maria", "Pueblo Libre", "San Miguel", "Magdalena del Mar",
            "Lince", "La Victoria", "San Isidro", "Miraflores", "Barranco",
            "Chorrillos", "San Juan de Lurigancho", "El Agustino", "Ate",
            "Santa Anita", "La Molina", "San Borja", "Surquillo", "Santiago de Surco",
            "Villa Maria del Triunfo", "Villa El Salvador", "San Juan de Miraflores",
            "Pachacamac", "Cieneguilla", "Lurigancho", "Lurin", "Punta Hermosa",
            "Punta Negra", "San Bartolo", "Santa Maria del Mar", "Pucusana", "Chaclacayo", "Callao"
        };

        sedesMiFarma = { "San Miguel", "Los Olivos", "Chorrillos" };

        // Añadiendo los distritos como vértices
        for (int i = 0; i < distritosLima.size(); i++) {
            G->adicionarVertice(distritosLima[i], i);
        }

        // Agregar conexiones entre distritos
        agregarRelaciones();
    }

    ~SedeAsignada() {
        delete G;
    }

    // Método para configurar las conexiones entre distritos
    void agregarRelaciones() {
        agregarArcoBidireccional("Ancon", "Santa Rosa", distanciaFija());
        agregarArcoBidireccional("Ancon", "Carabayllo", distanciaFija());
        agregarArcoBidireccional("Santa Rosa", "Puente Piedra", distanciaFija());
        agregarArcoBidireccional("Puente Piedra", "Carabayllo", distanciaFija());
        agregarArcoBidireccional("Carabayllo", "Comas", distanciaFija());
        agregarArcoBidireccional("Comas", "Los Olivos", distanciaFija());
        agregarArcoBidireccional("Comas", "San Juan de Lurigancho", distanciaFija());
        agregarArcoBidireccional("Los Olivos", "Independencia", distanciaFija());
        agregarArcoBidireccional("Independencia", "San Martin de Porres", distanciaFija());
        agregarArcoBidireccional("San Martin de Porres", "Rimac", distanciaFija());
        agregarArcoBidireccional("San Martin de Porres", "Callao", distanciaFija());
        agregarArcoBidireccional("Rimac", "Cercado de Lima", distanciaFija());
        agregarArcoBidireccional("Cercado de Lima", "Breña", distanciaFija());
        agregarArcoBidireccional("Breña", "Jesus Maria", distanciaFija());
        agregarArcoBidireccional("Jesus Maria", "Pueblo Libre", distanciaFija());
        agregarArcoBidireccional("Pueblo Libre", "Magdalena del Mar", distanciaFija());
        agregarArcoBidireccional("Magdalena del Mar", "San Miguel", distanciaFija());
        agregarArcoBidireccional("Callao", "San Miguel", distanciaFija());
        agregarArcoBidireccional("San Miguel", "Pueblo Libre", distanciaFija());
        agregarArcoBidireccional("San Miguel", "Jesus Maria", distanciaFija());
        agregarArcoBidireccional("Jesus Maria", "San Isidro", distanciaFija());
        agregarArcoBidireccional("Pueblo Libre", "Brena", distanciaFija());
        agregarArcoBidireccional("Brena", "La Victoria", distanciaFija());
        agregarArcoBidireccional("La Victoria", "Lince", distanciaFija());
        agregarArcoBidireccional("Lince", "San Isidro", distanciaFija());
        agregarArcoBidireccional("San Isidro", "Miraflores", distanciaFija());
        agregarArcoBidireccional("Miraflores", "Barranco", distanciaFija());
        agregarArcoBidireccional("Barranco", "Chorrillos", distanciaFija());
        agregarArcoBidireccional("Santiago de Surco", "Chorrillos", distanciaFija());
        agregarArcoBidireccional("San Juan de Miraflores", "Chorrillos", distanciaFija());
        agregarArcoBidireccional("Villa El Salvador", "Chorrillos", distanciaFija());
        agregarArcoBidireccional("Cercado de Lima", "El Agustino", distanciaFija());
        agregarArcoBidireccional("El Agustino", "San Juan de Lurigancho", distanciaFija());
        agregarArcoBidireccional("San Juan de Lurigancho", "Lurigancho", distanciaFija());
        agregarArcoBidireccional("Ate", "Santa Anita", distanciaFija());
        agregarArcoBidireccional("Santa Anita", "La Molina", distanciaFija());
        agregarArcoBidireccional("La Molina", "Santiago de Surco", distanciaFija());
        agregarArcoBidireccional("Santiago de Surco", "San Borja", distanciaFija());
        agregarArcoBidireccional("San Borja", "Surquillo", distanciaFija());
        agregarArcoBidireccional("Surquillo", "Miraflores", distanciaFija());
        agregarArcoBidireccional("Surquillo", "Santiago de Surco", distanciaFija());
        agregarArcoBidireccional("Santiago de Surco", "San Juan de Miraflores", distanciaFija());
        agregarArcoBidireccional("San Juan de Miraflores", "Villa Maria del Triunfo", distanciaFija());
        agregarArcoBidireccional("Villa Maria del Triunfo", "Villa El Salvador", distanciaFija());
        agregarArcoBidireccional("Villa El Salvador", "Lurin", distanciaFija());
        agregarArcoBidireccional("Lurin", "Pachacamac", distanciaFija());
        agregarArcoBidireccional("Pachacamac", "Lurigancho", distanciaFija());
        agregarArcoBidireccional("Lurigancho", "Cieneguilla", distanciaFija());
        agregarArcoBidireccional("Lurigancho", "Chaclacayo", distanciaFija());
        agregarArcoBidireccional("Chaclacayo", "Cieneguilla", distanciaFija());
        agregarArcoBidireccional("Cieneguilla", "La Molina", distanciaFija());
        agregarArcoBidireccional("Lurin", "Punta Hermosa", distanciaFija());
        agregarArcoBidireccional("Punta Hermosa", "Punta Negra", distanciaFija());
        agregarArcoBidireccional("Punta Negra", "San Bartolo", distanciaFija());
        agregarArcoBidireccional("San Bartolo", "Santa Maria del Mar", distanciaFija());
        agregarArcoBidireccional("Santa Maria del Mar", "Pucusana", distanciaFija());
        agregarArcoBidireccional("San Miguel", "Pueblo Libre", distanciaFija());
        agregarArcoBidireccional("Lince", "Jesus Maria", distanciaFija());
        agregarArcoBidireccional("La Victoria", "Cercado de Lima", distanciaFija());
    }

    // Método para calcular y mostrar la sede más cercana
    string calcularSedeCercana(const string& distritoUser) {
        int distanciaMinima = 999999;
        string sedeMasCercana = sedesMiFarma[0];

        for (const auto& sede : sedesMiFarma) {
            int distancia = G->distanciaMinima(distritoUser, sede);
            if (distancia < distanciaMinima) {
                distanciaMinima = distancia;
                sedeMasCercana = sede;
            }
        }
        if (distanciaMinima != -1) {
            this->distancia = distanciaMinima;
            this->tiempo = (distanciaMinima / 50) * 60 + 5;
        }
        return sedeMasCercana;
    }

    int getDistancia() {
        return this->distancia;
    }

    int getTiempo() {
        return this->tiempo;
    }

    void mostrarConexiones() {
        for (string distrito : distritosLima) {
            cout << "Conexiones desde " << distrito << ": ";
            int cantidadArcos = G->cantidadArcos(distrito);
            for (int j = 0; j < cantidadArcos; j++) {
                string destino = G->obtenerEtiquetaVertice(G->obtenerVerticeLlegada(distrito, j));
                int distancia = G->obtenerArco(distrito, destino);
                cout << destino << " (" << distancia << " km) ";
            }
            cout << endl;
        }
    }

};
