#include "../Materiales Grafos/grafoMA.h"
#include "../Algoritmos/Dijkstra.cpp"
#include "actividad1.cpp" //Dijkstra Inverso
#include "../Algoritmos/Floyd.cpp"
#include<vector>

template<typename tCoste>
struct camino{
    typename GrafoP<tCoste>::vertice origen, destino;
};

template<typename tCoste>
void zuelandia(GrafoP<tCoste>& G, vector<typename GrafoP<tCoste>::vertice> ciudades,
              vector<camino<tCoste> > carreteras, typename GrafoP<tCoste>::vertice capital){
    
    typedef typename GrafoP<tCoste>::vertice vertice;


    //Vector para Dijkstra
    vector<tCoste> D(G.numVert());
    vector<typename GrafoP<tCoste>::vertice> vectD; 

    //vector para Dijkstra Inverso
    vector<tCoste> I(G.numVert());
    vector<typename GrafoP<tCoste>::vertice> vectI; 

    const tCoste INFINITO = GrafoP<tCoste>::INFINITO;

    //Ponemos en INFINITO las ciudades rebeldes
     for(size_t it = 0; it < ciudades.size(); it++){
        vertice rebelde = ciudades[it];
        for(vertice i = 0; i< G.numVert(); i++){
            G[i][rebelde]= INFINITO;
            G[rebelde][i]= INFINITO;
        }
    }

    //Ponemos en INFINITO las carreteras rebeldes
    for(size_t it = 0; it < carreteras.size(); it++){
        camino<tCoste> rebelde = carreteras[it];
        vertice origen = rebelde.origen;
        vertice destino = rebelde.destino;
        G[origen][destino] = INFINITO;
       
    }

    //Hacemos Dijkstra: encontrar distancia minimo desde capital al resto de 
    //ciudades
    D = Dijkstra(G, capital, vectD);

    //Hacemos Dijkstra Inverso: encontrar distancia minimo desde resto de 
    //ciudades a capital

    D = DijkstraInv(G, capital,vectI);

    //Suma de distancias mínimas
    for(vertice i=0; i<G.numVert();i++){
        for(vertice j = 0; j<G.numVert();j++){
            if(i != j) //omitimos diagonal
                G[i][j] = suma(D[j], I[i]);
        }
    }

}
