#include "../Materiales Grafos/grafoMA.h"
#include "../Algoritmos/Floyd.cpp"

template<typename tCoste>
tCoste pseudocentro(const GrafoP<tCoste>& G) { 

    typedef typename GrafoP<tCoste>::vertice vertice; 

    matriz<vertice> P; //matriz de vertices para Floyd

    matriz<tCoste> A = Floyd(G, P); 

    //diametro = valor maximo posible
    tCoste diametro = GrafoP<tCoste>::INFINITO;
    
    typedef typename GrafoP<tCoste>::INFINITO INFINITO;

    vertice pseudo; //Almacenar vertice del pseudocodigo

    //Buscamos el nodo pseudocentro, recorriendo la matriz
    for(vertice i = 0; i < G.numVert(); i++){ 

        tCoste lej1 = 0; //Primera distancia mas lejana
        tCoste lej2 = 0; //Segunda distancia mas lejana

        for(vertice j = 0; j < G.numVert(); j++){

            //Buscamos dos distancias mas lejanas
            if(A[i][j] >= lej1){
                lej2 = lej1;
                lej1 = A[i][j];
            
            }else if(A[i][j] >= lej2){
                lej2 = A[i][j];
            }
            
            if(diametro > lej1 + lej2){
                diametro = lej1 + lej2;
                pseudo = i;
            }
            /* 
            Al finalizar el bucle, diametro contendrá el valor del diámetro del 
            grafo (la suma de las distancias mínimas a los dos nodos más alejados del 
            pseudocentro) y pseudo contendrá el índice del vértice pseudocentro encontrado. 
            */
        }

    }

    
}
