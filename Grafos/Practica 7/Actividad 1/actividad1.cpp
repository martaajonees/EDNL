#include "../Materiales Grafos/grafoPMC.h"
#include "FloydMax.hpp"
template<typename tCoste>
struct Viaje{
    public:
        tCoste Coste;
        typename vector<tCoste>::vertice origen, destino;
};

template<typename tCoste>
Viaje<tCoste> otravezungrafo(GrafoP<tCoste> G){

    typedef typename GrafoP<tCoste>::vertice vertice;
    const tCoste INFINITO = GrafoP<tCoste>::INFINITO;

    matriz<vertice> Vmax(G.numVert());
    matriz<tCoste> max = FloydMax(G,Vmax); //Matriz de costes máximos

    Viaje<tCoste> viaje;
    viaje.origen = viaje.destino = viaje.Coste = 0; //Inicializamos a 0

    //Calculamos el máximo de los costes entre todos los nodos
    for(vertice i = 0; i< G.numVert(); i++){
        for(vertice j = 0; j<G.numVert(); j++){
            if(G[i][j]!= INFINITO && viaje.Coste < max[i][j]) {
                viaje.origen = i;
                viaje.destino = j;
                viaje.coste = max[i][j];
            }

        }
    }
    return viaje;

}
