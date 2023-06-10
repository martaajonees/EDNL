#include <cassert>         
#include "grafoPMC.h"
using namespace std;

template<typename tCoste>
vector<tCoste> DijkstraInv(GrafoP<tCoste>& G, typename GrafoP<tCoste>::vertice destino,
                            vector<typename GrafoP<tCoste>::vertice>& P ){
    //Estructuras
    const size_t n = G.numVert();
    vector<bool> S(n, false);
    typedef typename GrafoP<tCoste>::vertice vertice;
    vertice v,w;
    vector<tCoste> Min(n);

    //Inicializamos Min y P al reves
    for(int i=0; i<n; i++){
        Min[i]= G[i][destino];
    }
    Min[destino]=0;
    P = vector<vertice>(n, destino);
    
    S[destino]= true;

    for(size_t i =1; i<=n-2; i++){
        tCoste CosteMin = GrafoP<tCoste>::INFINITO;
        for(v=0; v<=n-1;v++){
            if(!S[v] && Min[v]<=CosteMin){
                CosteMin = Min[v];
                w=v;
            }
        }
        S[w]= true;
        for(v=0; v<n;v++){
            if(!S[v]){
                tCoste O = suma(Min[w], G[w][w]);
                if(Min[v]>O){
                    Min[v]= O;
                    P[v]= w;
                }
            }
        }
    }
    return Min;

}
