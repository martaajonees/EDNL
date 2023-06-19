struct Casilla {
    int fila, columna;
};

struct Pared {
    Casilla a, b;
};

bool movimiento_caballo(Casilla a, Casilla b){
    return (abs(b.columna - a.columna) == 1 && abs(b.fila - a.fila)==2) || (abs(b.fila - a.fila)==1 && abs(b.columna - a.columna)==2);
}

template<typename tCoste>
typename GrafoP<tCoste>::vertice Casilla_a_Nodo(Casilla a, int N){
    return a.fila * N + a.columna;
}

template<typename tCoste>
Casilla Nodo_a_Casilla(typename GrafoP<tCoste>::vertice a, int N){
    Casilla c;
    c.columna = a % N;
    c.fila = a / N;
    return c;
}


template<typename tCoste>
typename GrafoP<tCoste>::tCamino laberinto(int N, typename GrafoP<tCoste>::vertice inicio, 
typename GrafoP<tCoste>::vertice fin, int &coste){
    typedef typename GrafoP<tCoste>::vertice vertice; 
    //Inicializamos Grafo con el tablero
    GrafoP<tCoste> tablero(N);

    for(vertice i = 0; i < N; i++){
        for(vertice j = 0; j < N; j++){
            if(i == j) tablero[i][j] = 0; //El coste a si mismo es 0
            else if(movimiento_caballo(Nodo_a_Casilla(i, N), Nodo_a_Casilla(j, N))) tablero[i][j] = 1; //adyascentes
            else tablero[i][j] = GrafoP<tCoste>::INFINITO;
        }
    }

    // Hago Dijkstra para el camino
    vector<vertice> vect;
    vector<tCoste> D = Dijkstra(tablero, inicio, vect);
    GrafoP<tCoste>::tCamino ruta = camino(inicio, fin, vect);
    coste = D[fin];

    return ruta;
}
