enum alergia {Bus, Tren, Avion};

struct viajero {
    unsigned dinero;
    alergia alergico;
};

template<typename tCoste>
vector<typename GrafoP<tCoste>::vertice> encontrar_ciudades(viajero v, GrafoP<tCoste> bus, GrafoP<tCoste> tren, GrafoP<tCoste> avion ,typename GrafoP<tCoste>::vertice origen){
    
    typedef typename GrafoP<tCoste>::vertice vertice;
    size_t N = tren.numVert();
    
    vector<vertice> vect;
    vector<tCoste> medio1(N), medio2(N);

    //Vemos que medios de transporte podemos utilizar
    switch (v.alergico){
    case Bus:
        medio1 = Dijkstra(tren, origen, vect);
        medio2 = Dijkstra(avion, origen, vect);
        break;
    case Tren:
        medio1 = Dijkstra(bus, origen, vect);
        medio2 = Dijkstra(avion, origen, vect);
        break;
    case Avion:
        medio1 = Dijkstra(bus, origen, vect);
        medio2 = Dijkstra(tren, origen, vect);
        break;
    default:
        break;
    }

    //Ponemos la secuencia de ciudades alcanzables con el dinero disponible
    vector<vertice> ciudades;
    for(vertice i = 0; i < N; i++){
        if(i != origen && v.dinero >= min(medio1[i], medio2[i])){
            ciudades.push_back(i);
        }
    }
    return ciudades;

}
