#include "../Materiales Grafos/grafoPMC.h"
#include "../Materiales Grafos/alg_grafoPMC.h"
#include "../Materiales Grafos/listaenla.h"

struct Casilla{
    int fila, colum; //Filas y columnas
};

struct Pared {
    Casilla a, b;
};

template<typename tCoste>
typename GrafoP<tCoste>::vertice Casilla_Nodo(const Casilla& c, int N){
    return  (c.fila * N) + c.colum;
}

template<typename tCoste>
Casilla Nodo_Casilla(typename GrafoP<tCoste>::vertice nodo, int N){
    Casilla c;
    c.fila = nodo / N;
    c.colum = nodo % N;
    return c;
}

bool adyascentes(Casilla uno, Casilla dos){
    return ((uno.fila - dos.fila ==0 && abs(uno.colum- dos.colum)==1)|| (uno.colum - dos.colum ==0 && abs(uno.fila- dos.fila)==1));
}

template<typename tCoste>
vector<Casilla> laberinto (int n, vector<Pared> p, Casilla entrada, Casilla salida){
    typedef typename GrafoP<tCoste>::vertice vertice; 
    // Creamos Grafo 
    GrafoP<tCoste> Laberinto(n*n);
    tCoste INFINITO = GrafoP<tCoste>::INFINITO;

    vertice inicio = Casilla_Nodo<tCoste>(entrada, n);

    vertice fin = Casilla_Nodo<tCoste>(salida, n);

    //Inicializamos el grafo:
    //Será de coste 1 las que sean adyascentes y coste infinito las que sean paredes 
    for(vertice i = 0; i != Laberinto.numVert(); i++){
        for(vertice j = 0; j != Laberinto.numVert(); j++){
            if(i==j) Laberinto[i][j] = 0; //El coste a si mismo es 0
            else if(adyascentes(Nodo_Casilla<tCoste>(i,n), Nodo_Casilla<tCoste>(j,n))) Laberinto [i][j] = 1;
            else Laberinto[i][j] = INFINITO;
        }
    }
    
    //Ponemos las paredes: 
    //El coste de la casilla a a b será infinito si tiene en medio una pared
    for(int i = 0; i != p.size() ; i++){
       Laberinto[Casilla_Nodo<tCoste>(p[i].a, n)][Casilla_Nodo<tCoste>(p[i].b, n)] = INFINITO;
        Laberinto[Casilla_Nodo<tCoste>(p[i].b, n)][Casilla_Nodo<tCoste>(p[i].a, n)] = INFINITO;
    }

    //Hacemos Dijkstra:
    vector<vertice> vect;
    vector<tCoste> vCostes = Dijkstra(Laberinto, inicio, vect);
    
    //Usamos la función camino para obtener el camino mínimo
    typename GrafoP<tCoste>::tCamino ruta = camino<vertice>(inicio, fin, vect);

    //Convertimos a vector de Casillas
    vector<Casilla> res;
    typename Lista<vertice>::posicion i = ruta.primera();
    while(i != ruta.fin()){
        res.push_back(Nodo_Casilla<tCoste>(ruta.elemento(i),n));
        i = ruta.siguiente(i);
    }
    return res;
}
