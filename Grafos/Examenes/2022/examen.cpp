struct Casilla{
    int fila, columna, altura;
};

template<typename tCoste>
void laberinto(size_t N, vector<Casilla> piedra, Casilla entrada, Casilla salida){
    typedef typename GrafoP<tCoste>::vertice vertice;
    vertice inicio = Casilla_Nodo(entrada, N);
    vertice fin = Casilla_Nodo(salida, N);
    //Inicializamos Grafo de costes
    GrafoP<tCoste> lab(N*N*N); // 3 dimensiones
    
    for(size_t k= 0; k < piedra.size(); k++){
        for(vertice i = 0; i < N*N*N; i++){
            for(vertice j = 0; j < N*N*N; j++){
                if(adyascentes(Nodo_Casilla(i, N),Nodo_Casilla(j, N))){ //El coste será de 1
                    lab[i][j] = 1;
                }else if(i == j){ //Así mismo será de 0
                    lab[i][j] = 0;
                } else { //Si no el coste es infinito;
                    lab[i][j] = GrafoP<tCoste>::INFINITO;
                }
                if(Casilla_Nodo(piedra[k], N) == i || Casilla_Nodo(piedra[k], N) == j){ //Si tiene piedra, el coste es infinito
                    lab[i][j] = GrafoP<tCoste>::INFINITO;
                }
            }
        }
    }
    //Para conseguir el camino, hacemos Dijkstra
    vector<vertice> vect(N*N*N);
    vector<tCoste> Dij = Dijkstra(lab, inicio, vect);
    GrafoP<tCoste>::tCamino ruta = camino(inicio, fin, Dij);

    cout<< "El camino es \n" << ruta;
    cout<< "\nSu longitud es de: " << Dij[fin];
    
    
}

template<typename tCoste>
typename GrafoP<tCoste>::vertice Casilla_Nodo(Casilla a, size_t N){
    return (a.fila * N) + a.columna + (a.altura * N * N);
}

template<typename tCoste>
Casilla Nodo_Casilla(typename GrafoP<tCoste>::vertice nodo, size_t N){
    Casilla c;
    c.fila = (nodo/N) % N;
    c.columna = nodo % N;
    c.altura = nodo/ (N*N)
}


bool adyascentes(Casilla n1, Casilla n2){
    return (abs(n1.fila - n2.fila) + abs(n1.columna - n2.columna) + abs(n1.altura - n2.altura))== 1;
}
