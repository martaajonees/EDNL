#include "../Materiales Grafos/grafoMA.h"
#include "FloydACT3.cpp"

/*
    Modificamos Floyd para que la diagonal principal se inicialice a INFINITO
    Si en la diagonal son todos infinitos es que es aciclico
*/
template<typename tCoste>

bool aciclico(const GrafoP<tCoste>& G) {

    typedef typename GrafoP<tCoste>::vertice vertice;

    GrafoP<vertice> P;

    GrafoP<tCoste> A = Floyd(G, P);

    bool acicl = true;

    //Recorremos el grafo
    for(vertice i = 0; i< G.numVert(); i++){
        for(vertice j = 0 ; j<G.numVert(); j++){
            if(i==j && A[i][j] != GrafoP<tCoste>::INFINITO) acicl = false;
        }
    }

    return acicl;

}
