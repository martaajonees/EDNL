#include "../Materiales Grafos/grafoPLA.h"
#include <cassert>    
using namespace std;

template<typename tCoste>
tCoste suma(tCoste x, tCoste y);

template<typename tCoste>
vector<tCoste> Dijkstra (const GrafoP<tCoste>& G, typename GrafoP<tCoste>::vertice origen, vector<typename GrafoP<tCoste>::vertice>& P ){
 
    //Creamos tipos
    typedef typename GrafoP<tCoste>::vertice vertice;
    vertice v, w;
    const size_t n = G.numVert(); //Tamaño es el número de vértices
    vector<bool> S(n, false); //Vector de bool inicializado con tamaño n y todo a falso
    vector<tCoste> Min; //Vector que tendrá el camino mínimo
    
    const tCoste INFINITO = std::numeric_limits<tCoste>::max();

    //Inicializamos con caminos directos desde origen
    Min= G[origen];
    Min[origen]= 0; //El coste al origen es siempre 0

    P = vector<vertice>(n,origen);

    //Calcular camino mínimo hasta cada vértice
    S[origen] = true; 

    for(int i = 1; i <= n-2 ; i++){ //Contador de iteraciones
        tCoste costeMin = INFINITO;
        for(v=0; v <= n-1; v++){
            if(!S[v] && Min[v] <= costeMin){ //Localizo vértice que no esté en S con menor coste
                costeMin= Min[v]; 
                w = v;
            }
        }

        S[w]=true; //Menor camino-ponemos a true
        const Lista<vertice>& adyascentes =G.adyacentes(w);
        for(typename Lista<vertice>::iterator it = adyascentes.primera(); it != adyascentes.fin(); it++){ //Recalculamos las distancias de los que no estén en S para w
            vertice v = *it;
            if(!S[v]){
                tCoste O = suma(Min[w], G[w][v]); //Sumamos vector de costes mínimos y M costes
                if(O < Min[v]){
                    Min[v] = O;
                    P[v] = w;
                }

            }
        }
        return Min;
    }
}

template<typename tCoste>
tCoste suma(tCoste x, tCoste y){
    const tCoste INFINITO = std::numeric_limits<tCoste>::max();
    if(x == INFINITO || y == INFINITO) return INFINITO;
    else return x + y;
}
