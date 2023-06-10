#include "../Materiales Grafos/grafoPMC.h"
#include "../Algoritmos/Dijkstra.cpp"
#include "../Practica 6/actividad1.cpp" //Dijkstra Inverso

struct Parte{
    int nCargas, destino;
    Parte(int num, int dest): nCargas(num), destino(dest) {}
};

template<typename tCoste>
unsigned cementos(GrafoP<tCoste> grafo, typename GrafoP<tCoste>::vertice capital,vector<Parte> trabajo){
    
    typedef typename GrafoP<tCoste>::vertice vertice;
    tCoste INFINITO = GrafoP<tCoste>::INFINITO;

    //Caminos mínimos para llegar a destino
    vector<vertice> vect;
    vector<tCoste> Ida(grafo.numVert());
    Ida = Dijkstra(grafo, capital, vect);

    //Camino mínimo de vuelta
    vector<tCoste> Vuelta(grafo.numVert());
    Vuelta = DijkstraInv(grafo, capital, vect);

    //Calculamos distancia
    unsigned distancia_total = 0;
    for(vertice i = 0; i < grafo.numVert(); i++){
        for(vertice j = 0; j < grafo.numVert(); j++){

            if(i != capital && trabajo[j].nCargas > 0 && trabajo[j].destino ==i){
                distancia_total += (Ida[i] + Vuelta[i]) * trabajo[j].nCargas;
            }
        }
    }
    return distancia_total;
}
