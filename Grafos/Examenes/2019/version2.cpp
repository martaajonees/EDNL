
struct ciudad {
    int x, y; //Coordenadas cartesianas
};

template<typename tCoste>
struct LineaAerea {
    LineaAerea(ciudad a, ciudad b, double d): a(a), b(b), distancia(d){}
    ciudad a, b; //Coordenadas cartesianas
    tCoste distancia;
};

template<typename tCoste>
tCoste distancia_euclidea(ciudad a, ciudad b){
    return sqrt(pow(a.x - b.x, 2)+ pow(a.y - b.y, 2));
}

template<typename tCoste>
LineaAerea<tCoste> minima(int i1, int i2, vector<ciudad> ciudades, Particion p){
    int N = ciudades.size(); //Número de ciudades
    const int inf = GrafoP<tCoste>::INFINITO;

    ciudad a, b;
    tCoste d_min = inf;
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N; j++){
            if(i1 == p.encontrar(i) && i2 == p.encontrar(j) ){ //Pertenece a las islas
                tCoste dist = distancia_euclidea<tCoste>(ciudades[i], ciudades[j]);
                if(d_min > dist){ //La distancia es menor
                    d_min = dist;
                    a = ciudades[i];
                    b = ciudades[j];
                }
            }
        }
    }
    LineaAerea<tCoste> l(a, b, d_min);
    return l;
}

template<typename tCoste>
vector<LineaAerea<tCoste> > Tombuctu2(vector<ciudad> ciudades, const Grafo& A){

    typedef typename GrafoP<tCoste>::vertice vertice;
    const int inf = GrafoP<tCoste>::INFINITO;

    int N = ciudades.size(); //Número de ciudades
    Particion p(N);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(A[i][j]){ //Hay conexion, son de la misma isla
                p.unir(p.encontrar(i), p.encontrar(j)); //Misma isla
            } 
        }
    }

    // Vector de representantes
    vector<int> representantes(N, -1);

    //Metemos todos los representantes
    for(int i = 0; i < N; i++){
        int rep = p.encontrar(i);
        if(representantes[rep] == -1){ //No está
            representantes[rep] = i;
        }
    }

    // Vemos ahora la línea más corta entre cada una de las islas
    vector<LineaAerea<tCoste> > lineas;
    for(int i = 0; i < N -1; i++){
        for(int j = i+1; j < N; j++){
            int isla1 = representantes[i];
            int isla2 = representantes[j];
            //Para estas dos islas, vemos cual sería la línea con dist minima
            lineas.push_back(minima<tCoste>(isla1, isla2, ciudades, p));
        }
    }

    
    return lineas;

}
