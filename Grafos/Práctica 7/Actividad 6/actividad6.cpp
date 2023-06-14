#include "../Materiales Grafos/grafoPMC.h"
#include "../Materiales Grafos/alg_grafoPMC.h"
#include "../Materiales Grafos/alg_grafo_E-S.h"
#include <iostream>
using namespace std;

// Hay 4 opciones. Todo Bus, todo tren, bus y cambio a tren, tren y cambio a bus
template<typename tCoste>
matriz<tCoste> tarifa_minima(GrafoP<tCoste> Bus, GrafoP<tCoste> Tren, typename GrafoP<tCoste>::vertice transbordo){
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t N = Bus.numVert();
    
    //Hacemos Floyd
    matriz<vertice> vert(N);
    matriz<tCoste> minBus = Floyd(Bus,vert);
    matriz<tCoste> minTren = Floyd(Tren,vert);
    
    matriz<tCoste> tarifaMinima(N);
    //Calculamos el transbordo
    for(vertice i = 0; i < N; i++){
        for(vertice j = 0; j < N; j++){
                tarifaMinima[i][j] = min(minBus[i][j], min(minTren[i][j],min(minBus[i][transbordo]+ minTren[transbordo][i], minTren[i][transbordo]+ minBus[transbordo][i])));
        }    
    }
    return tarifaMinima;
}
