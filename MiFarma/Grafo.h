#pragma once
#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <vector>
#include <string>
using namespace std;

template<class T, T vacio = -1>
class CGrafo {
private:
    class CArco {
    public:
        T info;
        int v;
        CArco(int vLlegada) {
            info = vacio;
            v = vLlegada;
        }
    };

    class CVertice {
    public:
        T info;
        vector<CArco*>* ady;
        CVertice() {
            info = vacio;
            ady = new vector<CArco*>();
        }
    };

    vector<CVertice*>* vertices;
    vector<string> etiquetas;

    int obtenerIndice(string& etiqueta) {
        for (int i = 0; i < etiquetas.size(); i++) {
            if (etiquetas[i] == etiqueta) {
                return i;
            }
        }
        return -1;
    }

public:
    CGrafo() {
        vertices = new vector<CVertice*>();
    }

    int adicionarVertice(string& etiqueta, T info) {
        // Crear el vértice y agregarlo
        CVertice* vert = new CVertice();
        vert->info = info;
        vertices->push_back(vert);
        etiquetas.push_back(etiqueta);
        return vertices->size() - 1;
    }

    int cantidadVertices() {
        return vertices->size();
    }

    T obtenerVertice(string& etiqueta) {
        int v = obtenerIndice(etiqueta);
        return (v != -1) ? (vertices->at(v))->info : vacio;
    }

    void modificarVertice(string& etiqueta, T info) {
        int v = obtenerIndice(etiqueta);
        (vertices->at(v))->info = info;
    }

    int adicionarArco(string& etiquetaDesde, string& etiquetaHasta, T infoArco) {
        int v = obtenerIndice(etiquetaDesde);
        int vLlegada = obtenerIndice(etiquetaHasta);
        CVertice* ver = vertices->at(v);
        CArco* arc = new CArco(vLlegada);
        arc->info = infoArco;
        ver->ady->push_back(arc);
        return ver->ady->size() - 1;
    }

    int cantidadArcos(string& etiqueta) {
        int v = obtenerIndice(etiqueta);
        return (vertices->at(v))->ady->size();
    }

    T obtenerArco(string& etiquetaDesde, string& etiquetaHasta) {
        int v = obtenerIndice(etiquetaDesde);
        int vLlegada = obtenerIndice(etiquetaHasta);
        CVertice* ver = vertices->at(v);
        for (CArco* arco : *(ver->ady)) {
            if (arco->v == vLlegada) {
                return arco->info;
            }
        }
        return vacio;
    }

    void modificarArco(string& etiquetaDesde, string& etiquetaHasta, T info) {
        int v = obtenerIndice(etiquetaDesde);
        int vLlegada = obtenerIndice(etiquetaHasta);

        CVertice* ver = vertices->at(v);
        for (CArco* arco : *(ver->ady)) {
            if (arco->v == vLlegada) {
                arco->info = info;
                return;
            }
        }
    }

    int obtenerVerticeLlegada(string& etiquetaDesde, int apos) {
        int v = obtenerIndice(etiquetaDesde);
        if (v != -1 && apos < (vertices->at(v))->ady->size()) {
            return (vertices->at(v))->ady->at(apos)->v;
        }
        return -1;
    }

    string obtenerEtiquetaVertice(int indice) {
        return (indice >= 0 && indice < etiquetas.size()) ? etiquetas[indice] : "";
    }

    int distanciaMinima(string desde, string hasta) {
        int inicio = obtenerIndice(desde);
        int destino = obtenerIndice(hasta);

        if (inicio == -1 || destino == -1) return -1;

        const int INF = 999999;
        vector<int> dist(vertices->size(), INF);
        vector<bool> visitado(vertices->size(), false);
        dist[inicio] = 0;

        for (int i = 0; i < vertices->size(); i++) {
            int u = -1, minDist = INF;

            for (int j = 0; j < vertices->size(); j++) {
                if (!visitado[j] && dist[j] < minDist) {
                    minDist = dist[j];
                    u = j;
                }
            }

            if (u == -1 || minDist == INF) break;
            visitado[u] = true;

            for (CArco* arco : *(vertices->at(u)->ady)) {
                int v = arco->v;
                int peso = arco->info;
                if (!visitado[v] && dist[u] + peso < dist[v]) {
                    dist[v] = dist[u] + peso;
                }
            }
        }

        return dist[destino] == INF ? -1 : dist[destino];
    }


};

#endif // !__GRAFO_HPP__
