//Se disponen de las coordenadas cartenianas de todas las ciudades
struct Ciudad {
    double x, y;
};

struct Puente {
    Ciudad a, b;
    double coste;
};

//Los costes de construir y viajar es la distancia euclidea
double distancia_euclidea(Ciudad a, Ciudad b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y ,2));
}

template<typename tCoste>
Puente mejor_puente(vector<Ciudad> costaf, vector<Ciudad> costad){
    typedef typename GrafoP<tCoste>::vertice vertice;
    double coste ;
    //Creamos Puente
    Puente p;
    p.coste = GrafoP<tCoste>::INFINITO;
    //Recorro todas las ciudades costeras
    for(int i = 0; i < costaf.size(); i++){ //De Fobos
        for(int j = 0; j < costad.size(); j++){ //De Deimos
            coste = distancia_euclidea(costaf[i], costad[j]);
            if(p.coste > coste){
                p.a = i;
                p.b = j;
                p.coste = coste;
            }
        }
    }
    return p;
}

template<typename tCoste>
typename GrafoP<tCoste>::tCamino grecoland(vector<Ciudad> fobos, vector<Ciudad> deimos, vector<Ciudad> costaf,
vector<Ciudad> costad, typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino){
    typedef typename GrafoP<tCoste>::vertice vertice;

    //Primero hay que reconstruir el Archipiélago
    //Reconstruimos fobos
    GrafoP<tCoste> F(fobos.size());
    for(vertice i = 0; i < n; i++){
        for(vertice j = 0; j < n; j++){
            F[i][j] = distancia_euclidea(fobos[i], fobos[j]);
        }
    }

    GrafoP<tCoste> FobosTotal(fobos.size());
    FobosTotal = Prim(F); 

    
    //Reconstruimos Deimos
    GrafoP<tCoste> D(deimos.size());
    for(vertice i = 0; i < n; i++){
        for(vertice j = 0; j < n; j++){
            F[i][j] = distancia_euclidea(deimos[i], deimos[j]);
        }
    }

    GrafoP<tCoste> DeimosTotal(deimos.size());
    DeimosTotal = Prim(D); 

    //Ponemos el mejor puente
    Puente puente = mejor_puente(costaf, costad);

    //Calculamos el coste mínimo en un supergrafo
    size_t n = fobos.size() + deimos.size();
    size_t f = fobos.size();
    size_t d = deimos.size();
    GrafoP<tCoste> SG(n);
     
    // Inicializamos
    for(vertice i = 0; i < f ; i++){
        for(vertice j = 0; j< f; j++){
            SG[i][j] = FobosTotal[i][j];
        }
    }

    for(vertice i = d; i < n ; i++){
        for(vertice j = d; j< n; j++){
            SG[i + f][j + f] = DeimosTotal[i][j];
        }
    }

    //Costes
    //Añadimos coste de puente
    SG[puente.a][puente.b + f] = SG[puente.b + f][puente.a] = puente.coste;

    //Hacemos Dikstra
    vector<vertice> vert(n);
    vector<tCoste> Dij = Dijkstra(SG, origen, destino, vert);

    //Camino mínimo

    return camino(origen, destino, Dij);
}
