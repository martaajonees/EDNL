#include <cassert>
#include "../Materiales Grafos/matriz.h"             
#include "../Materiales Grafos/grafoPMC.h"
using namespace std;
/*
FLOYD nos devuelve una matriz de costes con el camino mínimo
*/
template<typename tCoste>
matriz<tCoste> Floyd(const GrafoP<tCoste>& G, matriz<typename GrafoP<tCoste>::vertice>& P){
    typedef typename GrafoP<tCoste>::vertice vertice;
    vertice v;
    const size_t n = G.numVert();
    matriz<tCoste> M(n); //Matriz que se va a devolver

    //Iniciamos M y P con  caminos directos entre cada par de vértices
    P = matriz<vertice>(n);

    //Inicialización
    for(vertice i = 0; i<= n-1; i++){
        M[i] = G[i]; //Rellenamos matriz de costes
        M[i][i] = GrafoP<tCoste>::INFINITO; //diagonal a INFINITO
        P[i] = vector<vertice>(n,i);
    }

    //Calculamos costes mínimos y caminos entre cualquier par de índices i y j
    for(vertice k=0; k<=n-1; k++){
        for(vertice i=0; i<=n-1; i++){
            for(vertice j=0; j<=n-1;j++){
                tCoste O=suma(M[i][k], M[k][i]);
                if(O< M[i][j]){
                    M[i][j]= O;
                    P[i][j]=k;
                } 
            }
        }
    }
    return M;
}
