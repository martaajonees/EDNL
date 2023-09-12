

#include "../Prácticas/Materiales Grafos/grafoPMC.h"
#include "../Prácticas/Materiales Grafos/grafoMA.h"
#include "../Prácticas/Materiales Grafos/alg_grafoMA.h"
#include<iostream>
using namespace std;

struct ciudad {
    int x, y; //Coordenadas cartesianas
};

struct puente {
    ciudad c1, c2;
    double distancia;
};

double distancia_euclidea(ciudad c1, ciudad c2){
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y + c2.y , 2));
}

template<typename tCoste>
puente archipielago(const Grafo& F, const Grafo& D, vector<ciudad> c_fobos, vector<ciudad> c_deimos,
vector<ciudad> costa_f, vector<ciudad> costa_d ){

    const int N1 = F.numVert();
    const int N2 = D.numVert();
    const int N = N1 + N2;
    typedef GrafoP<tCoste>::vertice vertice;
    const int inf = GrafoP<tCoste>::INFINITO;

    //Creamos un grafo mc
    GrafoP<tCoste> G(N);
    //Inicializamos
    for(int i = 0; i < N1; i++){
        for(int j = 0; j < N1; j++){
            if(F[i][j] == 1){
                G[i][j] = distancia_euclidea(c_fobos[i], c_fobos[j]);
            } else{
                G[i][j] = inf;
            }
        }
    }

    for(int i = N1; i < N; i++){
        for(int j = N1; j < N; j++){
            if(D[i-N1][j-N1] == 1){
                G[i][j] = distancia_euclidea(c_deimos[i-N1], c_deimos[j-N1]);
            } else {
                G[i][j] = inf;
            }
        }
    }

    //Simulamos un puente
    puente p;
    tCoste m = inf;
    for(int i = 0; i < costa_d; i++){
        for(int j = 0; j < costa_f; j++){
            vertice v1 = costa_d[i];
            vertice v2 = costa_f[j];
            G[buscar(v1, c_deimos)][buscar(v2, c_fobos)] = 
            G[buscar(v2, c_fobos)][buscar(v1, c_deimos)]= distancia_euclidea(costa_d[i], costa_d[j]);
            tCoste coste = coste_total(G);
            if(m > coste){
                m = coste;
                p.c1 = v1;
                p.c2 = v2;
                p.distancia = distancia_euclidea(costa_d[i], costa_d[j]);;
            }
            G[buscar(v1, c_deimos)][buscar(v2, c_fobos)] = G[buscar(v2, c_fobos)][buscar(v1, c_deimos)]= inf;
        }
    }

    return p;

}
template<typename tCoste>
tCoste coste_total (const GrafoP<tCoste>& G){
    tCoste total = 0;
    for(int i = 0; i < G.numVert(); i++){
        for(int j = 0; j < G.numVert(); j++){
            if(G[i][j] != GrafoP<tCoste>::INFINITO) total += G[i][j] 
        }
    }
    return total;
}

size_t buscar(ciudad r, vector<ciudad> c_fobos){
    for(int i = 0; i < c_fobos.size(); i++){
        if(c_fobos[i].x == r.x && c_fobos[i].y == r.y){
            return i;
        }
    }
    return -1; // No existe
}
